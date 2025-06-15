import java.util.Arrays;

public class ProductArray {
    public static long[] productArray(int[] numbers) {
        long allProduct = 1;
        long[] res = new long[numbers.length];
        
        for (int elem: numbers) allProduct *= elem;
        for (int i = 0; i < numbers.length; i++) res[i] = allProduct/numbers[i];  
        
        return res;
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert Arrays.equals(ProductArray.productArray(new int[] {20,12}), new long[] {20,12}) : errorMessage;
        assert Arrays.equals(ProductArray.productArray(new int[] {10,2,5}), new long[] {1,5,2}) : errorMessage;
        assert Arrays.equals(ProductArray.productArray(new int[] {216,24,162,324}), new long[] {3,27,4,2}) : errorMessage;
        System.out.println("Assertion passed.");
    }
}
