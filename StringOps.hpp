// StringOps.hpp
#ifndef STRINGOPS_HPP
#define STRINGOPS_HPP
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <bitset>
using namespace std;

//bool result = include("hello world", "world") 
inline bool include(const std::string& str, const std::string& substr) {
    return str.find(substr) != std::string::npos;
}

// int size;
// string* result = split("hello world", size)
inline string* split(const string& str, int& numPalavras) {
    std::istringstream stream(str);
    std::string palavra;
    numPalavras = 0;
    while (stream >> palavra) {
        ++numPalavras;
    }
    stream.clear();
    stream.seekg(0, std::ios::beg);
    std::string* palavras = new std::string[numPalavras];
    for (int i = 0; i < numPalavras; ++i) {
        stream >> palavras[i];
    }
    return palavras;
} 

//string* result = split("hello world")
inline string* split(const std::string& str) {
    int numPalavras = 0; // Inicializa numPalavras com 0
    return split(str, numPalavras); // Chama a versão principal da função com numPalavras fornecido
}

//string result = replace("hello owor", "owor", "world!");
inline std::string replace(const std::string& str, const std::string& de, const std::string& para) {
    std::string resultado = str;
    size_t pos = 0;
    while ((pos = resultado.find(de, pos)) != std::string::npos) {
        resultado.replace(pos, de.length(), para);
        pos += para.length(); // Move a posição para frente após a substituição
    }
    return resultado;
}

//string file = readtxt("myfile.txt")
inline string readtxt(const string& file) {
    string result;
    string line;
    ifstream myfile (file);
    if (myfile.is_open()) {
        while(getline(myfile, line)) {
            result += line + "\n";
        }
        myfile.close();
        result.pop_back();
    }
    else cout << "Unable to open file\n";
    return result;
}

// bool result = writetxt("myfile.txt", "hello world!");
inline bool writetxt(const std::string& nomeArquivo, const std::string& conteudo) {
    std::ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        arquivo << conteudo;
        arquivo.close();
        return true;
    } else {
        return false;
    }
}
//string file = readfile("myfile.txt")
inline string readfile(const string& file) {
    string result;
    ifstream myfile(file, ios::binary);
    if (myfile.is_open()) {
        stringstream buffer;
        buffer << myfile.rdbuf();
        result = buffer.str();
        myfile.close();
    } else {
        cout << "Unable to open file\n";
    }
    return result;
}
//bool result = writeFile("myfile.txt", "hello world!");
inline bool writefile(const std::string& nomeArquivo, const std::string& conteudo) {
    ofstream arquivo(nomeArquivo, ios::binary);
    if (arquivo.is_open()) {
        arquivo.write(conteudo.c_str(), conteudo.size());
        arquivo.close();
        return true;
    } else {
        return false;
    }
}
#endif