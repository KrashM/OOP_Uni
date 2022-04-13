#pragma once

class Date{

    private:
        unsigned day, mounth, year;

    public:
        Date();
        Date(unsigned day, unsigned mounth, unsigned year);
        Date(const Date &other);

        const Date &operator =(const Date &other);

        const char *toString() const;

};