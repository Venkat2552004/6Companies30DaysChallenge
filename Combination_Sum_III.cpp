Link : https://leetcode.com/problems/combination-sum-iii/description/
Goldman Sachs, Amazon | Day - 2 | Problem - 1


class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& ans,int k, int n, int start){
        // if ans is of required size and its sum of its elements is n, the consider
        if(ans.size() == k and n == 0){
            res.push_back(ans);
            return;
        }
        for(int i = start; i <= 9; i++){
            ans.push_back(i);
            solve(res, ans, k, n - i, i + 1);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> partial_ans;
        vector<vector<int>> res;
        //calling solve function starting from num 1
        solve(res, partial_ans, k, n, 1);
        return res;
    }
    
};
