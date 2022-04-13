/** @file rectangle.hpp
 * @brief Class for rectangles
 *
 * @author Brandon Ching
 *
 * @bug No currently known bugs;
 */

class rectangle {
 public:
  rectangle();
  ~rectangle();

  rectangle& operator<(rectangle& OTHER);
  rectangle& operator>(rectangle& OTHER);

  float base;
  float height;
};

/** @brief create a new rectagle of 1x1 */
rectangle::rectangle() {
  base = 1;
  height = 1;
}

/** @brief delete a rectangle */
rectangle::~rectangle() {}

/** @brief Less than comparator operator
 *
 * @param rect1 First rectagle to be compared
 * @param rect2 Second rectangle to compare to rect1
 *
 * @return true when the base of rect1 is less than the base of rect2 OR the
 * bases are equal and the height of rect is less than the height of rect2
 */
bool operator<(const rectangle& rect1, const rectangle& rect2) {
  if ((rect1.base < rect2.base) ||
      ((rect1.base == rect2.base) && (rect1.height < rect2.height))) {
    return true;
  }
  return false;
}

/** @brief Greater than comparator operator
 *
 * @param rect1 First rectagle to be compared
 * @param rect2 Second rectangle to compare to rect1
 *
 * @return true when the base of rect1 is greater than the base of rect2 OR the
 * bases are equal and the height of rect is greater than the height of rect2
 */
bool operator>(const rectangle& rect1, const rectangle& rect2) {
  if ((rect1.base > rect2.base) ||
      ((rect1.base == rect2.base) && (rect1.height > rect2.height))) {
    return true;
  }
  return false;
}
