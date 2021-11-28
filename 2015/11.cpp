#include <iostream>
#include <string>

using namespace std;

string getnextpw(string pw)
{
    bool change = true;
    uint8_t pos = 7;

    while ( change )
    {
        ++pw[pos];
        if ( '{' == pw[pos] )
        {
            pw[pos] = 'a';
            pos--;
        } else {
            change = false;
        }
    }

    return pw;
}

bool checkvalidpw ( const string &pw )
{
    for ( auto c : pw )
    {
        if ( 'i'==c || 'o'==c || 'l'==c )
            return false;
    }

    bool valid = false;
    for ( uint8_t i = 0; i<5; ++i )
    {
        if ( pw[i+2] == pw[i]+2 && pw[i+1] == pw[i]+1 )
            valid = true;
    }

    if ( !valid )
        return false;

    int paircount = 0;
    for ( uint8_t i = 0; i<7; ++i )
    {
        if ( pw[i]==pw[i+1] )
        {
            ++paircount;
            i+=1;
        }
    }

    return (paircount>=2);
}

int main(int, char**) {

    string password("cqjxxzaa");

    while ( !checkvalidpw(password) )
    {
        password = getnextpw ( password );
    }
    cout << "Next Password: " << password << endl;

    return 0;
}
