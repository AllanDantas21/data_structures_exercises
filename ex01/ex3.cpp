//
//3. Leia a entrada uma linha de cada vez. Em qualquer ponto depois
//de ler as primeiras 42 linhas, se alguma linha estiver em branco (ou
//seja, uma sequência de comprimento 0), imprima a linha que ocorreu 42 linhas anteriores a essa. Por exemplo, se a Linha 242 estiver
//em branco, então seu programa deve imprimir a linha 200. Este programa deve ser implementado de modo que nunca armazene mais
//de 43 linhas da entrada a qualquer momento.
//

#include <iostream>
#include <fstream>
#include <queue>

void add_with_limit(std::queue<std::string> &queue, std::string &line)
{
  if (queue.size() == 42)
    queue.pop();
  queue.push(line);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    return (0);
  std::fstream file(argv[1]);
  if(!file)
    return(std::cerr << "Erro ao abrir o arquivo", 0);
  std::queue<std::string> queue;
  std::string line;
  while(!file.eof()){
    std::getline(file, line);
    add_with_limit(queue, line);
    if (line.size() == 0 && queue.size() == 42)
      std::cout << queue.front();
  }
  file.close();
  return (0);
}
