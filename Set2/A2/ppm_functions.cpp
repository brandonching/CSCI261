

#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
#include "ppm_functions.h"

void print_file_options() {
  cout << "Which image to load?" << endl
       << "  1. Brick" << endl
       << "  2. Wallpaper" << endl
       << "  3. Private" << endl
       << "Enter 1, 2, or 3: ";
}

void print_operation_options() {
  cout << "Which process to apply?" << endl
       << "  1. Convert to grayscale" << endl
       << "  2. Invert the colors" << endl
       << "Enter 1 or 2: ";
}

int get_user_input(int minValue, int maxValue) {
  int inputValue;
  // Loop until valid input
  while (true) {
    cin >> inputValue;

    // test if input is int
    if (!cin.fail()) {
      // test if input is within range
      if (inputValue >= minValue && inputValue <= maxValue) {
        break;  // exit loop when input is valid
      }
    }

    cerr << endl << "Invalid input." << endl << endl;
    cin.clear();  // clear error

    char badChar;  // clear out rest of input line
    do {
      badChar = cin.get();
    } while (badChar != '\n');

    // reprint input menu based on max value
    switch (maxValue) {
      case 2:
        print_operation_options();
        break;
      case 3:
        print_file_options();
        break;
    }
  }

  return inputValue;
}

bool open_files(ifstream& inputImage, ofstream& outputImage, int fileOption,
                int operationOption) {
  // File name constants
  string inputFileNames[3] = {"brick.ppm", "wallpaper.ppm", "private.ppm"};
  string outputFileNames[3][2] = {
      {"brick_grayscale.ppm", "brick_inverted.ppm"},
      {"wallpaper_grayscale.ppm", "wallpaper_inverted.ppm"},
      {"private_grayscale.ppm", "private_inverted.ppm"}};

  // open files
  inputImage.open(inputFileNames[fileOption - 1]);
  outputImage.open(outputFileNames[fileOption - 1][operationOption - 1]);

  // check for an error
  if (inputImage.fail()) {
    cerr << "Error opening input file";
    return 0;
  }
  if (outputImage.fail()) {
    cerr << "Error opening output file";
    return 0;
  }

  // tell user files are being opened/written
  cout << "Opening " << inputFileNames[fileOption - 1] << " file" << endl;
  cout << "Writing " << outputFileNames[fileOption - 1][operationOption - 1]
       << " file" << endl;

  // if both open return true
  return 1;
}

bool read_header_information(ifstream& inputImage, int& width, int& height,
                             int& maxValue) {
  // Get files type
  string PPMtype;
  inputImage >> PPMtype;

  // If not P3 exit
  if (PPMtype != "P3") {
    return 0;
  }

  // define width, height, and maxValue
  inputImage >> width;
  inputImage >> height;
  inputImage >> maxValue;
  return 1;
}

void write_header_information(std::ofstream& outputImage, int width, int height,
                              int maxValue) {
  // write header info from input file to output file
  outputImage << "P3\n" << width << " " << height << "\n" << maxValue << "\n";
}

void read_and_write_modified_pixels(std::ifstream& inputImage,
                                    std::ofstream& outputImage,
                                    int operationOption, int width, int height,
                                    int maxValue) {
  int red, green, blue;
  // run loop for each pixel
  for (int i = 0; i < (width * height); i++) {
    // get each RGB value for pixel
    inputImage >> red;
    inputImage >> green;
    inputImage >> blue;

    // based on operation either convert to grayscale or invert
    switch (operationOption) {
      case 1:
        outputImage << 0.2989 * red + 0.5870 * green + 0.1140 * blue << "\n";
        outputImage << 0.2989 * red + 0.5870 * green + 0.1140 * blue << "\n";
        outputImage << 0.2989 * red + 0.5870 * green + 0.1140 * blue << "\n";
        break;
      case 2:
        outputImage << maxValue - red << "\n";
        outputImage << maxValue - green << "\n";
        outputImage << maxValue - blue << "\n";
        break;
    }
  }
  // close the files
  inputImage.close();
  outputImage.close();
}
