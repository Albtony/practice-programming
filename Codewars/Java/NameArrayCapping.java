/*
 * Source: https://www.codewars.com/kata/5356ad2cbb858025d800111d
 * Diff: 7 Kyu
 * 
 * Create a function that accepts an array of names, and returns an array of each name with its first 
 * letter capitalized and the remainder in lowercase.
 * 
 * Examples
 * ["jo", "nelson", "jurie"] -->  ["Jo", "Nelson", "Jurie"]
 * ["KARLY", "DANIEL", "KELSEY"] --> ["Karly", "Daniel", "Kelsey"]
 */

import java.util.Arrays;

public class NameArrayCapping {
    public String[] capMe (String[] strings) {
        for (int i = 0; i < strings.length; i++) {
            if (strings[i] == null || strings[i].isEmpty()) continue;
            strings[i] = strings[i].substring(0, 1).toUpperCase() + strings[i].substring(1).toLowerCase();
        }
        return strings;
    }

    public static void main (String[] args) {
        NameArrayCapping n = new NameArrayCapping();
        String errorMessage = "Womp Womp";
        assert Arrays.equals(n.capMe(new String[]{"echo", "slamma", "jamma"}), new String[]{"Echo", "Slamma", "Jamma"}) : errorMessage;
        assert Arrays.equals(n.capMe(new String[]{"LAKAD", "MATATAAAAG"}), new String[]{"Lakad", "Matataaaag"}) : errorMessage;
        assert Arrays.equals(n.capMe(new String[]{""}), new String[]{""}) : errorMessage;
        assert Arrays.equals(n.capMe(new String[]{}), new String[]{}) : errorMessage;
        System.out.println("Assertion passed.");
    }
}