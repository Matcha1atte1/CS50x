import os
os.environ['SDL_VIDEODRIVER'] = 'dummy'
os.environ['SDL_RENDER_DRIVER'] = 'software'
import pygame
import sys

# intitialise pygame
pygame.init()

# window dimensions
screen_width, screen_height = 800, 600
screen = pygame.display.set_mode((screen_width, screen_height))

# window title
pygame.display.set_caption('Blackjack Game')

# set variable to hold the colour of blackjack table, dark green
background_colour = (0, 128, 0)

# main game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # fill screen with the background colour, dark green
    screen.fill(background_colour)

    pygame.display.flip()








# quit pygame
pygame.quit() # clear pygame resources
sys.exit() # exit program


