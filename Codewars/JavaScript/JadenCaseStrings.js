// Source : https://www.codewars.com/kata/5390bac347d09b7da40006f6/train/javascript
// Diff : 7 Kyu

/* 
Jaden Smith, the son of Will Smith, is the star of films such as The Karate Kid (2010) and After Earth (2013). Jaden is also known for 
some of his philosophy that he delivers via Twitter. When writing on Twitter, he is known for almost always capitalizing every word. For 
simplicity, you'll have to capitalize each word, check out how contractions are expected to be in the example below.

Your task is to convert strings to how they would be written by Jaden Smith. The strings are actual quotes from Jaden Smith, but they are 
not capitalized in the same way he originally typed them.
*/

String.prototype.toJadenCase = function () {
    var res = '';
    const arr = this.toLowerCase().split(' ');
    console.log(arr);
    for(var index in arr){ 
        res += arr[index].charAt(0).toUpperCase() + arr[index].slice(1) + ' ';
    }

    return res.substring(0, res.length-1);
}

// Test
console.log("my passion is burning".toJadenCase());
console.log("how can mirrors be real if our eyes aren't real".toJadenCase());