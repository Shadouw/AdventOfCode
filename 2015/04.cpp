#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include <openssl/md5.h>

using namespace std;

string getmd5 ( string secret, unsigned long number) {
    string secretnumber ( secret );
    secretnumber += to_string( number );

    static unsigned char md5_result[MD5_DIGEST_LENGTH];
    MD5((const unsigned char*)secretnumber.c_str(), secretnumber.length(), md5_result);

    stringstream retval;

    for ( auto c : md5_result )
    {
        retval << setfill('0') << std::setw(2) << std::hex << (unsigned int)c;
    }

    return retval.str();
}

int main(int, char**) {
    unsigned long counter = 0;

    while ( true )
    {
        string md5 = getmd5 ( "bgvyzdsv", counter);

        if ( string("000000") == md5.substr(0,6) )
        {
            cout << counter << ": " << md5 << endl;
            return 0;
        }

        ++counter;
    }

    return 0;
}
