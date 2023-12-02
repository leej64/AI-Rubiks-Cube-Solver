# Created by Junwon Lee 2023-12-01

import random
from tqdm import tqdm

"""
               [2]
               WWW            
               WWW
               WWW
          [3]  [0]  [4]  [5]
          GGG  RRR  BBB  OOO
          GGG  RRR  BBB  OOO
          GGG  RRR  BBB  OOO
               [1]
               YYY
               YYY
               YYY  
"""
# Red, Yellow, White, Green, Blue, Orange
# [0]: front, [1]: down, [2]: up, [3]: left, [4]: right, [5]: back

# list to represent commands
# First element in each tuple represents dimension to turn
# Second element in each tuple represents direction to turn - Clockwise/CounterClockwise
COMMAND = [('U', 'C'), ('U', "CC"), ('D', 'C'), ('D', "CC"), ('F', 'C'), ('F', "CC"),
            ('B', 'C'), ('B', "CC"), ('L', 'C'), ('L', "CC"), ('R', 'C'), ('R', "CC")]

GOALSTATE = [[['R','R','R'], ['R','R','R'], ['R','R','R']], 
             [['Y','Y','Y'], ['Y','Y','Y'], ['Y','Y','Y']],
             [['W','W','W'], ['W','W','W'], ['W','W','W']],
             [['G','G','G'], ['G','G','G'], ['G','G','G']],
             [['B','B','B'], ['B','B','B'], ['B','B','B']],
             [['O','O','O'], ['O','O','O'], ['O','O','O']]]

THRESHOLD = 26

class Cube:
    def __init__(self, state = GOALSTATE):
        self.state = state

    def getState(self):
        return self.state
    
    def setState(self, state):
        self.state = state

    # prints out cube in planar figure
    def printState(self):
        # prints out upper dimension
        for i in range(3):
            print("    ", end="")
            for j in range(3):
                print(self.state[2][i][j], end="")
            print()

        # prints out side dimensions
        for i in range(3):
            for k in range(4):
                for j in range(3):
                    if k == 0:
                        print(self.state[3][i][j], end="")
                    elif k == 1:
                        print(self.state[0][i][j], end="")
                    elif k == 2:
                        print(self.state[4][i][j], end="")
                    elif k == 3:
                        print(self.state[5][i][j], end="")
                print (" ", end="")
            print()

        # prints out down dimension
        for i in range(3):
            print("    ", end="")
            for j in range(3):
                print(self.state[1][i][j], end="")
            print()
        print()


    # handles change within dimension after a turn
    def moveDimension(self, state, dimension):
        for _ in range(2):
            temp = state[dimension][0][0]
            state[dimension][0][0] = state[dimension][1][0]
            state[dimension][1][0] = state[dimension][2][0]
            state[dimension][2][0] = state[dimension][2][1]
            state[dimension][2][1] = state[dimension][2][2]
            state[dimension][2][2] = state[dimension][1][2]
            state[dimension][1][2] = state[dimension][0][2]
            state[dimension][0][2] = state[dimension][0][1]
            state[dimension][0][1] = temp

    # handles changes with different dimension after a turn
    # turns selected dimension into clockwise direction
    def move(self, state, dimension):
        if dimension == 'U':
            temp = state[0][0]
            state[0][0] = state[4][0]
            state[4][0] = state[5][0]
            state[5][0] = state[3][0]
            state[3][0] = temp
            self.moveDimension(state,2)
            
        elif dimension == 'D': 
            temp = state[0][2]
            state[0][2] = state[3][2]
            state[3][2] = state[5][2]
            state[5][2] = state[4][2]
            state[4][2] = temp
            self.moveDimension(state,1)
            
        elif dimension == 'F': 
            temp = state[2][2]
            state[2][2] = [state[3][2][2], state[3][1][2], state[3][0][2]]
            state[3][0][2], state[3][1][2], state[3][2][2] = state[1][0]
            state[1][0] = [state[4][2][0], state[4][1][0], state[4][0][0]]
            state[4][0][0], state[4][1][0], state[4][2][0] = temp
            self.moveDimension(state,0)
            
        elif dimension == 'B': 
            temp = state[2][0]
            state[2][0] = [state[4][0][2], state[4][1][2], state[4][2][2]]
            state[4][2][2], state[4][1][2], state[4][0][2] = state[1][2]
            state[1][2] = [state[3][0][0], state[3][1][0], state[3][2][0]]
            state[3][2][0], state[3][1][0], state[3][0][0] = temp
            self.moveDimension(state,5)    
            
        elif dimension == 'L': 
            temp = [state[0][0][0], state[0][1][0], state[0][2][0]]
            state[0][0][0], state[0][1][0], state[0][2][0] = state[2][0][0], state[2][1][0], state[2][2][0]
            state[2][0][0], state[2][1][0], state[2][2][0] = state[5][2][2], state[5][1][2], state[5][0][2]
            state[5][0][2], state[5][1][2], state[5][2][2] = state[1][2][0], state[1][1][0], state[1][0][0]
            state[1][0][0], state[1][1][0], state[1][2][0] = temp
            self.moveDimension(state,3)
            
        elif dimension == 'R': 
            temp = [state[0][0][2], state[0][1][2], state[0][2][2]]
            state[0][0][2], state[0][1][2], state[0][2][2] = state[1][0][2], state[1][1][2], state[1][2][2]
            state[1][0][2], state[1][1][2], state[1][2][2] = state[5][2][0], state[5][1][0], state[5][0][0]
            state[5][0][0], state[5][1][0], state[5][2][0] = state[2][2][2], state[2][1][2], state[2][0][2]
            state[2][0][2], state[2][1][2], state[2][2][2] = temp
            self.moveDimension(state,4)

    # handles command tuple and turns cube
    # returns new state after command
    def turn(self, command):
        dimension, direction = command
        newState = self.state
        count = 1 if direction == 'C' else 3
        for _ in range(count): self.move(newState, dimension)
        return newState

    # initializes Cube into random starting state
    # Turns cube into random direction num times
    def initRandState(self, num):
        for _ in range(num):
            command = random.choice(COMMAND)
            self.state = self.turn(command)