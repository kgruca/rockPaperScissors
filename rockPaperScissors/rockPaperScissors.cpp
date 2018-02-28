//This program is a rock, paper, scissors simulator
//author: Krzysztof Gruca

#include <iostream>
#include <cstdlib>
#include <ctime>

//function prototypes
int compChoice();
int userChoice();
void displayCompChoice(int);
int winner(int, int);
bool playAgain();
int repeat();

//global constants
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 4;

//int main
int main() {

	int compMove, userMove, gameOutcome;
	bool newGame;

	do
	{
		compMove = compChoice();

		userMove = userChoice();

		/*If user chose option 4 from the menu, they want to quit. This if/else statement will
		terminate the program with a message*/
		if (userMove == 4) {
			std::cout << "Sorry to see you go so soon!" << std::endl << std::endl;
		}
		else {

			displayCompChoice(compMove);

			gameOutcome = winner(compMove, userMove);

			//if user and computer choose the same option, there must be a tie-breaker
			while (gameOutcome == 2) {

				gameOutcome = repeat();
			}
			newGame = playAgain();
		}	
	} while (newGame);
	
	//thank user for playing game
	std::cout << "Thank you for playing!" << std::endl << std::endl;

	system("pause");
	return 0;
}

//generates the computer's move 
int compChoice() {

	//generate random numbers each time program is run
	unsigned seed = time(0);
	srand(seed);

	int y = 1 + rand() % 3;
	return y;
}

//provides a menu to the user, takes the user's choice, and return the choice to int main
int userChoice() {

	int n;

	//Display menu and get user's choice
	std::cout << "Hello and welcome to a game of Rock, Paper, Scissors!" << std::endl;
	std::cout << "Please make a selection of 1, 2, 3 or 4, based on the following menu: " << std::endl << std::endl;
	std::cout << "\t\t\t***********************" << std::endl;
	std::cout << "\t\t\t*ROCK, PAPER, SCISSORS*" << std::endl;
	std::cout << "\t\t\t***********************" << std::endl;
	std::cout << "\t\t\t*1. Rock              *" << std::endl;
	std::cout << "\t\t\t*2. Paper             *" << std::endl;
	std::cout << "\t\t\t*3. Scissors          *" << std::endl;
	std::cout << "\t\t\t*4. Quit              *" << std::endl;
	std::cout << "\t\t\t***********************" << std::endl << std::endl;
	std::cout << "What is your selection: ";

	std::cin >> n;

	std::cout << std::endl << std::endl;

	while (n < 1 || n > 4) {
		std::cout << "Please enter a valid selection: " << std::endl;
		std::cin >> n;

		std::cout << std::endl;
	}
	
	switch (n) {
	case ROCK:
		return 1;
		break;
	case PAPER: 
		return 2;
		break;
	case SCISSORS:
		return 3;
		break;
	case QUIT:
		return 4;
		break;
	}
}

//display computer's move
void displayCompChoice(int n) {
	if (n == ROCK) {
		std::cout << "The computer chose ROCK!" << std::endl;
	}
	else if (n == PAPER) {
		std::cout << "The computer chose PAPER!" << std::endl;
	}
	else if (n == SCISSORS) {
		std::cout << "The computer chose SCISSORS!" << std::endl;
	}
}

//provide the result of the game
int winner(int n, int o) {

	if ((n == ROCK && o == SCISSORS) || (n == PAPER && o == ROCK) || (n == SCISSORS && o == PAPER)) {
		std::cout << "You lose! The computer wins!" << std::endl << std::endl;
		return 1;
	}
	else if (n == o) {
		std::cout << "There is a tie!" << std::endl;
		std::cout << "You must play again!" << std::endl << std::endl << std::endl;
		return 2;
	}
	else {
		std::cout << "You win! The computer loses" << std::endl << std::endl;
		return 3;
	}
}

//ask player if they want to play again. return true if yes, false if no
bool playAgain() {
	char choice;

	std::cout << "Would you like to play again? Type Y for yes or N for no: ";
	std::cin >> choice;

	std::cout << std::endl << std::endl;

	while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
		std::cout << "Please enter a valid selection: ";
		std::cin >> choice;
	}
	std::cout << std::endl << std::endl;

	if (choice == 'Y' || choice == 'y') {
		return true;
	}
	else
		return false;
}

//repeat game in case of a tie
int repeat() {

	int compMove, userMove, gameOutcome;
	bool newGame;

	for (int i = 0; i < 81; i++) {
		std::cout << '*';
	}

	std::cout << std::endl << std::endl << std::endl;

	compMove = compChoice();

	userMove = userChoice();

	displayCompChoice(compMove);

	return gameOutcome = winner(compMove, userMove);

}