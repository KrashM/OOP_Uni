#include "Student.h"
#include <cstring>

Student::Student(){

    this -> firstName = new char[1];
    this -> firstName[0] = '\0';
    this -> lastName = new char[1];
    this -> lastName[0] = '\0';
    this -> phone = new char[1];
    this -> phone[0] = '\0';
    this -> email = new char[1];
    this -> email[0] = '\0';

}

Student::Student(const char *name, const Subject subject, const short experience, const char *email, const char *phone){

}

Student::Student(const Student &other){


}

Student::~Student(){

    delete[] this -> firstName;
    delete[] this -> lastName;
    delete[] this -> phone;
    delete[] this -> email;

}

const char *Student::toString() const{

    char *result = new char[1024];
    result[0] = '\0';

    strcat(result, "First name: ");
    strcat(result, this -> firstName);
    strcat(result, "Last name: ");
    strcat(result, this -> lastName);
    strcat(result, "Birth date: ");
    strcat(result, this -> birthDate.toString());
    strcat(result, "Email: ");
    strcat(result, this -> email);
    strcat(result, "Phone: ");
    strcat(result, this -> phone);
    // strcat(result, "Class: ");
    // strcat(result, this -> _class.toString());
    strcat(result, "Grades: ");
    strcat(result, this -> grades.toString());

    return result;

}