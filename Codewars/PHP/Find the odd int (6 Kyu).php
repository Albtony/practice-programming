<?php
/*
Source: https://www.codewars.com/kata/54da5a58ea159efa38000836/train/php
Title: Find the Odd Int
Diff: 6 kyu

Instruction
Given an array of integers, find the one that appears an odd number of times.
There will always be only one integer that appears an odd number of times.

Examples
[7] should return 7, because it occurs 1 time (which is odd).
[0] should return 0, because it occurs 1 time (which is odd).
[1,1,2] should return 2, because it occurs 1 time (which is odd).
[0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
[1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
*/

function findIt(array $seq) : int {
    foreach($seq as $num) {
        $count = count(array_keys($seq, $num));
        if($count & 1) return $num;
    }
    return -1;
}

function assertEquals($ans, $res) {
    if($ans == $res) echo "true\n";
    else echo "false\n";
}

assertEquals(5, findIt([20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5]));
assertEquals(-1, findIt([1,1,2,-2,5,2,4,4,-1,-2,5]));
assertEquals(5, findIt([20,1,1,2,2,3,3,5,5,4,20,4,5]));
assertEquals(10, findIt([10]));
assertEquals(10, findIt([1,1,1,1,1,1,10,1,1,1,1]));
?>