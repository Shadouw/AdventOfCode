#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <set>

#include <catch2/catch_test_macros.hpp>

#include <aocmd5.h>

using namespace std;

class OneTimePad
{
public:
    OneTimePad(const string &_salt) : salt(_salt)
    {
    }

    string gethash(unsigned long c)
    {
            string md5hex(salt + to_string(c));
            return getmd5hexhash(md5hex);
    }

    string getStretchedHash(string hash)
    {
        for ( int i=0; i<2016; ++i )
            hash = getmd5hexhash(hash);

        return hash;
    }

    void getFive(bool stretch)
    {
        bool searching = true;
        while (searching)
        {
            string md5hash = gethash(counter++);
            if ( stretch )
                md5hash = getStretchedHash(md5hash);

            for (int i = 0; i < md5hash.size() - 2; ++i)
                if (md5hash[i] == md5hash[i + 1] && md5hash[i] == md5hash[i + 2])
                {
                    keythree[md5hash[i]].insert(counter - 1);
                    break;
                }

            for (int i = 0; i < md5hash.size() - 4; ++i)
                if (md5hash[i] == md5hash[i + 1] &&
                    md5hash[i] == md5hash[i + 2] &&
                    md5hash[i] == md5hash[i + 3] &&
                    md5hash[i] == md5hash[i + 4])
                {
                    {
                        keyfive[md5hash[i]].insert(counter - 1);
                        searching = false;
                    }
                }
        }
    }

    void confirmKeys()
    {
        for (const auto &key : keythree)
            for (const auto &index : key.second)
            {
                auto &key5 = keyfive[key.first];

                for (auto &index2 : key5)
                    if (index < index2 && index2 <= index + 1000)
                        keys.insert(index);
            }
    }

    long getResult(bool stretch)
    {
        while (keys.size() < 64)
        {
            getFive(stretch);
            confirmKeys();
        }

        unsigned long c = 0;
        long result=0;
        for (const auto &elem : keys)
        {
            if (c++ == 63)
            {
                result = elem;
                break;
            }
        }

        cout << "result: " << result << endl;
        return result;
    }

private:
    const string salt;
    unsigned long counter = 0;
    map<char, set<unsigned long>> keythree;
    map<char, set<unsigned long>> keyfive;
    set<unsigned long> keys;
};

TEST_CASE("TestdataA")
{
    OneTimePad OneTimePadData("abc");
    REQUIRE(22728 == OneTimePadData.getResult(false));
}

TEST_CASE("TestdataB")
{
    OneTimePad OneTimePadData("abc");
    REQUIRE(22551 == OneTimePadData.getResult(true));
}

TEST_CASE("OneTimePadA")
{
    OneTimePad OneTimePadData("ahsbgdzn");
    REQUIRE(23890 == OneTimePadData.getResult(false));
}

TEST_CASE("OneTimePadB")
{
    OneTimePad OneTimePadData("ahsbgdzn");
    REQUIRE(22696 == OneTimePadData.getResult(true));
}
