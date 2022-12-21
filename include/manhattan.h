#pragma once

#include <vector>
#include <utility>
#include <cassert>

template <class T, std::size_t N>
T manhattandistance(std::array<T, N> v1, std::array<T, N> v2)
{
    T mhd = 0;

    for (T t = 0; t < N; ++t)
        mhd += abs(v1[t] - v2[t]);

    return mhd;
}

template<class T>
T manhattandistanceV(std::vector <T>v1, std::vector<T> v2)
{
    T mhd = 0;
    assert(v1.size() == v2.size());

    for (T t = 0; t < v2.size(); ++t)
        mhd += abs(v1[t] - v2[t]);

    return mhd;
}

// The pair version gets its own name, otherwise we have ambiguous bracket enclosed list.
template <class T>
T manhattandistanceP(std::pair<T,T> v1, std::pair<T,T> v2)
{
    T mhd = 0;
    mhd += abs(v1.first - v2.first) + abs(v1.second - v2.second);

    return mhd;
}

template long manhattandistanceV<long>(std::vector<long>, std::vector<long>);