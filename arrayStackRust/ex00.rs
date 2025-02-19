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

    fn length(&self) -> usize {
        self.stack.len()
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

    let mut s = Stack::new();

    let path = Path::new(&args[1]);
    let file = File::open(&path)?;
    let reader = io::BufReader::new(file);

    for line in reader.lines() {
        let line = line?;
        s.push(line);
    }
    for _i in 0..s.length() {
        println!("{}", s.pop().unwrap());
    }
    Ok(())
}