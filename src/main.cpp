#include <iostream>
#include "Python.h"

#define PY_SSIZE_T_CLEAN

int main(int argc, char *argv[]){
    // On release
    setenv("PYTHONPATH",".",1);

    std::cout << "Hello C++" << std::endl;
    
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);

    if (program == NULL){
        std::cerr << "Fatal error cannot decode argv[0]" << std::endl;
        exit(1);
    }

    Py_SetProgramName(program);

    Py_Initialize();

    PyObject* game_module = PyImport_ImportModule("resources.simple");


    if (game_module != NULL) {
        // Assuming your Game class is defined in your Python module
        PyObject* game_class = PyObject_GetAttrString(game_module, "Game");

        if (game_class && PyCallable_Check(game_class)) {
            // Create an instance of the Game class
            PyObject* game_instance = PyObject_CallObject(game_class, NULL);

            if (game_instance != NULL) {
                // Call the setup() method
                PyObject_CallMethod(game_instance, "setup", NULL);

                // Game loop
                while (true) {
                    // Call the game_loop() method
                    PyObject_CallMethod(game_instance, "game_loop", NULL);

                    // Check if the game is still running
                    PyObject* running_state = PyObject_CallMethod(game_instance, "get_running_state", NULL);
                    bool running = PyObject_IsTrue(running_state);

                    // Clean up
                    Py_DECREF(running_state);

                    if (!running)
                        break;

                    // Insert a delay or handle other tasks here
                }

                // Clean up
                Py_DECREF(game_instance);
            }

            Py_DECREF(game_class);
        }

        Py_DECREF(game_module);
    }

    PyMem_RawFree(program);

    // Finalize Python
    Py_Finalize();

    return 0;
}



