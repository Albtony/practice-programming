/*
Source: https://www.codewars.com/kata/601c18c1d92283000ec86f2b/train/java
Diff: 7 Kyu

The status of each element of an array of integers can be determined by its position in the array and the value of the other elements in the array. 
The status of an element E in an array of size N is determined by adding the position P, 0 <= P < N, of the element in the array to the number of 
array elements in the array that are less than E.

For example, consider the array containing the integers: 6 9 3 8 2 3 1. The status of the element 8 is 8 because its position is 3 and there are 5 
elements in the array that are less than 8.

You will return the elements of the original array from low to high status order. In the event there is a tie for status of two or more elements,
you will output them in order of appearance in the array.

EXAMPLE:
status([6, 9, 3, 8, 2, 3, 1]) = [6, 3, 2, 1, 9, 3, 8]
*/

import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class StatusArrays {
    static class Entry {
        int value;
        int index;
        int rank;

        Entry(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    public static int[] status (int[] nums) {
        List<Entry> entries = IntStream.range(0, nums.length)
            .mapToObj(i -> new Entry(nums[i], i))
            .collect(Collectors.toList());

        for (Entry ent : entries) {
            ent.rank = (int) entries.stream().filter(other -> other.value < ent.value).count();
            System.out.printf("rawr %d: %d + %d = %d\n", ent.value, ent.rank, ent.index, ent.rank + ent.index);
        } 


        entries.sort(Comparator.comparingInt(e -> (e.rank  + e.index)));
        return entries.stream().mapToInt(e -> e.value).toArray();
    }

    static int[] betterStatus(int[] nums) {
        return IntStream.range(0, nums.length).boxed()
            .sorted(Comparator.comparingLong(i -> i + IntStream.of(nums).filter(n -> n < nums[i]).count()))
            .mapToInt(i -> nums[i]).toArray();
    }

    public static void main(String[] args) {
        String errorrMessage = "Womp Womp";
        assert StatusArrays.status(new int[] {6,9,3,8,2,3,1}) == new int[] {6,3,2,1,9,3,8} : errorrMessage;
        assert StatusArrays.status(new int[] {5,-2,-3,5,-2,5,1,-3,-4,8,7,3,4,8,9,6}) == new int[] {5 ,5 ,5 ,8 ,7 ,-2 ,-2 ,-3 ,1 ,9,8 ,3 ,-3,4 ,-4 ,6} : errorrMessage;
        assert StatusArrays.status(new int[] {-3,4,-2,14,6,9,4,0,10}) == new int[] {14,-3,4,6,9,10,-2,4,0} : errorrMessage;
        System.out.println("Assertion Passed");
    }
}
