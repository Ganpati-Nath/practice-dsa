#include<iostream>
#include<string>

using namespace std;

class Vehicle {
    protected:
        string name;
        string model;
        int noOfTyres;

    public:


        Vehicle(string _name, string _model, int _noOfTyres) {
            cout << "I'm inside Vehicle ctor..." << endl;
            this->name = _name;
            this->model = _model;
            this->noOfTyres = _noOfTyres;
        }

    public:
        void start_engine() {

            cout << "Engine is starting " << name << " " << model << endl;
        }

        void stop_engine() {

            cout << "Engine is stopping " << name << " " << model << endl;
        }
};

class Car : public Vehicle {
    protected:
        int noOfDoors;
        string transmissionType;

    public:

        Car(string _name, string _model, int _noOfTyres, int _noOfDoors, string _transmissionType):Vehicle(_name, _model, _noOfTyres) {
            cout << "I'm inside Car ctor..." << endl;
            this->noOfDoors = _noOfDoors;
            this->transmissionType = _transmissionType;
        }

        void startAC() {

            cout << "AC has started of " << name << endl;
        }
        
};

class Motorcycle : public Vehicle {
    protected:
        string handleBarStyle;
        string suspensionType;

    public:
        Motorcycle(string _name, string _model, int _noOfTyres, string _handleBarStyle, string _suspensionType):Vehicle(_name, _model, _noOfTyres) {
            cout << "I'm inside Motorcycle ctor..." << endl;
            this->handleBarStyle = _handleBarStyle;
            this->suspensionType = _suspensionType;
        }

        void wheelie() {

            cout << "wheelie kr rhi h " << name << endl;
        }
};

int main() {

    Car A("Maruti 800", "LXI", 4, 4, "Manual");
    A.start_engine();
    A.startAC();
    A.stop_engine();
    // A.name; // inaccessible...

    // Vehicle v;
    // v.name; // inaccessible...
    Motorcycle M("BMW", "VXI", 2, "U", "Hard");
    M.start_engine();
    M.wheelie();
    M.stop_engine();

    return 0;
}