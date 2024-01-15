// Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Microsoft | Day - 15 | Problem - 3

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mid = nums[n / 2];
        for(int i = 0; i < n; i++)
            res += abs(nums[i] - mid);
        return res;
    }
};
