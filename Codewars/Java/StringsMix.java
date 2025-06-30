/*
Source: https://www.codewars.com/kata/5629db57620258aa9d000014/java
Diff: 4 Kyu

Given two strings s1 and s2, we want to visualize how different the two strings are. We will only take into account the lowercase letters (a to z). 
First let us count the frequency of each lowercase letters in s1 and s2.

s1 = "A aaaa bb c"
s2 = "& aaa bbb c d"
s1 has 4 'a', 2 'b', 1 'c'
s2 has 3 'a', 3 'b', 1 'c', 1 'd'
So the maximum for 'a' in s1 and s2 is 4 from s1; the maximum for 'b' is 3 from s2. In the following we will not consider letters when the maximum 
of their occurrences is less than or equal to 1.

We can resume the differences between s1 and s2 in the following string: "1:aaaa/2:bbb" where 1 in 1:aaaa stands for string s1 and aaaa because the 
maximum for a is 4. In the same manner 2:bbb stands for string s2 and bbb because the maximum for b is 3.

The task is to produce a string in which each lowercase letters of s1 or s2 appears as many times as its maximum if this maximum is strictly greater 
than 1; these letters will be prefixed by the number of the string where they appear with their maximum value and :. If the maximum is in s1 as well 
as in s2 the prefix is =:.

In the result, substrings (a substring is for example 2:nnnnn or 1:hhh; it contains the prefix) will be in decreasing order of their length and when 
they have the same length sorted in ascending lexicographic order (letters and digits - more precisely sorted by codepoint); the different groups will 
be separated by '/'. See examples and "Example Tests".
Hopefully other examples can make this clearer.

s1 = "my&friend&Paul has heavy hats! &"
s2 = "my friend John has many many friends &"
mix(s1, s2) --> "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"

s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &"
s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&"
mix(s1, s2) --> "1:mmmmmm/=:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"

s1="Are the kids at home? aaaaa fffff"
s2="Yes they are here! aaaaa fffff"
mix(s1, s2) --> "=:aaaaaa/2:eeeee/=:fffff/1:tt/2:rr/=:hh"
Note for Swift, R, PowerShell
The prefix =: is replaced by E:

s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &"
s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&"
mix(s1, s2) --> "1:mmmmmm/E:nnnnnn/1:aaaa/1:hhh/2:yyy/2:dd/2:ff/2:ii/2:rr/E:ee/E:ss"
*/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class StringsMix {
    public static String mix(String s1, String s2) {
        HashMap<Integer, Integer> charOccurS1 = new HashMap<>();
        HashMap<Integer, Integer> charOccurS2 = new HashMap<>();
        StringBuilder result = new StringBuilder();

        s1.chars().filter(c -> c >= 'a' && c <= 'z').forEach(c -> charOccurS1.put(c, charOccurS1.getOrDefault(c, 0) + 1));
        s2.chars().filter(c -> c >= 'a' && c <= 'z').forEach(c -> charOccurS2.put(c, charOccurS2.getOrDefault(c, 0) + 1));

        s1.concat(s2)
            .chars()
            .boxed()
            .distinct()
            .filter(c -> c >= 'a' && c <= 'z')
            .map(c -> {
                int count1 = charOccurS1.getOrDefault(c, 0);
                int count2 = charOccurS2.getOrDefault(c, 0);
                int maxCount = Math.max(count1, count2);

                if (maxCount <= 1) return null;

                int origin = (count1 == count2) ? 3 : (count1 > count2 ? 1 : 2);
                return new int[] {c, maxCount, origin};
            })
            .filter(Objects::nonNull)
            .sorted((a, b) -> {
                int cmp1 = Integer.compare(b[1], a[1]); 
                if (cmp1 != 0) return cmp1;
                int cmp2 = Integer.compare(a[2], b[2]);
                if (cmp2 != 0) return cmp2;
                return  Integer.compare(a[0], b[0]);
            })
            .forEach(arr -> {
                String originStr = switch (arr[2]) {
                    case 1 -> "1";
                    case 2 -> "2";
                    case 3 -> "=";
                    default -> "?";
                };
                result.append(originStr)
                    .append(":")
                    .append(String.valueOf((char) arr[0]).repeat(arr[1]))
                    .append("/");
            });

        if (result.length() > 0) result.setLength(result.length() - 1); 
        return result.toString();
    }

        public static String betterMix(String s1, String s2) {
        s1 = s1.replaceAll("[^a-z]", "");
        s2 = s2.replaceAll("[^a-z]", "");

        Map<String,Long> map1 = Arrays.stream(s1.split("")).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        Map<String,Long> map2 = Arrays.stream(s2.split("")).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

        Set<String> keySet = new HashSet<>(map1.keySet());
        keySet.addAll(new HashSet<>(map2.keySet()));

        List<String[]> result = new ArrayList<>();
        for (String key:keySet) {
            long value1 = map1.getOrDefault(key, 0L), value2 = map2.getOrDefault(key, 0L);
            if ((value1 > 1) || (value2 > 1)) {
                long compare = value1 - value2;
                if (compare > 0)
                    result.add(new String[]{"1", Stream.generate(() -> key).limit(value1).collect(Collectors.joining())});
                else if (compare < 0)
                    result.add(new String[]{"2", Stream.generate(() -> key).limit(value2).collect(Collectors.joining())});
                else
                    result.add(new String[]{"=", Stream.generate(() -> key).limit(value1).collect(Collectors.joining())});
            }
        }

        return result.stream()
            .sorted(Comparator.comparing((String[] a) -> a[1].length()).reversed().thenComparing(a -> a[0]).thenComparing(a -> a[1]))
            .map(a -> Arrays.stream(a).collect(Collectors.joining(":")))
            .collect(Collectors.joining("/")).replaceFirst("/$", "");
    }

    public static void main(String[] args) {
        String errorMessage = "Womp Womp";
        assert StringsMix.mix("Are they here", "yes, they are here").equals("2:eeeee/2:yy/=:hh/=:rr") : errorMessage;
        assert StringsMix.mix("looping is fun but dangerous", "less dangerous than coding").equals("1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg") : errorMessage;
        assert StringsMix.mix(" In many languages", " there's a pair of functions").equals("1:aaa/1:nnn/1:gg/2:ee/2:ff/2:ii/2:oo/2:rr/2:ss/2:tt") : errorMessage;
        assert StringsMix.mix("Lords of the Fallen", "gamekult").equals("1:ee/1:ll/1:oo") : errorMessage;
        assert StringsMix.mix("codewars", "codewars").equals("") : errorMessage;
        assert StringsMix.mix("A generation must confront the looming ", "codewarrs").equals("1:nnnnn/1:ooooo/1:tttt/1:eee/1:gg/1:ii/1:mm/=:rr") : errorMessage;
        System.out.println("Assertion Passed");
    }
}
