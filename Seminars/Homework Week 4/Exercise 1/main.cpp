#include <iostream>
#include "Dictionary.h"
#include "Record.h"

using std::cin;
using std::cout;

int main(){

    Dictionary myDict = Dictionary();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){

        char *word = new char[1], *meaning = new char[1];
        cout << "Enter word and meaning\n";
        cin >> word >> meaning;
        Record rec = Record(word, meaning);
        myDict.add(rec);

    }

    cout << "Done with records\n";
    cout << myDict.toString() <<'\n';

    char *word = new char[1];
    cout << "Enter word\n";
    cin >> word;

    cout << myDict.findMeaning(word) << '\n';
    cout << myDict.remove(word) << '\n';

    int index;
    cin >> index;

    cout << myDict.getByIndex(index) << '\n';

    cout << "Getting sorted\n";
    myDict.sort();
    cout << myDict.toString() << '\n';

}

/*
4
sa
wasd
mol
molly
mol
moal
q
quit
*/