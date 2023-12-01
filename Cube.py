# Created by Junwon Lee 2023-12-01

import random

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


# prints out cube in planar figure
def printCube(cube):
    # prints out upper dimension
    for i in range(3):
        print("    ", end="")
        for j in range(3):
            print(cube[2][i][j], end="")
        print()

    # prints out side dimensions
    for i in range(3):
        for k in range(4):
            for j in range(3):
                if k == 0:
                    print(cube[3][i][j], end="")
                elif k == 1:
                    print(cube[0][i][j], end="")
                elif k == 2:
                    print(cube[4][i][j], end="")
                elif k == 3:
                    print(cube[5][i][j], end="")
            print (" ", end="")
        print()

    # prints out down dimension
    for i in range(3):
        print("    ", end="")
        for j in range(3):
            print(cube[1][i][j], end="")
        print()
    print()

# handles change within dimension after a turn
def moveDimension(cube, dimension):
    for _ in range(2):
        temp = cube[dimension][0][0]
        cube[dimension][0][0] = cube[dimension][1][0]
        cube[dimension][1][0] = cube[dimension][2][0]
        cube[dimension][2][0] = cube[dimension][2][1]
        cube[dimension][2][1] = cube[dimension][2][2]
        cube[dimension][2][2] = cube[dimension][1][2]
        cube[dimension][1][2] = cube[dimension][0][2]
        cube[dimension][0][2] = cube[dimension][0][1]
        cube[dimension][0][1] = temp

# handles changes with different dimension after a turn
# turns selected dimension into clockwise direction
def move(cube, dimension):
    if dimension == 'U':
        temp = cube[0][0]
        cube[0][0] = cube[4][0]
        cube[4][0] = cube[5][0]
        cube[5][0] = cube[3][0]
        cube[3][0] = temp
        moveDimension(cube,2)
        
    elif dimension == 'D': 
        temp = cube[0][2]
        cube[0][2] = cube[3][2]
        cube[3][2] = cube[5][2]
        cube[5][2] = cube[4][2]
        cube[4][2] = temp
        moveDimension(cube,1)
        
    elif dimension == 'F': 
        temp = cube[2][2]
        cube[2][2] = [cube[3][2][2], cube[3][1][2], cube[3][0][2]]
        cube[3][0][2], cube[3][1][2], cube[3][2][2] = cube[1][0]
        cube[1][0] = [cube[4][2][0], cube[4][1][0], cube[4][0][0]]
        cube[4][0][0], cube[4][1][0], cube[4][2][0] = temp
        moveDimension(cube,0)
        
    elif dimension == 'B': 
        temp = cube[2][0]
        cube[2][0] = [cube[4][0][2], cube[4][1][2], cube[4][2][2]]
        cube[4][2][2], cube[4][1][2], cube[4][0][2] = cube[1][2]
        cube[1][2] = [cube[3][0][0], cube[3][1][0], cube[3][2][0]]
        cube[3][2][0], cube[3][1][0], cube[3][0][0] = temp
        moveDimension(cube,5)    
        
    elif dimension == 'L': 
        temp = [cube[0][0][0], cube[0][1][0], cube[0][2][0]]
        cube[0][0][0], cube[0][1][0], cube[0][2][0] = cube[2][0][0], cube[2][1][0], cube[2][2][0]
        cube[2][0][0], cube[2][1][0], cube[2][2][0] = cube[5][2][2], cube[5][1][2], cube[5][0][2]
        cube[5][0][2], cube[5][1][2], cube[5][2][2] = cube[1][2][0], cube[1][1][0], cube[1][0][0]
        cube[1][0][0], cube[1][1][0], cube[1][2][0] = temp
        moveDimension(cube,3)
        
    elif dimension == 'R': 
        temp = [cube[0][0][2], cube[0][1][2], cube[0][2][2]]
        cube[0][0][2], cube[0][1][2], cube[0][2][2] = cube[1][0][2], cube[1][1][2], cube[1][2][2]
        cube[1][0][2], cube[1][1][2], cube[1][2][2] = cube[5][2][0], cube[5][1][0], cube[5][0][0]
        cube[5][0][0], cube[5][1][0], cube[5][2][0] = cube[2][2][2], cube[2][1][2], cube[2][0][2]
        cube[2][0][2], cube[2][1][2], cube[2][2][2] = temp
        moveDimension(cube,4)

# handles command tuple and turns cube
def turn(cube, command):
    dimension, direction = command
    count = 1 if direction == 'C' else 3
    for _ in range(count): move(cube, dimension)

# initializes Cube into random starting state
# Turns cube into random direction num times
def initRandCube(cube, num):
    for _ in range(num):
        command = random.choice(COMMAND)
        turn(cube, command)

# Create cube
cube = [[] for _ in range(6)]
for _ in range(3):
    cube[0].append(['R','R','R']); cube[1].append(['Y','Y','Y']); cube[2].append(['W','W','W'])
    cube[3].append(['G','G','G']); cube[4].append(['B','B','B']); cube[5].append(['O','O','O'])
# Get input to initialize random cube
num = int(input("Select number of turns to initialize cube: "))
# initialize random cube
initRandCube(cube, int(num))
print("Cube initial State: ")
printCube(cube)