// Link : https://leetcode.com/problems/k-divisible-elements-subarrays/
// Goldman Sachs | Day - 4 | Problem - 1


class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        vector<int> arr;
        for(int i = 0; i < nums.size(); i++){
            int cnt = 0;
            arr.clear();
            for(int j = i; j < nums.size(); j++){
                arr.push_back(nums[j]);
                if(nums[j] % p == 0)
                    cnt++;
                if(cnt <= k)
                    s.insert(arr);
                else break;
            }
        }
        return s.size();
    }
};
