#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef unsigned int mytype;

const string inputT[] = {
""
};

const string inputA[] = {
""
};

mytype getNumberOfPresents(mytype housenumber)
{
    mytype retval = 0;

    for ( int i=1; i<=housenumber; ++i )
    {
        if ( 0 == (housenumber % i) )
            retval += i;
    }

    return retval * 10;
}

mytype getNumberof11Presents (mytype housenumber)
{
    mytype startingelf = ceil(double(housenumber)/50.0);

    mytype retval = 0;

    for ( int i=startingelf; i<=housenumber; ++i )
    {
        if ( 0 == (housenumber % i) )
            retval += i;
    }

    return retval * 11;
}
auto &input = inputT;

int main(int, char**) {

    mytype resultA = 770000; // Yeah I already found it, lets speed it up little bit ;-)
    mytype presentsA = 1;
    mytype resultB = 780000;
    mytype presentsB = 1;

    for ( int i=1; i<10; ++i )
        cout << i << " :" << getNumberOfPresents(i) << endl;

    // A
    presentsA = getNumberOfPresents(resultA);
    while (presentsA < 33100000)
    {
        ++resultA;
        presentsA = getNumberOfPresents(resultA);

        if ( 0 == (resultA%1000))
            cout << resultA << ": " << presentsA << endl;
    }

    cout << "Result A: " << resultA << endl;

    // B
    presentsB = getNumberof11Presents(resultB);
    while (presentsB < 33100000)
    {
        ++resultB;
        presentsB = getNumberof11Presents(resultB);

        if ( 0 == (resultB%1000))
            cout << resultB << ": " << presentsB << endl;
    }

    cout << "Result B: " << resultB << endl;

    return 0;
}
