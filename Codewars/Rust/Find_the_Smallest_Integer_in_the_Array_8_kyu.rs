/*
Source: https://www.codewars.com/kata/55a2d7ebe362935a210000b2/rust
Title: Find the smallest integer in the array
Diff: 8 kyu

Instruction:
Given an array of integers your solution should find the smallest integer.

For example:

Given [34, 15, 88, 2] your solution will return 2
Given [34, -345, -1, 100] your solution will return -345
You can assume, for the purpose of this kata, that the supplied array will not be empty.
*/

fn find_smallest_int(arr: &[i32]) -> i32 {
    let mut min = i32::MAX;
    for i in 0..arr.len() {
        if arr[i] < min {
            min = arr[i];
        }
    }

    return min;
}

fn main() {
    assert_eq!(find_smallest_int(&[34, 15, 88, 2]), 2);
    assert_eq!(find_smallest_int(&[34, -345, -1, 100]), -345);
    println!("solution has passed all of the defined testcases");
}