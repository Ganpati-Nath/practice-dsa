#include<iostream>
#include<string>

using namespace std;

class Add {
    public:

        // Aka Static Polymorphism / Compile time Polymorphism...
        // sum of 2 integers...
        int sum(int x, int y) {

            cout << "Sum of 2 integers : ";
            return x + y;
        }

        // different argument count...
        // sum of 3 integers...
        int sum(int x, int y, int z) {

            cout << "Sum of 3 integers : ";
            return x + y + z;
        }

        // different argument type...
        // sum of 2 doubles...
        double sum(double x, double y) {

            cout << "Sum of 2 doubles : ";
            return x + y;
        }
};

int main() {

    // creation of an object...
    Add add;

    int a = 5, b = 8, c = 10;
    double e = 3.5, f = 9.3;

    cout << add.sum(a, b) << endl;
    cout << add.sum(a, b, c) << endl;
    cout << add.sum(e, f) << endl;

    return 0;
}