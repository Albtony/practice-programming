/**
Source: https://www.codewars.com/kata/5a651865fd56cb55760000e0/train/java
Diff: 7 Kyu
Definition
An element is leader if it is greater than The Sum all the elements to its right side.

Task
Given an array/list [] of integers , Find all the LEADERS in the array.

Notes
Array/list size is at least 3 .

Array/list's numbers Will be mixture of positives , negatives and zeros
Repetition of numbers in the array/list could occur.
Returned Array/list should store the leading numbers in the same order in the original array/list .

Input >> Output Examples
arrayLeaders ({1, 2, 3, 4, 0}) ==> return {4}
Explanation:
4 is greater than the sum all the elements to its right side
Note : The last element 0 is equal to right sum of its elements (abstract zero).

arrayLeaders ({16, 17, 4, 3, 5, 2}) ==> return {17, 5, 2}
Explanation:
17 is greater than the sum all the elements to its right side
5 is greater than the sum all the elements to its right side
Note : The last element 2 is greater than the sum of its right elements (abstract zero).

arrayLeaders ({5, 2, -1}) ==> return {5, 2}
Explanation:
5 is greater than the sum all the elements to its right side
2 is greater than the sum all the elements to its right side
Note : The last element -1 is less than the sum of its right elements (abstract zero).

arrayLeaders ({0, -1, -29, 3, 2}) ==> return {0, -1, 3, 2}
Explanation:
0 is greater than the sum all the elements to its right side
-1 is greater than the sum all the elements to its right side
3 is greater than the sum all the elements to its right side
Note : The last element 2 is greater than the sum of its right elements (abstract zero).
 */


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ArrayLeaders {
    public static List<Integer> arrayLeaders(int[] numbers) {
        List<Integer> res = new ArrayList<>();
        int currSum = 0;
        for (int i = numbers.length-1; i >= 0; i--) {
            if(numbers[i] > currSum) res.add(0, numbers[i]);
            currSum += numbers[i];
        }

        return res;
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert ArrayLeaders.arrayLeaders(new int[] {1,2,3,4,0}).equals(Arrays.asList(4)) : errorMessage;
        assert ArrayLeaders.arrayLeaders(new int[] {16,17,4,3,5,2}).equals(Arrays.asList(17,5,2)) : errorMessage;
        assert ArrayLeaders.arrayLeaders(new int[] {-1,-29,-26,-2}).equals(Arrays.asList(-1)) : errorMessage;
        assert ArrayLeaders.arrayLeaders(new int[] {-36,-12,-27}).equals(Arrays.asList(-36,-12)) : errorMessage;
        assert ArrayLeaders.arrayLeaders(new int[] {5,2}).equals(Arrays.asList(5,2)) : errorMessage;
        assert ArrayLeaders.arrayLeaders(new int[] {0,-1,-29,3,2}).equals(Arrays.asList(0,-1,3,2)) : errorMessage;
        System.out.println("Assertion passed.");
    }   
}
