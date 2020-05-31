#include <string>
#include "Timer.h"
#include <vector>

using namespace std;

void myFunc(){
    Timer("myFunc");

    int value = 0;

    for (size_t i = 0; i < 1000; i++)
        value += i;
}

int main(){
    myFunc();

    {
        Timer("Scope");
        vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

        for (const string& word : msg)
        {
            cout << word << " ";
        }
    }
    cout << endl;
    return 0;
}