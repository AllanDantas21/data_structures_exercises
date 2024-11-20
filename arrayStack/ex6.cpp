//
// 6. Leia toda a entrada uma linha de cada vez. Em seguida, imprima
// todas as linhas ordenadas por comprimento, com as linhas mais curtas primeiro. No caso em que duas linhas tenham o mesmo comprimento, resolva sua ordem usando a “ordem classificada”. As linhas
// duplicadas devem ser impressas apenas uma vez.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;
    std::fstream file(argv[1]);;
    std::vector<std::string> lines;
    std::string line;

    if (!file.is_open())
        return (1);
    while (std::getline(file, line)){
        lines.push_back(line);
    }
    std::set<std::string> unique_lines(lines.begin(), lines.end());
    lines.assign(unique_lines.begin(), unique_lines.end());
    unique_lines.erase("");

    std::sort(lines.begin(), lines.end(), [](const std::string& a, const std::string& b) {
        if (a.length() == b.length()) {
            return (a < b);
        }
        return (a.length() < b.length());
    });
    
    for (const auto& l : lines) {
        std::cout << l << std::endl;
    }
    return 0;
}