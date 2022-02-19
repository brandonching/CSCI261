/* CSCI 261: Assignment 2: A2 - PPM Image Editor
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: A Program that allows for the selection of 3 diffrent ppm files
 * and either convert to grayscale or invert the colors
 */

// Libraries
#include <fstream>
#include <iostream>  // For cin, cout, etc.

#include "ppm_functions.h"

// Library namespace
using namespace std;

// Constants

int main() {
  // Display file opetions menu
  print_file_options();
  int fileOption = get_user_input(1, 3);

  // Display file operations menu
  print_operation_options();
  int operationOption = get_user_input(1, 2);

  // Declate fstream objects
  ifstream inputImage;
  ofstream outputImage;

  // Open files
  open_files(inputImage, outputImage, fileOption, operationOption);

  // Read file
  int width, height, maxValue;
  read_header_information(inputImage, width, height, maxValue);

  // Convert and write new file
  write_header_information(outputImage, width, height, maxValue);
  read_and_write_modified_pixels(inputImage, outputImage, operationOption,
                                 width, height, maxValue);

  return 0;
}