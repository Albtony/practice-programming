<?php 
/*
Source: https://www.codewars.com/kata/5259b20d6021e9e14c0010d4/train/php
Title: Reverse words
Diff: 7 kyu

Instruction
Complete the function that accepts a string parameter, and reverses each word in the string. All spaces in the string should be retained.

Examples
"This is an example!" ==> "sihT si na !elpmaxe"
"double  spaces"      ==> "elbuod  secaps"
*/

function reverseWords($str) {
    $res = '';
    $words = explode(' ', $str);
    
    foreach($words as $word) {
        $chars = str_split($word);
        for($i = count($chars)-1; $i >= 0; $i--)
            $res .= $chars[$i];
        $res .= ' ';
    }

    $res = substr($res, 0, -1);
    return $res;
}

function assertEquals($ans, $res) {
    if($ans == $res) echo "true\n";
    else echo "false\n";
}

assertEquals('ehT kciuq nworb xof spmuj revo eht yzal .god', reverseWords('The quick brown fox jumps over the lazy dog.'));
assertEquals('elppa', reverseWords('apple'));
assertEquals('a b c d', reverseWords('a b c d'));
assertEquals('elbuod  decaps  sdrow', reverseWords('double  spaced  words'));
assertEquals('desserts stressed', reverseWords('stressed desserts'));
assertEquals('olleh olleh', reverseWords('hello hello'));

/*
Possible better solution

function reverseWords($str) {
    return implode(' ', array_reverse(explode(' ', strrev($str))));
}
*/
?>