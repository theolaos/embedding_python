#include <iostream>
#include "Python.h"

#define PY_SSIZE_T_CLEAN

int main(int argc, char *argv[]){
    setenv("PYTHONPATH",".",1);

    std::cout << "Hello C++" << std::endl;
    
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);

    if (program == NULL){
        std::cerr << "Fatal error cannot decode argv[0]" << std::endl;
        exit(1);
    }

    Py_SetProgramName(program);

    Py_Initialize();


    PyObject* simple_gaem_name = PyUnicode_FromString((char*)"resources.simple");
    PyObject* module_name = PyImport_Import(simple_gaem_name);

    if (module_name == NULL){
        std::cerr << "Module resources simple, not found." << std::endl;
        return -1;
    }
    

    PyObject* myClass = PyObject_GetAttrString(module_name,"Game");

    PyObject* gameClass = PyObject_CallObject(myClass, NULL);

    PyObject* gameSetup = PyObject_CallMethod(gameClass,(char *)"setup","s",gameClass); 
    if (gameSetup == NULL){
        std::cerr << "Game setup not initialized" << std::endl;
        return -1;
    }
    PyObject* gameLoop = PyObject_CallMethod(gameClass,(char *)"game_loop","s",gameClass);
    if (gameLoop == NULL){
        std::cerr << "game loop not initialized" << std::endl;
        return -1;
    }

    static bool running = true;
    while (running){
        gameLoop = PyObject_CallMethod(gameClass,(char *)"game_loop","s",gameClass);
        running = PyObject_CallMethod(gameClass,(char *)"get_false","s",gameClass);
        if (running == NULL){
            std::cerr << "running not initialized" << std::endl;
            return -1;
        }
    }


    Py_DECREF(simple_gaem_name);
    Py_DECREF(gameClass);
    Py_DECREF(gameLoop);
    Py_DECREF(gameSetup);
    Py_DECREF(myClass);

    if (Py_FinalizeEx() < 0 ){
        exit(120);
    }


    PyMem_RawFree(program);

    return 0;
}