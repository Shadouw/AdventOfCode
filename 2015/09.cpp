#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const string inputT[][3] = {
    "London", "Dublin", "464",
    "London", "Belfast", "518",
    "Dublin", "Belfast", "141"
};

const string inputA[][3] = {
    "Tristram", "AlphaCentauri", "34",
    "Tristram", "Snowdin", "100",
    "Tristram", "Tambi", "63",
    "Tristram", "Faerun", "108",
    "Tristram", "Norrath", "111",
    "Tristram", "Straylight", "89",
    "Tristram", "Arbre", "132",
    "AlphaCentauri", "Snowdin", "4",
    "AlphaCentauri", "Tambi", "79",
    "AlphaCentauri", "Faerun", "44",
    "AlphaCentauri", "Norrath", "147",
    "AlphaCentauri", "Straylight", "133",
    "AlphaCentauri", "Arbre", "74",
    "Snowdin", "Tambi", "105",
    "Snowdin", "Faerun", "95",
    "Snowdin", "Norrath", "48",
    "Snowdin", "Straylight", "88",
    "Snowdin", "Arbre", "7",
    "Tambi", "Faerun", "68",
    "Tambi", "Norrath", "134",
    "Tambi", "Straylight", "107",
    "Tambi", "Arbre", "40",
    "Faerun", "Norrath", "11",
    "Faerun", "Straylight", "66",
    "Faerun", "Arbre", "144",
    "Norrath", "Straylight", "115",
    "Norrath", "Arbre", "135",
    "Straylight", "Arbre", "127"
};

const string inputB[][3] = {
""
};

set<string> cities;
map<pair<string,string>, uint32_t> distances;
vector<string> route;
uint32_t mindistance = -1;
uint32_t maxdistance = 0;


auto &input = inputA;

void nextStep ( const string &lastcity, uint32_t distance )
{
    if ( route.size() == cities.size() )
    {
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
        return;
    }

    for ( auto city : cities )
    {
        if ( find(route.begin(), route.end(), city) == route.end() )
        {
            route.push_back(city);
            nextStep ( city, distance + distances[make_pair(lastcity, city)] );
            route.pop_back();
        }
    }
}

int main(int, char**) {

    int resultA = 0;
    int resultB = 0;

    for ( auto elem : input )
    {
        cities.insert(elem[0]);
        cities.insert(elem[1]);

        distances[make_pair(elem[0], elem[1])] = stoi(elem[2]);
        distances[make_pair(elem[1], elem[0])] = stoi(elem[2]);
    }

    cout << "Number of cities: " << cities.size() << endl;

    for ( auto city : cities )
    {
        route.clear();
        route.push_back(city);

        nextStep ( city, 0 );
    }

    cout << "Result A: " << resultA << endl;
    cout << "Result B: " << resultB << endl;

    return 0;
}
