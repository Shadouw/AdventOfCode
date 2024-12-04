#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

using namespace std;

const int inputT[] = {20,15,10,5,5};
const int inputA[] = {43,3,4,10,21,44,4,6,47,41,34,17,17,44,36,31,46,9,27,38};

auto &input = inputA;
auto sizeofinput = sizeof(input)/sizeof(input[0]);

void nextContainer ( int remaining, int level, int &result, int &num, vector<int> &solution )
{
    static int minnum = INT8_MAX;

    if ( level < sizeofinput-1 )
    {
        for ( int i=0; i<=1; ++i )
        {
            if ( remaining - (input[level]*i) >= 0 )
            {
                solution.push_back(i);
                nextContainer ( remaining - (input[level]*i), level+1, result, num, solution );
                solution.pop_back();
            }
        }
    } else {
        if ( remaining == input[level] || 0 == remaining )
        {
            solution.push_back ( remaining / input[level] );
            ++result;

            int numofbin = 0;
            for ( auto elem : solution )
            {
                if ( 1 == elem )
                    ++numofbin;
                cout << elem << " ";
            }
            cout << endl;

            if ( numofbin < minnum )
            {
                minnum = numofbin;
                num = 1;
            } else if ( numofbin == minnum )
                ++num;

            solution.pop_back();
        }
    }
}

int main(int, char**) {

    int resultA = 0;
    int resultB = 0;

    vector<int> solution;

    nextContainer ( 150, 0, resultA, resultB, solution );

    for ( auto elem : input )
    {
        
    }

    cout << "Result A: " << resultA << endl;
    cout << "Result B: " << resultB << endl;

    return 0;
}
