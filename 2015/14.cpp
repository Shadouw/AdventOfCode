#include <iostream>
#include <string>
#include <map>

using namespace std;

const string inputT[][4] = {
    "Comet", "14", "10", "127",
    "Dancer", "16", "11", "162"
};

const string inputA[][4] = {
    "Dancer", "27", "5", "132",
    "Cupid", "22", "2", "41",
    "Rudolph", "11", "5", "48",
    "Donner", "28", "5", "134",
    "Dasher", "4", "16", "55",
    "Blitzen", "14", "3", "38",
    "Prancer", "3", "21", "40",
    "Comet", "18", "6", "103",
    "Vixen", "18", "5", "84"
};

const string inputB[] = {
""
};

uint32_t getDistance ( string Reindeer, uint32_t kms, uint32_t flysec, uint32_t restsec, uint32_t totalsec )
{
    uint32_t period = flysec + restsec; 
    uint32_t numperiods = totalsec / period;
    uint32_t remainingperiodtime = totalsec % period;

    uint32_t retval =  numperiods * kms * flysec + ( remainingperiodtime > flysec ? kms * flysec : kms * remainingperiodtime );

    return retval;
}


auto &input = inputA;

int main(int, char**) {

    int resultA = 0;
    int resultB = 0;

    const uint32_t ttime = 2503;

    for ( auto elem : input )
    {
        uint32_t distance = getDistance ( elem[0], stoi(elem[1]), stoi(elem[2]), stoi(elem[3]), ttime );
        cout << elem[0] << ": " << distance << endl;

        if ( distance > resultA )
            resultA = distance;
    }

    map<string,uint32_t> points;
    for ( int i=1; i<=ttime; ++i )
    {
        uint32_t maxdistance = 0;

        for ( auto elem : input )
        {
            uint32_t distance = getDistance ( elem[0], stoi(elem[1]), stoi(elem[2]), stoi(elem[3]), i );
            if ( distance > maxdistance )
            {
                maxdistance = distance;
            }
        }
        for ( auto elem : input )
        {
            uint32_t distance = getDistance ( elem[0], stoi(elem[1]), stoi(elem[2]), stoi(elem[3]), i );
            if ( distance == maxdistance )
            {
                ++points[elem[0]];
            }
        }
    }

    for ( auto elem : points )
    {
        if ( elem.second > resultB )
            resultB = elem.second;
    }

    cout << "Result A: " << resultA << endl;
    cout << "Result B: " << resultB << endl;

    return 0;
}
