#pragma once 

class Subject{

    private:
        char *name;
        char *description;

    public:
        Subject();
        Subject(const char *name, const char *description);
        Subject(const Subject &other);
        ~Subject();

        const Subject &operator =(const Subject& s);
        const char *toString() const;

};

