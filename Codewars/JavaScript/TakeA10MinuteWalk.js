// Source : https://www.codewars.com/kata/54da539698b8a2ad76000228/train/javascript
// Diff : 6 Kyu

/*
Description:
You live in the city of Cartesia where all roads are laid out in a perfect grid. You arrived ten minutes too early to an appointment, 
so you decided to take the opportunity to go for a short walk. The city provides its citizens with a Walk Generating App on their phones 
-- everytime you press the button it sends you an array of one-letter strings representing directions to walk (eg. ['n', 's', 'w', 'e']). 
You always walk only a single block for each letter (direction) and you know it takes you one minute to traverse one city block, so create 
a function that will return true if the walk the app gives you will take you exactly ten minutes (you don't want to be early or late!) and 
will, of course, return you to your starting point. Return false otherwise.

Note: you will always receive a valid array containing a random assortment of direction letters ('n', 's', 'e', or 'w' only). It will never 
give you an empty array (that's not a walk, that's standing still!).
*/

function isValidWalk(walk) {
    var dx = 0
    var dy = 0
    var dt = walk.length

    for (var i = 0; i < walk.length; i++) {
        switch (walk[i]) {
            case 'n': dy--; break
            case 's': dy++; break
            case 'w': dx--; break
            case 'e': dx++; break
        }
    }

    return dt === 10 && dx === 0 && dy === 0
}

// Test
var fail =
    [
        ['n'],
        ['n', 's'],
        ['n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'],
        ['n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's', 'e', 'w'],
        ['n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 'n'],
        ['e', 'e', 'e', 'w', 'n', 's', 'n', 's', 'e', 'w'],
        ['n', 'e', 'n', 'e', 'n', 'e', 'n', 'e', 'n', 'e'],
        ['n', 'w', 'n', 'w', 'n', 'w', 'n', 'w', 'n', 'w'],
        ['e', 's', 'e', 's', 'e', 's', 'e', 's', 'e', 's'],
        ['w', 's', 'w', 's', 'w', 's', 'w', 's', 'w', 's'],
    ];


var pass =
    [
        ['n', 's', 'n', 's', 'n', 's', 'n', 's', 'n', 's'],
        ['e', 'w', 'e', 'w', 'n', 's', 'n', 's', 'e', 'w'],
        ['n', 's', 'e', 'w', 'n', 's', 'e', 'w', 'n', 's'],
        ['n', 'n', 'n', 's', 's', 's', 'e', 'w', 'n', 's'],
    ];

for (var i = 0; i < pass.length; i++)
    console.log(isValidWalk(pass[i]))

for (var i = 0; i < fail.length; i++)
    console.log(isValidWalk(fail[i]))