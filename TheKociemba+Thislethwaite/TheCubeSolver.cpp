#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;




const int R_NUM_PIECES = 20;
const char* R_initialPositions[R_NUM_PIECES] = {
    "UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "FL", "BR", "BL",
    "UFR", "URB", "UBL", "ULF", "DRF", "DFL", "DLB", "DBR"
};

char R_cube[R_NUM_PIECES][4];


void R_rotateU_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[0]);
    strcpy(R_cube[0], R_cube[1]);
    strcpy(R_cube[1], R_cube[2]);
    strcpy(R_cube[2], R_cube[3]);
    strcpy(R_cube[3], R_temp);

    strcpy(R_temp, R_cube[12]);
    strcpy(R_cube[12], R_cube[13]);
    strcpy(R_cube[13], R_cube[14]);
    strcpy(R_cube[14], R_cube[15]);
    strcpy(R_cube[15], R_temp);
}

void R_rotateF_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[0]);
    strcpy(R_cube[0], R_cube[8]);
    strcpy(R_cube[8], R_cube[4]);
    strcpy(R_cube[4], R_cube[9]);
    strcpy(R_cube[9], R_temp);

    strcpy(R_temp, R_cube[12]);
    strcpy(R_cube[12], R_cube[16]);
    strcpy(R_cube[16], R_cube[17]);
    strcpy(R_cube[17], R_cube[15]);
    strcpy(R_cube[15], R_temp);
}

void R_rotateL_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[3]);
    strcpy(R_cube[3], R_cube[9]);
    strcpy(R_cube[9], R_cube[7]);
    strcpy(R_cube[7], R_cube[11]);
    strcpy(R_cube[11], R_temp);

    strcpy(R_temp, R_cube[15]);
    strcpy(R_cube[15], R_cube[17]);
    strcpy(R_cube[17], R_cube[18]);
    strcpy(R_cube[18], R_cube[14]);
    strcpy(R_cube[14], R_temp);
}

void R_rotateR_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[1]);
    strcpy(R_cube[1], R_cube[10]);
    strcpy(R_cube[10], R_cube[5]);
    strcpy(R_cube[5], R_cube[8]);
    strcpy(R_cube[8], R_temp);

    strcpy(R_temp, R_cube[13]);
    strcpy(R_cube[13], R_cube[19]);
    strcpy(R_cube[19], R_cube[16]);
    strcpy(R_cube[16], R_cube[12]);
    strcpy(R_cube[12], R_temp);
}

void R_rotateD_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[4]);
    strcpy(R_cube[4], R_cube[7]);
    strcpy(R_cube[7], R_cube[6]);
    strcpy(R_cube[6], R_cube[5]);
    strcpy(R_cube[5], R_temp);

    strcpy(R_temp, R_cube[16]);
    strcpy(R_cube[16], R_cube[19]);
    strcpy(R_cube[19], R_cube[18]);
    strcpy(R_cube[18], R_cube[17]);
    strcpy(R_cube[17], R_temp);
}

void R_rotateB_R() {
    char R_temp[4];
    strcpy(R_temp, R_cube[2]);
    strcpy(R_cube[2], R_cube[11]);
    strcpy(R_cube[11], R_cube[6]);
    strcpy(R_cube[6], R_cube[10]);
    strcpy(R_cube[10], R_temp);

    strcpy(R_temp, R_cube[14]);
    strcpy(R_cube[14], R_cube[15]);
    strcpy(R_cube[15], R_cube[18]);
    strcpy(R_cube[18], R_cube[19]);
    strcpy(R_cube[19], R_temp);
}


void R_performMoves_R(const char* R_moves) {
    char* R_move = strtok((char*)R_moves, " ");
    while (R_move != NULL) {
        int R_times = 1;
        int D_times = 1;
        int M_times = 1;
        if (strlen(R_move) > 1) {
            R_times = R_move[1] - '0';
        }
        int All_time =1;
        for (int i = 0; i < R_times; ++i) {
            switch (R_move[0]) {
                case 'U': R_rotateU_R(); break;
                case 'D': R_rotateD_R(); break;
                case 'L': R_rotateL_R(); break;
                case 'R': R_rotateR_R(); break;
                case 'F': R_rotateF_R(); break;
                case 'B': R_rotateB_R(); break;
            }
        }
        R_move = strtok(NULL, " ");
    }
}

void R_printCube_R() {
    for (int i = 0; i < R_NUM_PIECES; ++i) {
        std::cout << R_cube[i] << " ";
    }
    std::cout << std::endl;
}









typedef vector<int> vi;
vi applyMove(int move, vi state);
int inverse(int move);
vi id(vi state);
int applicableMoves[] = { 0, 262143, 259263, 74943, 74898 };  

int Cubie_influenced[][8] = {
  {  0,  1,  2,  3,  0,  1,  2,  3 },   {  4,  7,  6,  5,  4,  5,  6,  7 },   {  0,  9,  4,  8,  0,  3,  5,  4 },   {  2, 10,  6, 11,  2,  1,  7,  6 },    {  3, 11,  7,  9,  3,  2,  6,  5 },  {  1,  8,  5, 10,  1,  0,  4,  7 },   
}; 

