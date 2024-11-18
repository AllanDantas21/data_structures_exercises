//
//1. Leia a entrada de uma linha de cada vez e, em seguida, escreva as
//linhas em ordem inversa, de modo que a última linha de entrada
//seja impressa primeiro, depois a segunda última linha de entrada, e
//assim por diante.
//
#include <iostream>
#include <fstream>
#include <stack>

int main(int argc, char **argv)
{
  if (argc != 2)
    return 0;
  
  std::ifstream file(argv[1]);
  if (!file)
    std::cerr << "Erro ao abrir o arquivo\n";

  std::stack<std::string> all_lines;
  std::string line = "";
  while(std::getline(file, line))
    all_lines.push(line);
  while(!all_lines.empty())
  {
    std::cout << all_lines.top() << std::endl;
    all_lines.pop();
  }
  file.close();
  return (0);
}

