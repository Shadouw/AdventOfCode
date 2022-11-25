#include <iostream>

#include <catch2/catch_test_macros.hpp>

using namespace std;

uint64_t fieldnumber(uint64_t row, uint64_t col )
{
    uint64_t fn = 0;

    fn += col;

    for ( uint64_t i= 0; i<row+col-1; ++i)
        fn +=i;

    return fn;
}

uint64_t getField ( uint64_t row, uint64_t col )
{
    uint64_t oldfield=20151125;
    uint64_t fn = fieldnumber(row,col);

    for (uint64_t f=1; f<fn; ++f)
    {
        oldfield = (oldfield*252533) % 33554393;
    }

    return oldfield;
}


TEST_CASE ("fieldnumber")
{
    REQUIRE ( 1 == fieldnumber(1,1) );
    REQUIRE ( 2 == fieldnumber(2,1) );
    REQUIRE ( 3 == fieldnumber(1,2) );

    REQUIRE ( 17 == fieldnumber(5,2) );

    REQUIRE ( 19 == fieldnumber(3,4) );
}

TEST_CASE ("fieldvalue")
{
    REQUIRE ( 20151125 == getField(1,1) );
    REQUIRE ( 31916031 == getField(2,1) );
    REQUIRE ( 18749137 == getField(1,2) );

    REQUIRE ( 17552253 == getField(5,2) );

    REQUIRE ( 7981243 == getField(3,4) );
}

TEST_CASE ("Let It Snow")
{
    REQUIRE ( 18361853 == fieldnumber(2978,3083));

    uint64_t resultA = getField(2978,3083);
    cout << "Result A: " << resultA << endl;
    REQUIRE ( 2650453 == resultA);
}
