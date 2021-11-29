#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

set<string> names;
map<pair<string,string>, int> happiness;
vector<string> table;

const string inputT[][3] = {
    "Alice", "+54", "Bob",
    "Alice", "-79", "Carol",
    "Alice", "-2", "David",
    "Bob", "+83", "Alice",
    "Bob", "-7", "Carol",
    "Bob", "-63", "David",
    "Carol", "-62", "Alice",
    "Carol", "+60", "Bob",
    "Carol", "+55", "David",
    "David", "+46", "Alice",
    "David", "-7", "Bob",
    "David", "+41", "Carol"
};

const string inputA[][3] = {
    "Alice", "+54", "Bob",
    "Alice", "-81", "Carol",
    "Alice", "-42", "David",
    "Alice", "+89", "Eric",
    "Alice", "-89", "Frank",
    "Alice", "+97", "George",
    "Alice", "-94", "Mallory",
    "Bob", "+3", "Alice",
    "Bob", "-70", "Carol",
    "Bob", "-31", "David",
    "Bob", "+72", "Eric",
    "Bob", "-25", "Frank",
    "Bob", "-95", "George",
    "Bob", "+11", "Mallory",
    "Carol", "-83", "Alice",
    "Carol", "+8", "Bob",
    "Carol", "+35", "David",
    "Carol", "+10", "Eric",
    "Carol", "+61", "Frank",
    "Carol", "+10", "George",
    "Carol", "+29", "Mallory",
    "David", "+67", "Alice",
    "David", "+25", "Bob",
    "David", "+48", "Carol",
    "David", "-65", "Eric",
    "David", "+8", "Frank",
    "David", "+84", "George",
    "David", "+9", "Mallory",
    "Eric", "-51", "Alice",
    "Eric", "-39", "Bob",
    "Eric", "+84", "Carol",
    "Eric", "-98", "David",
    "Eric", "-20", "Frank",
    "Eric", "-6", "George",
    "Eric", "+60", "Mallory",
    "Frank", "+51", "Alice",
    "Frank", "+79", "Bob",
    "Frank", "+88", "Carol",
    "Frank", "+33", "David",
    "Frank", "+43", "Eric",
    "Frank", "+77", "George",
    "Frank", "-3", "Mallory",
    "George", "-14", "Alice",
    "George", "-12", "Bob",
    "George", "-52", "Carol",
    "George", "+14", "David",
    "George", "-62", "Eric",
    "George", "-18", "Frank",
    "George", "-17", "Mallory",
    "Mallory", "-36", "Alice",
    "Mallory", "+76", "Bob",
    "Mallory", "-34", "Carol",
    "Mallory", "+37", "David",
    "Mallory", "+40", "Eric",
    "Mallory", "+18", "Frank",
    "Mallory", "+7", "George"
};

