#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "The first floor contains a hydrogen-compatible microchip and a lithium-compatible microchip.",
    "The second floor contains a hydrogen generator.",
    "The third floor contains a lithium generator.",
    "The fourth floor contains nothing relevant."};

const vector<string> inputData = {
    "The first floor contains a polonium generator, a thulium generator, a thulium-compatible microchip, a promethium generator, a ruthenium generator, a ruthenium-compatible microchip, a cobalt generator, and a cobalt-compatible microchip.",
    "The second floor contains a polonium-compatible microchip and a promethium-compatible microchip.",
    "The third floor contains nothing relevant.",
    "The fourth floor contains nothing relevant."};

class status
{
public:
    status(int _iteration) : iteration(_iteration)
    {
    }

    void parseline(string line)
    {
        int floor = 0;
        if ("The first floor contains" == line.substr(0, 24))
        {
            floor = 1;
            line = line.substr(24);
        }
        else if ("The second floor contains" == line.substr(0, 25))
        {
            floor = 2;
            line = line.substr(25);
        }
        else if ("The third floor contains" == line.substr(0, 24))
        {
            floor = 3;
            line = line.substr(24);
        }
        else if ("The fourth floor contains" == line.substr(0, 25))
        {
            floor = 4;
            line = line.substr(25);
        }
        else
            cout << "Unknown line: '" << line << "'" << endl;

        auto pos = line.find(" a ");
        while (string::npos != pos)
        {
            auto pos2 = line.find_first_of("- ", pos + 3);
            if (string::npos == pos2)
                cout << "Unexpected end of line: '" << line << "'";

            string element = line.substr(pos + 3, pos2 - (pos + 3));

            if ('-' == line[pos2])
                microchips[element] = floor;
            else
                generators[element] = floor;

            pos = line.find(" a ", pos2);
        }
    }

    /* From the description (https://adventofcode.com/2016/day/11)
     * The experimental RTGs have poor radiation containment, so they're dangerously radioactive.
     * The chips are prototypes and don't have normal radiation shielding,
     * but they do have the ability to generate an electromagnetic radiation shield when powered.
     * Unfortunately, they can only be powered by their corresponding RTG.
     * An RTG powering a microchip is still dangerous to other microchips.
     *
     * In other words, if a chip is ever left in the same area as another RTG,
     * and it's not connected to its own RTG, the chip will be fried.
     * Therefore, it is assumed that you will follow procedure and keep chips connected to their corresponding
     * RTG when they're in the same room, and away from other RTGs otherwise.
     */
    bool checkStatus()
    {
        for (auto mc : microchips)
        {
            bool owngenerator = false, othergenerator = false;
            int floor = mc.second;

            if (generators[mc.first] != floor)
                for (auto g : generators)
                    if (floor == g.second && g.first != mc.first)
                        return false;
        }

        return true;
    }

    bool checkAllOnFloor(int f)
    {
        for (auto mc : microchips)
            if (mc.second != f)
                return false;

        for (auto g : generators)
            if (g.second != f)
                return false;

        return true;
    }

    bool checkValidMove(const int targetfloor, bool chip1, string elem1, bool chip2, string elem2) const
    {
        if (4 < targetfloor)
            return false;
        if (1 > targetfloor)
            return false;
        if (abs(elevator - targetfloor) != 1)
            return false;

        if (elevator != (chip1 ? microchips : generators).at(elem1))
            return false;
        if (elevator != (chip2 ? microchips : generators).at(elem2))
            return false;

        return true;
    }

    bool Move(const int targetfloor, bool chip1, string elem1, bool chip2, string elem2)
    {
        (chip1 ? microchips : generators)[elem1] = targetfloor;
        (chip2 ? microchips : generators)[elem2] = targetfloor;
        elevator = targetfloor;

        return checkStatus();
    }

    bool operator==(const status &other) const {
        return generators == other.generators
            && microchips == other.microchips
            && elevator == other.elevator;
    }
    bool operator!=(const status &other) const { return !(*this == other); }

    friend std::ostream &operator<<(std::ostream &os, const status &rhs) {
        os << "Iteration: " << rhs.iteration << endl;

        for ( int e=4; e>=1; --e )
        {
            os << "F" << e << ": ";

            if (rhs.elevator == e ) 
                os << " E ";
            else
                os << "   ";

            os << "G: ";
            for ( auto g : rhs.generators )
                if (g.second==e)
                    os << g.first << " ";

            os << "M: ";
            for ( auto m : rhs.microchips )
                if (m.second==e)
                    os << m.first << " ";

            os << endl;
        }

        return os;
    }

