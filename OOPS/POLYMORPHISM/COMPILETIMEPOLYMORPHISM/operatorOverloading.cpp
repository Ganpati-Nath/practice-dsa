#include<iostream>
#include<string>

using namespace std;

class Complex {

    public:
        int real; // for real part...
        int imag; // for imaginary part...

        // default constructor...
        Complex() {

            real = imag = -1; // not valid...
        }

        // parameterised constructor...
        Complex(int r, int i) : real(r), imag(i) {
                                        }; // initialization list...

        void print() {
            // printing complex no...
            printf("[%d + i%d]\n", this->real, this->imag);
        }

        // operator overloading...
        Complex operator + (const Complex &B) {
            Complex C;
            C.real = this->real + B.real;
            C.imag = this->imag + B.imag;

            return C;
        }

        // operator overloading...
        bool operator == (const Complex &B) {

            return (this->real == B.real) && (this->imag == B.imag);
        }


};

int main() {

    Complex A(3, 3);
    A.print();

    Complex B(3, 3);
    B.print();

    Complex C;
    C = A + B;
    C.print();

    bool check = (A == B);
    cout << check << endl;;

    return 0;
}