#ifndef POSITION_H
#define POSITION_H
/**
 * @brief the row and column of a position
 *
 */
struct Position {
  /**
   * @brief row of position
   *
   */
  int row;
  /**
   * @brief column of position
   *
   */
  int column;
  
  Position();
  Position(int R, int C);
};

Position::Position() {
  row = 0;
  column = 0;
}
Position::Position(int R, int C) {
  row = R;
  column = C;
}

#endif