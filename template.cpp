#include <iostream>
#include <string>

using namespace std;

const string inputT[] = {
""
};

const string inputA[] = {
""
};

const string inputB[] = {
""
};


auto &input = inputT;
auto sizeofinput = sizeof(input) / sizeof(input[0]);

int main(int, char**) {
    cout << "sizeofinput: " << sizeofinput << endl;
    int resultA = 0;
    int resultB = 0;

    for ( auto elem : input )
    {
    }

    cout << "Result A: " << resultA << endl;
    cout << "Result B: " << resultB << endl;

    return 0;
}
