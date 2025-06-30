/*
Source: https://www.codewars.com/kata/513e08acc600c94f01000001/java]
Diff : 5 Kyu

The rgb function is incomplete. Complete it so that passing in RGB decimal values will result in a hexadecimal 
representation being returned. Valid decimal values for RGB are 0 - 255. Any values that fall out of that range 
must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, the shorthand with 3 will not work here.

Examples (input --> output):
255, 255, 255 --> "FFFFFF"
255, 255, 300 --> "FFFFFF"
0, 0, 0       --> "000000"
148, 0, 211   --> "9400D3"
*/

public class RGBToHexConversion {
    public static String rgb(int r, int g, int b) {
        r = Math.max(0, Math.min(r, 255));
        g = Math.max(0, Math.min(g, 255));
        b = Math.max(0, Math.min(b, 255));
        return String.format("%02X%02X%02X", r, g, b);
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert RGBToHexConversion.rgb(255, 255, 255).equals("FFFFFF") : errorMessage;
        assert RGBToHexConversion.rgb(1, 2, 3).equals("010203") : errorMessage;
        assert RGBToHexConversion.rgb(0, 0, 0).equals("000000") : errorMessage;
        assert RGBToHexConversion.rgb(254, 253, 252).equals("FEFDFC") : errorMessage;
        assert RGBToHexConversion.rgb(-20, 275, 125).equals("00FF7D") : errorMessage;
        System.out.println("Assertion Passed");
    }
}
