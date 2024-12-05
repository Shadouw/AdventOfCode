#include <iostream>
#include <cstdint>
#include <string>
#include <set>

using namespace std;

const string inputT[][2] = {
    "e", "H",
    "e", "O",
    "H", "HO",
    "H", "OH",
    "O", "HH",
    "HOHOHO", ""};

const string inputA[][2] = {
    "Al", "ThF",
    //"Al", "ThRnFAr",
    "B", "BCa",
    "B", "TiB",
    //"B", "TiRnFAr",
    "Ca", "CaCa",
    "Ca", "PB",
    "Ca", "PRnFAr",
    "Ca", "SiRnFYFAr",
    "Ca", "SiRnMgAr",
    "Ca", "SiTh",
    "F", "CaF",
    "F", "PMg",
    "F", "SiAl",
    //"H", "CRnAlAr",
    //"H", "CRnFYFYFAr",
    //"H", "CRnFYMgAr",
    //"H", "CRnMgYFAr",
    "H", "HCa",
    //"H", "NRnFYFAr",
    //"H", "NRnMgAr",
    "H", "NTh",
    "H", "OB",
    //"H", "ORnFAr",
    "Mg", "BF",
    "Mg", "TiMg",
    //"N", "CRnFAr",
    "N", "HSi",
    //"O", "CRnFYFAr",
    //"O", "CRnMgAr",
    "O", "HP",
    //"O", "NRnFAr",
    "O", "OTi",
    "P", "CaP",
    "P", "PTi",
    "P", "SiRnFAr",
    "Si", "CaSi",
    "Th", "ThCa",
    "Ti", "BP",
    "Ti", "TiTi",
    "e", "HF",
    "e", "NAl",
    "e", "OMg",
    "CRnCaSiRnBSiRnFArTiBPTiTiBFArPBCaSiThSiRnTiBPBPMgArCaSiRnTiMgArCaSiThCaSiRnFArRnSiRnFArTiTiBFArCaCaSiRnSiThCaCaSiRnMgArFYSiRnFYCaFArSiThCaSiThPBPTiMgArCaPRnSiAlArPBCaCaSiRnFYSiThCaRnFArArCaCaSiRnPBSiRnFArMgYCaCaCaCaSiThCaCaSiAlArCaCaSiRnPBSiAlArBCaCaCaCaSiThCaPBSiThPBPBCaSiRnFYFArSiThCaSiRnFArBCaCaSiRnFYFArSiThCaPBSiThCaSiRnPMgArRnFArPTiBCaPRnFArCaCaCaCaSiRnCaCaSiRnFYFArFArBCaSiThFArThSiThSiRnTiRnPMgArFArCaSiThCaPBCaSiRnBFArCaCaPRnCaCaPMgArSiRnFYFArCaSiThRnPBPMgAr", ""};

const string inputB[][2] = {
    "1", "5F",
    "1", "57F8",
    "B", "B2",
    "B", "6B",
    "B", "67F8",
    "2", "22",
    "2", "PB",
    "2", "P7F8",
    "2", "47FYF8",
    "2", "4738",
    "2", "45",
    "F", "2F",
    "F", "P3",
    "F", "41",
    "H", "C718",
    "H", "C7FYFYF8",
    "H", "C7FY38",
    "H", "C73YF8",
    "H", "H2",
    "H", "N7FYF8",
    "H", "N738",
    "H", "N5",
    "H", "OB",
    "H", "O7F8",
    "3", "BF",
    "3", "63",
    "N", "C7F8",
    "N", "H4",
    "O", "C7FYF8",
    "O", "C738",
    "O", "HP",
    "O", "N7F8",
    "O", "O6",
    "P", "2P",
    "P", "P6",
    "P", "47F8",
    "4", "24",
    "5", "52",
    "6", "BP",
    "6", "66",
    "e", "HF",
    "e", "N1",
    "e", "O3",
    "C7247B47F86BP66BF8PB245476BPBP38247638245247F8747F866BF8224745224738FY47FY2F845245PBP6382P7418PB2247FY4527F882247PB47F83Y222245224182247PB418B2222452PB45PBPB247FYF845247F8B2247FYF8452PB45247P387F8P6B2P7F82222472247FYF8F8B245F85454767P38F82452PB247BF822P722P3847FYF82457PBP38"};

auto &input = inputB;

const uint32_t numoftransitions = (sizeof(input) / sizeof(input[0])) - 1;
const string inputstring = input[numoftransitions][0];

void addTransformation(set<string> &resultset, const string inputstring, const string from, const string to, size_t maxsize = -1)
{
    //cout << from << " ==> " << to << endl;
    auto pos = inputstring.find(from);
    while (string::npos != pos)
    {
        string result = inputstring.substr(0, pos);
        result += to;
        result += inputstring.substr(pos + from.size());
        //cout << result << endl;

        if (result.length() <= maxsize)
            resultset.insert(result);

        pos = inputstring.find(from, pos + 1);
    }
}

int main(int, char **)
{
    int resultA = 0;
    int resultB = 0;

    set<string> resultsetA;
    cout << inputstring << endl;
    for (auto elem : input)
    {
        if (elem[1] != "")
        {
            addTransformation(resultsetA, inputstring, elem[0], elem[1]);
        }
    }
    resultA = resultsetA.size();
    cout << "Result A: " << resultA << endl;

    // Part 2
    set<string> resultsetB[2];
    uint8_t activeset = 0;
    resultsetB[activeset].insert("e");

    while (resultsetB[activeset].end() == resultsetB[activeset].find(inputstring))
    {
        ++resultB;

        resultsetB[1 - activeset].clear();

        //for ( auto elem1 : resultsetB[activeset] )
        for (auto elem1 = resultsetB[activeset].begin(); elem1 != resultsetB[activeset].end();)
        {
            if (*elem1 != "")
            {
                for (auto elem2 : input)
                {
                    if (elem2[1] != "")
                    {
                        addTransformation(resultsetB[1 - activeset], *elem1, elem2[0], elem2[1], inputstring.length());
                    }
                }

                // Remove
                resultsetB[activeset].erase(elem1++);
            }
        }

        activeset = 1 - activeset;
        cout << resultB << " " << resultsetB[activeset].size() << endl;
    }

    cout << "Result B: " << resultB << endl;

    return 0;
}
