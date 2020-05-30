#include <string>
#include "Timer.h"

void myFunc(){
    Timer("myFunc");

    int value = 0;

    for (size_t i = 0; i < 10000; i++)
        value += 2;
}

int main(){
    myFunc();
    return 0;
}