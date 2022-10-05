<?php
/*
Source: https://www.codewars.com/kata/57356c55867b9b7a60000bd7/train/php
Title: Basic Mathematical Operations
Diff: 8 kyu

Instruction
Your task is to create a function that does four basic mathematical operations.

The function should take three arguments - operation(string/char), value1(number), value2(number).
The function should return result of numbers after applying the chosen operation.

Examples(Operator, value1, value2) --> output
('+', 4, 7) --> 11
('-', 15, 18) --> -3
('*', 5, 5) --> 25
('/', 49, 7) --> 7
*/

function basicOp($op, $val1, $val2) {
    if($op == '+') return $val1 + $val2;
    else if($op == '-') return $val1 - $val2;
    else if($op == '*') return $val1 * $val2;
    else if($op == '/') return $val1 / $val2;
}

function check($res, $ans) {
    if($res == $ans) echo "true\n";
    else echo "false\n";
}

check(basicOp('+', 4, 7), 11);
check(basicOp('-', 15, 18), -3);
check(basicOp('*', 5, 5), 25);
check(basicOp('/', 49, 7), 7);

/*
Possible better solution
function basicOp($op, $val1, $val2) {
    switch ($op) {
        case '+': return $val1 + $val2;
        case '-': return $val1 - $val2;
        case '*': return $val1 * $val2;
        case '/': return $val1 / $val2;
    }
}
*/
?>
