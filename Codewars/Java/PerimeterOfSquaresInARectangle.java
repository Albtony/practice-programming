/*
Source: https://www.codewars.com/kata/559a28007caad2ac4e000083/java
Diff: 5 Kyu

The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8. It's easy to see that the sum of the perimeters of 
these squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80 

Could you give the sum of the perimeters of all the squares in a rectangle when there are n + 1 squares disposed in the same manner as in the drawing:
-- no image LOLZ --

Hint:
See Fibonacci sequence

Ref:
http://oeis.org/A000045

The function perimeter has for parameter n where n + 1 is the number of squares (they are numbered from 0 to n) and returns the total 
perimeter of all the squares.

perimeter(5)  should return 80
perimeter(7)  should return 216
*/

import java.math.BigInteger;
import java.util.HashMap;

public class PerimeterOfSquaresInARectangle {
    static HashMap<BigInteger, BigInteger> memo = new HashMap<>(); 

    // as you can tell from the datatype, i need to handle very large input
    // my current approach is simple recursion + memoization
    // filling memoization pre final function call helpsto reduce the stack calls needed by the calls
    // im currently limiting the stack to 1000
    // encounter out of memory error at n = 100_000
    public static BigInteger perimeter(BigInteger n) {
        return cumFibonacci(n.add(BigInteger.valueOf(1))).multiply(BigInteger.valueOf(4));   
    }

    public static BigInteger cumFibonacci(BigInteger n) {
        BigInteger res = BigInteger.valueOf(0);
        fillMemo(n);
        while(n.compareTo(BigInteger.valueOf(0)) != 0) {
            res = res.add(fibonacci(n));
            n = n.subtract(BigInteger.valueOf(1));
        }  
        return res;
    }

    public static void fillMemo(BigInteger n) {
        for (int i = 1000; n.compareTo(BigInteger.valueOf(i)) == 1; i += 1000) {
            fibonacci(BigInteger.valueOf(i));
        }
    }

    public static BigInteger fibonacci(BigInteger n) {
        if (n.compareTo(BigInteger.valueOf(0)) == 0) return BigInteger.valueOf(0);
        else if (n.compareTo(BigInteger.valueOf(1)) == -1) return BigInteger.valueOf(1);
        if (memo.containsKey(n)) return memo.get(n);

        BigInteger res = fibonacci(n.subtract(BigInteger.valueOf(1))).add(fibonacci(n.subtract(BigInteger.valueOf(2))));
        memo.put(n, res);
        return res;
    }

    // much better, the loop approach is clearer, contain less overhead, 
    // therefore faster, and use less memory due to not having a memoization feature
    // able to run n > 1000_000
    public static BigInteger betterPerimeter(BigInteger n) {           
        BigInteger a = BigInteger.ZERO;
        BigInteger b = BigInteger.ONE;
        BigInteger c = BigInteger.ONE;
        BigInteger sum = BigInteger.ZERO;
        
        for(int i = 0; i <= n.intValue(); i++) {
        a = b;
        b = c;
        c = a.add(b);
        sum = sum.add(a);      
        }
        
        return sum.multiply(BigInteger.valueOf(4));
	}

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert PerimeterOfSquaresInARectangle.perimeter(BigInteger.valueOf(5)).equals(BigInteger.valueOf(80)) : errorMessage;
        assert PerimeterOfSquaresInARectangle.perimeter(BigInteger.valueOf(7)).equals(BigInteger.valueOf(216)) : errorMessage;
        assert PerimeterOfSquaresInARectangle.perimeter(BigInteger.valueOf(30)).equals(BigInteger.valueOf(14098308)) : errorMessage;
        System.out.println("Assertion Passed");
    }
}
