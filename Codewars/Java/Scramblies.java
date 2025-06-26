/*
Source: https://www.codewars.com/kata/55c04b4cc56a697bb0000048/java
Diff: 5 Kyu

Complete the function scramble(str1, str2) that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.

Notes:

Only lower case letters will be used (a-z). No punctuation or digits will be included.
Performance needs to be considered.
Examples
scramble('rkqodlw', 'world') ==> True
scramble('cedewaraaossoqqyt', 'codewars') ==> True
scramble('katas', 'steak') ==> Falses
*/

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Scramblies {
    public static boolean scramble(String str1, String str2) {
        List<Integer> asciiList1 = str1.chars().boxed().collect(Collectors.toList());   
        List<Integer> asciiList2 = str2.chars().boxed().collect(Collectors.toList());
        for (Integer ascii : asciiList1) {
            asciiList2.remove(ascii);
        }
        return asciiList2.isEmpty();
    }

    public static boolean betterScramble(String str1, String str2) {
        Map<Integer, Integer> cnt = new HashMap<>();
        str2.chars().forEach(i -> cnt.put(i, cnt.getOrDefault(i, 0) + 1));
        str1.chars().filter(cnt::containsKey).forEach(i -> cnt.put(i, cnt.get(i) - 1));
        return cnt.values().stream().filter(i -> i > 0).count() == 0;
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert Scramblies.scramble("rkqodlw","world") == true : errorMessage;
        assert Scramblies.scramble("cedewaraaossoqqyt","codewars") == true : errorMessage;
        assert Scramblies.scramble("katas","steak") == false : errorMessage;
        assert Scramblies.scramble("scriptjavx","javascript") == false : errorMessage;
        assert Scramblies.scramble("scriptingjava","javascript") == true : errorMessage;
        assert Scramblies.scramble("scriptsjava","javascripts") == true : errorMessage;
        assert Scramblies.scramble("javscripts","javascript") == false : errorMessage;
        assert Scramblies.scramble("aabbcamaomsccdd","commas") == true : errorMessage;
        assert Scramblies.scramble("commas","commas") == true : errorMessage;
        assert Scramblies.scramble("sammoc","commas") == true : errorMessage;

        // largos
        String s1 = "abcdefghijklmnopqrstuvwxyz".repeat(10_000);
        String s2 = "zyxcba".repeat(9_000);
        assert Scramblies.scramble(s1,s2) == true : errorMessage;

        System.out.println("Assertion Passed");
    }
}