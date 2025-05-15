// Source : https://www.codewars.com/kata/57eb936de1051801d500008a/javascript
// Diff : 5 Kyu

/*
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

moveZeros([false,1,0,1,2,0,1,3,"a"]) // returns[false,1,1,2,1,3,"a",0,0]
*/

function moveZeros(arr) {
    let zeroCount = 0;
    for (let i = 0; i < arr.length - zeroCount; i++) {
        if (arr[i] === 0) {
        zeroCount++;
        arr.splice(i, 1);
        arr.push(0)
        i--; 
        }
    }
    return arr;
}

function betterMoveZeros(arr) {
    return arr => [
            ...arr.filter(n => n !== 0),
            ...arr.filter(n => n === 0)
        ];
}