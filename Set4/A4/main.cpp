/* CSCI 261: Assignment 4: A4 - Abstract Lists: Wavefront OBJ File Validator
 *
 * Author: Brandon Ching
 * Resources: N/A
 *
 * Description: working with list/array and the obj file type
 */

// Libraries
#include <fstream>
#include <iostream>  // For cin, cout, etc.
#include <string>
#include "functions.cpp"

// Library namespace
using namespace std;

// Constants


int main(int argc, char* argv[]) {
  string filename;
  if (argc == 1) {
    filename = prompt_user_for_filename();
  } else if (argc == 2) {
    filename = argv[1];
  } else {
    cerr << "Usage: " << argv[0] << " [filename]" << endl;
    cerr << "  filename   - optional file to open upon start" << endl;
    return -2;
  }

  // open file for parsing
  ifstream fileIn;
  if (!open_file(fileIn, filename)) {
    cerr << "Could not open file \"" << filename << "\"" << endl;
    cerr << "Shutting down" << endl;
    return -1;
  } else {
    cout << "Opening file " << filename << endl
         << "File successfully opened!" << endl;
  }

  // Create LinkedList for comments, vertex, and faces
  LinkedList<string>* comments = new LinkedList<string>;
  LinkedList<Vertex<float>>* vertices = new LinkedList<Vertex<float>>;
  LinkedList<Face<int>>* faces = new LinkedList<Face<int>>;

  // read the data and do something with it
  string line;
  while (getline(fileIn, line)) {
    if (line[0] == '#') {  // comments
      comments->pushBack(line.substr(2));
    } else if (line[0] == 'v') {  // Verticies
      Vertex<float> tempVertex;
      string temp;
      if (line[2] == ' ') {
        temp = line.substr(3);
      } else {
        temp = line.substr(2);
      }
      // get X, Y, Z values
      tempVertex.x = stof(temp.substr(0, temp.find(' ')));
      tempVertex.y = stof(temp.substr(
          temp.find(' '), temp.substr(temp.find(' ') + 2).find(' ') + 2));
      tempVertex.z = stof(temp.substr(
          temp.find(' ') + temp.substr(temp.find(' ') + 2).find(' ') + 2,
          temp.length() - 1));
      vertices->pushBack(tempVertex);
    } else if (line[0] == 'f') {
      Face<int> tempFace;
      string temp;
      if (line[2] == ' ') {
        temp = line.substr(3);
      } else {
        temp = line.substr(2);
      }
      // get X, Y, Z values
      tempFace.p = stof(temp.substr(0, temp.find(' ')));
      tempFace.q = stof(temp.substr(
          temp.find(' '), temp.substr(temp.find(' ') + 2).find(' ') + 2));
      tempFace.r = stof(temp.substr(
          temp.find(' ') + temp.substr(temp.find(' ') + 2).find(' ') + 2,
          temp.length() - 1));
      faces->pushBack(tempFace);
    }
  }

  cout << "Read In" << endl;
  cout << "         " << comments->size() << " comments" << endl;
  cout << "         " << vertices->size() << " vertices" << endl;
  cout << "         " << faces->size() << " faces" << endl;
  cout << endl;

  // Validate faces
  cout << "Validating faces..." << endl;
  bool fileIsValid = true;
  for (unsigned int face = 1; face < faces->size(); face++) {
    // compare Faces for duplicate indeces
    if ((faces->at(face).p == faces->at(face).q) ||
        (faces->at(face).p == faces->at(face).r) ||
        (faces->at(face).q == faces->at(face).r)) {
      cout << "        Face " << face + 1 << " has duplicate indices" << endl;
      fileIsValid = false;
    }

    // compare for out of range
    if ((unsigned(faces->at(face).p) > vertices->size()) ||
        (unsigned(faces->at(face).q) > vertices->size()) ||
        (unsigned(faces->at(face).r) > vertices->size())) {
      cout << "        Face " << face + 1 << " contains vertices out of range"
           << endl;
      fileIsValid = false;
    }
  }

  // print out if file is valid
  if (fileIsValid) {
    cout << "...File is valid!" << endl;
  } else {
    cout << "...File is invalid.";
    return 0;
  }

  // Print Menu
  int inputChoice;
  // loop thorugh menu forever until 4 is inputed
  while (inputChoice != 4) {
    cout << "What do you wish to do?" << endl;
    cout << "        1) Print comments" << endl
         << "        2) Print vertices" << endl
         << "        3) Print faces" << endl
         << "        4) Quit" << endl;
    cout << "Choice: ";

    cin >> inputChoice;
    cout << endl;
    // change response based on input
    switch (inputChoice) {
      case 1:  // comments
        for (unsigned int i = 1; i <= comments->size(); i++) {
          cout << "Comment #" << i << "  " << comments->at(i - 1) << endl;
        }
        cout << endl;
        break;
      case 2:  // vertices
        for (unsigned int i = 1; i <= vertices->size(); i++) {
          cout << "Vertex #" << i << " ";
          printVertex(vertices, i);
          cout << endl;
        }
        cout << endl;
        break;
      case 3:  // faces
        for (unsigned int i = 1; i <= faces->size(); i++) {
          cout << "Face #" << i << "        ";
          printVertex(vertices, faces->at(i - 1).p);
          cout << "        ";
          printVertex(vertices, faces->at(i - 1).q);
          cout << "        ";
          printVertex(vertices, faces->at(i - 1).r);
          cout << endl;
        }
        cout << endl;
        break;
    }
  }

  // Dellocate LinkedList
  delete comments;
  delete vertices;
  delete faces;
  return 0;
}