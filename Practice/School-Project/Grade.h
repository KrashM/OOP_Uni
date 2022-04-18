#pragma once

#include "Subject.h"

class Grade{

    private:
        Subject subject;
        short grade;

    public:
        Grade();
        Grade(const Subject subject, const short grade);
        Grade(const Grade &other);

        Grade &operator =(const Grade &other);

        const char *toString() const;

};