// Source : https://www.codewars.com/kata/54ff3102c1bad923760001f3/train/javascript
// Diff : 7 kyu

/*
Return the number (count) of vowels in the given string.

We will consider a, e, i, o, u as vowels for this Kata (but not y).

The input string will only consist of lower case letters and/or spaces.
*/

function getCount(str) {
    var vowelsCount = 0;
    
    for(var i = 0; i < str.length; i++){
      var chr = str.charAt(i);
      var check = ['a', 'i', 'u', 'e', 'o'];
      for(var j = 0; j < check.length; j++){
        if(chr == check[j])
            vowelsCount++;
      }
    }
    
    return vowelsCount;
}

// Test 
console.log(getCount('Baba Booey'));
console.log(getCount('aiueo'));