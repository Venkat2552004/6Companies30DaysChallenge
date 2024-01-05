// Link : https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
// Goldman Sachs | Day - 5 | Problem - 3


class Solution {
public:
    
    long m = (long)1e9+7;
    int numberOfWays(int startPos, int endPos, int k) {
        // 2D vector of size 3002 x 1001
        // because constraints specify that pos lies btw 1 and 1000 (includes 1 and 1000);
        vector<vector<int>> dp(3002);
        for(int i = 0; i < 3002; i++)
            dp[i] = vector<int>(1001, -1);
        int curr = startPos;
        return solve(curr, startPos, endPos, k, dp);
    }

    int solve(int curr, int st, int e, int k, vector<vector<int>> &dp){
        if(k == 0){
            if(curr == e) return 1;
            else return 0;
        }
        // if we already have answer, we can simply return that answer
        if(dp[curr + 1001][k] != -1)
            return dp[curr + 1001][k];

        int moveLeft = solve(curr - 1, st, e, k - 1, dp) % m;
        int moveRight = solve(curr + 1, st, e, k - 1, dp) % m;
        
        dp[curr + 1001][k] = (moveLeft + moveRight) % m;
        return dp[curr + 1001][k] % m;
    }

};