    // Copy Constructor
    /*
    status(const status &stat) : generators(stat.generators),
                                 microchips(stat.microchips),
                                 iteration(stat.iteration),
                                 elevator(stat.elevator)
    {
    }
    */

private:
    map<string, int> generators;
    map<string, int> microchips;

    int iteration;
    int elevator = 1;

    friend class RadioisotopeThermoelectricGenerators;
};

class RadioisotopeThermoelectricGenerators
{
public:
    RadioisotopeThermoelectricGenerators(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        status initstatus(0);

        // Parse data
        for (auto elem : input)
            initstatus.parseline(elem);

        stati.push_back(initstatus);
    }

    bool checkIfStatusExists(const status &s)
    {
        for ( auto e : oldstati )
            if ( s == e )
                return true;

        for ( auto e : stati )
            if ( s == e )
                return true;

        return false;        
    }

    long getResultA()
    {
        long resultA = 0;
        long currentIteration = 0;

        while (0 == resultA)
        {
            const status firststatus = stati.front();
            stati.erase(stati.begin());
            oldstati.push_back(firststatus);

            if ( firststatus.iteration != currentIteration)
            {
                currentIteration = firststatus.iteration;
                cout << "Iteration: " << currentIteration << " Size: " << oldstati.size() << endl;
            }

            for (int e = firststatus.elevator - 1; e <= firststatus.elevator + 1; e += 2)
            {
                if (0 < e && e <= 4)
                {
                    for (auto c1 : firststatus.microchips)
                        for (auto c2 : firststatus.microchips)
                            if (firststatus.checkValidMove(e, true, c1.first, true, c2.first))
                            {
                                status newstatus(firststatus);
                                ++newstatus.iteration;
                                if (newstatus.Move(e, true, c1.first, true, c2.first))
                                {
                                    if ( !checkIfStatusExists(newstatus) )
                                    {
                                        stati.push_back(newstatus);
                                        //cout << newstatus << endl;
                                        if (newstatus.checkAllOnFloor(4))
                                        {
                                            // Check if we already had this status
                                            resultA = newstatus.iteration;
                                            break;
                                        }
                                    }
                                }
                            }

                    for (auto g1 : firststatus.generators)
                        for (auto g2 : firststatus.generators)
                            if (firststatus.checkValidMove(e, false, g1.first, false, g2.first))
                            {
                                status newstatus(firststatus);
                                ++newstatus.iteration;
                                if (newstatus.Move(e, false, g1.first, false, g2.first))
                                {
                                    if ( !checkIfStatusExists(newstatus) )
                                    {
                                        stati.push_back(newstatus);
                                        //cout << newstatus << endl;
                                        if (newstatus.checkAllOnFloor(4))
                                        {
                                            // Check if we already had this status
                                            resultA = newstatus.iteration;
                                            break;
                                        }
                                    }
                                }
                            }

                    for (auto c1 : firststatus.microchips)
                        for (auto g2 : firststatus.generators)
                            if (firststatus.checkValidMove(e, true, c1.first, false, g2.first))
                            {
                                status newstatus(firststatus);
                                ++newstatus.iteration;
                                if (newstatus.Move(e, true, c1.first, false, g2.first))
                                {
                                    if ( !checkIfStatusExists(newstatus) )
                                    {
                                        stati.push_back(newstatus);
                                        //cout << newstatus << endl;
                                        if (newstatus.checkAllOnFloor(4))
                                        {
                                            // Check if we already had this status
                                            resultA = newstatus.iteration;
                                            break;
                                        }
                                    }
                                }
                            }
                }
            }
        }

        cout << "resultA: " << resultA << endl;
        return resultA;
    }
    long getResultB()
    {
        long resultB = 0;
        // for (auto e : stati)
        //     resultB += e.getResultB();

        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    vector<status> stati;
    vector<status> oldstati;
};

TEST_CASE("Testdata")
{
    RadioisotopeThermoelectricGenerators RadioisotopeThermoelectricGeneratorsData(inputTestdata);
    REQUIRE(11 == RadioisotopeThermoelectricGeneratorsData.getResultA());
    REQUIRE(0 == RadioisotopeThermoelectricGeneratorsData.getResultB());
}

TEST_CASE("RadioisotopeThermoelectricGenerators")
{
    RadioisotopeThermoelectricGenerators RadioisotopeThermoelectricGeneratorsData(inputData);
    REQUIRE(0 == RadioisotopeThermoelectricGeneratorsData.getResultA());
    REQUIRE(0 == RadioisotopeThermoelectricGeneratorsData.getResultB());
}