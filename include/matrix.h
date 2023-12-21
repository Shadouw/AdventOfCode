#pragma once

template <class T>
class matrix {
public:
    matrix(std::size_t _X, std::size_t _Y)
        : X(_X)
        , Y(_Y)
    {
        m = new T[X * Y];
    }

    std::size_t index(std::size_t x, std::size_t y) const
    {
        return x + Y * y;
    }

    T& operator[](std::size_t idx) { return m[idx]; }
    T& operator[](std::pair<std::size_t, std::size_t> idx) { return m[index(idx.first, idx.second)]; }

    void fill(T value)
    {
        for (std::size_t i = 0; i < X * Y; ++i)
            m[i] = value;
    }

    void print() const
    {
        for (std::size_t x = 0; x < X; ++x) {
            for (std::size_t y = 0; y < Y; ++y) {
                std::cout << m[index( x, y )] << "\t";
            }
            std::cout << std::endl;
        }
    }

    ~matrix()
    {
        delete[] m;
        m = nullptr;
    }

private:
    T* m = nullptr;
    std::size_t X;
    std::size_t Y;
};