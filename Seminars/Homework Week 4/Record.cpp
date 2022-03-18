#include "Record.h"

Record::Record(const char *word, const char *meaning){

    this -> word = word;
    this -> meaning = meaning;

}

Record::Record(const Record &rec){

    this -> word = rec.word;
    this -> meaning = rec.meaning;

}

Record::Record(){

    this -> word = new char[0];
    this -> meaning = new char[0];

}

Record::~Record(){

    delete[] this -> word;
    delete[] this -> meaning;

}

void Record::setWord(const char *word){ this -> word = word; }
void Record::setMeaning(const char *meaning){ this -> meaning = meaning; }
const char* Record::getMeaning(){ return this -> meaning; }

char* Record::toString(){

    char *result = new char[1];
    int i;
    for(i = 0; this -> word[i] != '\0'; i++)
        result[i] = this -> word[i];
    result[i] = '-';
    i++;
    for(i = 0; this -> word[i] != '\0'; i++)
        result[i] = this -> meaning[i];
    result[i] = '\0';

    return result;

}

bool Record::compare(const char *word){

    int i;
    for(i = 0; this -> word[i] != '\0' || word[i] != '\0'; i++)
        if(this -> word[i] != word[i]) return false;
    if(this -> word[i] != word[i]) return false;

    return true;

}