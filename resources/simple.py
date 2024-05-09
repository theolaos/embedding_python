import pygame
# import sys

# # pygame setup
# pygame.init()
# screen = pygame.display.set_mode((1280, 720))
# clock = pygame.time.Clock()
# running = True

# while running:
#     # poll for events
#     # pygame.QUIT event means the user clicked X to close your window
#     for event in pygame.event.get():
#         if event.type == pygame.QUIT:
#             running = False

#     # fill the screen with a color to wipe away anything from last frame
#     screen.fill("purple")

#     # RENDER YOUR GAME HERE

#     # flip() the display to put your work on screen
#     pygame.display.flip()

#     clock.tick(60)  # limits FPS to 60

# pygame.quit()
class Game:
    def __init__(self) -> None:
        self.screen = None
        self.clock = None
        self.running = None
    
    def setup(self) -> None:
        self.screen = pygame.display.set_mode((1280, 720))
        self.clock = pygame.time.Clock()
        self.running = True
        print("ran")

    def game_loop(self) -> None:
        """
        Game loop without a game loop.
        """
        # poll for events
        # pygame.QUIT event means the user clicked X to close your window
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                self.running = False

        # fill the screen with a color to wipe away anything from last frame
        print("purple screen")
        self.screen.fill("purple")

        # RENDER YOUR GAME HERE

        # flip() the display to put your work on screen
        pygame.display.flip()

    def get_false(self) -> bool:
        return self.running

print("helo")
del pygame