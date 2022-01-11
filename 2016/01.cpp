#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

using namespace std;

class bunnyhq {
public:
  bunnyhq(const vector<string> &_input) : input(_input) {
    cout << "Size of Input: " << input.size() << endl;
    hop();
    cout << xpos << " " << ypos << endl;
  }

  void hop() {
    for (auto elem : input) {
      if ('R' == elem[0]) {
        if (++orientation > 3)
          orientation = 0;
      } else if ('L' == elem[0]) {
        if (--orientation < 0)
          orientation = 3;
      } else
        cout << ":-o" << endl;

      int value = stoi(elem.substr(1));
      // cout << value << endl;

      for (int i = 0; i < value; ++i) {

        switch (orientation) {
        case 0:
          xpos += 1;
          break;
        case 1:
          ypos += 1;
          break;
        case 2:
          xpos -= 1;
          break;
        case 3:
          ypos -= 1;
          break;
        default:
          cout << ":-o" << endl;
        }

        auto curpos = make_pair(xpos, ypos);
        if (locations.find(curpos) != locations.end()) {
          if (-1 == resultB) {
            resultB = getDistance();
          }
        }
        locations.insert(curpos);
      }
    }
  }

  int getDistance() { return (abs(xpos) + abs(ypos)); }
  int getB() { return resultB; }

private:
  const vector<string> input;
  int resultB = -1;

  int orientation = 0; // 0=N, E, S, 3=W;
  int xpos = 0, ypos = 0;

  set<pair<int, int>> locations;
};

TEST_CASE("R2, L3") {
  bunnyhq testbunnyhq({"R2", "L3"});
  REQUIRE(5 == testbunnyhq.getDistance());
}

TEST_CASE("R2, R2, R2") {
  bunnyhq testbunnyhq({"R2", "R2", "R2"});
  REQUIRE(2 == testbunnyhq.getDistance());
}

TEST_CASE("R5, L5, R5, R3") {
  bunnyhq testbunnyhq({"R5", "L5", "R5", "R3"});
  REQUIRE(12 == testbunnyhq.getDistance());
}

TEST_CASE("R8, R4, R4, R8") {
  bunnyhq testbunnyhq({"R8", "R4", "R4", "R8"});
  // REQUIRE(12 == testbunnyhq.getDistance());
  REQUIRE(4 == testbunnyhq.getB());
}

TEST_CASE("Problem A") {
  bunnyhq testbunnyhq(
      {"R2",   "L1", "R2", "R1",   "R1", "L3", "R3", "L5", "L5", "L2", "L1",
       "R4",   "R1", "R3", "L5",   "L5", "R3", "L4", "L4", "R5", "R4", "R3",
       "L1",   "L2", "R5", "R4",   "L2", "R1", "R4", "R4", "L2", "L1", "L1",
       "R190", "R3", "L4", "R52",  "R5", "R3", "L5", "R3", "R2", "R1", "L5",
       "L5",   "L4", "R2", "L3",   "R3", "L1", "L3", "R5", "L3", "L4", "R3",
       "R77",  "R3", "L2", "R189", "R4", "R2", "L2", "R2", "L1", "R5", "R4",
       "R4",   "R2", "L2", "L2",   "L5", "L1", "R1", "R2", "L3", "L4", "L5",
       "R1",   "L1", "L2", "L2",   "R2", "L3", "R3", "L4", "L1", "L5", "L4",
       "L4",   "R3", "R5", "L2",   "R4", "R5", "R3", "L2", "L2", "L4", "L2",
       "R2",   "L5", "L4", "R3",   "R1", "L2", "R2", "R4", "L1", "L4", "L4",
       "L2",   "R2", "L4", "L1",   "L1", "R4", "L1", "L3", "L2", "L2", "L5",
       "R5",   "R2", "R5", "L1",   "L5", "R2", "R4", "R4", "L2", "R5", "L5",
       "R5",   "R5", "L4", "R2",   "R1", "R1", "R3", "L3", "L3", "L4", "L3",
       "L2",   "L2", "L2", "R2",   "L1", "L3", "R2", "R5", "R5", "L4", "R3",
       "L3",   "L4", "R2", "L5",   "R5"});
  REQUIRE(234 == testbunnyhq.getDistance());
  REQUIRE(113 == testbunnyhq.getB());
}