#include "StringOps.hpp"

int main(int argc, char const *argv[]){ 
	string file = argv[1];
	int size;
	file = replace(file, " ", "_");
	file = replace(file, "\\", " ");
	file = replace(file, ".", " ");
	string* name = split(file,size);

	cout << "escolha a extensao do arquivo: (ex: .txt, .png, etc)" << endl;
	cout << name[size-2] << ".";
	string ext;
	getline(cin, ext);

  	string str;
	string bin = readfile(name[size-2]+"."+name[size-1]);
	bin = replace(bin, " ", "1");
	bin = replace(bin, "\t", "0");

	for (size_t i = 0; i < bin.size(); i += 8) {
        bitset<8> bits(bin.substr(i, 8));
        str += static_cast<char>(bits.to_ulong());
    }

    writefile(name[size-2]+"."+ext, str);
    system(("start "+name[size-2]+"."+ext).c_str());
  	return 0;
}