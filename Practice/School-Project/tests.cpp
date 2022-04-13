#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Subject.h"
#include "Student.h"
#include <cstring>

TEST_SUITE("Testing subject class"){

    TEST_CASE("Testing default constructor"){

        Subject s;
        CHECK_EQ(strcmp(s.toString(), "Name: \nDescription: "), 0);

    }
    
    TEST_CASE("Testing parametric constructor"){

        Subject s("Mathematics", "Very cool");
        CHECK_EQ(strcmp(s.toString(), "Name: Mathematics\nDescription: Very cool"), 0);

    }
    
    TEST_CASE("Testing copy constructor"){

        Subject s("Hello", "World");
        Subject cpy(s);
        CHECK_EQ(strcmp(cpy.toString(), "Name: Hello\nDescription: World"), 0);

    }
    
    TEST_CASE("Testing = operator"){

        Subject s = Subject("Programming", "The best");
        CHECK_EQ(strcmp(s.toString(), "Name: Programming\nDescription: The best"), 0);

    }

}

TEST_SUITE("Testing student class"){

    TEST_CASE("Testing default constructor"){

        Student s;
        CHECK_EQ(strcmp(s.toString(), "Name: \nDescription: "), 0);

    }
    
    // TEST_CASE("Testing parametric constructor"){

    //     Subject s("Mathematics", "Very cool");
    //     CHECK_EQ(strcmp(s.toString(), "Name: Mathematics\nDescription: Very cool"), 0);

    // }
    
    // TEST_CASE("Testing copy constructor"){

    //     Subject s("Hello", "World");
    //     Subject cpy(s);
    //     CHECK_EQ(strcmp(cpy.toString(), "Name: Hello\nDescription: World"), 0);

    // }
    
    // TEST_CASE("Testing = operator"){

    //     Subject s = Subject("Programming", "The best");
    //     CHECK_EQ(strcmp(s.toString(), "Name: Programming\nDescription: The best"), 0);

    // }

}