// Source : codewars.com/kata/5648b12ce68d9daa6b000099/train/javascript
// Diff : 7 Kyu

/*
There is a bus moving in the city, and it takes and drop some people in each bus stop.
You are provided with a list (or array) of integer pairs. Elements of each pair represent number of people get into bus (The first item) 
and number of people get off the bus (The second item) in a bus stop.

Your task is to return number of people who are still in the bus after the last bus station (after the last array). Even though it is the 
last bus stop, the bus is not empty and some people are still in the bus, and they are probably sleeping there :D
Take a look on the test cases.

Please keep in mind that the test cases ensure that the number of people in the bus is always >= 0. So the return integer can't be negative.
The second value in the first integer array is 0, since the bus is empty in the first bus stop.
*/

var number = function(busStops){
    var nbus = 0;
    var getin, getout;
    
    for(var i = 0; i < busStops.length; i++){
      getin = busStops[i][0];
      getout = busStops[i][1];
      nbus += (getin - getout);
    }
    
    return nbus;
}

// Test
var test1 = [[1,0], [2,0]];
var test2 = [[10,0], [0,10]];
var test3 = [[10,0], [5,10], [0,3]];
console.log(number(test1));
console.log(number(test2));
console.log(number(test3));