const string inputB[][3] = {
    "Alice", "+54", "Bob",
    "Alice", "-81", "Carol",
    "Alice", "-42", "David",
    "Alice", "+89", "Eric",
    "Alice", "-89", "Frank",
    "Alice", "+97", "George",
    "Alice", "-94", "Mallory",
    "Alice", "0", "MySelf",
    "Bob", "+3", "Alice",
    "Bob", "-70", "Carol",
    "Bob", "-31", "David",
    "Bob", "+72", "Eric",
    "Bob", "-25", "Frank",
    "Bob", "-95", "George",
    "Bob", "+11", "Mallory",
    "Bob", "0", "MySelf",
    "Carol", "-83", "Alice",
    "Carol", "+8", "Bob",
    "Carol", "+35", "David",
    "Carol", "+10", "Eric",
    "Carol", "+61", "Frank",
    "Carol", "+10", "George",
    "Carol", "+29", "Mallory",
    "Carol", "0", "MySelf",
    "David", "+67", "Alice",
    "David", "+25", "Bob",
    "David", "+48", "Carol",
    "David", "-65", "Eric",
    "David", "+8", "Frank",
    "David", "+84", "George",
    "David", "+9", "Mallory",
    "David", "0", "MySelf",
    "Eric", "-51", "Alice",
    "Eric", "-39", "Bob",
    "Eric", "+84", "Carol",
    "Eric", "-98", "David",
    "Eric", "-20", "Frank",
    "Eric", "-6", "George",
    "Eric", "+60", "Mallory",
    "Eric", "0", "MySelf",
    "Frank", "+51", "Alice",
    "Frank", "+79", "Bob",
    "Frank", "+88", "Carol",
    "Frank", "+33", "David",
    "Frank", "+43", "Eric",
    "Frank", "+77", "George",
    "Frank", "-3", "Mallory",
    "Frank", "0", "MySelf",
    "George", "-14", "Alice",
    "George", "-12", "Bob",
    "George", "-52", "Carol",
    "George", "+14", "David",
    "George", "-62", "Eric",
    "George", "-18", "Frank",
    "George", "-17", "Mallory",
    "George", "0", "MySelf",
    "Mallory", "-36", "Alice",
    "Mallory", "+76", "Bob",
    "Mallory", "-34", "Carol",
    "Mallory", "+37", "David",
    "Mallory", "+40", "Eric",
    "Mallory", "+18", "Frank",
    "Mallory", "+7", "George",
    "Mallory", "0", "MySelf",
    "MySelf", "0", "Alice",
    "MySelf", "0", "Bob",
    "MySelf", "0", "Carol",
    "MySelf", "0", "David",
    "MySelf", "0", "Eric",
    "MySelf", "0", "Frank",
    "MySelf", "0", "George",
    "MySelf", "0", "Mallory"
};

auto &input = inputB;

void nextStep ( const string &lastname )
{
    static int maxhappiness = 0;
    if ( table.size() == names.size() )
    {
        /*
        if ( distance < mindistance )
        {
            cout << "Minimal Distance: ";
            for ( auto city : route) 
            {
                cout << city << " ";
            }
            cout << distance << endl;
            mindistance = distance;
        }

        if ( maxdistance < distance )
        {
            cout << "Maximal Distance: ";
            for ( auto city : route) 
            {
                cout << city << " ";
            }
            cout << distance << endl;
            maxdistance = distance;
        }
        */
        int tablehappiness = happiness[make_pair(table[0], table[table.size()-1])] + 
                             happiness[make_pair(table[table.size()-1], table[0])];

        for ( int i=0; i<table.size()-1; ++i )
        {
            tablehappiness += happiness[make_pair(table[i], table[i+1])] + 
                              happiness[make_pair(table[i+1], table[i])];
        }   

        if ( tablehappiness > maxhappiness )
        {
            for ( int i=0; i<table.size(); ++i )    
            {
                if ( 0 == i )
                {
                    cout << happiness[make_pair(table[i], table[table.size()-1])] << " ";
                }
                cout << table[i] << " ";
                if ( i<table.size()-1 )
                {
                    cout << happiness[make_pair(table[i], table[i+1])] << " ";
                    cout << happiness[make_pair(table[i+1], table[i])] << " ";
                } else {
                    cout << happiness[make_pair(table[i], table[0])] << " ";
                    
                }
            }

            cout << "(" << tablehappiness << ")" << endl;

            maxhappiness = tablehappiness;
        }
        return;
    }

    for ( auto name : names )
    {
        if ( find(table.begin(), table.end(), name) == table.end() )
        {
            table.push_back(name);
            nextStep ( name );
            table.pop_back();
        }
    }
}

int main(int, char**) {

    int resultA = 0;
    int resultB = 0;

    for ( auto elem : input )
    {
        names.insert(elem[0]);
        names.insert(elem[2]);

        happiness[make_pair(elem[0], elem[2])] = stoi(elem[1]);
    }    

    cout << "Number of names: " << names.size() << endl;
    for ( auto name : names )
        cout << name << endl;

    for ( auto name : names )
    {
        table.clear();
        table.push_back(name);

        nextStep ( name );
    }

    cout << "Result A: " << resultA << endl;
    cout << "Result B: " << resultB << endl;

    return 0;
}
