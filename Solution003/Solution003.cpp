#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution003 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(128, -1);  // ASCII defult is -1 
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            if (vec[s[right]] >= left){
                left = vec[s[right]] + 1;
            }
            vec[s[right]] = right;
            maxLength = max(maxLength, right-left+1);
        }
        return maxLength;
    }
};

int main() {
    Solution003 sol;
    string test = "abcabcbb";
    cout << "input: " << test << endl;
    cout << "length of longest substring: " << sol.lengthOfLongestSubstring(test) << endl;
    return 0;
}