#include "Dictionary.h"

Dictionary::Dictionary(Record *records, int size){

    this -> records = records;
    this -> size = size;

}

Dictionary::Dictionary(){ this -> size = 0; }

Dictionary::~Dictionary(){ delete[] this -> records; }

void Dictionary::add(const Record &newRecord){

    this -> records[this -> size] = newRecord;
    this -> size++;

}

void Dictionary::sort(){}

const char* Dictionary::findMeaning(const char *word){

    for(int i = 0; i < this -> size; i++)
        if(this -> records[i].compare(word))
            return this -> records[i].getMeaning();

}

const char* Dictionary::getByIndex(int index){ return this -> records[index].getMeaning(); }

char* Dictionary::toString(){

    char *result = new char[1];
    int index = 0;
    for(int i = 0; i < this -> size; i++){

        char *rec = this -> records[i].toString();
        for(int j = 0; rec[j] != '\0'; j++){

            result[index] = rec[j];
            index++;

        }

        result[index] = '\n';
        index++;

    }

    result[index] = '\0';
    
    return result;

}

bool Dictionary::remove(const char *word){

    for(int i = 0; i < this -> size; i++)
        if(this -> records[i].compare(word)){

            for(int j = 0; j < this -> size; j++)
                this -> records[i + j] = this -> records[i + j + 1];
            return true;

        }

    return false;

}