/*
Source: https://www.codewars.com/kata/53da3dbb4a5168369a0000fe/train/rust
Title: Even or Odd
Diff: 8 kyu

Instruction
Create a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.
*/

fn even_or_odd(i: i32) -> &'static str {
    if i & 1 == 1 {
        return "Odd"
    } else {
        return "Even"
    }
}

fn main() {
    assert_eq!(even_or_odd(0), "Even");
    assert_eq!(even_or_odd(2), "Even");
    assert_eq!(even_or_odd(1), "Odd");
    assert_eq!(even_or_odd(7), "Odd");
    assert_eq!(even_or_odd(-1), "Odd");
    println!("solution has passed all of the defined testcases");
}