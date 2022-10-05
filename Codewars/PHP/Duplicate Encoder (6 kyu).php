<?php
/*
Source: https://www.codewars.com/kata/5259b20d6021e9e14c0010d4/train/php
Title: Reverse words
Diff: 6 kyu

Instruction
The goal of this exercise is to convert a string to a new string where each character in the new string is "(" if that character 
appears only once in the original string, or ")" if that character appears more than once in the original string. Ignore 
capitalization when determining if a character is a duplicate.

Examples
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" 
*/

function duplicate_encode($word) {
    $word = strtolower($word);
	$chars = str_split($word);
    $dict = getDict($word, $chars);
    $res = '';
    
    foreach($chars as $char) {
        $res .= $dict[$char];
    }
    return $res;
}

function getDict($word, $chars) {
    $dict = null;
    foreach($chars as $char) {
        if(substr_count($word, $char) == 1) $dict[$char] = '(';
        else $dict[$char] = ')';
    }
    return $dict;
}

function assertEquals($ans, $res) {
    if($ans == $res) echo "true\n";
    else echo "false\n";
}

assertEquals('(((', duplicate_encode('din'));
assertEquals('()()()', duplicate_encode('recede'));
assertEquals(')())())', duplicate_encode('Success'));
assertEquals('))))))', duplicate_encode('iiiiii'),);
assertEquals(')))))(', duplicate_encode(' ( ( )'));

/*
Possible better solution
function duplicate_encode(string $word) : string {
    $splittedWord = str_split(strtolower($word));
    $countMap = array_count_values($splittedWord);
    $finalString = '';
    foreach ($splittedWord as $letter)
        ($countMap[$letter] === 1) ? $finalString .= '(' : $finalString .= ')';
    return $finalString;
}
*/
?>