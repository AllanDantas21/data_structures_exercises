#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>

void process_lines(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open())
        return(std::cerr << "Erro ao abrir o arquivo: \n", void());
    std::unordered_set<std::string> seen_once;
    std::unordered_set<std::string> printed;
    std::string line;

    while (std::getline(infile, line)) {
        if (seen_once.emplace(line).second)
            continue;
        if (printed.emplace(line).second)
            std::cout << line << std::endl;
    }

    infile.close();
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo>" << std::endl;
        return 1;
    }
    process_lines(argv[1]);
    return 0;
}