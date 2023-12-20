#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#include <stringtovector.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata1 = {
    "broadcaster -> a, b, c",
    "%a -> b",
    "%b -> c",
    "%c -> inv",
    "&inv -> a"
};

const vector<string> inputTestdata2 = {
    "broadcaster -> a",
    "%a -> inv, con",
    "&inv -> b",
    "%b -> con",
    "&con -> output"
};

const vector<string> inputData = {
    "%jx -> rt, rs",
    "&cc -> cd, fc, qr, nl, gk, zr",
    "%qs -> cl, rs",
    "%zr -> cq",
    "%mx -> nr, pm",
    "%mj -> qr, cc",
    "%cj -> cc, nt",
    "%jv -> sp",
    "%dj -> bd, zc",
    "%kt -> lt",
    "broadcaster -> gz, xg, cd, sg",
    "&dn -> rx",
    "%br -> nf, bd",
    "%cd -> cc, nl",
    "%zc -> jq, bd",
    "%xg -> cf, pm",
    "%nz -> gm, bd",
    "&dd -> dn",
    "%nb -> sl",
    "&pm -> kt, xg, xp, jv, sp",
    "&fh -> dn",
    "%rt -> qq",
    "%qq -> rs, hd",
    "%hd -> qs, rs",
    "&xp -> dn",
    "%pj -> cc, mj",
    "%gz -> bd, kb",
    "%zd -> jv, pm",
    "%cq -> cj, cc",
    "%qr -> gk",
    "%ng -> jk, bd",
    "%kb -> bd, sv",
    "%cl -> zx, rs",
    "%gj -> zd, pm",
    "%sl -> kx",
    "%sv -> br",
    "%nf -> bd, nz",
    "%zx -> rs",
    "%nt -> mn, cc",
    "%rh -> nb, rs",
    "%gk -> ln",
    "&bd -> gm, gz, fh, sv",
    "%jq -> ng, bd",
    "%sp -> pc",
    "%sg -> rs, rh",
    "%kx -> jx",
    "&fc -> dn",
    "%cf -> gj, pm",
    "%pc -> kt, pm",
    "%jk -> bd",
    "%vf -> pm",
    "&rs -> sg, dd, sl, kx, nb, rt",
    "%nr -> vf, pm",
    "%ln -> zr, cc",
    "%lt -> pm, mx",
    "%gm -> dj",
    "%nl -> pj",
    "%mn -> cc"
};

class Pulse {
public:
    Pulse(string s, bool p, string t)
        : source(s)
        , pulse(p)
        , target(t)
    {
    }

    string source;
    bool pulse;
    string target;
};

/**
 * @brief Class "Module" wraps flip-flop and conjuctions
 *
 * %Flip-Flop:
 * - High Pulse: Ignored
 * - Low Pulse: Flips state
 *
 * &Conjunction:
 * - Remembers all most recent input states
 * - If all are high: send low. Otherwise send high.
 */
class Module {
public:
    Module() { }
    Module(const string _input)
        : input(_input)
    {
        string mod(input);
        if ('&' == mod[0] || '%' == mod[0]) {
            type = mod[0];
            mod = mod.substr(1);
        }

        auto pos = mod.find(" -> ");
        if (string::npos == pos)
            cout << "Unknown Module: " << input << endl;

        name = mod.substr(0, pos);
        vector<string> targets(stringtovector(mod.substr(pos + 4), ','));
        for (auto t : targets) {
            if (' ' == t[0])
                destinations.push_back(t.substr(1));
            else
                destinations.push_back(t);
        }
    }

    bool processPulse(Pulse p)
    {
        bool fired = false;
        switch (type) {
        case ' ': // Broadcaster
            state = p.pulse;
            fired = true;
            break;
        case '%': // Flip-Flop
            if (!p.pulse) {
                state = !state;
                fired = true;
            }
            break;
        case '&': // Conjunction
            inputs[p.source] = p.pulse;
            state = false;
            for (auto i : inputs)
                if (!i.second)
                    state = true;

            fired = true;
            break;
        default:
            break;
        }

        return fired;
    }

private:
    string input;

