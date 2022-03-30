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

// Library namespace
using namespace std;

// Constants
template <typename T>
struct Node {
  T value;
  Node* pNext;
};

template <typename T>
class LinkedList {
 public:
  LinkedList();
  ~LinkedList();

  void pushFront(const T VALUE);
  void pushBack(const T VALUE);
  T popFront();

  T front();
  T back();
  unsigned int size() const;

  LinkedList(const LinkedList& OTHER);
  LinkedList& operator=(const LinkedList& OTHER);
  T at(const int POS) const;

 private:
  Node<T>* mpHead;
  Node<T>* mpTail;
  unsigned int mSize;
  Node<T>* mMakeNodeForValue(const T VALUE);
};

// Constructor
template <typename T>
LinkedList<T>::LinkedList() {
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}
// Copy Constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& OTHER) {
  mpHead = OTHER.mpHead;
  mpTail = OTHER.mpTail;
  mSize = OTHER.size();
  LinkedList newList;
  for (unsigned int i = 0; i < OTHER.size(); i++) {
    newList.pushBack(OTHER.at(i));
  }
}

// Copy Assignment Operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& OTHER) {
  // Self-asignment
  if (this == &OTHER) {
    return *this;
  }
  // do deep copy
  LinkedList newList(OTHER);
  swap(newList.mpHead, mpHead);
  swap(newList.mpTail, mpTail);
  swap(newList.mSize, mSize);
  return *this;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
  Node<T>* tempNode = mpHead;
  while (tempNode != nullptr) {
    Node<T>* tempNext = tempNode->pNext;
    delete tempNode;
    tempNode = tempNext;
  }
  mpHead = nullptr;
  mpTail = nullptr;
  mSize = 0;
}

// mMakeNodeForValue()
template <typename T>
Node<T>* LinkedList<T>::mMakeNodeForValue(const T VALUE) {
  Node<T>* tempNode = new Node<T>;
  tempNode->pNext = nullptr;
  tempNode->value = VALUE;
  return tempNode;
}

// pushFront()
template <typename T>
void LinkedList<T>::pushFront(const T VALUE) {
  Node<T>* tempNode = new Node<T>;
  tempNode->pNext = mpHead;
  tempNode->value = VALUE;
  mpHead = tempNode;
  mSize++;
  if (mSize == 1) {
    mpTail = mpHead;
  }
}

// pushBack()
template <typename T>
void LinkedList<T>::pushBack(const T VALUE) {
  Node<T>* tempNode = new Node<T>;
  tempNode->pNext = nullptr;
  tempNode->value = VALUE;
  if (mpTail != nullptr) {
    mpTail->pNext = tempNode;
  }
  mpTail = tempNode;
  mSize++;
  if (mSize == 1) {
    mpHead = mpTail;
  }
}

// popFront()
template <typename T>
T LinkedList<T>::popFront() {
  if (mpHead->pNext != nullptr) {
    Node<T>* tempNode = mpHead;
    mpHead = mpHead->pNext;
    delete tempNode;
    mSize--;
  }
  return T();
}

// front()
template <typename T>
T LinkedList<T>::front() {
  if (mpHead->pNext != nullptr) {
    return mpHead->value;
  }

  return T();
}

// back()
template <typename T>
T LinkedList<T>::back() {
  if (mpTail->pNext != nullptr) {
    return mpTail->value;
  }
  return T();
}

// size()
template <typename T>
unsigned int LinkedList<T>::size() const {
  return mSize;
}

// at()
template <typename T>
T LinkedList<T>::at(const int POS) const {
  if (POS < 0) {
    return T();
  }
  Node<T>* currentNode = mpHead;
  for (int i = 0; i < POS; i++) {
    currentNode = currentNode->pNext;
    if (currentNode == nullptr) {
      return T();
    }
  }
  return currentNode->value;
}

// structure for verticies
template <typename T>
struct Vertex {
  T x, y, z;
};

// Structure for faces
template <typename T>
struct Face {
  T p, q, r;
};

string prompt_user_for_filename() {
  cout << "Please Provide a File Name: ";
  string fileName;
  cin >> fileName;
  return fileName;
}

bool open_file(ifstream& inputFile, const string FILENAME) {
  // Open File
  inputFile.open(FILENAME);

  // Check for an error
  if (inputFile.fail()) {
    cerr << "Error opeing file." << endl;
    return 0;
  }
  // retrun 1 if open sucessful
  return 1;
}

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
    cout << endl << line << endl;
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
  cout << endl << endl;
  for (unsigned int i = 0; i < comments->size(); i++) {
    cout << comments->at(i) << endl;
  }

  // Dellocate LinkedList
  delete comments;
  delete vertices;
  delete faces;
  return 0;
}