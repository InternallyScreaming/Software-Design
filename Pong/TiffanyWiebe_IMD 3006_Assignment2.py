import pygame, sys
from pygame.locals import *


#####Referenced this link to assist me with coding this game
####http://trevorappleton.blogspot.com/2014/04/writing-pong-using-python-and-pygame.html

# class that holds all the defines in the game
class GAME:
    ######################## WINDOW ########################
    winWidth        = 800
    winHeight       = 700

    ######################## GAME OBJECTS ########################
    lineThickness   = 15
    paddleSize      = 80
    paddleOffset    = 30

    ######################## COLORS ########################
    PRPL = (111, 30, 81)
    CYAN = (18, 203, 196)


    FPS = 100

# draws the background color to purple & draws a centerline, top dow, in cyan
def drawGameArea(object):
    arenaSURFACE.fill((object.PRPL))
    pygame.draw.line(arenaSURFACE, object.CYAN, ((object.winWidth/2), 0), ((object.winWidth/2), object.winHeight))
    pygame.display.flip

# draws the player's paddle and the opposing wall, both in cyan
# will stop the paddle from going beyond the upper and lower limits of the window
def drawPaddle(paddle, object):
    if paddle.bottom >= (object.winHeight):
        paddle.bottom = (object.winHeight)
    elif paddle.top == 0:
        paddle.top = 0
    pygame.draw.rect(arenaSURFACE, object.CYAN, paddle)

#draws the ball in cyan to the window
def drawBall(ball, object):
    pygame.draw.rect(arenaSURFACE, object.CYAN, ball)

#moves the ball's xy coordinates
def moveBall(ball, X, Y):
    ball.x += X
    ball.y += Y
    return ball

#detects if the ball's top has hit the top of the screen
#detects if the ball's bottom has hit the bottom of the screen
#if either of these are true, reverse the ball's Y direction
#detects if the ball's left has hit the left side of the screen
#detects if the ball's right has hit the right side of the screen
#if either of these are true, reverse the ball's X direction
def collisionDetection_Wall(ball, X, Y, object):
    if ball.top == (0) or ball.bottom == (object.winHeight):
        Y = Y * -1
    if ball.left == (0) or ball.right == (object.winWidth):
        X = X * -1

    return [X, Y]



def collisionDetection_Paddle(ball, pad1, pad2, bX):
    #if the ball's X direction is -1 and the player's paddle's right side is equal to the ball'sleft side
        #and the player's paddle top  is less than ball's top and player's paddle bottom is greater than ball's bottom
        #return -1
        #this will be used to change the balls X direction
    if bX == -1  and pad1.right == ball.left and pad1.top < ball.top and pad1.bottom > ball.bottom:
        return -1

    #If the ball's X direction is 1 and the ball's right is equal to paddle 2's left(the wall's left)
            #return -1
            #this will be used to change the balls X direction
    elif bX == 1  and pad2.left == ball.right:
        return -1
    
    #if the ball does not hit any of the paddles return 1
    else:
        return 1

######################################################MAIN FUNCTION#######################################################
def main():
    #initiate pygame
    pygame.init()
    


    #Create an instance of the game class
    GAMESETTINGS = GAME()

    #Set the positions of player 1 and player 2(wall)
    p1Pos = (GAMESETTINGS.winHeight - GAMESETTINGS.paddleSize) /2
    p2Pos = (GAMESETTINGS.winHeight - GAMESETTINGS.paddleSize) /2

    #Create teh game paddles
    p1Pad = pygame.Rect(GAMESETTINGS.paddleOffset, p1Pos, GAMESETTINGS.lineThickness, GAMESETTINGS.paddleSize)
    p2Pad = pygame.Rect(GAMESETTINGS.winWidth - GAMESETTINGS.lineThickness, p2Pos, GAMESETTINGS.lineThickness, GAMESETTINGS.winHeight)
    
    #set the ball coordinates
    ballCOOR = [(GAMESETTINGS.winWidth/2 - GAMESETTINGS.lineThickness/2), (GAMESETTINGS.winHeight/2 - GAMESETTINGS.lineThickness/2)]
    #set the ball's directional movement
    ballDir = [-1, -1]
    #draw the ball
    ball =  pygame.Rect(ballCOOR[0], ballCOOR[1], GAMESETTINGS.lineThickness, GAMESETTINGS.lineThickness)

    #create the clock, this will be used to create our frames per second
    clock = pygame.time.Clock()

    #call global variable, arenaSurface
    global arenaSURFACE
    #set the surface to the size of the window width and height that is defined in the game class
    arenaSURFACE = pygame.display.set_mode((GAMESETTINGS.winWidth, GAMESETTINGS.winHeight))
    
    #initialize these functions for the first time
    #draw game area, pass in the game class
    drawGameArea(GAMESETTINGS)

    #draw the paddles, pass in the game class
    drawPaddle(p1Pad, GAMESETTINGS)
    drawPaddle(p2Pad, GAMESETTINGS)

    #draw ball, pass in the game class
    drawBall(ball, GAMESETTINGS)

    #set the mouse visibility to 0
    pygame.mouse.set_visible(0)

    while True:
        #events
        for event in pygame.event.get():
            #if there is a quit, return 0,
            if event.type == QUIT:
                return 0
            #if there is mouse movement, have mouse's x and y coordinates equal the position of the mouse cursor(which is invisible)
            elif event.type == MOUSEMOTION:
                mouseCoorX, mouseCoorY = event.pos
                #have Player 1's paddle's y position equal the mouse's y position
                p1Pad.y = mouseCoorY

        #update the game surface
        pygame.display.update()
        #tick the clock to the next frame
        clock.tick(GAMESETTINGS.FPS)

        #update the draw functions
        drawGameArea(GAMESETTINGS)          #draw game area
        drawPaddle(p1Pad, GAMESETTINGS)     #draws the paddles
        drawPaddle(p2Pad, GAMESETTINGS)     #draws the paddles
        drawBall(ball, GAMESETTINGS)        #draws the ball
        #move the ball
        ball = moveBall(ball, ballDir[0], ballDir[1])
        #check for wall collision
        #ball will not change direction if there is no collision
        ballDir = collisionDetection_Wall(ball, ballDir[0], ballDir[1], GAMESETTINGS)
        #check for ball collision
        #ball will not change direction if there is no collision
        ballDir[0] = ballDir[0] * collisionDetection_Paddle(ball, p1Pad, p2Pad, ballDir[0])


#Calls the main function
if __name__ == '__main__':
    main()