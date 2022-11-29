#include <iostream>
#include <string>
#include <cassert>

using namespace std;

const string inputT[][6] = {
"Butterscotch", "-1", "-2", "6", "3", "8",
"Cinnamon", "2", "3", "-2", "-1", "3"
};

const string inputA[][6] = {
"Sprinkles", "5", "-1", "0", "0", "5",
"PeanutButter", "-1", "3", "0", "0", "1",
"Frosting", "0", "-1", "4", "0", "6",
"Sugar", "-1", "0", "0", "2", "8"
};

const string inputB[][6] = {
""
};

auto &input = inputA;

long resultA = 0;
long resultB = 0;

auto const numofinput = sizeof(input) / sizeof(input[0]);

void addSpoon( int elem, int size, int remaining )
{
    static long cap=0, dur=0, fla=0, tex=0, cal=0;
    if ( 100 == remaining)
    {
        cap=0; dur=0; fla=0; tex=0; cal=0;
    }

    //cout << input[elem][0] << "(" << size << ") ";

    cap += size * stoi(input[elem][1]);
    dur += size * stoi(input[elem][2]);
    fla += size * stoi(input[elem][3]);
    tex += size * stoi(input[elem][4]);
    cal += size * stoi(input[elem][5]);

    ++elem;

    if ( elem < numofinput-1 )
    {
        for ( int i=0; i<=remaining-size; ++i )
            addSpoon ( elem, i, remaining-size );
    } 
    else if ( elem == numofinput-1 )
    {
        addSpoon ( elem, remaining-size, remaining-size );
    }
    else
    {
        assert ( 0 == remaining-size );

        int result = (cap<0 ? 0 : cap) * (dur<0 ? 0 : dur) * (fla<0 ? 0 : fla) * (tex<0 ? 0 : tex);
        if (result > resultA )
            resultA = result;    
        
        if (result > resultB && 500 == cal)
            resultB = result;    

        //cout << result << endl;   
    }

    --elem;

    cap -= size * stoi(input[elem][1]);
    dur -= size * stoi(input[elem][2]);
    fla -= size * stoi(input[elem][3]);
    tex -= size * stoi(input[elem][4]);
    cal -= size * stoi(input[elem][5]);
}

int main(int, char**) {

    for ( int i=0; i<=100; ++i )
        addSpoon(0, i, 100);

    for ( auto elem : input )
    {
    }

    cout << "Result A: " << resultA << endl;
    cout << "Result B: " << resultB << endl;

    return 0;
}
