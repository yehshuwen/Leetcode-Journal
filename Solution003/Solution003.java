import java.util.HashMap;

'''
    3. Longest Substring Without Repeating Characters
    在所有「沒重複」的「連續子字串」中，長度最長的那一個是多少？
    不管發生幾次重複，我們都要在移動過程中，把曾經出現過的最大長度給存下來。
    遇到重複，只丟掉「左邊那重複的字元及其之前的所有字元」，盡可能保留後面的部分。
    O(n)
'''
class Solution003 {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1) return s.length();

        HashMap<Character, Integer> map = new HashMap<>();
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right ++) {
            char currentChar = s.charAt(right);

            if (map.containsKey(currentChar)) {
                left = Math.max(left, map.get(currentChar) + 1 );
            }
            map.put(currentChar, right);
            maxLength = Math.max(maxLength, right - left + 1);
        }
        return maxLength;
    }

    public static void main(String[] args) {
        Solution003 sol = new Solution003();
        System.out.println(sol.lengthOfLongestSubstring("abcabcbb"));
    }
}