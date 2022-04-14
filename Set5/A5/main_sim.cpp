/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Left-Right-Center Game simulation using circularly doubly linked
 * list
 */

// Libraries
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>  // For cin, cout, etc.

#include "CircularDoublyLinkedList.hpp"
#include "Player.hpp"

// Library namespace
using namespace std;

// Constants
int game(int playerCount);

int main() {
  // Generate random seed
  srand(time(0));
  rand();

  // get player count for simulation
  int playerCount;
  cout << "How many Players would you like to simulate?" << endl << "> ";
  cin >> playerCount;

  // simulation
  int totalTurns = game(playerCount);
  double lastAvg = 0;
  double thisAvg = totalTurns;
  int gameCount = 1;


//first game
  cout << "Game #" << gameCount << " - " << totalTurns << " Turns - " << thisAvg
       << " Average Turns" << endl;

  // the other games
  while (abs(thisAvg - lastAvg) >= 0.0001) {
    gameCount++;
    int thisGameTurns = game(playerCount);
    totalTurns += thisGameTurns;
    lastAvg = thisAvg;
    thisAvg = (double)totalTurns / gameCount;
    cout << "Game #" << gameCount << " - " << thisGameTurns << " Turns - "
         << thisAvg << " Average Turns" << endl;
  }
  return 0;
}

int game(int playerCount) {
  int centerPot = 0;
  bool clockWise = true;
  int turns = 0;

  // build player
  CircularDoublyLinkedList<Player> *playerList =
      new CircularDoublyLinkedList<Player>;
  for (int i = 0; i < playerCount; i++) {
    playerList->insert(i, Player(i + 1));
  }

  // Game Play
  DoublyNode<Player> *currentNode = playerList->getHead();
  Player currentPlayer;
  while (playerCount >= 2) {
    // get current player
    currentPlayer = currentNode->value;

    // if player is still in game, print current chip count
    if (currentPlayer.getchips() > 0) {
      int rollCount = currentPlayer.getchips();
      if (rollCount > 3) {
        rollCount = 3;
      }

      // roll 1-3 times baed on number of chips left
      for (int roll = 1; roll <= rollCount; roll++) {
        int diceRoll = rand() % 8;
        switch (diceRoll) {
          case 0:
          case 1:
          case 2:
            break;
          case 3:
            currentPlayer.remove();
            playerList->set(currentPlayer.getID() - 1, currentPlayer);
            currentNode->pLast->value.give();
            break;
          case 4:
            currentPlayer.remove();
            playerList->set(currentPlayer.getID() - 1, currentPlayer);
            currentNode->pNext->value.give();
            break;
          case 5:
            currentPlayer.center(centerPot);
            playerList->set(currentPlayer.getID() - 1, currentPlayer);
            break;
          case 6:
            clockWise = !clockWise;
            break;
          case 7:
            if (clockWise) {
              currentNode = currentNode->pNext;
            } else {
              currentNode = currentNode->pLast;
            }
            break;
        }
      }

      // Update Current Player count
      playerCount = 0;
      for (int i = 0; i < playerList->size(); i++) {
        if (playerList->get(i).getchips() > 0) {
          playerCount++;
        }
      }
    }

    // get node for next player for next turn
    if (clockWise) {
      currentNode = currentNode->pNext;
    } else {
      currentNode = currentNode->pLast;
    }

    // increment turns
    turns++;
  }

  // get last player(winner)
  for (int i = 0; i < playerList->size(); i++) {
    if (playerList->get(i).getchips() != 0) {
      currentPlayer = playerList->get(i);
    }
  }
  return turns;
}