/* 
 * Source: https://www.codewars.com/kata/580dda86c40fa6c45f00028a/java
 * Diff: 7 Kyu
 * 
 * Find the sum of the odd numbers within an array, after cubing the initial integers. 
 * The function should return undefined/None/nil/NULL if any of the values aren't numbers.
 * 
 * Note: There are ONLY integers in the JAVA and C# versions of this Kata.
*/

public class FindOddCubes {
    public static int cubeOdd(int arr[]) {
        int res = 0;
        for (int elem : arr) {
            if (elem % 2 == 0) continue;
            res += (elem*elem*elem);
        }
        return res;
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert FindOddCubes.cubeOdd(new int[] {-5, -5, 5, 5}) == 0 : errorMessage;
        assert FindOddCubes.cubeOdd(new int[] {1, 2, 3, 4}) == 28 : errorMessage;
        assert FindOddCubes.cubeOdd(new int[] {-3, -2, 2, 3}) == 0 : errorMessage;
        System.out.println("Assertion passed.");
    }
}
