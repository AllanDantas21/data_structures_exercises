//
// Leia as primeiras 50 linhas de entrada e depois escreva-as em ordem
// inversa. Leia as próximas 50 linhas e depois escreva-as em ordem
// inversa. Faça isso até que não haja mais linhas deixadas para ler,
// neste ponto, quaisquer linhas restantes devem ser impressas na ordem inversa.
//
use std::env;
use std::fs::File;
use std::path::Path;
use std::io::{self, BufRead};

struct Stack<T> {
    stack: Vec<T>,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack { stack: Vec::new() }
    }

    fn is_empty(&self) -> bool {
        self.stack.is_empty()
    }

    fn pop(&mut self) -> Option<T> {
        self.stack.pop()
    }

    fn push(&mut self, item: T) {
        self.stack.push(item)
    }
}

fn main() -> io::Result<()> {
    let args: Vec<String> = env::args().collect();

    if args.len() != 2 {
        eprintln!("Usage: {} <file_path>", args[0]);
        return Err(io::Error::new(io::ErrorKind::InvalidInput, "Invalid number of arguments"));
    }

    let path = Path::new(&args[1]);
    let file = File::open(&path)?;
    let reader = io::BufReader::new(file);
    let mut lines_iter = reader.lines();
    
    let mut stack = Stack::new();
    
    loop {
        let mut count = 0;
        
        while count < 50 {
            match lines_iter.next() {
                Some(Ok(line)) => {
                    stack.push(line);
                    count += 1;
                },
                Some(Err(e)) => return Err(e),
                None => break,
            }
        }
    
        if count == 0 {
            break;
        }
        
        while !stack.is_empty() {
            if let Some(line) = stack.pop() {
                println!("{}", line);
            }
        }
    }
    
    Ok(())
}
