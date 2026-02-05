#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution438 {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();

        if (s_len < p_len) return {};
        
        vector<int> result;
        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        
        for (int i = 0; i < p_len; i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }
        if (pCount == sCount) result.push_back(0);

        for (int i = p_len; i < s_len; i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - p_len] - 'a']--;

            if (pCount == sCount) {
                result.push_back(i - p_len + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution438 sol;
    string s = "abab";
    string p = "ab";
    cout << "input: s=" << s << ",p=" << p << endl;
    vector<int> res = sol.findAnagrams(s, p);
    cout << "result: ["; 
    for (int x : res) {
        cout << x << " ";
    }
    cout << "]" << endl;
    return 0;
}