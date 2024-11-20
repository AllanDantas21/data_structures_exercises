//
// 9. Leia toda a entrada uma linha de cada vez e permute aleatoriamente
// as linhas antes de imprimi-las. 
// Para ser claro: Você não deve modificar o conteúdo de qualquer linha.
// Em vez disso, a mesma coleção
// de linhas deve ser impressa, mas em uma ordem aleatória....
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

int main() {
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(std::cin, line)){
        lines.push_back(line);
    }

    // add randomizer

    for (const auto& l : lines) {
        std::cout << l << std::endl;
    }
    return (0);
}