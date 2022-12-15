#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>

#include <catch2/catch_test_macros.hpp>

using namespace std;

const vector<string> inputTestdata = {
    "Sensor at x=2, y=18: closest beacon is at x=-2, y=15",
    "Sensor at x=9, y=16: closest beacon is at x=10, y=16",
    "Sensor at x=13, y=2: closest beacon is at x=15, y=3",
    "Sensor at x=12, y=14: closest beacon is at x=10, y=16",
    "Sensor at x=10, y=20: closest beacon is at x=10, y=16",
    "Sensor at x=14, y=17: closest beacon is at x=10, y=16",
    "Sensor at x=8, y=7: closest beacon is at x=2, y=10",
    "Sensor at x=2, y=0: closest beacon is at x=2, y=10",
    "Sensor at x=0, y=11: closest beacon is at x=2, y=10",
    "Sensor at x=20, y=14: closest beacon is at x=25, y=17",
    "Sensor at x=17, y=20: closest beacon is at x=21, y=22",
    "Sensor at x=16, y=7: closest beacon is at x=15, y=3",
    "Sensor at x=14, y=3: closest beacon is at x=15, y=3",
    "Sensor at x=20, y=1: closest beacon is at x=15, y=3"};

const vector<string> inputData = {
    "Sensor at x=3291456, y=3143280: closest beacon is at x=3008934, y=2768339",
    "Sensor at x=3807352, y=3409566: closest beacon is at x=3730410, y=3774311",
    "Sensor at x=1953670, y=1674873: closest beacon is at x=2528182, y=2000000",
    "Sensor at x=2820269, y=2810878: closest beacon is at x=2796608, y=2942369",
    "Sensor at x=3773264, y=3992829: closest beacon is at x=3730410, y=3774311",
    "Sensor at x=2913793, y=2629579: closest beacon is at x=3008934, y=2768339",
    "Sensor at x=1224826, y=2484735: closest beacon is at x=2528182, y=2000000",
    "Sensor at x=1866102, y=3047750: closest beacon is at x=1809319, y=3712572",
    "Sensor at x=3123635, y=118421: closest beacon is at x=1453587, y=-207584",
    "Sensor at x=2530789, y=2254773: closest beacon is at x=2528182, y=2000000",
    "Sensor at x=230755, y=3415342: closest beacon is at x=1809319, y=3712572",
    "Sensor at x=846048, y=51145: closest beacon is at x=1453587, y=-207584",
    "Sensor at x=3505756, y=3999126: closest beacon is at x=3730410, y=3774311",
    "Sensor at x=2506301, y=3745758: closest beacon is at x=1809319, y=3712572",
    "Sensor at x=1389843, y=957209: closest beacon is at x=1453587, y=-207584",
    "Sensor at x=3226352, y=3670258: closest beacon is at x=3730410, y=3774311",
    "Sensor at x=3902053, y=3680654: closest beacon is at x=3730410, y=3774311",
    "Sensor at x=2573020, y=3217129: closest beacon is at x=2796608, y=2942369",
    "Sensor at x=3976945, y=3871511: closest beacon is at x=3730410, y=3774311",
    "Sensor at x=107050, y=209321: closest beacon is at x=1453587, y=-207584",
    "Sensor at x=3931251, y=1787536: closest beacon is at x=2528182, y=2000000",
    "Sensor at x=1637093, y=3976664: closest beacon is at x=1809319, y=3712572",
    "Sensor at x=2881987, y=1923522: closest beacon is at x=2528182, y=2000000",
    "Sensor at x=3059723, y=2540501: closest beacon is at x=3008934, y=2768339"};

class Sensor
{
public:
    Sensor(const string _input) : input(_input)
    {

        // Parse

        auto pos = input.find("x=");
        position.first = stoi(input.substr(pos + 2));

        pos = input.find("y=");
        position.second = stoi(input.substr(pos + 2));

        pos = input.rfind("x=");
        nextbeacon.first = stoi(input.substr(pos + 2));

        pos = input.rfind("y=");
        nextbeacon.second = stoi(input.substr(pos + 2));
    }

