/*
Source: https://www.codewars.com/kata/5544c7a5cb454edb3c000047/java
Diff: 6 Kyu
A child is playing with a ball on the nth floor of a tall building. The height of this floor above ground level, h, is known.

He drops the ball out of the window. The ball bounces (for example), to two-thirds of its height (a bounce of 0.66).

His mother looks out of a window 1.5 meters from the ground.

How many times will the mother see the ball pass in front of her window (including when it's falling and bouncing)?

Three conditions must be met for a valid experiment:
Float parameter "h" in meters must be greater than 0
Float parameter "bounce" must be greater than 0 and less than 1
Float parameter "window" must be less than h.
If all three conditions above are fulfilled, return a positive integer, otherwise return -1.

Note:
The ball can only be seen if the height of the rebounding ball is strictly greater than the window parameter.

Examples:
- h = 3, bounce = 0.66, window = 1.5, result is 3

- h = 3, bounce = 1, window = 1.5, result is -1 

(Condition 2) not fulfilled).
*/

public class BouncingBalls {
    // 1e-12 is needed to compensate the fragility of the floating precision in programming, 
    // but is not robust given input with high enough precision
    public static int bouncingBall(double h, double bounce, double window) {
        if (!(h > 0 && bounce > 0 && bounce < 1 && h > window)) return -1;
        int bounces = (int)Math.floor((Math.log(window + 1e-12/h) / Math.log(bounce)));
        return bounces * 2 + 1;
    }

    // iterative approach, less performant, but more robust
    public static int bouncingBallIterative(double h, double bounce, double window) {
        if (!(h > 0 && bounce > 0 && bounce < 1 && h > window)) return -1;
        int bounces = 1;

        while (h * bounce > window) {
            bounces += 2;
            h *= bounce;     
        }

        return bounces;
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert BouncingBalls.bouncingBall(3.0, 0.66, 1.5) == 1 : errorMessage;
        assert BouncingBalls.bouncingBall(0, 0, 0) == 1 : errorMessage;
        assert BouncingBalls.bouncingBall(0, 0, 0) == 1 : errorMessage;
        assert BouncingBalls.bouncingBall(0, 0, 0) == 1 : errorMessage;
        assert BouncingBalls.bouncingBall(0, 0, 0) == 1 : errorMessage;
        assert BouncingBalls.bouncingBall(0, 0, 0) == 1 : errorMessage;
        assert BouncingBalls.bouncingBall(0, 0, 0) == 1 : errorMessage;
        assert BouncingBalls.bouncingBall(0, 0, 0) == 1 : errorMessage;
    }
}
