#include<iostream>
#include<string>

using namespace std;

class Shape {

    public:

        virtual void draw() {

            cout << "Generic shape..." << endl;
        }
};

class Circle : public Shape {

    public:

        void draw() override {

            cout << "Circle..." << endl;
        }
};

class Rectangle : public Shape {

    public:

        void draw() override {

            cout << "Rectangle..." << endl;
        }
};

class Triangle : public Shape {

    public:

        void draw() override {

            cout << "Triangle..." << endl;
        }
};

void shapeDraw(Shape *s) {
    s->draw();
}

int main() {

    Circle c;
    c.draw();

    Rectangle r;
    r.draw();

    Triangle *t = new Triangle(); // in heap...

    shapeDraw(&c);
    shapeDraw(&r);
    shapeDraw(t);

    return 0;
}