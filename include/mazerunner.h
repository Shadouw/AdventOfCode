#pragma once
#include <cassert>
#include <utility>

typedef std::pair<long, long> position;

class maze {
public:
    maze(std::size_t _X, std::size_t _Y):X(_X),Y(_Y)
    {
        for (auto l = 0; l < _X * _Y; ++l)
            mazememory += ' ';
    }

    std::size_t getX() const { return X; }
    std::size_t getY() const { return Y; }

    std::size_t index(std::size_t x, std::size_t y) const { return x + Y * y; }

    char& operator[](std::size_t idx) { return mazememory[idx]; }
    char& operator[](std::pair<std::size_t, std::size_t> idx) { return mazememory[index(idx.first, idx.second)]; }

    void setblockedFieldTypes(std::string _blockedFieldTypes)
    {
        blockedFieldTypes = _blockedFieldTypes;
    }

    bool isValidPosition(position p) const
    {
        return (p.first >= 0 && p.first < X && p.second >= 0 && p.second < Y);
    }

    bool isFree(position p) const
    {
        if (!isValidPosition(p))
            return false;

        if (std::string::npos != blockedFieldTypes.find(mazememory[index(p.first, p.second)]))
            return false;

        return true;
    }

private:
    std::size_t X;
    std::size_t Y;
    std::string mazememory;
    std::string blockedFieldTypes;

    friend class mazerunner;
};

class mazerunner {
public:
    mazerunner(size_t _x, size_t _y)
        : mymaze(_x, _y)
    {
    }

    void setPosition(position _pos)
    {
        pos = _pos;
    }

    void setOrientation(char _orientation)
    {
        orientation = _orientation;
    }

    void setMarkAsSeen(char _markasseen)
    {
        markAsSeen = _markasseen;
        mymaze[pos] = markAsSeen;
    }

    void setMaze(maze _maze) { mymaze = _maze; }

    void setblockedFieldTypes(std::string blockedFieldTypes)
    {
        mymaze.setblockedFieldTypes(blockedFieldTypes);
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

    /*     std::string getString() const
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
        } */

    long getSeenFields()
    {
        long count = 0;
        for (std::size_t y = 0; y < mymaze.getY(); ++y) {
            for (std::size_t x = 0; x < mymaze.getX(); ++x) {
                if (markAsSeen == mymaze[mymaze.index(x, y)])
                    ++count;
            }
        }
        return count;
    }

private:
    position pos = { 0, 0 };
    char orientation = ' ';
    maze mymaze;
    char markAsSeen = 0;
};