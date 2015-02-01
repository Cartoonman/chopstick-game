#include <iostream> 
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Global initialized vars
string gameStart;
bool gameStartBOOL = false;
bool GAME = true;
bool inval = false;
int TURN = 1;
int hitCalc;
int cINT;
int SplitCHOICE;
string CHOICE;


static unsigned int PLAYER1_LEFTHAND = 1, PLAYER1_RIGHTHAND = 1, PLAYER2_LEFTHAND = 1, PLAYER2_RIGHTHAND = 1;

/* 
q <---------> e
Your hands: 
a <---------> d
CONTROLS
*/



int main() {

	cout << "Welcome to a game of Chopsticks!" << endl;
	while(gameStartBOOL == false){  // Start menu for starting or quitting the game
		cout << "If you are ready to start, type Start. To quit, type Quit." << endl;
		cout << "Selection: ";
		cin >> gameStart;
		if (gameStart == "Quit" || gameStart == "quit")
			return 0;
		else if (gameStart == "Start" || gameStart == "start")
			gameStartBOOL = true;
		}

		
	cout << "Starting the game . . ." << endl;
	
	while (GAME == true){ // When GAME == false, game over occured
		if(TURN == 1){  //Player 1
			cout << "\n\n___PLAYER 1___\n\n" << endl;
			cout << "Player 2's hands: \n " << PLAYER2_RIGHTHAND << " <---------> " << PLAYER2_LEFTHAND << endl;
			cout << "Your hands: \n " << PLAYER1_LEFTHAND << " <---------> " << PLAYER1_RIGHTHAND << endl;
			
			/* 
			Player 2's hands: 
			1 <---------> 1
			Your hands: 
			1 <---------> 1
			*/
			
			
			if (inval == true)  // used for input error handling 
				cout << "Input invalid, please try again" << endl;
			else
				cout << "Make your move: ";
				
				
			cin >> CHOICE; // Input based on controls
			
			if (CHOICE == "dq")      // This whole section is dealing with the fact that C++ doesn't do string switch statements.
				cINT = 1;
			else if (CHOICE == "de")
				cINT = 2;
			else if (CHOICE == "ae")
				cINT = 3;
			else if (CHOICE == "aq")
				cINT = 4;
			else if (CHOICE == "ad")
				cINT = 5;
			else if (CHOICE == "da")
				cINT = 6;
			else
				cINT = 0;
				
			switch(cINT) {  //V6 Game Engine 
				//Hits
				case 1:
					if (PLAYER1_RIGHTHAND < 1 || PLAYER2_RIGHTHAND < 1){ //Checking validity of move. hands with 0 aren't valid
						inval = true;
						continue;
						}
					else if (PLAYER1_RIGHTHAND + PLAYER2_RIGHTHAND <= 4) //If hit is valid but doesn't result in a kill
						PLAYER2_RIGHTHAND = PLAYER1_RIGHTHAND + PLAYER2_RIGHTHAND;
					else                                                 // Hit resulted in a kill
						PLAYER2_RIGHTHAND = 0;					
					break;
				case 2:
					if (PLAYER1_RIGHTHAND < 1 || PLAYER2_LEFTHAND < 1){ //Checking validity of move. hands with 0 aren't valid
						inval = true;
						continue;
						}
					else if (PLAYER1_RIGHTHAND + PLAYER2_LEFTHAND <= 4) //If hit is valid but doesn't result in a kill
						PLAYER2_LEFTHAND = PLAYER1_RIGHTHAND + PLAYER2_LEFTHAND;
					else                                                 // Hit resulted in a kill
						PLAYER2_LEFTHAND = 0;		
					break;
				case 3:
					if (PLAYER1_LEFTHAND < 1 || PLAYER2_LEFTHAND < 1){ //Checking validity of move. hands with 0 aren't valid
						inval = true;
						continue;
						}
					else if (PLAYER1_LEFTHAND + PLAYER2_LEFTHAND <= 4) //If hit is valid but doesn't result in a kill
						PLAYER2_LEFTHAND = PLAYER1_LEFTHAND + PLAYER2_LEFTHAND;
					else                                                 // Hit resulted in a kill
						PLAYER2_LEFTHAND = 0;		
					break;
				case 4:
					if (PLAYER1_LEFTHAND < 1 || PLAYER2_RIGHTHAND < 1){ //Checking validity of move. hands with 0 aren't valid
						inval = true;
						continue;
						}
					else if (PLAYER1_LEFTHAND + PLAYER2_RIGHTHAND <= 4) //If hit is valid but doesn't result in a kill
						PLAYER2_RIGHTHAND = PLAYER1_LEFTHAND + PLAYER2_RIGHTHAND;
					else                                                 // Hit resulted in a kill
						PLAYER2_RIGHTHAND = 0;		
					break;
				
				//Splits
				case 5:
					if (PLAYER1_LEFTHAND < 1){ // Checks to see if the hand you wanted to split had a valid number
						inval = true;
						continue;
						}
					cout << "\nYou chose to split your Left Hand with your Right Hand.\nPlease enter the ammount you wish to split." << endl;
					while (1){
						cout << "Split: ";
						cin >> SplitCHOICE;
						if (SplitCHOICE > PLAYER1_LEFTHAND){  // Checks to see if your split choice was valid based on what you currently have in your hand
							cout << "Error: Your split was invalid. Please try again" << endl;
							continue;
							}
						else if (PLAYER1_RIGHTHAND + SplitCHOICE > 4 || SplitCHOICE < 1){ // Checks to see if your split choice would make the other hand go over 4 or is 0.
							cout << "Error: Your split was invalid. Please try again" << endl;
							continue;
							}
						else{
							PLAYER1_RIGHTHAND = PLAYER1_RIGHTHAND + SplitCHOICE;
							PLAYER1_LEFTHAND = PLAYER1_LEFTHAND - SplitCHOICE;
							break;
							}
						}
					break;
				case 6:
					if (PLAYER1_RIGHTHAND < 1){ // Checks to see if the hand you wanted to split had a valid number
						inval = true;
						continue;
						}
					cout << "\nYou chose to split your Right Hand with your Left Hand.\nPlease enter the ammount you wish to split." << endl;
					while (1){
						cout << "Split: ";
						cin >> SplitCHOICE;
						if (SplitCHOICE > PLAYER1_RIGHTHAND){  // Checks to see if your split choice was valid based on what you currently have in your hand
							cout << "Error: Your split was invalid. Please try again" << endl;
							continue;
							}
						else if (PLAYER1_LEFTHAND + SplitCHOICE > 4 || SplitCHOICE < 1){ // Checks to see if your split choice would make the other hand go over 4 or is 0.
							cout << "Error: Your split was invalid. Please try again" << endl;
							continue;
							}
						else{
							PLAYER1_LEFTHAND = PLAYER1_LEFTHAND + SplitCHOICE;
							PLAYER1_RIGHTHAND = PLAYER1_RIGHTHAND - SplitCHOICE;
							break;
							}
						}
					break;
				
				//Error Handling
				default:
					inval = true;
					continue;	
				}
					
			inval = false; //Resetting all necessary values for next turn
				
				
			TURN = -1*TURN; //Using negation to act as flip flop player toggle
		
		
			}
			
			
		if(TURN == -1){  //Player 2
			cout << "\n\n___PLAYER 2___\n\n" << endl;
			cout << "Player 1's hands: \n " << PLAYER1_RIGHTHAND << " <---------> " << PLAYER1_LEFTHAND << endl;
			cout << "Your hands: \n " << PLAYER2_LEFTHAND << " <---------> " << PLAYER2_RIGHTHAND << endl;
			
			
			
			if (inval == true)  // used for input error handling 
				cout << "Input invalid, please try again" << endl;
			else
				cout << "Make your move: ";
				
				
			cin >> CHOICE; // Input based on controls
			
			if (CHOICE == "dq")      // This whole section is dealing with the fact that C++ doesn't do string switch statements.
				cINT = 1;
			else if (CHOICE == "de")
				cINT = 2;
			else if (CHOICE == "ae")
				cINT = 3;
			else if (CHOICE == "aq")
				cINT = 4;
			else if (CHOICE == "ad")
				cINT = 5;
			else if (CHOICE == "da")
				cINT = 6;
			else
				cINT = 0;
				
			switch(cINT) {  //V6 Game Engine 
				//Hits
				case 1:
					if (PLAYER2_RIGHTHAND < 1 || PLAYER1_RIGHTHAND < 1){ //Checking validity of move. hands with 0 aren't valid
						inval = true;
						continue;
						}
					else if (PLAYER2_RIGHTHAND + PLAYER1_RIGHTHAND <= 4) //If hit is valid but doesn't result in a kill
						PLAYER1_RIGHTHAND = PLAYER2_RIGHTHAND + PLAYER1_RIGHTHAND;
					else                                                 // Hit resulted in a kill
						PLAYER1_RIGHTHAND = 0;					
					break;
				case 2:
					if (PLAYER2_RIGHTHAND < 1 || PLAYER1_LEFTHAND < 1){ //Checking validity of move. hands with 0 aren't valid
						inval = true;
						continue;
						}
					else if (PLAYER2_RIGHTHAND + PLAYER1_LEFTHAND <= 4) //If hit is valid but doesn't result in a kill
						PLAYER1_LEFTHAND = PLAYER2_RIGHTHAND + PLAYER1_LEFTHAND;
					else                                                 // Hit resulted in a kill
						PLAYER1_LEFTHAND = 0;		
					break;
				case 3:
					if (PLAYER2_LEFTHAND < 1 || PLAYER1_LEFTHAND < 1){ //Checking validity of move. hands with 0 aren't valid
						inval = true;
						continue;
						}
					else if (PLAYER2_LEFTHAND + PLAYER1_LEFTHAND <= 4) //If hit is valid but doesn't result in a kill
						PLAYER1_LEFTHAND = PLAYER2_LEFTHAND + PLAYER1_LEFTHAND;
					else                                                 // Hit resulted in a kill
						PLAYER1_LEFTHAND = 0;		
					break;
				case 4:
					if (PLAYER2_LEFTHAND < 1 || PLAYER1_RIGHTHAND < 1){ //Checking validity of move. hands with 0 aren't valid
						inval = true;
						continue;
						}
					else if (PLAYER2_LEFTHAND + PLAYER1_RIGHTHAND <= 4) //If hit is valid but doesn't result in a kill
						PLAYER1_RIGHTHAND = PLAYER2_LEFTHAND + PLAYER1_RIGHTHAND;
					else                                                 // Hit resulted in a kill
						PLAYER1_RIGHTHAND = 0;		
					break;
				
				//Splits
				case 5:
					if (PLAYER2_LEFTHAND < 1){ // Checks to see if the hand you wanted to split had a valid number
						inval = true;
						continue;
						}
					cout << "\nYou chose to split your Left Hand with your Right Hand.\nPlease enter the ammount you wish to split." << endl;
					while (1){
						cout << "Split: ";
						cin >> SplitCHOICE;
						if (SplitCHOICE > PLAYER2_LEFTHAND){  // Checks to see if your split choice was valid based on what you currently have in your hand
							cout << "Error: Your split was invalid. Please try again" << endl;
							continue;
							}
						else if (PLAYER2_RIGHTHAND + SplitCHOICE > 4 || SplitCHOICE < 1){ // Checks to see if your split choice would make the other hand go over 4 or is 0.
							cout << "Error: Your split was invalid. Please try again" << endl;
							continue;
							}
						else{
							PLAYER2_RIGHTHAND = PLAYER2_RIGHTHAND + SplitCHOICE;  //Split happens
							PLAYER2_LEFTHAND = PLAYER2_LEFTHAND - SplitCHOICE;
							break;
							}
						}
					break;
				case 6:
					if (PLAYER2_RIGHTHAND < 1){ // Checks to see if the hand you wanted to split had a valid number
						inval = true;
						continue;
						}
					cout << "\nYou chose to split your Right Hand with your Left Hand.\nPlease enter the ammount you wish to split." << endl;
					while (1){
						cout << "Split: ";
						cin >> SplitCHOICE;
						if (SplitCHOICE > PLAYER2_RIGHTHAND){  // Checks to see if your split choice was valid based on what you currently have in your hand
							cout << "Error: Your split was invalid. Please try again" << endl;
							continue;
							}
						else if (PLAYER2_LEFTHAND + SplitCHOICE > 4 || SplitCHOICE < 1){ // Checks to see if your split choice would make the other hand go over 4 or is 0.
							cout << "Error: Your split was invalid. Please try again" << endl;
							continue;
							}
						else{
							PLAYER2_LEFTHAND = PLAYER2_LEFTHAND + SplitCHOICE;   //Split happens
							PLAYER2_RIGHTHAND = PLAYER2_RIGHTHAND - SplitCHOICE;
							break;
							}
						}
					break;
				
				//Error Handling
				default:
					inval = true;
					continue;
				}
					
			inval = false; //Resetting all necessary values for next turn
			TURN = -1*TURN; //Using negation to act as flip flop player toggle	
			}
		
		
		

		
		}
	

	
	return 0;
	}


