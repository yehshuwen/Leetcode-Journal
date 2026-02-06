#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution209 {
public:
    int minSubArrayLen(int target,  vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int currentSum = 0;
        int minLen = INT_MAX;
        for (int right = 0; right<n; right++) {
            currentSum += nums[right];
            while (currentSum >= target) 
            {
                minLen = min(minLen, right-left+1);
                currentSum -= nums[left];
                left++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

int main() {
    Solution209 sol;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    cout << "Target: " << target << endl;
    cout << "Array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    cout << "result: " << sol.minSubArrayLen(target, nums) << endl;
};