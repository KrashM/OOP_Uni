#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../includes/doctest.h"
#include "../../includes/Vector.h"
#include <iostream>

TEST_SUITE("Test vector class"){

    TEST_CASE("Test copy constructor"){

        class Point{

            private:
                int x, y;

            public:
                Point(): x(0), y(0){}
                Point(int x, int y): x(x), y(y){}

                const char *toString() const{

                    char *result = new char[1024];

                    result[0] = '0' + this -> x;
                    result[1] = '-';
                    result[2] = '0' + this -> y;
                    result[3] = '\0';

                    return result;

                }

        };

        Vector<Point> integers;
        std::cout << integers.toString() << '\n';
        integers.pushBack(Point(1, 2));
        integers.pushBack(Point(3, 4));
        integers.pushBack(Point(4, 5));

        Vector<Point> newIntegers(integers);
        std::cout << newIntegers.toString() << '\n';

    }

}