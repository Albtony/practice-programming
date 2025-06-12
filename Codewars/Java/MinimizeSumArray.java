import java.util.Arrays;

public class MinimizeSumArray {
    public static int minSum(int[] passed) {
        int sum = 0;
        int left = 0;
        int right = passed.length-1;
        Arrays.sort(passed);

        while(left < right) {
            sum += (passed[left] * passed[right]);
            left++;
            right--;
        }
        return sum;
    }

    public static int beterminSum(int[] numbers)
    {
        java.util.Arrays.sort(numbers);
        int min = 0;
        
        for (int i = 0; i < numbers.length / 2; i++)
            min += numbers[i] * numbers[numbers.length - 1 - i];
        
        return min; 
    }

    public static void main (String[] args) {
        String errorMessage = "Womp Womp";
        assert MinimizeSumArray.minSum(new int[] {5,4,2,3}) == 22 : errorMessage;
        assert MinimizeSumArray.minSum(new int[] {12,6,10,26,3,24}) == 342 : errorMessage;
        assert MinimizeSumArray.minSum(new int[] {9,2,8,7,5,4,0,6}) == 74 : errorMessage;
        assert MinimizeSumArray.minSum(new int[] {}) == 0 : errorMessage;
        System.out.println("Assertion passed.");
    }
}
