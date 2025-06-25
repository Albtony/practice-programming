/*
Source: https://www.codewars.com/kata/523f5d21c841566fde000009/train/java
Diff: 6 Kyu

Implement a function that computes the difference between two lists. The function should remove all occurrences of elements from \
the first list (a) that are present in the second list (b). The order of elements in the first list should be preserved in the result.

Examples
If a = [1, 2] and b = [1], the result should be [2].

If a = [1, 2, 2, 2, 3] and b = [2], the result should be [1, 3].
*/

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.Collectors;

public class ArrayDiff {
    public static int[] arrayDiff(int[] a, int[] b) {
        Set<Integer> setB = new HashSet<>(Arrays.stream(b).boxed().collect(Collectors.toSet()));
        return Arrays.stream(a).filter(e -> !setB.contains(e)).toArray();
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert Arrays.equals(ArrayDiff.arrayDiff(new int [] {1,2}, new int[] {1}), new int[] {2}) : errorMessage;
        assert Arrays.equals(ArrayDiff.arrayDiff(new int [] {1,2,2}, new int[] {1}), new int[] {2,2}) : errorMessage;
        assert Arrays.equals(ArrayDiff.arrayDiff(new int [] {1,2,2}, new int[] {2}), new int[] {1}) : errorMessage;
        assert Arrays.equals(ArrayDiff.arrayDiff(new int[] {1,2,2}, new int[] {1,2,2}), new int[] {}) : errorMessage;
        assert Arrays.equals(ArrayDiff.arrayDiff(new int [] {1,2,2}, new int[] {}), new int[] {1,2,2}) : errorMessage;
        assert Arrays.equals(ArrayDiff.arrayDiff(new int[] {}, new int[] {}), new int[] {}) : errorMessage;
        System.out.println("Assertion Passed");
    }
}