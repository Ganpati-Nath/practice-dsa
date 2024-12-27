#include <iostream>
#include "bird.h"

using namespace std;

void birdBehaveSomething(Bird *&bird) {
    bird->eat();
    bird->fly();
    bird->eat();
}

int main() {

    Bird *b = new eagle();
    birdBehaveSomething(b);

    return 0;
}