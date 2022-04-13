#include "Subject.h"
#pragma once 

class Grade
{
    private:
        Subject subject;
        short grade;

    public:
        Grade();
        Grade(const Subject subject, const short grade);

        const char *toString() const;
};

