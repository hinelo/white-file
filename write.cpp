#include "StringOps.hpp"

int main(int argc, char const *argv[]) {
	string file = argv[1];
	string Str = readfile(file);
	int size;
	file = replace(file, " ", "_");
	file = replace(file, "\\", ".");
	file = replace(file, ".", " ");
	string* name = split(file,size);
    string bin;
  	for (char& _char : Str) {
        bin +=bitset<8>(_char).to_string();
    }

  	string tentativa = replace(bin, "1", " ");
  	tentativa = replace(tentativa, "0", "\t");

  	writefile(name[size-2]+".white", tentativa);
  	cout<< "arquivo salvo como: " << name[size-2]+".white" << endl;
  	system("pause");
  	delete[] name;
    return 0;
}