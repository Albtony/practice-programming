// Source : https://www.codewars.com/kata/55f2b110f61eb01779000053/train/javascript
// Diff : 7 Kyu

/*
Description:
Given two integers a and b, which can be positive or negative, find the sum of all the integers between and including them and return it. If the two numbers are equal return a or b.

Note: a and b are not ordered!

Examples (a, b) --> output (explanation)
(1, 0) --> 1 (1 + 0 = 1)
(1, 2) --> 3 (1 + 2 = 3)
(0, 1) --> 1 (0 + 1 = 1)
(1, 1) --> 1 (1 since both are same)
(-1, 0) --> -1 (-1 + 0 = -1)
(-1, 2) --> 2 (-1 + 0 + 1 + 2 = 2)
 */

function getSum(a, b) {
    var max = Math.max(a, b);
    var min = Math.min(a, b);

    // Sum of n unit with d = 1, arithmetic
    return (max - min + 1) / 2 * (max + min);
}

// Test
console.log(getSum(0,100));
console.log(getSum(1,0));
console.log(getSum(-1,2));
console.log(getSum(1,2));
