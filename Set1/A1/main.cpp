/* CSCI 261: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description:
 */

// Libraries.
#include <cstdlib>
#include <ctime>
#include <iostream>  // For cin, cout, etc.

// Library namespace
using namespace std;

// Constants
string moves[3] = {"Rock", "Paper", "Scissors"};
string players[2] = {"Player", "Computer"};

int main() {
  string playAgain = "Y";
  int playerWins = 0;
  int computerWins = 0;
  int tiedGames = 0;
  // Keep playing until play is done
  while (playAgain == "Y" | playAgain == "y") {
    // Welcome Message and get player input
    string player1;
    cout << "Welcome one and all to a round of Rock, Paper, Scissors! "
            "(Enter R, P or S)"
         << endl
         << "Player one: ";
    cin >> player1;

    // Display player input in full
    if (player1 == "r" | player1 == "R") {
      player1 = "Rock";
    } else if (player1 == "p" | player1 == "P") {
      player1 = "Paper";
    } else if (player1 == "s" | player1 == "S") {
      player1 = "Scissors";
    }
    cout << endl << "Player choose " << player1 << endl;

    // Computer Plays random
    srand(time(0));
    rand();
    string computer = moves[rand() % 3];
    cout << "Computer choose " << computer << endl << endl;

    // Determine Tie
    if (player1 == computer) {
      cout << player1 << " ties " << computer << endl;
      cout << "Tied game!" << endl;
      tiedGames++;
    }

    // Determin Winner
    if (player1 == "Rock" & computer == "Paper") {
      cout << "Paper Beats Rock" << endl << "Computer Wins";
      computerWins++;
    } else if (player1 == "Scissors" & computer == "Rock") {
      cout << "Rock Beats Scissors" << endl << "Computer Wins";
      computerWins++;
    } else if (player1 == "Paper" & computer == "Scissors") {
      cout << "Scissors Beats Paper" << endl << "Computer Wins";
      computerWins++;
    } else if (player1 == "Paper" & computer == "Rock") {
      cout << "Paper Beats Rock" << endl << "Player Wins";
      playerWins++;
    } else if (player1 == "Rock" & computer == "Scissors") {
      cout << "Rock Beats Scissors" << endl << "Player Wins";
      playerWins++;
    } else if (player1 == "Scissors" & computer == "Paper") {
      cout << "Scissors Beats Paper" << endl << "Player Wins";
      playerWins++;
    }

    // Play Again
    cout << endl <<endl<< "Do you want to play again? (Y/N) ";
    cin >> playAgain;
    cout << endl;
  }
  // Game Over message and scores
  cout << "Thanks for playing!" << endl;
  cout << "You won " << playerWins << " game(s), lost " << computerWins
       << " game(s), and tied " << tiedGames << " games(s)." << endl;
  return 0;
}