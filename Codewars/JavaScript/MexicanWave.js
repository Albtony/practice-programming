// Source : https://www.codewars.com/kata/58f5c63f1e26ecda7e000029/javascript
// Diff : 6 Kyu

/*
Task
In this simple Kata your task is to create a function that turns a string into a Mexican Wave. You will be passed a string 
and you must return an array of strings where an uppercase letter is a person standing up.

Rules
1.  The input string will always consist of lowercase letters and spaces, but may be empty, in which case you must return an empty array. 
2.  If the character in the string is whitespace then pass over it as if it was an empty seat

Examples
"hello" => ["Hello", "hEllo", "heLlo", "helLo", "hellO"]
" s p a c e s " => [ " S p a c e s ", " s P a c e s ", " s p A c e s ", " s p a C e s ", " s p a c E s ", " s p a c e S "]
*/

function wave(str) {
    const result = [];
    for (let i = 0; i < str.length; i++) {
        const char = str[i];
        if (char !== ' ') {
            const newStr = str.slice(0, i) + char.toUpperCase() + str.slice(i + 1);
            result.push(newStr);
        }
    }
    return result;
}

console.log("wazzup");
console.log("bet ya can't do this")
console.log("nevermind")

