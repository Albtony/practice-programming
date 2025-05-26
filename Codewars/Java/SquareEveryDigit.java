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