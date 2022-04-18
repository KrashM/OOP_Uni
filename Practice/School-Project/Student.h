#pragma once

#include "Class.h"
#include "Grade.h"
#include "Date.h"
#include <Vector>

class Student{

    private:
        char *firstName, *lastName, *email, *phone;
        Date birthDate;
        Class _class;
        // Vector<Grade> grades;
        Grade grades[1024];
        int numGrades;

    public:
        Student();
        Student(const char *firstName, const char *lastName, const char *email, const char *phone, const Date &birthDate, const Class &_class, const Grade grades[], const int numGrades);
        Student(const Student &other);
        ~Student();

        const bool operator =(const Student &other);
        const char *toString() const;

};