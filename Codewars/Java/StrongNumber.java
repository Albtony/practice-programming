/*
Source: https://www.codewars.com/kata/5a4d303f880385399b000001/java
Diff: 7 Kyu

Strong number is a number with the sum of the factorial of its digits is equal to the number itself.

For example, 145 is strong, because 1! + 4! + 5! = 1 + 24 + 120 = 145.

Task
Given a positive number, find if it is strong or not, and return either "STRONG!!!!" or "Not Strong !!".

Examples
1 is a strong number, because 1! = 1, so return "STRONG!!!!".
123 is not a strong number, because 1! + 2! + 3! = 9 is not equal to 123, so return "Not Strong !!".
145 is a strong number, because 1! + 4! + 5! = 1 + 24 + 120 = 145, so return "STRONG!!!!".
150 is not a strong number, because 1! + 5! + 0! = 122 is not equal to 150, so return "Not Strong !!".
*/

public class StrongNumber {
    public static String isStrongNumber(int num) {
        int res = 0;
        for (int currNum = num; currNum > 0; currNum /= 10) {
            int currFac = 1;
            for (int digit = currNum % 10; digit > 1; digit--)
                currFac *= digit;
            res += currFac;
        }

        return res == num ? "STRONG!!!!" : "Not Strong !!"; 
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        String trueString = "STRONG!!!!";
        String falseString = "Not Strong !!";
        assert StrongNumber.isStrongNumber(1).equals(trueString) : errorMessage;
        assert StrongNumber.isStrongNumber(2).equals(trueString) : errorMessage;
        assert StrongNumber.isStrongNumber(145).equals(trueString) : errorMessage;
        assert StrongNumber.isStrongNumber(7).equals(falseString) : errorMessage;
        assert StrongNumber.isStrongNumber(93).equals(falseString) : errorMessage;
        assert StrongNumber.isStrongNumber(185).equals(falseString) : errorMessage;
        System.out.println("Assertion Passed");
    }
}