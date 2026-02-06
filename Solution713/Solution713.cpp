#include <iostream>
#include <vector>

using namespace std;

class Solution713 {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int target) {
        if (target <= 1) return 0;
        int count = 0;
        int left = 0;
        long long product = 1;

        for (int right = 0; right<nums.size(); right++) {
            product *= nums[right];
            while (product >= target) {
            product /= nums[left];
            left ++;
            }
            count += (right - left + 1);
        }
        return count;
    }
};

int main() {
    Solution713 sol;
    vector<int> nums = {10, 5, 2, 6};
    int target = 100;

    cout << "Input: nums = [10, 5, 2, 6], k = " << target << endl;
    int result = sol.numSubarrayProductLessThanK(nums, target);
    cout << "Output: " << result << endl;

    return 0;
}