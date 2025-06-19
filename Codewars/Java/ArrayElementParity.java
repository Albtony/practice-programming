/*
Source: https://www.codewars.com/kata/5a092d9e46d843b9db000064/train/java
Diff: 7 Kyu

In this Kata, you will be given an array of integers whose elements have both a negative and a positive value, except for one integer that is 
either only negative or only positive. Your task will be to find that integer.

Examples:

[1, -1, 2, -2, 3] => 3
3 has no matching negative appearance

[-3, 1, 2, 3, -1, -4, -2] => -4
-4 has no matching positive appearance

[1, -1, 2, -2, 3, 3] => 3
(the only-positive or only-negative integer may appear more than once)

Good luck!
*/
import java.util.stream.IntStream;

public class ArrayElementParity {
    public static int solve (int[] arr) {
        long posCount = IntStream.of(arr).filter(n -> n > 0).count();
        long negCount = IntStream.of(arr).filter(n -> n < 0).count();
        int diffCount = (int) Math.abs(posCount - negCount);
        return IntStream.of(arr).sorted().sum() / diffCount;
    }

    public static int betterSolve (int[] arr) {
        return IntStream.of(arr).distinct().sum();
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Wonp";
        assert ArrayElementParity.solve(new int[] {1,-1,2,-2,3}) == 3 : errorMessage;
        assert ArrayElementParity.solve(new int[] {-3,1,2,3,-1,-4,-2}) == -4 : errorMessage;
        assert ArrayElementParity.solve(new int[] {1,-1,2,-2,3,3}) == 3 : errorMessage;
        assert ArrayElementParity.solve(new int[] {-110,110,-38,-38,-62,62,-38,-38,-38}) == -38 : errorMessage;
        assert ArrayElementParity.solve(new int[] {-9,-105,-9,-9,-9,-9,105}) == -9 : errorMessage;
        System.out.println("Assertion Passed");

    }
}