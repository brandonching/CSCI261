#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief A player and its respective info
 *
 */
class Player {
 public:
  // Constructor/destructor
  Player();
  Player(const int playerID);

  int getID() const;
  int getchips() const;

  void remove();
  void give();
  void center(int& center);

 private:
  /**
   * @brief the unique ID of this player
   *
   */
  int ID;
  /**
   * @brief how many chips this player current has
   *
   */
  int chips;
};

/** @brief Creates a new player with playerID and 3 chips.
 * Default ID = -1
 */
Player::Player() {
  ID = -1;
  chips = 3;
}

/** @brief Creates a new player with playerID and 3 chips */
Player::Player(const int playerID) {
  ID = playerID;
  chips = 3;
}

/** @brief Get uniquie id of player
 *
 * @return Unique ID */
int Player::getID() const { return ID; }

/** @brief Get the number of chips a player has
 *
 * @return Number of chips */
int Player::getchips() const { return chips; }

/** @brief Removes chip from calle
 *
 */
void Player::remove() { chips--; }

/** @brief Gives calle a chip
 *
 */
void Player::give() { chips++; }

/** @brief Gives a chip to the center and removes from player */
void Player::center(int& center) {
  center++;
  chips--;
}

#endif