#include "Subject.h"
#pragma once 

class Teacher
{
    private:
        char *name, *email, *phone;
        Subject subject;
        short experience;

    public:
        Teacher();
        Teacher(const char *name, const Subject subject, const short experience, const char *email, const char *phone);
        ~Teacher();

        const bool operator ==(const Teacher &other);
        const char *toString() const;
};

