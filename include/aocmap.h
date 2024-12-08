#pragma once
#include <aoc.h>

typedef std::pair<long, long> position;

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

        while ( std::string::npos != pos )
        {
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
        if ( !isFree(p) )
            return false;

        mapmemory[index(p)] = c;
        return true;
    }

private:
    std::size_t X;
    std::size_t Y;
    std::string mapmemory;

    std::string freeFields = ".";

    friend class mazerunner;
};