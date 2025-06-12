import java.util.Arrays;
import static java.util.Arrays.stream;

public class ProductOfMaximumsOfArray {
    public static long maxProduct(int[] numbers, int sub_size) {
        long product = 1;
        Arrays.sort(numbers);
        
        for (int i = 0; i < sub_size; i++) 
            product *= numbers[numbers.length-i-1];
        return product; 
    }

    public static long stremMaxProduct(int[] numbers, int subSize) {
        return stream(numbers)
            .sorted()
            .skip(numbers.length-subSize)
            .mapToLong(Long::valueOf)
            .reduce(1, (x,y)->x*y);
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {4,3,5}, 2) == 20 : errorMessage;
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {10,8,7,9}, 3) == 720 : errorMessage;
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {8,6,4,6}, 3) == 288 : errorMessage;
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {10,2,3,8,1,10,4}, 5) == 9600 : errorMessage;
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {13,12,-27,-302,25,37,133,155,-14}, 5) == 247895375 : errorMessage;
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {-4,-27,-15,-6,-1}, 2) == 4 : errorMessage;
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {-17,-8,-102,-309}, 2) == 136 : errorMessage;
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {10,3,-27,-1}, 3) == -30 : errorMessage;
        assert ProductOfMaximumsOfArray.maxProduct(new int[] {14,29,-28,39,-16,-48}, 4) == -253344 : errorMessage;
        System.out.println("Assertion passed.");
    }
}
