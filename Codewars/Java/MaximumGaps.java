/*
Source: https://www.codewars.com/kata/5a7893ef0025e9eb50000013/train/java
Diff: 7 Kyu

Task
Given an array/list [] of integers , Find The maximum difference between the successive elements in its sorted form.

Notes
Array/list size is at least 3 .

Array/list's numbers Will be mixture of positives and negatives also zeros_
Repetition of numbers in the array/list could occur.
The Maximum Gap is computed Regardless the sign.

Input >> Output Examples
maxGap ({13,10,5,2,9}) ==> return (4)
Explanation:
The Maximum Gap after sorting the array is 4 , The difference between 9 - 5 = 4 .

maxGap ({-3,-27,-4,-2}) ==> return (23)
Explanation:
The Maximum Gap after sorting the array is 23 , The difference between  |-4- (-27) | = 23 .
Note : Regardless the sign of negativity .

maxGap ({-7,-42,-809,-14,-12}) ==> return (767)  
Explanation:
The Maximum Gap after sorting the array is 767 , The difference between  | -809- (-42) | = 767 .
Note : Regardless the sign of negativity .

maxGap ({-54,37,0,64,640,0,-15}) //return (576)
Explanation:
The Maximum Gap after sorting the array is 576 , The difference between  | 64 - 640 | = 576 .
Note : Regardless the sign of negativity .
*/

import java.util.Arrays;

public class MaximumGaps {
    public static int maxGap(int[] numbers) {
        int res = 0;
        Arrays.sort(numbers);

        for (int i = 1; i < numbers.length; i++) 
            res = Math.max(res, (numbers[i] - numbers[i-1]));

        return res; 
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert MaximumGaps.maxGap(new int[]{13,10,2,9,5}) == 4 : errorMessage;
        assert MaximumGaps.maxGap(new int[]{13,3,5}) == 8 : errorMessage;
        assert MaximumGaps.maxGap(new int[]{24,299,131,14,26,25}) == 168 : errorMessage;
        assert MaximumGaps.maxGap(new int[]{-3,-27,-4,-2}) == 23 : errorMessage;
        assert MaximumGaps.maxGap(new int[]{-7,-42,-809,-14,-12}) == 767 : errorMessage;
        assert MaximumGaps.maxGap(new int[]{12,-5,-7,0,290}) == 278 : errorMessage;
        assert MaximumGaps.maxGap(new int[]{-54,37,0,64,-15,640,0}) == 576 : errorMessage;
        System.out.println("Assertion passed");
    }
}
