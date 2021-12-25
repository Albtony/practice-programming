// Source : https://www.codewars.com/kata/558fc85d8fd1938afb000014/train/javascript
// Diff : 7 Kyu

/*
Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. 
No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.
*/

function sumTwoSmallestNumbers(numbers) {
    var min1 = Number.MAX_SAFE_INTEGER;
    var min2 = Number.MAX_SAFE_INTEGER;

    for (var i = 0; i < numbers.length; i++)
        if (min1 > numbers[i])
            min1 = numbers[i];

    for (var i = 0; i < numbers.length; i++)
        if (min2 > numbers[i] && numbers[i] >= min1)
            min2 = numbers[i];

    return min1 + min2;
}

// Test
const arr1 = [2,2,2,2,2];
const arr2 = [1,2,3,4,5];
const arr3 = [100,99,98,97,96];
console.log(sumTwoSmallestNumbers(arr1));
console.log(sumTwoSmallestNumbers(arr2));
console.log(sumTwoSmallestNumbers(arr3));
