/*
Source: https://www.codewars.com/kata/52b7ed099cdc285c300001cd/java
Diff: 4 Kyu

Write a function called sumIntervals/sum_intervals that accepts an array of intervals, and returns the sum of all the interval lengths. Overlapping intervals should only be counted once.

Intervals
Intervals are represented by a pair of integers in the form of an array. The first value of the interval will always be less than the second value. Interval example: [1, 5] 
is an interval from 1 to 5. The length of this interval is 4.

Overlapping Intervals
List containing overlapping intervals:

[
    [1, 4],
    [7, 10],
    [3, 5]
]
The sum of the lengths of these intervals is 7. Since [1, 4] and [3, 5] overlap, we can treat the interval as [1, 5], which has a length of 4.

Examples:
sumIntervals( [
    [1, 2],
    [6, 10],
    [11, 15]
] ) => 9

sumIntervals( [
    [1, 4],
    [7, 10],
    [3, 5]
] ) => 7

sumIntervals( [
    [1, 5],
    [10, 20],
    [1, 6],
    [16, 19],
    [5, 11]
] ) => 19

sumIntervals( [
    [0, 20],
    [-100000000, 10],
    [30, 40]
] ) => 100000030
Tests with large intervals
Your algorithm should be able to handle large intervals. All tested intervals are subsets of the range [-1000000000, 1000000000].
*/

import java.util.Arrays;
import java.util.Comparator;

public class SumOfIntervals {
    public static int sumIntervals(int[][] intervals) {
        int res = 0;
        int maxUpperBound = Integer.MIN_VALUE;
        Arrays.sort(
            intervals, 
            Comparator
                .comparingInt((int[] a) -> a[0])
                .thenComparingInt((int[] a) -> a[1])
        );
        for(int i=0; i<intervals.length; i++) {
            for(int j=i; j<intervals.length; j++) {
                if(intervals[i][1] <= maxUpperBound && intervals[i][0] < maxUpperBound) {
                    continue;
                }
                if(intervals[i][1] < intervals[j][1]) {
                    res += (Math.min(intervals[i][1], intervals[j][0]) - intervals[i][0]);
                    maxUpperBound = Math.max(maxUpperBound, Math.min(intervals[i][1], intervals[j][0]));
                    i = j;
                }
                if(j == intervals.length-1) {
                    res += (intervals[i][1] - intervals[i][0]);
                    maxUpperBound = Math.max(maxUpperBound, intervals[i][1]);
                    if(i == j) return res;
                }
            }
        }
        return res;
    }

    public static int betterSumIntervals(int[][] intervals) {
        if (intervals.length == 0) return 0;
        Arrays.sort(
            intervals, 
            Comparator
                .comparingInt((int[] a) -> a[0])
                .thenComparingInt((int[] a) -> a[1])
        );

        int res = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];

            if (curStart <= end) {
                end = Math.max(end, curEnd);
            } else {
                res += end - start;
                start = curStart;
                end = curEnd;
            }
        }

        res += end - start;
        return res;
    }


    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert SumOfIntervals.betterSumIntervals(new int[][]{}) == 0 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{4, 4}, {6, 6}, {8, 8}}) == 0 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{1, 2}, {6, 10}, {11, 15}}) == 9 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{4, 8}, {9, 10}, {15, 21}}) == 11 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{-1, 4}, {-5, -3}}) == 7 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{-245, -218}, {-194, -179}, {-155, -119}}) == 78 : errorMessage;        
        assert SumOfIntervals.betterSumIntervals(new int[][]{{-1_000_000_000, 1_000_000_000}}) == 2_000_000_000 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{0, 20}, {-100_000_000, 10}, {30, 40}}) == 100_000_030 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{1, 2}, {2, 6}, {6, 55}}) == 54 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{-2, -1}, {-1, 0}, {0, 21}}) == 23 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{1, 4}, {7, 10}, {3, 5}}) == 7 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{5, 8}, {3, 6}, {1, 2}}) == 6 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{1, 5}, {10, 20}, {1, 6}, {16, 19}, {5, 11}}) == 19 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{2, 5}, {-1, 2}, {-40, -35}, {6, 8}}) == 13 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{-7, 8}, {-2, 10}, {5, 15}, {2000, 3150}, {-5400, -5338}}) == 1234 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{-101, 24}, {-35, 27}, {27, 53}, {-105, 20}, {-36, 26}}) == 158 : errorMessage;
        assert SumOfIntervals.betterSumIntervals(new int[][]{{-375, -368}, {-54, -51}, {-33, -27}, {238, 255},{330, 350}, {331, 350}}) == 53 : errorMessage;
        System.out.println("Assertion Passed");
    }
}
