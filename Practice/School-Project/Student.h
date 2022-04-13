#pragma once

#include "Class.h"
#include "Grade.h"
#include "Date.h"
#include "Vector.h"

class Student{

    private:
        char *firstName, *lastName, *email, *phone;
        Date birthDate;
        Class _class;
        Vector<Grade> grades;

    public:
        Student();
        Student(const char *name, const Subject subject, const short experience, const char *email, const char *phone);
        Student(const Student &other);
        ~Student();

        const bool operator =(const Student &other);
        const char *toString() const;

};

