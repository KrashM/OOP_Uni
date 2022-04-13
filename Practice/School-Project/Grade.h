#pragma once

#include "Subject.h"

class Grade{

    private:
        Subject subject;
        short grade;

    public:
        Grade();
        Grade(const Subject subject, const short grade);

        const char *toString() const;

};