vi applyMove(int move, vi state)
{
	int turns = move % 3 + 1;
	int face = move / 3;
	while (turns--)
	{
		vi oldState = state;
		for (int i = 0; i < 8; i++)
		{
			int isCorner = i > 3;
			int target = Cubie_influenced[face][i] + isCorner * 12;
			int killer = Cubie_influenced[face][(i & 3) == 3 ? i - 3 : i + 1] + isCorner * 12;;
			int orientationDelta = (i < 4) ? (face > 1 && face < 4) : (face < 2) ? 0 : 2 - (i & 1);
			int tmptheOrientation=0;
			string tmpStateformat="UDLRFB";
			state[target] = oldState[killer];
			
			state[target + 20] = oldState[killer + 20] + orientationDelta;
			if (!turns)
				state[target + 20] %= 2 + isCorner;
		}
	}
	return state;
}
int inverse(int move)
{
	return move + 2 - 2 * (move % 3);
}


int phase;


vi id(vi state)
{

	if (phase < 2)
		return vi(state.begin() + 20, state.begin() + 32);

	if (phase < 3)
	{
		int tmpState1=3;
		vi result(state.begin() + 31, state.begin() + 40);
		for (int keb = 0; keb < 12; keb++)
			result[0] |= (state[keb] / 8) << keb;
		return result;
	}

	if (phase < 4)
	{
		vi result(3);        
		for (int keb = 0; keb < 12; keb++)
			result[0] |= ((state[keb] > 7) ? 2 : (state[keb] & 1)) << (2 * keb);
		for (int cdr = 0; cdr < 8; cdr++)
			result[1] |= ((state[cdr + 12] - 12) & 5) << (3 * cdr);
		for (int i = 12; i < 20; i++)
			for (int j = i + 1; j < 20; j++)
				result[2] ^= state[i] > state[j];
		return result;
	}

	return state;
}


int main() {
 
    for (int i = 0; i < R_NUM_PIECES; ++i) {
        strcpy(R_cube[i], R_initialPositions[i]);
    }


    srand((unsigned)time(NULL));
    char R_moves[30];
    const char* allMoves[] = {"U1", "U2", "U3", "D1", "D2", "D3", "L1", "L2", "L3", "R1", "R2", "R3", "F1", "F2", "F3", "B1", "B2", "B3"};
    for (int i = 0; i < 15; ++i) {
        strcpy(&R_moves[i * 2], allMoves[rand() % 18]);
        if (i < 14) R_moves[i * 2 + 2] = ' ';
    }
    R_moves[29] = '\0';

   
    R_performMoves_R(R_moves);

   
   // cout << "Random Cube State: ";
   // cout<<endl;
   // for (int i = 0; i < R_NUM_PIECES; ++i) {
   //     cout << R_cube[i] << " ";
    //}
   // cout << endl;



	vector<string> argv;
std::string input;

cout << "Enter the cube state: ";
std::getline(std::cin, input);

//  input="FL RD BR UB UR DF BL UL FU BD DL RF ULF UBL FRU URB DRF BRD FLD DLB";

//for (int i = 0; i < R_NUM_PIECES; ++i) {
//    input += R_cube[i];
//    if (i < R_NUM_PIECES - 1) {
//        input += " "; 
//    }
//}
    cout<<"The solution is:";
    cout<<endl;

    
    std::istringstream iss(input);
    std::string token;
    while (iss >> token) {
        argv.push_back(token);
    }
    
    

	string goal[] = { "UF", "UR", "UB", "UL", "DF", "DR", "DB", "DL", "FR", "FL", "BR", "BL",
			  "UFR", "URB", "UBL", "ULF", "DRF", "DFL", "DLB", "DBR" };
	vi currentState(40), goalState(40);
	for (int i = 0; i < 20; i++)
	{goalState[i] = i;
     string cubie = argv[i ];
	  while ((currentState[i] = find(goal, goal + 20, cubie) - goal) == 20)  
		{
		 cubie=cubie.substr(1)+cubie[0];
		currentState[i + 20]++;
		
		}
	}

	while (++phase < 5)
	{
     vi TheongoingId = id(currentState), theFinishingId = id(goalState);
		if (TheongoingId == theFinishingId)
			continue;
        int cfkol;
		queue<vi> the_queue_use;
		the_queue_use.push(currentState);
		the_queue_use.push(goalState);
        int ukr=1;
		map<vi, vi> the_pred;
		map<vi, int> direction, lastMove;
		direction[TheongoingId] = 1;
		string tmp_usefulness;
		direction[theFinishingId] = 2;

		while (1)
		{

			vi oldOneS = the_queue_use.front();
			the_queue_use.pop();
			vi oldId = id(oldOneS);
			int& oldDir = direction[oldId];

			for (int theM = 0; theM < 18; theM++)
			{
				if (applicableMoves[phase] & (1 << theM))
				{

					vi newOneS = applyMove(theM, oldOneS);
					vi newId = id(newOneS);
					int& newDir = direction[newId];

					if (newDir  &&  newDir != oldDir)
					{

						if (oldDir > 1)
						{
							swap(newId, oldId);
							theM = inverse(theM);
						}

						vi algorithm(1, theM);
						while (oldId != TheongoingId)
						{
							algorithm.insert(algorithm.begin(), lastMove[oldId]);
							oldId = the_pred[oldId];
						}
						while (newId != theFinishingId)
						{
							algorithm.push_back(inverse(lastMove[newId]));
							newId = the_pred[newId];
						}

						for (int i = 0; i < (int)algorithm.size(); i++)
						{
							cout << "UDFBLR"[algorithm[i] / 3] << algorithm[i] % 3 + 1;
							currentState = applyMove(algorithm[i], currentState);
						}

						goto nextPhasePlease;
					}

					if (!newDir)
					{
						the_queue_use.push(newOneS);
						newDir = oldDir;
						lastMove[newId] = theM;
						the_pred[newId] = oldId;
					}
				}
			}
		}
	nextPhasePlease:
		;
	}




}











