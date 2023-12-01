# AI-Final-Project

Project Title: Finding Solution to Rubik’s Cube Problem Using AI techniques

Team member: Junwon Lee junwon.lee@vanderbilt.edu
Yuesheng Hao yuesheng.hao@vanderbilt.edu

Description: Use the AI techniques to solve the Rubik’s Cube problem. To restore a
Rubik’s Cube as soon as possible.

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

Evaluation Plan: Number of moves, with fewer the better. It is known that no initial
state requires more than 26 moves in the quarter turn metric (God’s number), so our
goal is to search a path with moves less than 26.

References
Korf, Richard E.. “Finding Optimal Solutions to Rubik's Cube Using Pattern Databases.”
AAAI/IAAI (1997).
Agostinelli, F., McAleer, S., Shmakov, A. et al. Solving the Rubik’s cube with deep
reinforcement learning and search. Nat Mach Intell 1, 356–363 (2019).
Herbert Kociemba. “The Two-Phase-Algorithm” The Two-Phase-Algorithm
(kociemba.org
