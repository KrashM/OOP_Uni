#include <fstream>

using std::ofstream;
using std::ios;

size_t getFileSize(ofstream &out){

    size_t currentPosition = in.tellp();
	out.seekg(ios::beg, ios::end);
    size_t size = out.tellp();

    out.seekp(ios::beg, currentPosition);

	return size;

}

void changeContent(ofstream &out){

    out.open("file.txt");

    size_t size = getFileSize(out);

    for(int i = 0; i < size; i++){

        out.put('H');
        out.seekp(ios::beg, i);

    }

    out.close();

}

int main(){

    ofstream out;
    changeContent(out);

}