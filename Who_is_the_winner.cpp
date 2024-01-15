// Link : https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Microsoft | Day - 15 | Problem - 1

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        for(int i = 1; i <= n; i++)
            v.push_back(i);
        int idx = 0;
        while(v.size() != 1){
            n = v.size();
            idx = (idx + k - 1) % n;
            v.erase(v.begin() + idx);
        }
        return v[0];
    }
};
