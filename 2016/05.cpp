#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include <aocmd5.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

string nexthash(const string doorid, unsigned long &startvalue, int &pos)
{
    while ( true )
    {
        string md5hex(doorid + to_string(startvalue));
        string md5hexresult = getmd5hexhash(md5hex);
        const char *md5hexarray = md5hexresult.c_str();

        //if ("00000" == md5hexresult.substr(0, 5))
        if ('0' == md5hexarray[0] &&
            '0' == md5hexarray[1] &&
            '0' == md5hexarray[2] &&
            '0' == md5hexarray[3] &&
            '0' == md5hexarray[4] )
        {
            if ( -1 == pos )
            {
                return md5hexresult.substr(5, 1);
            }
            else
            {
                if ('0' <= md5hexarray[5] && md5hexarray[5] <='7')
                {
                    pos = stoi(md5hexresult.substr(5, 1));
                    return md5hexresult.substr(6, 1);
                }
            } 
        }
        ++startvalue;
    }
    return ":-(";
}

string getpassword(const string doorid)
{
    unsigned long counter = 0;
    int pos = -1;
    string password(nexthash(doorid, counter,pos));

    for (int i = 0; i < 7; ++i)
    {
        password += nexthash(doorid, ++counter, pos);
    }

    return password;
}

string getpasswordB(const string doorid)
{
    unsigned long counter = 0;
    int pos = 1;
    char password[] = {'.', '.', '.', '.', '.', '.', '.', '.', 0};

    while ('.' == password[0] ||
           '.' == password[1] ||
           '.' == password[2] ||
           '.' == password[3] ||
           '.' == password[4] ||
           '.' == password[5] ||
           '.' == password[6] ||
           '.' == password[7])
    {
        string nh(nexthash(doorid, ++counter, pos));
        if ( '.' == password[pos] )
        {
            password[pos] = nh.c_str()[0];
            cout << password << endl;
        }
    }

    return password;
}

TEST_CASE("MD5 A")
{
    int pos = -1;

    REQUIRE("00000155f8105dff7f56ee10fa9b9abd" == getmd5hexhash("abc3231929"));
    unsigned long counter = 0;
    REQUIRE("1" == nexthash("abc", counter, pos));
    REQUIRE(3231929 == counter);
    REQUIRE("8" == nexthash("abc", ++counter, pos));
    REQUIRE(5017308 == counter);
    REQUIRE("f" == nexthash("abc", ++counter, pos));
    REQUIRE(5278568 == counter);

    REQUIRE("18f47a30" == getpassword("abc"));
}

TEST_CASE ( "Problem A" )
{
    REQUIRE("f77a0e6e" == getpassword("cxdnnyjw"));
}

TEST_CASE("MD5 B")
{
    int pos = 100;

    unsigned long counter = 0;
    REQUIRE("5" == nexthash("abc", counter, pos));
    REQUIRE(3231929 == counter);
    REQUIRE(1 == pos);

    REQUIRE("e" == nexthash("abc", ++counter, pos));
    REQUIRE(5357525 == counter);
    REQUIRE(4 == pos);

    REQUIRE("05ace8e3" == getpasswordB("abc"));
}

TEST_CASE("Problem B")
{
    REQUIRE("999828ec" == getpasswordB("cxdnnyjw"));
}