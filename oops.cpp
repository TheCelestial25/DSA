#include <bits/stdc++.h>

using namespace std;

// Friend Class
// class A {
//     int a = 2;
//     friend void funny(A&);
// };

// class B {
//     int b;
// public:
//     void fun(A &x) {
//         cout << "A::a = " << x.a;
//     }
// };

// void funny(A &x) {
//     cout << "A::a = " << x.a;
// }


// -------------------------------- //

class Animal {
public:
    virtual void sound() {
        cout << "Animal sound." << endl;
    }
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Bark." << endl;
    }
};

template<typename T> T genericBigger(T a, T b) {
    return a > b ? a : b;
}

int main() {
    enum slotType {Car, Bike};
    slotType slot = Bike;
    try{
        if(slot == Car) cout << "Car";
        else throw "Not a Car";
    }
    catch(const char* e) {
        cout << e << endl;
    }
    cout << genericBigger(1, 2) << endl;
    cout << genericBigger(1.00, 3.00) << setprecision(2) << endl;
    return 0;
}