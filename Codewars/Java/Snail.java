/*
Source: https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1/java
Diff: 4 Kyu

Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:


NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.

NOTE 2: The 0x0 (empty matrix) is represented as en empty array inside an array [[]].
*/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Snail {
    // it works, even on non square, but is too stateful and harder to debug
    public static int[] snail(int[][] array) {
        int left = 0;
        int top = 0;
        int right = array[0].length;
        int bottom = array.length;
        int totElem = right * bottom;
        int row = left;
        int col = top;
        int diffx = 1;
        int diffy = 1;
        boolean x = true;
        boolean y = false;
        List<Integer> result = new ArrayList<>();

        while (result.size() < totElem) {
            if(x) {
                int i = diffx == 1 ? left : right-1;
                for (; i >= left && i < right; i += diffx) result.add(array[row][i]);
                
                if (diffx == 1) top++;
                else bottom--;
                
                x = false;
                y = true;
                
                col = i-diffx;
                diffx *= -1;
                continue;
            }
            if(y) {
                int i = diffy == 1 ? top : bottom-1;
                for (; i >= top && i < bottom; i += diffy) result.add(array[i][col]);
                
                if (diffy == 1) right--;
                else left++;
                
                y = false;
                x = true;
                
                row = i-diffy;
                diffy *= -1;
                continue;
            }
        }

        return result.stream().mapToInt(i->i).toArray();
    }

    // better, more idiomatic, less moving parts, and easier to debug
    public static int[] betterSnail(int[][] array) {
        if (array == null || array.length == 0 || array[0].length == 0) return new int[0];

        int rows = array.length;
        int cols = array[0].length;
        List<Integer> result = new ArrayList<>();

        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) result.add(array[top][i]);
            top++;

            for (int i = top; i <= bottom; i++) result.add(array[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) result.add(array[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) result.add(array[i][left]);
                left++;
            }
        }

        return result.stream().mapToInt(Integer::intValue).toArray();
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert Arrays.equals(Snail.betterSnail(new int[][] {{1, 2, 3},{4, 5, 6},{7, 8, 9}}), new int[] {1, 2, 3, 6, 9, 8, 7, 4, 5}) : errorMessage;
        System.out.println("Assertion Passed");
    }
}