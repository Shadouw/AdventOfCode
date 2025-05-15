#include <aoc.h>

using namespace std;
using namespace aoc;

class ProgramAlarm {
public:
    ProgramAlarm(string _file, string _extension)
        : datafile(_file, _extension)
    {
        assert(1 == datafile.getYSize());
        program = stringtolongvector(datafile.getLines()[0], ',');
    }

    void fix1202()
    {
        program[1] = 12;
        program[2] = 2;
    }

    long runProgram()
    {
        auto tempprog = program;
        long pc = 0;
        long opcode = -1;

        while (99 != opcode) {
            opcode = tempprog[pc];
            switch (opcode) {
            case 1:
                tempprog[tempprog[pc + 3]] = tempprog[tempprog[pc + 2]] + tempprog[tempprog[pc + 1]];
                break;
            case 2:
                tempprog[tempprog[pc + 3]] = tempprog[tempprog[pc + 2]] * tempprog[tempprog[pc + 1]];
                break;
            case 99:
                break;
            default:
                cout << "Wrong op code: " << opcode << endl;
            }
            pc += 4;
        }
        return tempprog[0];
    }

    long searchVerbAndNoun()
    {
        for ( long verb = 0; verb <=99;++verb)
        {
            for ( long noun = 0; noun <=99;++noun)
            {
                program[1] = noun;
                program[2] = verb;

                if ( 19690720==runProgram() )
                {
                    return 100 * noun + verb;
                }
            }
        }

        return -1;
    }

private:
    aocdatafile datafile;
    vector<long> program;
};

TEST_CASE("Testdata")
{
    ProgramAlarm ProgramAlarmData(__FILE__, "example");
    REQUIRE(3500 == ProgramAlarmData.runProgram());
    //REQUIRE(0 == ProgramAlarmData.searchVerbAndNoun());
}

TEST_CASE("ProgramAlarm")
{
    ProgramAlarm ProgramAlarmData(__FILE__, "mydata");
    ProgramAlarmData.fix1202();
    REQUIRE(4484226 == ProgramAlarmData.runProgram());

    // Just to ensure: It's unmodified!
    REQUIRE(4484226 == ProgramAlarmData.runProgram());
    REQUIRE(5696== ProgramAlarmData.searchVerbAndNoun());
}