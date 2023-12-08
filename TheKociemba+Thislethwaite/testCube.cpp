#include <iostream>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

const int R_NUM_PIECES = 20;

char R_cube[R_NUM_PIECES][4];

void R_setCubeState_R(const vector<string>& state) {
    for (int i = 0; i < R_NUM_PIECES; ++i) {
        strcpy(R_cube[i], state[i].c_str());
    }
}
int UF = 0;
int FU=0;
int UR = 1;
int UB = 2;
int UL = 3;
int DF = 4;
int DR = 5;
int DB = 6;
int DL = 7;
int FR = 8;
int FL = 9;
int BR = 10;int RB=10;
int BL = 11;int LB=11;
int UFR = 12;
int URB = 13;
int UBL = 14;
int ULF = 15;int UFL=15;
int DRF = 16;int DFR=16;
int DFL = 17;int DLF=17;
int DLB = 18;int DBL=18;
int DBR = 19;int DRB=19;


void R_rotateU_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[UF]);
    strcpy(R_cube[UF], R_cube[UR]);
    strcpy(R_cube[UR], R_cube[UB]);
    strcpy(R_cube[UB], R_cube[UL]);
    strcpy(R_cube[UL], R_temp);

    strcpy(R_temp, R_cube[UFR]);
    strcpy(R_cube[UFR], R_cube[URB]);
    strcpy(R_cube[URB], R_cube[UBL]);
    strcpy(R_cube[UBL], R_cube[UFL]);
    strcpy(R_cube[UFL], R_temp);
}

void R_rotateF_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[FL]);
    strcpy(R_cube[FL], R_cube[DF]);
    strcpy(R_cube[DF], R_cube[FR]);
    strcpy(R_cube[FR], R_cube[UF]);
    strcpy(R_cube[UF], R_temp);

    strcpy(R_temp, R_cube[UFL]);
    strcpy(R_cube[UFL], R_cube[DFL]);
    strcpy(R_cube[DFL], R_cube[DFR]);
    strcpy(R_cube[DFR], R_cube[UFR]);
    strcpy(R_cube[UFR], R_temp);
}

void R_rotateL_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[UL]);
    strcpy(R_cube[UL], R_cube[BL]);
    strcpy(R_cube[BL], R_cube[DL]);
    strcpy(R_cube[DL], R_cube[FL]);
    strcpy(R_cube[FL], R_temp);

    strcpy(R_temp, R_cube[UFL]);
    strcpy(R_cube[UFL], R_cube[UBL]);
    strcpy(R_cube[UBL], R_cube[DBL]);
    strcpy(R_cube[DBL], R_cube[DFL]);
    strcpy(R_cube[DFL], R_temp);
}

void R_rotateR_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[UR]);
    strcpy(R_cube[UR], R_cube[FR]);
    strcpy(R_cube[FR], R_cube[DR]);
    strcpy(R_cube[DR], R_cube[BR]);
    strcpy(R_cube[BR], R_temp);

    strcpy(R_temp, R_cube[URB]);
    strcpy(R_cube[URB], R_cube[UFR]);
    strcpy(R_cube[UFR], R_cube[DRF]);
    strcpy(R_cube[DRF], R_cube[DBR]);
    strcpy(R_cube[DBR], R_temp);
}

void R_rotateD_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[DF]);
    strcpy(R_cube[DF], R_cube[DL]);
    strcpy(R_cube[DL], R_cube[DB]);
    strcpy(R_cube[DB], R_cube[DR]);
    strcpy(R_cube[DR], R_temp);

    strcpy(R_temp, R_cube[DFR]);
    strcpy(R_cube[DFR], R_cube[DLF]);
    strcpy(R_cube[DLF], R_cube[DBL]);
    strcpy(R_cube[DBL], R_cube[DRB]);
    strcpy(R_cube[DRB], R_temp);
}

void R_rotateB_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[UB]);
    strcpy(R_cube[UB], R_cube[RB]);
    strcpy(R_cube[RB], R_cube[DB]);
    strcpy(R_cube[DB], R_cube[LB]);
    strcpy(R_cube[LB], R_temp);

    strcpy(R_temp, R_cube[URB]);
    strcpy(R_cube[URB], R_cube[DBR]);
    strcpy(R_cube[DBR], R_cube[DLB]);
    strcpy(R_cube[DLB], R_cube[UBL]);
    strcpy(R_cube[UBL], R_temp);
}




void R_performMoves_R(const char* R_moves) {
    int i = 0;
    while (R_moves[i] != '\0') {
        char move = R_moves[i];
        int times = 1;

        if (R_moves[i + 1] >= '1' && R_moves[i + 1] <= '3') {
            times = R_moves[i + 1] - '0';
            i += 2; 
        } else {
            i++; 
        }

        for (int j = 0; j < times; ++j) {
            switch (move) {
                case 'U': R_rotateU_R(); break;
                case 'D': R_rotateD_R(); break;
                case 'L': R_rotateL_R(); break;
                case 'R': R_rotateR_R(); break;
                case 'F': R_rotateF_R(); break;
                case 'B': R_rotateB_R(); break;
            }
        }
    }
}



void R_printCube_R() {
    for (int i = 0; i < R_NUM_PIECES; ++i) {
        std::cout << R_cube[i] << " ";
    }
    std::cout << std::endl;
}

bool areBlocksEqual(const char* block1, const char* block2) {
    size_t len1 = strlen(block1);
    size_t len2 = strlen(block2);

    if (len1 != len2) return false;


    if (len1 == 2) {
        return (block1[0] == block2[0] && block1[1] == block2[1]) ||
               (block1[0] == block2[1] && block1[1] == block2[0]);
    }


    if (len1 == 3) {
        return (block1[0] == block2[0] && block1[1] == block2[1] && block1[2] == block2[2]) ||
               (block1[0] == block2[1] && block1[1] == block2[2] && block1[2] == block2[0]) ||
               (block1[0] == block2[2] && block1[1] == block2[0] && block1[2] == block2[1]);
    }

    return false;
}


int main() {
    string input, moves;
    vector<string> initialState;

    cout << "Enter initial cube state: ";
    getline(cin, input);
    istringstream iss(input);
    string token;
    while (iss >> token) {
        initialState.push_back(token);
    }

    R_setCubeState_R(initialState);

    cout << "Enter solution moves: ";
    getline(cin, moves);


    R_performMoves_R(moves.c_str());

    cout << "The state of the cube after the moves is(General representation,Direction is not useful here): " << endl;
    R_printCube_R();

    const char* R_solvedState[R_NUM_PIECES] = {
        "UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "FL", "BR", "BL",
        "UFR", "URB", "UBL", "ULF", "DRF", "DFL", "DLB", "DBR"
    };




bool isSolved = true;
for (int i = 0; i < R_NUM_PIECES; ++i) {
    if (!areBlocksEqual(R_cube[i], R_solvedState[i])) {
        isSolved = false;
        break;
    }
}

if (isSolved) {
    cout << "This answer is correct!" << endl;
} else {
    cout << "The answer is incorrect." << endl;
}



    return 0;
}
