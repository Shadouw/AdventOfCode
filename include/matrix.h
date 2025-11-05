#pragma once

typedef std::pair<long, long> position;

template <class T>
class matrix {
public:
    matrix(std::size_t _X, std::size_t _Y)
        : X(_X)
        , Y(_Y)
    {
        m = new T[X * Y];
    }

    matrix(const matrix& other)
    {
        X = other.X;
        Y = other.Y;
        m = new T[X * Y];

        for (size_t p = 0; p < X * Y; ++p)
            m[p] = other.m[p];
    }

    matrix& operator=(const matrix& other)
    {
        if (this != &other) {
            X = other.X;
            Y = other.Y;

            delete[] m;
            m = new T[X * Y];

            std::copy(other.m, other.m + X * Y, m);
        }
        return *this;
    }

    std::size_t index(std::size_t x, std::size_t y) const
    {
        return x + X * y;
    }

    T& operator[](std::size_t idx) { return m[idx]; }
    T& operator[](std::pair<std::size_t, std::size_t> idx) { return m[index(idx.first, idx.second)]; }

    void fill(T value)
    {
        for (std::size_t i = 0; i < X * Y; ++i)
            m[i] = value;
    }

    bool isValidPosition(position p) const
    {
        return (p.first >= 0 && p.first < X && p.second >= 0 && p.second < Y);
    }

    bool setIfValidCell(position p, T value)
    {
        if ( !isValidPosition(p) )
            return false;

        m[index(p.first, p.second)] = value;
        return true;
    }

    void print() const
    {
        for (std::size_t x = 0; x < X; ++x) {
            for (std::size_t y = 0; y < Y; ++y) {
                std::cout << m[index(x, y)] << "\t";
            }
            std::cout << std::endl;
        }
    }

    std::size_t getX() const { return X; }
    std::size_t getY() const { return Y; }

    ~matrix()
    {
        delete[] m;
        m = nullptr;
    }

protected:
    T* m = nullptr;
    std::size_t X;
    std::size_t Y;
};
