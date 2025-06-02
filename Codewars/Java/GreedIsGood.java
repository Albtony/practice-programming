/* 
 * Source: https://www.codewars.com/kata/5270d0d18625160ada0000e4/java
 * Diff: Kyu 5
 * 
 * Greed is a dice game played with five six-sided dice. Your mission, should you choose to accept it, is to score a throw according to these rules. 
 * You will always be given an array with five six-sided dice values.
 * 
 * Three 1's => 1000 points
 * Three 6's =>  600 points
 * Three 5's =>  500 points
 * Three 4's =>  400 points
 * Three 3's =>  300 points
 * Three 2's =>  200 points
 * One   1   =>  100 points
 * One   5   =>   50 point
 * Each of 5 dice can only be counted once in each roll. For example, a given "5" can only count as part of a triplet (contributing to the 500 points) 
 * or as a single 50 points, but not both in the same roll.
 * 
 * Example scoring
 * Throw       Score
 * ---------   ------------------
 * 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 * 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 * 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
 * 
 * Note: your solution must not modify the input array.
*/

public class GreedIsGood {
    public static int greedy (int[] dice) {
        int ans = 0;
        int[] freq = new int[7];

        for (int die : dice) {
            freq[0]++;
            freq[die]++;
        }

        while (freq[0] > 0) {
            ans += helper(1, freq, 3, 1000);
            ans += helper(6, freq, 3, 600);
            ans += helper(5, freq, 3, 500);
            ans += helper(4, freq, 3, 400);
            ans += helper(3, freq, 3, 300);
            ans += helper(1, freq, 1, 100);
            ans += helper(5, freq, 1, 50);
        }

        return ans;
    }

    private static int helper (int die, int[] freq, int thresh, int score) {
        if (freq[0] <= thresh && freq[die] <= thresh) {
            freq[0] -= thresh;
            freq[die] -= thresh;
            return score;
        }
    
        return 0;
    }
}
