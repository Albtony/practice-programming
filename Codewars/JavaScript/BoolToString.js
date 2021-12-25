// Source : https://www.codewars.com/kata/53369039d7ab3ac506000467/train/javascript
// Diff : 8 Kyu

/* 
Complete the method that takes a boolean value and return a "Yes" string for true, or a "No" string for false.
*/

function boolToWord( bool ){
    if(bool)
      return 'Yes';
    else
      return 'No';
}

// Test
console.log(boolToWord(true));
console.log(boolToWord(true))