    int getPostionsWithoutBeacon()
    {
        int PostionsWithoutBeacon = 0;

        return PostionsWithoutBeacon;
    }

    bool getResultB()
    {
        int resultB = 0;

        return resultB;
    }

    string getString()
    {
        return input;
    }

private:
    string input;
    pair<long, long> position;
    pair<long, long> nextbeacon;

    friend class BeaconExclusionZone;
};

class BeaconExclusionZone
{
public:
    BeaconExclusionZone(const vector<string> &_input) : input(_input)
    {
        cout << "Size of Input: " << input.size() << endl;

        // Parse data
        for (auto elem : input)
            Sensors.push_back(Sensor(elem));

        min.first = Sensors[0].position.first;
        min.second = Sensors[0].position.second;
        max.first = Sensors[0].position.first;
        max.second = Sensors[0].position.second;

        for (auto sensor : Sensors)
        {
            if (sensor.position.first < min.first)
                min.first = sensor.position.first;
            if (sensor.position.first > max.first)
                max.first = sensor.position.first;

            if (sensor.position.second < min.second)
                min.second = sensor.position.second;
            if (sensor.position.second > max.second)
                max.second = sensor.position.second;

            if (sensor.nextbeacon.first < min.first)
                min.first = sensor.nextbeacon.first;
            if (sensor.nextbeacon.first > max.first)
                max.first = sensor.nextbeacon.first;

            if (sensor.nextbeacon.second < min.second)
                min.second = sensor.nextbeacon.second;
            if (sensor.nextbeacon.second > max.second)
                max.second = sensor.nextbeacon.second;
        }

        cout << "Minimum: " << min.first << "/" << min.second << endl;
        cout << "Maximum: " << max.first << "/" << max.second << endl;
    }

    int getPostionsWithoutBeacon(long row)
    {
        set<long> xposwithoutbeacon;

        for (auto e : Sensors)
        {
            long manhattan = abs(e.position.first - e.nextbeacon.first) + abs(e.position.second - e.nextbeacon.second);

            // How many fields are touched into both directions in that row?
            long touchdistance = manhattan - abs(e.position.second - row);

            if (touchdistance >= 0)
            {
                for (long t = e.position.first - touchdistance; t <= e.position.first + touchdistance; ++t)
                    xposwithoutbeacon.insert(t);
            }
        }

        // Remove beacons and sensors from list
        for (auto e : Sensors)
        {
            if (e.position.second == row)
                xposwithoutbeacon.erase(e.position.first);
            if (e.nextbeacon.second == row)
                xposwithoutbeacon.erase(e.nextbeacon.first);
        }

        cout << "result A: " << xposwithoutbeacon.size() << endl;
        return xposwithoutbeacon.size();
    }
    
    int getResultB()
    {
        int resultB = 0;
        for (auto e : Sensors)
            resultB += e.getResultB();

        cout << "result B: " << resultB << endl;
        return resultB;
    }

private:
    const vector<string> input;
    vector<Sensor> Sensors;

    pair<long, long> min;
    pair<long, long> max;
};

TEST_CASE("Testdata")
{
    BeaconExclusionZone BeaconExclusionZoneData(inputTestdata);
    REQUIRE(26 == BeaconExclusionZoneData.getPostionsWithoutBeacon(10));
    REQUIRE(0 == BeaconExclusionZoneData.getResultB());
}

TEST_CASE("BeaconExclusionZone")
{
    BeaconExclusionZone BeaconExclusionZoneData(inputData);
    REQUIRE(5564017 == BeaconExclusionZoneData.getPostionsWithoutBeacon(2000000));
    REQUIRE(0 == BeaconExclusionZoneData.getResultB());
}