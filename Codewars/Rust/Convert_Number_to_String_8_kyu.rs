/*
Source: https://www.codewars.com/kata/5265326f5fda8eb1160004c8/train/rust
Title: Convert a Number to a String!
Diff: 8 kyu

Instruction
We need a function that can transform a number (integer) into a string.
What ways of achieving this do you know?

Examples (input --> output):
123  --> "123"
999  --> "999"
-100 --> "-100"
*/

fn number_to_string(i: i32) -> String {
    return i.to_string();
}

fn main() {
    assert_eq!("-2147483648", number_to_string(i32::MIN));
    assert_eq!("-1", number_to_string(-1i32));
    assert_eq!("0", number_to_string(0i32));
    assert_eq!("1", number_to_string(1i32));
    assert_eq!("2147483647", number_to_string(i32::MAX));

    assert_eq!("123", number_to_string(123i32));
    assert_eq!("999", number_to_string(999i32));
    assert_eq!("-100", number_to_string(-100i32));
    println!("solution has passed all of the defined testcases");
}