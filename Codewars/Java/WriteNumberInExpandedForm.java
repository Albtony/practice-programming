/*
Source: https://www.codewars.com/kata/5842df8ccbd22792a4000245/java
Diff: 6 Kyu

Write Number in Expanded Form
You will be given a number and you will need to return it as a string in Expanded Form. For example:

12 --> "10 + 2"
45 --> "40 + 5"
70304 --> "70000 + 300 + 4"
NOTE: All numbers will be whole numbers greater than 0.

If you liked this kata, check out part 2!!
*/
import java.util.stream.IntStream;

public class WriteNumberInExpandedForm {
    public static String expandedForm(int num) {
        String numStr = String.valueOf(num);
        int numlength = numStr.length();
        StringBuilder res = new StringBuilder();
        IntStream.range(0, numlength)
            .forEach(i -> {
                String c = String.valueOf(numStr.charAt(i));
                if (!c.equals("0")) res.append(c.concat("0".repeat(numlength-i-1))). append(" + ");
            });
        if(res.toString().isEmpty()) return "0";
        return res.toString().substring(0, res.toString().length()-3);
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert WriteNumberInExpandedForm.expandedForm(2).equals("2") : errorMessage;
        assert WriteNumberInExpandedForm.expandedForm(12).equals("10 + 2") : errorMessage;
        assert WriteNumberInExpandedForm.expandedForm(4982342).equals("4000000 + 900000 + 80000 + 2000 + 300 + 40 + 2") : errorMessage;
        assert WriteNumberInExpandedForm.expandedForm(9000000).equals("9000000") : errorMessage;
        assert WriteNumberInExpandedForm.expandedForm(Integer.MAX_VALUE).equals("2000000000 + 100000000 + 40000000 + 7000000 + 400000 + 80000 + 3000 + 600 + 40 + 7") : errorMessage;
        System.out.println("Assertion Passed");
    }
}
