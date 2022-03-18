#ifndef RECORD
#define RECORD

class Record{

    private:
        const char *word, *meaning;

    public:
        Record(const char *word, const char *meaning);
        Record(const Record &rec);
        Record();
        ~Record();

        void setWord(const char *word);
        void setMeaning(const char *meaning);
        const char* getMeaning();
        char *toString();
        bool compare(const char *word);

};

#endif