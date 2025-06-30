/*
Source: https://www.codewars.com/kata/5511b2f550906349a70004e1/java
Diff: 5 Kyu

Define a function that takes in two non-negative integers a and b and returns the last decimal digit of a^b
Note that a and b may be very large!

For example, the last decimal digit of 9^7 is 9, since 9^7 = 4782969. The last decimal digit of
2^200^2^300, which has over 10^92 decimal digits, is 6. Also, please take 0^0 to be 1.

You may assume that the input will always be valid
*/
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class LastDigitOfALargeNumber {
    static final List<List<Integer>> CONTAINER = generate();

    public static int builtInLastDigit(BigInteger n1, BigInteger n2) {
        return n1.modPow(n2, BigInteger.TEN).intValue();
    }

    public static int lastDigit(BigInteger n1, BigInteger n2) {
        if(n2.equals(BigInteger.valueOf(0))) return 1;

        int baseRemainder =  n1.mod(BigInteger.valueOf(10)).intValue();
        int cycleSize = LastDigitOfALargeNumber.CONTAINER.get(baseRemainder).size();

        // map 1-m to 0-n pattern
        int powerRemainder = n2.subtract(BigInteger.valueOf(1)).mod(BigInteger.valueOf(cycleSize)).intValue();
        return LastDigitOfALargeNumber.CONTAINER.get(baseRemainder).get(powerRemainder);
    }

    private static List<List<Integer>> generate() {
        List<List<Integer>> container = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            List<Integer> currList = new ArrayList<>();
            currList.add(i);
            int curr = i*i;
            while (curr % 10 != i) {
                currList.add(curr%10);
                curr *= i;
            }
            container.add(currList);
        }
        return container;
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(2), BigInteger.valueOf(1)) == 2 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(2), BigInteger.valueOf(2)) == 4 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(2), BigInteger.valueOf(3)) == 8 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(2), BigInteger.valueOf(4)) == 6 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(2), BigInteger.valueOf(5)) == 2 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(2), BigInteger.valueOf(6)) == 4 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(2), BigInteger.valueOf(7)) == 8 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(4), BigInteger.valueOf(1)) == 4 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(4), BigInteger.valueOf(2)) == 6 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(9), BigInteger.valueOf(7)) == 9 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(0), BigInteger.valueOf(10)) == 0 : errorMessage;
        assert LastDigitOfALargeNumber.lastDigit(BigInteger.valueOf(1705309872  ), BigInteger.valueOf(1858229654)) == 4 : errorMessage;
        System.out.println("Assertion Passed");
    }
}
