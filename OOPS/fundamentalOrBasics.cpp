#include<iostream>
#include<string>

using namespace std;

// class is a keyword for defining a class or template or blueprint...
class Student {

    // publically accesible...
    public:

        // attributes...
        int id;
        int age;
        string name;
        int nos;
        float* gpa;

        // default ctor/constructor...
        // Student() {

        //     cout << this->name << " Student default ctor called..." << endl;
        // };

        // parameterised ctor...
        Student(int id, int age, string name, int nos, float gpa) {

            cout << this->name << " Student parameterised ctor called..." << endl;
            this->id = id;
            this->age = age;
            this->name = name;
            this->nos = nos;
            this->gpa = new float(gpa);            
        }

        // copy ctor...
        Student(const Student &srcObj) {

            cout << " Student copy ctor called..." << endl;
            this->id = srcObj.id;
            this->age = srcObj.age;
            this->name = srcObj.name;
            this->nos = srcObj.nos;
        };

        // behaviours...
        void study() {

            cout << this->name << " studying..." << endl;
        }

        void sleep() {

            cout << this->name << " sleeping..." << endl;
        }

        void bunk() {

            cout << this->name << " bunking..." << endl;
        }

        // dtor/destructor...
        ~Student() {

            cout << this->name << " Student default dtor called..." << endl;
            // deallocation...
            delete this->gpa;
        };
};

int main() {

    // Student A;
    // Student B;

    // naive approach...
    // A.id = 1;
    // A.age = 15;
    // A.name = "Ranu";
    // A.nos = 6;

    // A.study();

    // naive approach...
    // B.id = 2;
    // B.age = 15;
    // B.name = "Rahul";
    // B.nos = 5;

    // B.bunk();

    // static memory allocation... stack
    // Student A(1, 15, "Ranu", 6);
    // Student B(2, 13, "Rahul", 4);
    // Student C(3, 15, "Rena", 6);
    // Student D(4, 15, "Ronaldo", 6);

    // cout << A.name << "  " << A.age << endl;

    // A.bunk();
    // B.sleep();

    //copy ctor...
    // Student C = A;  // optional...
    // Student C(A);

    // cout << A.name << "   " << C.name << endl;

    // dynamic memory allocation... heap
    Student* A = new Student(1, 14, "Babbar", 7, 9.8);

    cout << A->name << "  " << A->age << "   " <<  *A->gpa << endl;
    // deallocation...
    delete A;
    return 0;
}