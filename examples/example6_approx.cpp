// C++11 - compare floating point numbers using approx.

#include "lest.hpp"

using lest::approx;

const lest::test specification[] =
{
    TEST( "Value approximates other value (pass)" )
    {
        EXPECT( 1.0  == approx( 1.0 ) );
        EXPECT( 1.01 != approx( 1.0 ) );
    },

    TEST( "Value approximates other value (fail)" )
    {
        EXPECT( 1.01 == approx( 1.0 ) );
    },

    TEST( "Value approximates other value using custom epsilon (pass)" )
    {
        approx custom = approx::custom().epsilon( 0.1 );

        EXPECT( approx( 1.01 ) != 1.0 );
        EXPECT( custom( 1.01 ) == 1.0 );
    },
};

int main( int argc, char * argv[] )
{
    return lest::run( specification, argc, argv );
}

// cl -nologo -Wall -EHsc -I.. example6_approx.cpp && example6_approx
// g++ -Wall -Wextra -Wmissing-include-dirs -std=c++11 -I.. -o example6_approx.exe example6_approx.cpp && example6_approx

// example6_approx.cpp:17: failed: Value approximates other value (fail): 1.01 == approx( 1.0 ) for 1.01 == 1
// 1 out of 3 selected tests failed.