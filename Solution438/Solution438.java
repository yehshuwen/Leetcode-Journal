package Solution438;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
    438. Find All Anagrams in a String
    Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
*/
class Solution438 {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        if (s.length() < p.length()) return result;

        int[] pCount = new int[26];
        int[] sCount = new int[26];

        for (int i = 0; i < p.length(); i++) {
            pCount[p.charAt(i) - 'a']++; // ASCII 
            sCount[s.charAt(i) - 'a']++; 
        }

        if(Arrays.equals(pCount, sCount)) result.add(0); //first window
        
        for (int i = p.length(); i<s.length(); i++) {
            sCount[s.charAt(i) - 'a']++; // add
            sCount[s.charAt(i - p.length()) - 'a']--; // remove

            if (Arrays.equals(pCount, sCount)) {
                result.add(i - p.length() + 1);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Solution438 sol = new Solution438();
        System.out.println(sol.findAnagrams("abab", "ab"));
    }
}
