/* 
 * Source: https://www.codewars.com/kata/546e2562b03326a88e000020/java
 * Diff: 7 Kyu
 * 
 * Welcome. In this kata, you are asked to square every digit of a number and concatenate them.
 * For example, if we run 9119 through the function, 811181 will come out, because 92 is 81 and 12 is 1. (81-1-1-81)
 * Example #2: An input of 765 will/should return 493625 because 72 is 49, 62 is 36, and 52 is 25. (49-36-25)
 * 
 * Note: The function accepts an integer and returns an integer.
 * Happy Coding!
*/
public class SquareEveryDigit {
    public int squareDigits(int n) {
        String numStr = String.valueOf(n);
        StringBuilder resStr = new StringBuilder();
        
        for (int i = 0; i < numStr.length(); i++) 
            resStr.append(square(Character.getNumericValue(numStr.charAt(i))));   

        long result = Long.parseLong(resStr.toString()); 
        if (result > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        else return (int) result;
    }
    
    private int square(int n) {
        return n*n;
    }

    public static void main(String[] args) {
        SquareEveryDigit s = new SquareEveryDigit();
        String errorMessage = "Womp Womp";
        assert s.squareDigits(123) == 149 : errorMessage;
        assert s.squareDigits(9119) == 811181 : errorMessage;
        System.out.println("Assertion passed.");
    }
}