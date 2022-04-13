#include "Grade.h"
#include <cstring>

Grade::Grade()
{

}

Grade::Grade(const Subject subject, const short grade)
{
    // тука се ползва копи коструктора ама не знам как
    this -> grade = grade;
}

const char *Grade::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    // strcat(result, "Subject: ");
    // strcat(result, this -> name);
    // strcat(result, "\n");

    // strcat(result, "Description: ");
    // strcat(result, this -> description);
    // strcat(result, "\n");
    
    return result;
}