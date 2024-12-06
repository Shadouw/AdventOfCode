#pragma once
#include <cassert>
#include <matrix.h>
#include <utility>

typedef std::pair<long, long> position;

class maze : public matrix<char> {
public:
    maze(std::size_t _X, std::size_t _Y)
        : matrix(_X, _Y)
    {
    }

    void setblockedFieldTypes(std::string _blockedFieldTypes)
    {
        blockedFieldTypes = _blockedFieldTypes;
    }

    bool isValidPosition(position p) const
    {
        return (p.first >= 0 && p.first < getX() && p.second >= 0 && p.second < getY());
    }

    bool isFree(position p) const
    {
        if (!isValidPosition(p))
            return false;

        if (std::string::npos != blockedFieldTypes.find(m[index(p.first, p.second)]))
            return false;

        return true;
    }

private:
    std::string blockedFieldTypes;
    friend class mazerunner;
};

class mazerunner {
public:
    mazerunner(maze& _mymaze)
        : mymaze(_mymaze)
    {
    }

    void setPosition(position _pos) { pos = _pos; }
    void setOrientation(char _orientation) { orientation = _orientation; }
    void setMarkAsSeen(char _markasseen)
    {
        markAsSeen = _markasseen;
        mymaze[pos] = markAsSeen;
    }

    void rotate(char r)
    {
        assert('R' == r || 'L' == r);
        switch (orientation) {
        case 'N':
            orientation = ('R' == r ? 'E' : 'W');
            break;
        case 'E':
            orientation = ('R' == r ? 'S' : 'N');
            break;
        case 'S':
            orientation = ('R' == r ? 'W' : 'E');
            break;
        case 'W':
            orientation = ('R' == r ? 'N' : 'S');
            break;
        default:
            std::cout << "Mazerunner has illegal orientation: " << orientation
                      << std::endl;

            break;
        }
    }

    //  1: Target field is blocked
    //  0: Okay, runner moved
    // -1: New Position would be outside the maze
    int move()
    {
        position newpos = pos;

        switch (orientation) {
        case 'N':
            --newpos.second;
            break;
        case 'E':
            ++newpos.first;
            break;
        case 'S':
            ++newpos.second;
            break;
        case 'W':
            --newpos.first;
            break;
        default:
            std::cout << "Mazerunner has illegal orientation: " << orientation
                      << std::endl;
            break;
        }

        if (!mymaze.isValidPosition(newpos))
            return -1;

        if (!mymaze.isFree(newpos))
            return 1;

        pos = newpos;
        if (markAsSeen)
            mymaze[newpos] = markAsSeen;
        return 0;
    }

    std::string getString() const
    {
        std::string mazeString;
        for (std::size_t y = 0; y < mymaze.getY(); ++y) {
            for (std::size_t x = 0; x < mymaze.getX(); ++x) {
                if (x == pos.first && y == pos.second) {
                    switch (orientation) {
                    case 'N':
                        mazeString += "^";
                        break;
                    case 'E':
                        mazeString += ">";
                        break;
                    case 'S':
                        mazeString += "Y";
                        break;
                    case 'W':
                        mazeString += "<";
                        break;
                    default:
                        mazeString += mymaze.m[mymaze.index(x, y)];
                        break;
                    }
                } else {
                    mazeString += mymaze.m[mymaze.index(x, y)];
                }
            }
            mazeString += "\n";
        }
        return mazeString;
    }

    long getSeenFields()
    {
        long count = 0;
        for (std::size_t y = 0; y < mymaze.getY(); ++y) {
            for (std::size_t x = 0; x < mymaze.getX(); ++x) {
                if (markAsSeen == mymaze.m[mymaze.index(x, y)])
                    ++count;
            }
        }
        return count;
    }

private:
    position pos = { 0, 0 };
    char orientation = ' ';
    maze& mymaze;
    char markAsSeen = 0;
};