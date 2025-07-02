/*
Source: https://www.codewars.com/kata/5324945e2ece5e1f32000370/java
Diff: 4 Kyu

Given the string representations of two integers, return the string representation of the sum of those integers.

For example:
sumStrings('1','2') // => '3'
A string representation of an integer will contain no characters besides the ten numerals "0" to "9".
I have removed the use of BigInteger and BigDecimal in java

Python: your solution need to work with huge numbers (about a milion digits), converting to int will not work.
*/

public class SumStringsAsNumbers {
    public static String sumStrings(String a, String b) {
        StringBuilder result = new StringBuilder("");
        a = a.length() > 0 ? SumStringsAsNumbers.ltrim(a) : "0";
        b = b.length() > 0 ? SumStringsAsNumbers.ltrim(b) : "0";

        String big = a.length() >= b.length() ? a : b;
        String small = a.length() >= b.length() ? b : a;
        
        int smallLen = Math.max(small.length() - 1, 0);
        int bigLen = Math.max(big.length() - 1, 0);
        int carry = 0;

        while (bigLen >= 0) {
            int bigPart = Character.getNumericValue(big.charAt(bigLen));
            int smallPart = smallLen >= 0 ? Character.getNumericValue(small.charAt(smallLen)) : 0; 
            int sum = bigPart + smallPart + carry;
            carry = sum / 10;
            result.append(String.valueOf(sum%10));
            bigLen--;
            smallLen--;
        }

        if (carry == 1) result.append('1');
        return result.reverse().toString();
    }

    private static String ltrim(String str) {
        int i = 0;
        while(str.charAt(i) == '0') i++;
        return str.substring(i);
    }

    public static void main(String[] args) {
        System.out.println(SumStringsAsNumbers.sumStrings("", "9999999999999567"));
    }
}
