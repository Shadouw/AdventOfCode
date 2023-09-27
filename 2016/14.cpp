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
        cout << "Size of salt: " << salt.size() << endl;
    }

    string gethash(unsigned long c)
    {
            string md5hex(salt + to_string(c));
            return getmd5hexhash(md5hex);
    }

    void getFive()
    {
        bool searching = true;
        while (searching)
        {
            string md5hash = gethash(counter++);

            for (int i = 0; i < md5hash.size() - 2; ++i)
                if (md5hash[i] == md5hash[i + 1] && md5hash[i] == md5hash[i + 2])
                // if (i == md5hash.size() - 4 || md5hash[i] != md5hash[i + 3])
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
                    // if (i == md5hash.size() - 6 || md5hash[i] != md5hash[i + 5])
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

    long getResultA()
    {
        while (keys.size() < 64)
        {
            getFive();
            confirmKeys();
        }

        unsigned long c = 0;
        long resultA=0;
        for (const auto &elem : keys)
        {
            if (c++ == 63)
            {
                resultA = elem;
                break;
            }
        }

        /* cout << "Print the shit: " << endl;
        for (auto key3 : keythree)
        {
            cout << key3.first << endl;
            for (auto elem : key3.second)
                cout << elem << ", ";
            cout << endl
                 << endl;
            for (auto elem : keyfive[key3.first])
                cout << elem << ", ";
            cout << endl;
        } */

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const string salt;
    unsigned long counter = 0;
    map<char, set<unsigned long>> keythree;
    map<char, set<unsigned long>> keyfive;
    set<unsigned long> keys;
};

TEST_CASE("Testdata")
{
    OneTimePad OneTimePadData("abc");
    REQUIRE(22728 == OneTimePadData.getResultA());
    REQUIRE(0 == OneTimePadData.getResultB());
}

TEST_CASE("OneTimePad")
{
    OneTimePad OneTimePadData("ahsbgdzn");
    REQUIRE(23890 == OneTimePadData.getResultA());
    REQUIRE(0 == OneTimePadData.getResultB());
}
