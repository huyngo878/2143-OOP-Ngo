#include <iostream>
#include<fstream>
#include <string>



using namespace std;

struct Node{
    int data;

    Node * next;
    Node(int x)
    {
        data = x;
        data = NULL;
    }
};

class MyVector
{
private:
    Node * head;
    Node * tail;
    int size;
    static ofstream fout;
    string fileName;
    bool sorted;

    void _inorderPush(int x)
    {
        Node * tempPtr = new Node(x);
        Node * prev = head;
        Node * curr = head;

        while(curr->data > x){
            prev = curr;
            curr = curr->next;
        }

        tempPtr->next = prev->next;
        prev->next = tempPtr;

        size++;
    }

public:
    MyVector()
    {
        init();
    }
    
    MyVector(int A[], int aSize)
    {
        init();

        for(int i = 0;i < aSize, i++)
        {
            pushRear(A[i]);
        }
    }

    void pushRear(int x)
    {
        Node * tempPtr = new Node(x);
        
        if(!head)
        {
            head = tail = tempPtr;
        }
    }

    void init()
    {
        head = tail = NULL;
        fileName = "";
        size = 0;
        sorted = 0;
    }

};



int main()
{



int a1[] = { 1, 2, 3, 4, 5 };
int a2[] = { 10, 20, 30 };

MyVector v1(a1,5);
MyVector v2(a2,3);

ofstream fout;
ofile.open("output.txt");

cout << v1[2] << endl;
// writes out 3

v1[4] = 9;
// v1 now = [1,2,3,4,9]

cout << v1 << endl;
// writes out [1,2,3,4,9] to console.

fout << v1 << endl;
// writes out [1,2,3,4,9] to your output file.

Vector v3 = v1 + v2;
cout << v3 << endl;
// writes out [11,22,33,4,9] to console.

v3 = v1 - v2;
cout << v3 << endl;
// writes out [-9,-18,-27,4,9] to console.

v3 = v2 - v1;
cout << v3 << endl;
// writes out [9,18,27,4,9] to console.

v3 = v2 * v1;
cout << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 * v2;
cout << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 / v2;
cout << v3 << endl;
// writes out [0,0,0,4,9] to console.

v3 = v2 / v1;
cout << v3 << endl;
// writes out [10,10,10,4,9] to console.

cout << (v2 == v1) << endl;
// writes 0 to console (false) .

MyVector v4 = v1;
cout << (v4 == v1) << endl;
// writes 1 to console (true) .



}