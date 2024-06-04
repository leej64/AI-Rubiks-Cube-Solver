# AI-Final-Project

Project Title: Finding Solution to Rubik’s Cube Problem Using AI techniques

Team member: Junwon Lee junwon.lee@vanderbilt.edu
Yuesheng Hao yuesheng.hao@vanderbilt.edu

Description: Use of AI techniques to solve the Rubik’s Cube problem, to restore Rubik’s Cube as soon as possible.<br>

Background/Motivation: Rubik’s Cube is a 3 X 3 X 3 cube with different colors on the
exposed surface of subcubes. Any plane of the cube can be rotated 90 degrees per
move in both clockwise and counterclockwise direction, and in the goal state, all of the
square surfaces on each side of the cube will have the same color. We are going to use
an AI technique to solve Rubik’s Cube problem starting from a random initial state.

AI techniques: Heuristic Search. (Korf’s algorithm: iterative-deepening-A* search)
Simulated annealing algorithm.
Kociemba algorithm (2-phase algorithm)
Deep Reinforcement Learning,artificial neural network, approximate value
iteration (DeepCubeA)

Evaluation Plan: For DeepCube neural network, it focuses on Number of moves, with fewer the better. It is known that no initial
state requires more than 26 moves in the quarter turn metric (God’s number), so our
goal is to search a path with moves less than 26.  For Kociemba and Thislethwaite, it focuses on correctness. 

File Description

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

For Heuristic and DeepCube neural network

Heuristic/Cube.py: Enviornment for heuristic search. Discarded and NOT used in final work!

Heuristic/HeuristicDB.py: Implementation of BFS for database. Discarded and NOT used in final work!

Database for optimal solutions and code for pytorch DNN was obtained and modified from https://github.com/forestagostinelli/DeepCubeA

DeepCube/ctg/avi.py: Implementation of approximate value iteration for database.

data/cube3/data_0.pkl: Database of optimal search result to compare with deep learning method. Used pickle library to export hashtable of state & cost data.

environments/enviornment_abstract.py: Abstract class used for multiple enviornments, only used for 3X3X3 cube problem for now.

cube3.py: Enviornment for 3X3X3 cube problem.

results/cube3: Solution result after performing A* search with deep learning database.

saved_models/cube3: Database obtained by AVI & DNN.

script/compare_solutions.py: Script to compare optimal search result and result from deep learning method.

search/astar.py: Implementation of A* search using database obtained by deep learning.

updater/updater.py: Helper class to update target cost function on each step of DNN.

utils: Helper classes for data, enviornment, neural network, and search model.

cudatest.py: For debugging perpose with pytorch execution.

train.sh: Contains terminal instructions to train, search, and compare with optimal solution. You can both use sh file or instructions inside the file on terminal.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
For Kociemba + ThislethWaite Algorithm

README.txt: explaination of how to test the program

Inputs_for_testing.txt: legal states of cube that could be used to test the program

TheCubeSolver.cpp: Solver of the Cube. Give it a state, it return a solution steps

testCube.cpp: test whether a solution step could solve a Cube in given state. (used to test the result from TheCubeSolver.cpp)


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


References

Korf, Richard E.. “Finding Optimal Solutions to Rubik's Cube Using Pattern Databases.”
AAAI/IAAI (1997).

Agostinelli, F., McAleer, S., Shmakov, A. et al. Solving the Rubik’s cube with deep
reinforcement learning and search. Nat Mach Intell 1, 356–363 (2019).

Herbert Kociemba. “The Two-Phase-Algorithm” The Two-Phase-Algorithm
(kociemba.org)

Korf, Richard E.. “Finding Optimal Solutions to Rubik's Cube Using Pattern Databases.” AAAI/IAAI (1997).
