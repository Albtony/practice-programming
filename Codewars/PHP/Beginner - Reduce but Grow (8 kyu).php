<?php
/*
Source: https://www.codewars.com/kata/57f780909f7e8e3183000078/php
Title: Beginner - Reduce but Grow
Diff: 8 kyu

Instruction
Given a non-empty array of integers, return the result of multiplying the values together in order. Example:
[1, 2, 3, 4] => 1 * 2 * 3 * 4 = 24
*/

function grow($a) {
    $res = 1;
    foreach($a as $elem) 
        $res *= $elem;
    return $res;
}

function check($res, $ans) {
    if($res == $ans) echo "true\n";
    else echo "false\n";
}

check(grow([1, 2, 3]), 6);
check(grow([4, 1, 1, 1, 4]), 16);
check(grow([2, 2, 2, 2, 2, 2]), 64);

/*
Possibly better solution
function grow($a) {
    return array_product($a);
}
*/
?>