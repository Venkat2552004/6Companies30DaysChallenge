// Link : https://leetcode.com/problems/number-of-people-aware-of-a-secret/
GoldMan Sachs | Day - 5 | Problem - 1

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        // index i is treated as day
        dp[1] = 1;
        long p = (long)1e9+7;
        // Initially 0 people know and at day[1]/dp[1], 1 person know the secret
        long whoKnows = 0;
        long ans = 0;
        for(int i = 2; i <= n; i++){
            // max is used incase if (i-delay) < 0
            // if a person know secret, he can start sharing after '+delay' days.So if the person already know secret on (i - delay'th) day, he can share that from i'th day.
            long canShare = dp[max(0, i - delay)];
            // similar to delay
            long willForget = dp[max(0, i - forget)];
            whoKnows = (whoKnows + canShare - willForget + (long)p) % (long)p;
            dp[i] = whoKnows;
        }
        //people who still remember the secret can be found from n - forget + 1 days
        for(int i = n - forget + 1; i <= n; i++){
            ans = (ans + dp[i]) % (long)p;
        }
        return ans;
    }
};
