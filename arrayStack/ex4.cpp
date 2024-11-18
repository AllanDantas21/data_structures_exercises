//
//Leia a entrada uma linha de cada vez e escreva cada linha na saída
//se não for uma duplicata de alguma linha de entrada anterior. Tome
//especial cuidado para que um arquivo com um monte de linhas duplicadas não use mais memória do que o necessário para o número
//de linhas únicas.
//
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

int main(int argc, char **argv){
    std::unordered_set<std::string> seenLines;
    std::string line;
    std::fstream file(argv[1]);

    if (argc != 2)
      return (file.close(), 0);
    while (std::getline(file, line)){
        if (seenLines.find(line) == seenLines.end()){
            seenLines.insert(line);
            std::cout << line << std::endl;       
      }
    }
    return (0);
}

