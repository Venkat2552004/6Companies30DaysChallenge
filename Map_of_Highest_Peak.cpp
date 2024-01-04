// Link : https://leetcode.com/problems/map-of-highest-peak/
// Goldman Sachs | Day - 4 | Problem - 2

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, -1));
        // queue to impelment BFS
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(isWater[i][j]){
                    ans[i][j] = 0;
                    q.push({i, j});
                }
                    
        // initially cells with 0 acts as nodes
        while(!q.empty()){
            auto idxs = q.front();
            q.pop();
            int i = idxs.first;
            int j = idxs.second;
            int val = ans[i][j];
            // trick to check all neighbouring cells is to take a vector like adj
            vector<int> adj = {-1, 0, 1, 0, -1};
            for(int k = 0; k < adj.size() - 1; k++){
                if(i + adj[k] >= 0 and i + adj[k] < rows and j + adj[k + 1] >= 0 and j + adj[k + 1] < cols and ans[i + adj[k]][j + adj[k + 1]] == -1){
                    ans[i + adj[k]][j + adj[k + 1]] = val + 1;
                    q.push({i + adj[k], j + adj[k + 1]});
                }
            }
        }
        return ans;
    }
};
