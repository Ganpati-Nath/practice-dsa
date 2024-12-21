#include<iostream>
#include<string>

using namespace std;

// class is a keyword for defining a class or template or blueprint...
class Student {

    // publically accesible...
    private:

        // attributes...
        int id;
        int age;
        string name;
        int nos;
        float* gpa;
        string gf;

        // default ctor/constructor...
        // Student() {

        //     cout << this->name << " Student default ctor called..." << endl;
        // };

    public:

        void setGPA (float a) {

            *this->gpa = a;
        }

        float getGPA() const {

            return *this->gpa;
        }

        int getAge() const {

            return this->age;
        }

        // parameterised ctor...
        Student(int id, int age, string name, int nos, float gpa, string gf) {

            cout << this->name << " Student parameterised ctor called..." << endl;
            this->id = id;
            this->age = age;
            this->name = name;
            this->nos = nos;
            this->gpa = new float(gpa);
            this->gf = gf;            
        }

        // copy ctor...
        // Student(const Student &srcObj) {

        //     cout << " Student copy ctor called..." << endl;
        //     this->id = srcObj.id;
        //     this->age = srcObj.age;
        //     this->name = srcObj.name;
        //     this->nos = srcObj.nos;
        // }

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
        }

    private:

        void gfChatting() {

            cout << " Chatting with gf..." << endl;
        }

};

int main() {

    Student A(1, 15, "Ranu", 6, 9.8, "Meena");
    cout << A.getGPA() << endl;
    A.setGPA(8.6);
    cout << A.getGPA() << endl;
    cout << A.getAge() << endl;
    return 0;
}