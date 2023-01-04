/*
Source: https://www.codewars.com/kata/5556282156230d0e5e000089/rust
Title: Will you make it?
Diff: 8 kyu

Instruction
You were camping with your friends far away from home, but when it's time to go back, you realize that your fuel is running out and the nearest pump is 50 miles away! 
You know that on average, your car runs on about 25 miles per gallon. There are 2 gallons left.

Considering these factors, write a function that tells you if it is possible to get to the pump or not.

Function should return true if it is possible and false if not.
*/

fn zero_fuel(distance_to_pump: u32, mpg: u32, gallons: u32) -> bool {
    if mpg * gallons >= distance_to_pump { 
        return true 
    } else { 
        return false 
    }
}

fn main() {
    assert_eq!(zero_fuel(50, 25, 2), true);
    assert_eq!(zero_fuel(100, 50, 1), false);
    println!("solution has passed all of the defined testcases");
}