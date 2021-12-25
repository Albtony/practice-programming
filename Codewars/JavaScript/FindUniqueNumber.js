// Source : https://www.codewars.com/kata/585d7d5adb20cf33cb000235/train/javascript
// Diff : 6 Kyu

/*
There is an array with some numbers. All numbers are equal except for one. Try to find it!

findUniq([ 1, 1, 1, 2, 1, 1 ]) === 2
findUniq([ 0, 0, 0.55, 0, 0 ]) === 0.552
It’s guaranteed that array contains at least 3 numbers.

The tests contain some very huge arrays, so think about performance.
*/

function findUniq(arr) {
    // Karena uniq cuma ada 1, pasti index dari uniq = lastindex dari uniq 
    return arr.find(n => arr.indexOf(n) === arr.lastIndexOf(n));
}


// Test
const arr1 = [1, 1, 1, 2, 1, 1];
const arr2 = [0, 0, 0.55, 0, 0];
console.log(findUniq(arr1));
console.log(findUniq(arr2));