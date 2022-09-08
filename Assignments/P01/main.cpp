#include <iostream>
#include <fstream>

using namespace std;

class Vector
{
private:
    int *array;
    int num;
    int index;
    string fileName;
    bool empty();
    bool size();
public:
    Vector();
    Vector(int *);
    Vector(int *, int);
    Vector(string);
    Vector(Vector(int *));
    void pushFront(int);
    void pushFront(int *);
    void pushRear(int);
    void pushRear(int *);
    void pushAt(int, int);
    void pushInOrder(int);
    int popFront();
    int popRear();
    int popAt(int);
    int find(int);
    void print();
};

Vector::Vector(const Vector &a)
{
    
}


int main()
{

}