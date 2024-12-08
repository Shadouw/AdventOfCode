#pragma once
#include <vector>

template <class T, std::size_t D>
class Position {
public:
    Position()
    {
        for (std::size_t d = 0; d < D; ++d)
            position.push_back(0);
    }

    Position(std::vector<T> input) { position = input; }

    T& operator[](std::size_t idx)
    {
        assert(idx < D);
        return position[idx];
    }
private:
    std::vector<T> position;
};