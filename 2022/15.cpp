#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <stdexcept>
#include <manhattan.h>

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

typedef pair<long, long> point;
typedef pair<long, long> range;

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

private:
    string input;
    point position;
    point nextbeacon;

    friend class BeaconExclusionZone;
};

class Line
{
public:
    void addValues(range area)
    {
        bool merged = false;
        for (auto it = ranges.begin(); it != ranges.end(); ++it)
        {
            try
            {
                range m = merge(*it, area);
                it->first = m.first;
                it->second = m.second;

                merged = true;

                break;
            }
            catch (const std::exception &e)
            {
                // std::cerr << e.what() << '\n';
            }
        }

        if (!merged)
            ranges.push_back(area);

        if (ranges.size() > 1)
            for (auto it1 = ranges.begin(); it1 != ranges.end(); ++it1)
                for (auto it2 = it1 + 1; it2 != ranges.end();)
                {
                    try
                    {
                        range m = merge(*it1, *it2);
                        it1->first = m.first;
                        it1->second = m.second;

                        it2 = ranges.erase(it2);
                    }
                    catch (const std::exception &e)
                    {
                        ++it2;
                    }
                }
    }

    void removeValue(long x)
    {
        for (auto it = ranges.begin(); it != ranges.end();)
        {
            if (it->first == x && it->second == x)
            {
                ranges.erase(it);
                return;
            }
            else if (it->first == x)
            {
                ++(it->first);
                return;
            }
            else if (it->second == x)
            {
                --(it->second);
                return;
            }
            if (it->first < x && x < it->second)
            {
                long second = it->second;
                it->second = x - 1;
                ranges.push_back(range(x + 1, second));
                return;
            }
            else
                ++it;
        }
    }

    static range merge(range r1, range r2)
    {
        // Case 1: first point of r1 in r2
        if (r2.first <= r1.first && r1.first <= r2.second)
            return (range(min(r1.first, r2.first), max(r1.second, r2.second)));

        // Case 2: second point of r1 in r2
        if (r2.first <= r1.second && r1.second <= r2.second)
            return (range(min(r1.first, r2.first), max(r1.second, r2.second)));

        // Case 3: r2 in r1
        if ((r1.first <= r2.first && r2.first <= r1.second) && (r1.first <= r2.second && r2.second <= r1.second))
            return (range(min(r1.first, r2.first), max(r1.second, r2.second)));

        throw range_error("No ovlerap");
    }

    long getElements()
    {
        long elements = 0;

        for (auto e : ranges)
            elements += e.second - e.first + 1;

        return elements;
    }

    long getTuningPosition(range r)
    {
        long tuningFrequency = -1;

        if (ranges.size() > 1)
        {
            for (auto e : ranges)
            {
                if (r.first < e.first && e.first <= r.second)
                    return e.first - 1;

                if (r.first <= e.second && e.second < r.second)
                    return e.second + 1;
            }
        }
        else if (r.first + 1 == ranges[0].first)
        {
            return ranges[0].first;
        }
        else if (r.second - 1 == ranges[0].second)
        {
            return ranges[0].second;
        }

        return tuningFrequency;
    }

private:
    vector<range> ranges;
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
        Line xLine;

        for (auto e : Sensors)
        {
            long manhattan = manhattandistanceP<long>(e.position, e.nextbeacon);

            // How many fields are touched into both directions in that row?
            long touchdistance = manhattan - abs(e.position.second - row);

            if (touchdistance >= 0)
                xLine.addValues(range(e.position.first - touchdistance, e.position.first + touchdistance));
        }

        // Remove beacons and sensors from list
        for (auto e : Sensors)
        {
            if (e.position.second == row)
                xLine.removeValue(e.position.first);

            if (e.nextbeacon.second == row)
                xLine.removeValue(e.nextbeacon.first);
        }

        cout << "result A: " << xLine.getElements() << endl;
        return xLine.getElements();
    }

    long getTuningFrequency(const size_t max)
    {
        long TuningFrequency = 0;

        for (long row = 0; row <= max; ++row)
        {
            Line xLine;

            for (auto e : Sensors)
            {
                auto epf = e.position.first;
                auto eps = e.position.second;

                long manhattan = manhattandistanceP<long>(e.position, e.nextbeacon);

                // How many fields are touched into both directions in that row?
                long touchdistance = manhattan - abs(eps - row);

                if (touchdistance >= 0)
                {
                    long tmin = (epf - touchdistance < 0 ? 0 : epf - touchdistance);
                    long tmax = (epf + touchdistance > max ? max : epf + touchdistance);
                    xLine.addValues(range(tmin, tmax));
                }
            }

            if (xLine.getTuningPosition(range(0, max)) > 0)
            {
                long resB = xLine.getTuningPosition(range(0, max)) * 4000000 + row;
                cout << "result B: " << resB << endl;
                return resB;
            }
        }
        return -1;
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
    REQUIRE(56000011 == BeaconExclusionZoneData.getTuningFrequency(20));
}

TEST_CASE("BeaconExclusionZone")
{
    BeaconExclusionZone BeaconExclusionZoneData(inputData);
    REQUIRE(5564017 == BeaconExclusionZoneData.getPostionsWithoutBeacon(2000000));
    REQUIRE(11558423398893 == BeaconExclusionZoneData.getTuningFrequency(4000000));
}