#ifndef DICTIONARY
#define DICTIONARY
#include "Record.h"

class Dictionary{

    private:
        Record *records = new Record[500];
        int size;

    public:
        Dictionary(Record *records, int size);
        Dictionary();
        ~Dictionary();

        void add(const Record &newRecord);
        void sort();
        const char* findMeaning(const char *word);
        const char* getByIndex(int index);
        char* toString();
        bool remove(const char *word);

};

#endif