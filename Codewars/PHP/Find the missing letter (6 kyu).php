<?php
/*
Source: https://www.codewars.com/kata/5839edaa6754d6fec10000a2/php
Title: Find the missing letter
Diff: 6 kyu

Instruction
Write a method that takes an array of consecutive (increasing) letters as input and that returns the missing letter in the array.
You will always get an valid array. And it will be always exactly one letter be missing. The length of the array will always be at 
least 2.
The array will always contain letters in only one case.

Example:
['a','b','c','d','f'] -> 'e'
['O','Q','R','S'] -> 'P'
*/

function find_missing_letter(array $array): string {
    $alph = str_split("abcdefghijklmnopqrstuvwxyz");
    $islower = ctype_lower(reset($array));
    $start = ord(strtolower(reset($array))) - 97;
    $end = ord(strtolower(end($array))) - 97;

    for($i = $start; $i < $end; $i++) {
        if(strtolower($array[$i-$start]) != $alph[$i])
            if($islower) return $alph[$i];
            else return strtoupper($alph[$i]);
    }
    return "";
}

function assertEquals($ans, $res) {
    if($ans == $res) echo "true\n";
    else echo "false\n";
}

assertEquals("e", find_missing_letter(['a','b','c','d','f']));
assertEquals("P", find_missing_letter(["O", "Q", "R", "S"]));

/*
Possible better solution
function find_missing_letter(array $array): string {
    $expected = range(current($array), end($array));
    $missing = array_diff($expected, $array);
    return end($missing);
}
*/
?>