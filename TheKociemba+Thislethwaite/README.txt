This is a Cube Solver Program.
Give the program a given state of Rubik cube, it will return a solution step to solve it.

Environment: Developed by Dev-C++ 5.11. All follow C++ 98 standard. So may not support                
             c++11
             So please use Dev-C++ 5.11 to test it. 

Downloading Dev-C++ 5.11 site:                https://sourceforge.net/projects/orwelldevcpp/files/Setup%20Releases/Dev-Cpp%205.11%20TDM-GCC%204.9.2%20Setup.exe/download

Or you can google "Dev-C++ 5.11 downloading".  


Testing Procedure:

1. Copy any testing input from "Inputs_for_testing.txt"  (Please dont copy the space before first character or after the last character since it may be space sensitive). These comprehensive testing input has all been proven to be legal states of Cube. It is ordered by difficulty, so the larger the row number is, the more complex that the cube is.  You could also enter any state of cube that is proven to be legal. The input file is just for testing convenience. 

2. Open "TheCubeSolver.cpp".   
   Compile and run the program.

3. It will ask you to give it a state, paste the testing input to it

4. It will return the solution of the cube.

5. Copy both the testing input and solution steps.

6. Open  "testCube.cpp" Open the test for the Cube. 
   Compile and run the program

7. It will ask you the initial state of cube and solution steps.  Paste the input into it(pls no paste any space before first or after last character), enter and then paste the solution steps into it and enter. 

8.It will eventually output whether it is solved. If it says"This answer is correct!", then the answer is tested to be correct. And finish!



For example: 
1.Choose LB DB RU DF LU BU RF RB UF RD DL LF DLB LFU FLD RDB FDR BLU BUR UFR

2.In the TheCubeSolver.cpp:

Enter the cube state: LB DB RU DF LU BU RF RB UF RD DL LF DLB LFU FLD RDB FDR BLU BUR UFR
->
The solution is:
L2U2R1B3F3U1L1D3F2U2R3U2L3L2U2L2D2L2F2U3F2U2L2U2B2U2R2D2R2B2

3.In the testCube.cpp

Enter initial cube state: LB DB RU DF LU BU RF RB UF RD DL LF DLB LFU FLD RDB FDR BLU BUR UFR
Enter solution moves: L2U2R1B3F3U1L1D3F2U2R3U2L3L2U2L2D2L2F2U3F2U2L2U2B2U2R2D2R2B2
->
The state of the cube after the moves is(General representation,Direction is not useful here):
UF RU BU LU DF RD DB DL RF LF RB LB UFR BUR BLU LFU FDR FLD DLB RDB
This answer is correct!











