/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: Left-Right-Center Game simulation using circularly doubly linked
 * list
 */

// Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>  // For cin, cout, etc.

#include "CircularDoublyLinkedList.hpp"
#include "Player.hpp"

// Library namespace
using namespace std;

// Constants

int main() {
  // Generate random seed
  srand(time(0));
  rand();

  int playerCount;
  int centerPot = 0;
  bool clockWise = true;
  int turns = 0;
  cout << "How many Players would you like to simulate?" << endl << "> ";
  cin >> playerCount;

  // build player list
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
      cout << "Player #" << currentPlayer.getID() << " has "
           << currentPlayer.getchips() << " chips left" << endl;
      int rollCount = currentPlayer.getchips();
      if (rollCount > 3) {
        rollCount = 3;
      }
      cout << "        Rolling " << rollCount << " dice" << endl;

      // roll 1-3 times baed on number of chips left
      for (int roll = 1; roll <= rollCount; roll++) {
        int diceRoll = rand() % 8;
        cout << "        Rolled a " << diceRoll << " - ";
        switch (diceRoll) {
          case 0:
          case 1:
          case 2:
            cout << "keep!" << endl;
            break;
          case 3:
            currentPlayer.remove();
            playerList->set(currentPlayer.getID() - 1, currentPlayer);
            currentNode->pLast->value.give();
            cout << "give left   - Player #"
                 << currentNode->pLast->value.getID() << " has "
                 << currentNode->pLast->value.getchips() << " chips - Player #"
                 << currentPlayer.getID() << " has " << currentPlayer.getchips()
                 << " chips" << endl;
            break;
          case 4:
            currentPlayer.remove();
            playerList->set(currentPlayer.getID() - 1, currentPlayer);
            currentNode->pNext->value.give();
            cout << "give right  - Player #"
                 << currentNode->pNext->value.getID() << " has "
                 << currentNode->pNext->value.getchips() << " chips - Player #"
                 << currentPlayer.getID() << " has " << currentPlayer.getchips()
                 << " chips" << endl;
            break;
          case 5:
            currentPlayer.center(centerPot);
            playerList->set(currentPlayer.getID() - 1, currentPlayer);
            cout << "give center - Center has " << centerPot
                 << " chips - Player #" << currentPlayer.getID() << " has "
                 << currentPlayer.getchips() << " chips" << endl;
            break;
          case 6:
            clockWise = !clockWise;
            cout << "reverse!" << endl;
            break;
          case 7:
            if (clockWise) {
              currentNode = currentNode->pNext;
            } else {
              currentNode = currentNode->pLast;
            }
            cout << "skip! skipping 1 player" << endl;
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

  // print end game message
  cout << "Player #" << currentPlayer.getID() << " wins with "
       << currentPlayer.getchips() << " chips left after " << turns << " turns";

  return 0;
}