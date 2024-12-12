#pragma once
#include <aoc.h>
#include <manhattan.h>

typedef std::pair<long, long> position;
typedef std::vector<position> region;

class aocmap {
public:
    aocmap(std::size_t _X, std::size_t _Y)
        : X(_X)
        , Y(_Y)
    {
        for (auto l = 0; l < _X * _Y; ++l)
            mapmemory += ' ';
    }

    aocmap(const std::vector<std::string>& _input)
    {
        X = _input[0].size();
        Y = _input.size();

        mapmemory.clear();

        for (auto y = 0; y < Y; ++y) {
            mapmemory += _input[y];
        }
    }

    std::size_t getX() const
    {
        return X;
    }
    std::size_t getY() const { return Y; }

    std::size_t index(position p) const { return index(p.first, p.second); }
    std::size_t index(std::size_t x, std::size_t y) const { return x + Y * y; }
    position index(std::size_t pos) const { return { pos % Y, pos / Y }; }

    void setfreeFields(std::string _freeFields) { freeFields = _freeFields; }

    char& operator[](std::size_t idx) { return mapmemory[idx]; }
    char& operator[](std::pair<std::size_t, std::size_t> idx) { return mapmemory[index(idx.first, idx.second)]; }

    bool isValidPosition(position p) const
    {
        return (p.first >= 0 && p.first < X && p.second >= 0 && p.second < Y);
    }

    bool isFree(position p) const
    {
        if (!isValidPosition(p))
            return false;

        if (std::string::npos != freeFields.find(mapmemory[index(p.first, p.second)]))
            return true;

        return false;
    }

    std::string getChars()
    {
        std::set<char> s;
        for (auto p = 0; p < X * Y; ++p) {
            if (std::string::npos == freeFields.find(mapmemory[p]))
                s.insert(mapmemory[p]);
        }

        std::string ret;
        for (auto _s : s)
            ret += _s;

        return ret;
    }

    std::vector<position> findAllChars(const char c)
    {
        std::vector<position> positions;
        std::size_t pos = 0;

        while (std::string::npos != pos) {
            if (c == mapmemory[pos])
                positions.push_back(index(pos));
            pos = mapmemory.find(c, pos + 1);
        }
        return positions;
    }

    bool setPosition(position p, char c)
    {
        if (!isValidPosition(p))
            return false;

        mapmemory[index(p)] = c;
        return true;
    }

    bool setIfFree(position p, char c)
    {
        if (!isFree(p))
            return false;

        mapmemory[index(p)] = c;
        return true;
    }

    std::string getString()
    {
        std::string ret;
        for (auto y = 0; y < Y; ++y) {
            for (auto x = 0; x < X; ++x) {
                ret += (*this)[{ x, y }];
            }
            ret += "\n";
        }
        return ret;
    }

    std::vector<std::vector<position>> findTrails(char start, char end)
    {
        std::vector<std::vector<position>> trails;
        for (auto p : findAllChars(start))
            trails.push_back({ p });

        for (auto c = start + 1; c <= end; ++c) {
            std::vector<std::vector<position>> temptrails;

            while (trails.size()) {
                auto const curtrail = trails.back();
                trails.pop_back();

                const auto lastpos = curtrail.back();

                for (int i = 0; i < 4; ++i) {
                    auto newpos = lastpos;

                    switch (i) {
                    case 0: // N
                        newpos.second -= 1;
                        break;
                    case 1: // E
                        newpos.first += 1;
                        break;
                    case 2: // S
                        newpos.second += 1;
                        break;
                    case 3: // W
                        newpos.first -= 1;
                        break;
                    default:
                        assert(false);
                        break;
                    }
                    if (isValidPosition(newpos)) {
                        if ((*this)[newpos] == c) {
                            auto temptrail = curtrail;
                            temptrail.push_back(newpos);
                            temptrails.push_back(temptrail);
                        }
                    }
                }
            }

            trails = temptrails;
        }

        return trails;
    }

    void getAllCharPositions()
    {
        for (auto p = 0; p < mapmemory.size(); p++)
            allCharPositions[mapmemory[p]].push_back(index(p));
    }

    void findRegions()
    {
        if (allCharPositions.empty())
            getAllCharPositions();

        for (auto cp : allCharPositions) {
            while (cp.second.size()) {
                region currentregion;
                currentregion.push_back(cp.second.back());
                cp.second.pop_back();

                // Get all elements in this region
                bool found = true;
                while (found) {
                    found = false;
                    for (auto e = cp.second.begin(); e != cp.second.end(); ++e) { // A reverse iterator might be faster
                        for (auto f : currentregion) {
                            if (1 == manhattandistanceP<long>(*e, f)) {
                                currentregion.push_back(*e);
                                e = cp.second.erase(e);
                                found = true;
                                break;
                            }
                        }
                        if (cp.second.end() == e)
                            break;
                    }
                }
                regions.push_back(currentregion);
            }
        }
    }

    long getArea(region r)
    {
        return r.size();
    }

    std::vector<position> getSurroundingPositions(const position &p) const
    {
        std::vector<position> ret;
        ret.push_back({p.first+1, p.second});
        ret.push_back({p.first, p.second+1});
        ret.push_back({p.first-1, p.second});
        ret.push_back({p.first, p.second-1});

        return ret;
    }

    long getPerimeter(region r)
    {
        long perimeter = 0;
        const char c = (*this)[r.front()];
        for (auto f : r) {
            for ( auto f2 : getSurroundingPositions(f) )
            {
                if ( !isValidPosition(f2) ) ++perimeter;
                else if ( c!= (*this)[f2] ) ++perimeter;
            }
        }
        return perimeter;
    }

    long getAreaXPerimeter()
    {
        long areaXperimeter = 0;
        for (auto r : regions) {
            areaXperimeter += getArea(r) * getPerimeter(r);
        }

        return areaXperimeter;
    }

private:
    std::size_t X;
    std::size_t Y;
    std::string mapmemory;

    std::string freeFields = ".";

    std::map<char, std::vector<position>> allCharPositions;
    std::vector<region> regions;

    friend class mazerunner;
};