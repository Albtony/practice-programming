// Source : https://www.codewars.com/kata/57eb936de1051801d500008a/javascript
// Diff : 7 Kyu

/*
Description:
You are given an initial 2-value array (x). You will use this to calculate a score.

If both values in (x) are numbers, the score is the sum of the two. If only one is a number, the score is that number. If neither is a number, return 'Void!'.

Once you have your score, you must return an array of arrays. Each sub array will be the same as (x) and the number of sub arrays should be equal to the score.

For example:

if (x) == ['a', 3] you should return [['a', 3], ['a', 3], ['a', 3]].
*/

function explode(x){
    let res = [];
    let score = calcScore(x);
    
    if (score == null) return "Void!";
    else while(score--) res.push(x);
    
    return res;
}

function calcScore(x) {
    if (typeof(x[0]) == "number" && typeof(x[1]) == "number") return x[0] + x[1];
    if (typeof(x[0]) == "number") return x[0];
    if (typeof(x[1]) == "number") return x[1];
    return null;
}

// test
console.log(explode(['a', '3']));
console.log(explode(['a', 3]));
console.log(explode([3, 'a']));
console.log(explode([3, 3]));
