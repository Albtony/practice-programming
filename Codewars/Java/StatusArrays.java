import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class StatusArrays {
    public static int[] status (int[] nums) {
        List<int[]> pairs = IntStream.range(0, nums.length)
                                .mapToObj(i -> new int[]{nums[i], i})
                                .collect(Collectors.toList());
        List<int[]> ranks = pairs.stream()
                                .map(i -> new int[]{i[0], (int) pairs.stream()
                                                                    .filter(j -> j[0] < i[0])
                                                                    .count()})
                                .collect(Collectors.toList());
        pairs.sort((a, b) -> {
            int rankA = ranks.stream().filter(i -> i[0] < a[0]).map(i -> i[1]).findFirst().orElse(-1);
            int rankB = ranks.stream().filter(i -> i[0] < b[0]).map(i -> i[1]).findFirst().orElse(-1);
            return (rankA + a[1]) - (rankB + b[1]);
        });

        return pairs.stream().mapToInt(i -> i[0]).toArray();
    }

    public static void main(String[] args) {
        int[] arr = StatusArrays.status(new int[] {6,9,3,8,2,3,1});
        for (int elem: arr)
        System.out.println(elem);
    }
}
