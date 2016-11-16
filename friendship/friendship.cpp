/*
*friendship in an class means that a friend can refers to this class' members
*including the private ones
* but,this friendship can not be inheritated by this class' descendants
* */

#include<iostream>
using namespace std;

class A {
public:
    A(int a) {
        x = a;
    }

    virtual ~A() {

    }
    
    friend void show();
private:
    int x;
};

class B : public A {
public:
    B(int b):A(b) {
        y = b;
    }

    virtual ~B() {
        
    }

private:
    int y;
};

void show() {
    B b(102);

    cout << "A::x=" << b.x << endl;
    //if we want to show B::y, it will report an error,
    //cause friendship cannot be inherited
    //cout << "B::y=" << b.y << endl;
}

int main() {
    show();

    return 0;
}
