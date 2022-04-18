#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest.h"
#include "Subject.h"
#include "Student.h"
#include "Date.h"
#include "Class.h"
#include "Grade.h"
#include <cstring>
#include <iostream>

TEST_SUITE("Testing date class"){

    TEST_CASE("Testing default constructor"){

        Date date;
        CHECK_EQ(strcmp(date.toString(), "0.0.0"), 0);

    }
    
    TEST_CASE("Testing parametric constructor"){

        Date date(22, 6, 2002);
        CHECK_EQ(strcmp(date.toString(), "22.6.2002"), 0);

    }
    
    TEST_CASE("Testing copy constructor"){

        Date date(22, 6, 2002);
        Date cpy(date);
        CHECK_EQ(strcmp(cpy.toString(), "22.6.2002"), 0);

    }
    
    TEST_CASE("Testing = operator"){

        Date date = Date(22, 6, 2002);
        CHECK_EQ(strcmp(date.toString(), "22.6.2002"), 0);

    }

}

TEST_SUITE("Testing grade class"){

    TEST_CASE("Testing default constructor"){

        Grade g;
        CHECK_EQ(strcmp(g.toString(), "Subject:  ---> Grade: 0"), 0);

    }
    
    TEST_CASE("Testing parametric constructor"){

        Grade g(Subject("Mathematics", "Very cool"), 3);
        CHECK_EQ(strcmp(g.toString(), "Subject: Mathematics ---> Grade: 3"), 0);

    }
    
    TEST_CASE("Testing copy constructor"){

        Grade g(Subject("Hello", "World"), 4);
        Grade cpy(g);
        CHECK_EQ(strcmp(cpy.toString(), "Subject: Hello ---> Grade: 4"), 0);

    }
    
    TEST_CASE("Testing = operator"){

        Grade g = Grade(Subject("Programming", "The best"), 6);
        CHECK_EQ(strcmp(g.toString(), "Subject: Programming ---> Grade: 6"), 0);

    }

}

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
        CHECK_EQ(strcmp(s.toString(), "First name: \nLast name: \nBirth date: 0.0.0\nEmail: \nPhone: \nGrades: \n"), 0);

    }
    
    TEST_CASE("Testing parametric constructor"){

        Student s("Hristo", "Kanev", "HristoKanevKrash@gmail.com", "0878686974", Date(22, 6, 2002), Class(), std::initializer_list<Grade>({Grade(Subject("Mathematics", "Very cool"), 6)}).begin(), 1);
        // std::cout << s.toString() << ' ' << strlen("First name: Hristo\nLast name: Kanev\nBirth date: 22.6.2002\nEmail: HristoKanevKrash@gmail.com\nPhone: 0878686974\nGrades: \nSubject: Mathematics ---> Grade: 6") << '\n';
        CHECK_EQ(strcmp(s.toString(), "First name: Hristo\nLast name: Kanev\nBirth date: 22.6.2002\nEmail: HristoKanevKrash@gmail.com\nPhone: 0878686974\nGrades: \nSubject: Mathematics ---> Grade: 6"), 0);

    }
    
    TEST_CASE("Testing copy constructor"){

        Student s("Hristo", "Kanev", "HristoKanevKrash@gmail.com", "0878686974", Date(22, 6, 2002), Class(), std::initializer_list<Grade>({Grade(Subject("Mathematics", "Very cool"), 6)}).begin(), 1);
        Student cpy(s);
        CHECK_EQ(strcmp(cpy.toString(), "First name: Hristo\nLast name: Kanev\nBirth date: 22.6.2002\nEmail: HristoKanevKrash@gmail.com\nPhone: 0878686974\nGrades: \nSubject: Mathematics ---> Grade: 6"), 0);

    }
    
    TEST_CASE("Testing = operator"){


        Student s = Student("Hristo", "Kanev", "HristoKanevKrash@gmail.com", "0878686974", Date(22, 6, 2002), Class(), std::initializer_list<Grade>({Grade(Subject("Mathematics", "Very cool"), 6)}).begin(), 1);
        CHECK_EQ(strcmp(s.toString(), "First name: Hristo\nLast name: Kanev\nBirth date: 22.6.2002\nEmail: HristoKanevKrash@gmail.com\nPhone: 0878686974\nGrades: \nSubject: Mathematics ---> Grade: 6"), 0);

    }

}