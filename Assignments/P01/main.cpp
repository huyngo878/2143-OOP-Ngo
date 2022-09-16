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

int counterRun = 0;
// struct to create the node an assign a number to it
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
  // lots of constructors
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
//Purpose: Open the file that the user chooses
//Receives: User input(string)
//Returns: nothing
void openFiles(ifstream &infile) {
  string inFileName;
  string outFileName;
  cout << "Enter the input file name: ";
  cin >> inFileName;
  infile.open(inFileName); // open input file
}

//Purpose: Puts number from a file into a linked list
//Receives: User(userfile)
//Returns: nothing
Vector::Vector(string fname) {
  ifstream infile;
  ofstream outfile;
  openFiles(infile);
  int num;
  //read until end of file and assign the number
  //to (num) then use pushFront(num) to add to a linked list
  while (!infile.eof()) {
    infile >> num;
    pushFront(num);
  }
}

//Purpose: Constructor to assign HEAD and TAIL to null when created
//Returns: nothing
Vector::Vector() {
  head = NULL;
  tail = NULL;
}

//Purpose: Allocated numbers in the array into a linked list
//Receives: Array and the size of the array
//Returns: nothing
Vector::Vector(int *_array, int size) {
  //use a forloop to go through the array and use the constructor
  //pushFront(arrayname[i]) to add the number to the linked list
  for (int i = size; i >= 0; i--) {
    if (i == size) {
    } else
      pushFront(_array[i]);
  }
}

//Purpose: Adds the link list to the other
//Receives: Vector
//Returns:  nothing
Vector::Vector(Vector *_Vector) {
  Node *firstList = head;
  Node *secondList = _Vector->head;
}

//Purpose: Push the data from linked list to another at the rear
//Receives: Vector that is being added in
//Returns: nothing
void Vector::pushRear(Vector _vector) {
  Node *firstList = head;
  Node *secondList = _vector.head;
  //if the first node is empty set the first node as head and tail
  if (head == NULL) {
    head = secondList;
    tail = secondList;
  } else {
    tail->next = secondList;
  }
  tail = secondList;
}

//Purpose: pushes a certain number to the rear of the linked list
//Receives: integer
//Returns: noting
void Vector::pushRear(int num) {
  Node *temp = new Node(num);
  //if the first node is empty set the first node as head and tail
  if (head == NULL) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
  }
  tail = temp;
}


//Purpose: Pushes a certain number to the front of the linked list
//Receives: integer
//Returns: nothing
void Vector::pushFront(int n) {
  Node *newNode = new Node(n);
  //if the first node is empty set the first node as head and tail
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

//Purpose: Removes a node from the linked list
//Receives: noting
//Returns: data of the deleted node
int Vector::popFront() {
  Node *temp = head;
  head = head->next;
  delete temp;
  return head->data;
}

//Purpose: push an entire vector to the front of the other
//Receives: Vector
//Returns: notning
void Vector::pushFront(Vector _vector) {
  Node *firstList = head;
  Node *secondList = _vector.head;
  //if the first node is empty set the first node as head and tail
  if (head == NULL) {
    head = secondList;
    tail = secondList;
  } else {
    head->next = secondList;
  }
  tail = secondList;
}

//Purpose: pop a number in the rear
//Receives: nothing
//Returns: number that was deleted
int Vector::popRear() {
  Node *temp = head;
  //traverse the linked list to check the next->next
  //if == NULL remove the node before it
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  tail = temp;
  int deletedNum = tail->next->data;
  delete tail->next;
  tail->next = NULL;
  return deletedNum;
}

//Purpose: traverse and prints the linked list
//Receives: nothing
//Returns: nothing
void Vector::print() {

  Node *traverse = head;

  ofstream outfile;
  outfile.open("test.out", fstream::app);
  //print out my heading here
  if(counterRun == 0)
  {
    outfile << "Huy Ngo" << endl << "9/15/2020" << endl
  << "Fall 2143" << endl << endl;
    counterRun++;
  }
  
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

//Purpose: Find a certain number in the linked list and display the index
//Receives: integer to find
//Returns: the index the number was at or if it was not found
int Vector::find(int num) {
  //index
  int index = 0;
  Node *temp = head;

  while (temp != NULL) {
    if (temp->data == num) {
      //if found return the index
      return index;
    }
    temp = temp->next;
    index++;
  }
  // If number is not found return -1
  return -1;
}

//Purpose: push a number to the correct order
//Receives: integer
//Returns: nothing
void Vector::inOrderPush(int num) {
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