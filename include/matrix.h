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

    //
    // Add Assignement Operator!!!
    //

    matrix(const matrix& obj)
    {
        X = obj.X;
        Y = obj.Y;
        m = new T[X * Y];

        for (size_t p = 0; p < X*Y; ++p)
            m[p] = obj.m[p];
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