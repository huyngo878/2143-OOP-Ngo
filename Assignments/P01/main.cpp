/*

  $$$$$$\    $$\ $$\   $$\  $$$$$$\
 $$  __$$\ $$$$ |$$ |  $$ |$$ ___$$\
 \__/  $$ |\_$$ |$$ |  $$ |\_/   $$ |
  $$$$$$  |  $$ |$$$$$$$$ |  $$$$$ /
 $$  ____/   $$ |\_____$$ |  \___$$\
 $$ |        $$ |      $$ |$$\   $$ |
 $$$$$$$$\ $$$$$$\     $$ |\$$$$$$  |
 \________|\______|    \__| \______/



 $$$$$$$\   $$$$$$\    $$\
 $$  __$$\ $$$ __$$\ $$$$ |
 $$ |  $$ |$$$$\ $$ |\_$$ |
 $$$$$$$  |$$\$$\$$ |  $$ |
 $$  ____/ $$ \$$$$ |  $$ |
 $$ |      $$ |\$$$ |  $$ |
 $$ |      \$$$$$$  /$$$$$$\
 \__|       \______/ \______|



 $$\   $$\                           $$\   $$\
 $$ |  $$ |                          $$$\  $$ |
 $$ |  $$ |$$\   $$\ $$\   $$\       $$$$\ $$ | $$$$$$\   $$$$$$\
 $$$$$$$$ |$$ |  $$ |$$ |  $$ |      $$ $$\$$ |$$  __$$\ $$  __$$\
 $$  __$$ |$$ |  $$ |$$ |  $$ |      $$ \$$$$ |$$ /  $$ |$$ /  $$ |
 $$ |  $$ |$$ |  $$ |$$ |  $$ |      $$ |\$$$ |$$ |  $$ |$$ |  $$ |
 $$ |  $$ |\$$$$$$  |\$$$$$$$ |      $$ | \$$ |\$$$$$$$ |\$$$$$$  |
 \__|  \__| \______/  \____$$ |      \__|  \__| \____$$ | \______/
                     $$\   $$ |                $$\   $$ |
                     \$$$$$$  |                \$$$$$$  |
                      \______/                  \______/

*/

#include <fstream>
#include <iostream>

using namespace std;

//struct to create the node an assign a number to it
struct Node {
  int data;
  Node *next;

  Node(int num) {
    data = num;
    next = NULL;
  }
};

class Vector {
private:
  Node *head;
  Node *tail;

public:
//lots of constructors
  Vector();
  Vector(string);
  Vector(Vector *);
  void pushFront(int);
  void print();
  void pushRear(int);
  void pushRear(Vector);
  int popFront();
  int popRear();
  void inOrderPush(int);
  int popAt(int);
  int find(int);
  void pushFront(Vector);
  Vector(int *, int);
};
//open files
void openFiles(ifstream &infile) {
  string inFileName;
  string outFileName;
  cout << "Enter the input file name: ";
  cin >> inFileName;
  infile.open(inFileName); // open input file
}

Vector::Vector(string fname) {
  ifstream infile;
  ofstream outfile;
  openFiles(infile);
  int num;
  while (!infile.eof()) {
    infile >> num;
    pushFront(num);
  }
}

Vector::Vector() {
  head = NULL;
  tail = NULL;
}

Vector::Vector(int *_array, int size) {
  for (int i = size; i >= 0; i--) {
    if (i == size) {
    } else
      pushFront(_array[i]);
  }
}

Vector::Vector(Vector *_Vector) {
  Node *firstList = head;
  Node *secondList = _Vector->head;
}

void Vector::pushRear(Vector _vector) {
  Node *firstList = head;
  Node *secondList = _vector.head;

  if (head == NULL) {
    head = secondList;
    tail = secondList;
  } else {
    tail->next = secondList;
  }
  tail = secondList;
}

void Vector::pushRear(int num) {
  Node *temp = new Node(num);

  if (head == NULL) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
  }
  tail = temp;
}

void Vector::pushFront(int n) {
  Node *newNode = new Node(n);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

int Vector::popFront() {
  Node *temp = head;
  head = head->next;
  delete temp;
  return head->data;
}

void Vector::pushFront(Vector _vector) {
  Node *firstList = head;
  Node *secondList = _vector.head;

  if (head == NULL) {
    head = secondList;
    tail = secondList;
  } else {
    head->next = secondList;
  }
  tail = secondList;
}

int Vector::popRear() {
  Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  tail = temp;
  int deletedNum = tail->next->data;
  delete tail->next;
  tail->next = NULL;
  return deletedNum;
}

void Vector::print() {

  Node *traverse = head;

  ofstream outfile;
  outfile.open("test.out", fstream::app);
  outfile << "[";
  while (traverse != NULL) {
    outfile << traverse->data;
    traverse = traverse->next;
    if (traverse == NULL) {
      outfile << "] ";
    } else
      outfile << ", ";
  }
  outfile << endl;
}

int Vector::find(int num) {
  // Used to keep track of the Node Index
  int index = 0;
  Node *temp = head;
  // LinkedList traversal for finding the node
  while (temp != NULL) {
    if (temp->data == num) {
      // If element found return index
      return index;
    }
    temp = temp->next;
    index++;
  }
  // If element not found
  return -1;
}

void Vector::inOrderPush(int num) {
  // Dynamically create your new node
  Node *temp = new Node(num);

  // if empty
  if (head == NULL) {
    head = temp;
    tail = temp;
  } else {

    Node *traverse = head;

    // if first number is smaller than num
    if (traverse->data > num) {
      pushFront(num);
    } else {

      while (traverse->next != NULL && (traverse->next->data < num)) {
        traverse = traverse->next;
      }

      if (traverse->next == NULL) {
        pushFront(num);
      } else {
        // connecting the node to the rest of the list
        temp->next = traverse->next;
        traverse->next = temp;
      }
    }
  }
}

int main() {

  int x = 0;

  Vector v1;
  v1.pushFront(18);
  v1.pushFront(20);
  v1.pushFront(25);
  v1.pushRear(18);
  v1.pushRear(20);
  v1.pushRear(25);
  v1.print();
  // [25, 20, 18, 18, 20, 25]

  int A[] = {11, 25, 33, 47, 51};
  Vector v2(A, 5);
  v2.print();
  // [11, 25, 33, 47, 51]

  v2.pushFront(9);
  // v2.inOrderPush(27);
  v2.pushRear(63);
  v2.print();
  // [9, 11, 25, 33, 47, 51, 63]

  v1.pushRear(v2);
  v1.print();
  v2.print();
  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

  x = v1.popFront();
  x = v1.popFront();
  x = v1.popFront();
  v1.print();
  v2.print();
  // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
  cout << x << endl;
  // 18

  x = v1.popRear();
  x = v1.popRear();
  x = v1.popRear();
  v2.print();
  v1.print();

  // [18, 20, 25, 9, 11, 25, 27, 33]
  cout << x << endl;
  // 47

  // x = v2.popAt(3);
  // v2.print();
  // [9, 11, 25, 33, 47, 51, 63]
  // cout << x << endl;

  // 27
  x = v2.find(51);
  v2.print();
  cout << x << endl;
  // 5

  x = v2.find(25);
  cout << x << endl;
  // -1

  Vector v3(v1);
  v3.print();
  // [18, 20, 25, 9, 11, 25, 27, 33]

  v3.pushFront(v2);
  v3.print();
  cout << " here" << endl;
  //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  Vector v4("input.dat");
  v4.print();
  // v4.pushRear(v3);
  // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23,
  // 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33,
  // 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
  //
  return 0;
}