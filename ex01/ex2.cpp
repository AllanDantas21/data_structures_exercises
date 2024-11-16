//
//Leia as primeiras 50 linhas de entrada e depois escreva-as em ordem
//inversa. Leia as próximas 50 linhas e depois escreva-as em ordem/
//inversa. Faça isso até que não haja mais linhas deixadas para ler,
//neste ponto, quaisquer linhas restantes devem ser impressas na ordem inversa.

#include <iostream>
#include <stack>
#include <fstream>

int main(int argc, char **argv)
{
  if (argc != 2)
    return (0);

  std::fstream file(argv[1]);
  if (!file)
    return (std::cerr << "Erro ao abrir o arquivo", 0);
  
  std::stack<std::string> stack;
  std::string line;
  while (!file.eof())
  {
    for (int i = 0; i <= 50; i++){
     std::getline(file, line);
     stack.push(line);
    }
    while(!stack.empty()){
      std::cout << stack.top() << std::endl;
      stack.pop();
    }
  }
  file.close();
  return 0;
}