    /**
     * @brief false: low pulse, true: high pulse
     *
     */
    bool state = false;
    char type = ' ';

    string name;
    map<string, bool> inputs;
    vector<string> destinations;

    friend class PulsePropagation;
};

class PulsePropagation {
public:
    PulsePropagation(const vector<string>& _input)
        : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input) {
            Module t(elem);
            Modules[t.name] = Module(elem);
        }

        // Add the input states (default: low pulse)
        for (auto m : Modules) {
            for (auto t : m.second.destinations) {
                Modules[t].inputs[m.first] = false;
            }
        }
    }

    void processPulses()
    {
        while (Pulses.size()) {
            Pulse p = Pulses.front();
            Pulses.pop();

            if (p.pulse)
                ++highpulsecount;
            else {
                ++lowpulsecount;
                if ( "rx"== p.target)
                    lowtorx = true;
            }

            if (Modules[p.target].processPulse(p)) {
                p.source = p.target;
                p.pulse = Modules[p.target].state;
                for (auto m : Modules[p.source].destinations) {
                    p.target = m;
                    Pulses.push(p);
                }
            }
        }
    }

    void pushButton()
    {
        // Press the button
        Pulses.push(Pulse("button", false, "broadcaster"));
    }

    long getFlipFlopsOn()
    {
        long val = 0;
        for (auto m : Modules)
            if ('%' == m.second.type && true == m.second.state)
                ++val;

        return val;
    }

    void resetModuleStates(){
        for ( auto &m : Modules )
            m.second.state = false;

        lowpulsecount = 0;
        highpulsecount = 0;
        lowtorx = false;
    }

    long getResultA()
    {
        for (int i = 0; i < 1000; ++i) {
            pushButton();
            processPulses();
        }

        long resultA = lowpulsecount * highpulsecount;

        cout << "resultA: " << resultA << endl;
        return resultA;
    }

    long getResultB()
    {
        resetModuleStates();

        long resultB = 0;
        while ( !lowtorx )
        {
            pushButton();
            ++resultB;
            processPulses();
        }
        
        cout << "resultB: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    map<string, Module> Modules;
    queue<Pulse> Pulses;
    long lowpulsecount = 0;
    long highpulsecount = 0;
    bool lowtorx = false;
};

TEST_CASE("Testdata1")
{
    PulsePropagation PulsePropagationData(inputTestdata1);
    PulsePropagationData.pushButton();
    PulsePropagationData.processPulses();
    REQUIRE(0 == PulsePropagationData.getFlipFlopsOn());
}

TEST_CASE("Testdata2")
{
    PulsePropagation PulsePropagationData(inputTestdata2);
    PulsePropagationData.pushButton();
    PulsePropagationData.processPulses();
    REQUIRE(2 == PulsePropagationData.getFlipFlopsOn());
    PulsePropagationData.pushButton();
    PulsePropagationData.processPulses();
    REQUIRE(1 == PulsePropagationData.getFlipFlopsOn());
    PulsePropagationData.pushButton();
    PulsePropagationData.processPulses();
    REQUIRE(1 == PulsePropagationData.getFlipFlopsOn());
    PulsePropagationData.pushButton();
    PulsePropagationData.processPulses();
    REQUIRE(0 == PulsePropagationData.getFlipFlopsOn());
}

TEST_CASE("Testdata3")
{
    PulsePropagation PulsePropagationData(inputTestdata1);
    REQUIRE(32000000 == PulsePropagationData.getResultA());
}

TEST_CASE("PulsePropagation")
{
    PulsePropagation PulsePropagationData(inputData);
    REQUIRE(899848294 == PulsePropagationData.getResultA());
    REQUIRE(0 == PulsePropagationData.getResultB());
}