#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>

using namespace std;

string lockandsay( const string &input )
{
    stringstream retval;
    uint16_t counter = 0;
    char oldc = input[0];

    for ( auto c : input )
    {
        if ( oldc == c )
            ++counter;
        else
        {
            retval << counter << oldc;
            oldc = c;
            counter = 1;
        }
    }

    retval << counter << oldc;

    return retval.str();
}


int main(int, char**) {

    //string input("1");
    string input("3113322113");

    for ( int i = 1; i<=50; ++i )
    {
        input = lockandsay ( input );
        cout << i << ". (" << input.length() << "): " << endl;
    }

    return 0;
}
