#pragma once

#include "Class.h"
#include "Grade.h"
#include "Date.h"
#include "Vector.h"

class Student{

    private:
        Vector<Grade> grades;
        Date birthDate;
        Class _class;
        char *firstName, *lastName, *email, *phone;

    public:
        Student();
        Student(const char *firstName, const char *lastName, const char *email, const char *phone, const Date &birthDate, const Class &_class, const Vector<Grade> grades);
        Student(const Student &other);
        ~Student();

        const bool operator =(const Student &other);
        const char *toString() const;

};