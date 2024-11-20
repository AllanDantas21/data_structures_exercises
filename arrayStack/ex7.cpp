//
// 7. Faça o mesmo que a pergunta anterior, 
// exceto que as linhas duplicadas devem ser impressas o 
// mesmo número de vezes que aparecem
// na entrada.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main(int argc, char **argv){
    if (argc != 2)
        return (1);
    std::fstream file(argv[1]);;
    std::vector<std::string> lines;
    std::string line;

    if (!file.is_open())
        return (1);
    while (std::getline(file, line)){
        lines.push_back(line);
    }

    std::sort(lines.begin(), lines.end(), [](const std::string& a, const std::string& b) {
        if (a.length() == b.length()) {
            return (a < b);
        }
        return (a.length() < b.length());
    });
    
    for (const auto& l : lines){
        std::cout << l << std::endl;
    }
    return 0;
}