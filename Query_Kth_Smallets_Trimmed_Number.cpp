// Link : https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/
// Goldman Sachs | Day - 1 | Problem - 3
// Complexity : O(qSize * n), qSize + n 

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int qSize = queries.size();
        int n = nums.size();
        int len = nums[0].length();
        // vector to store query results
        vector<int> res(qSize);
        for(int i = 0; i < qSize; i++){
            // xth smallest elements means after sorting, [x-1]th ele (x starts from 1)
            int x = queries[i][0];
            // we trim left most until we get queries[i][l] len element.So I used element length
            int trim = len - queries[i][1];
            //pair is used to store result and index
            vector<pair<string, int>> trimmed;
            for(int j = 0; j < n; j++){
                string ans = nums[j].substr(trim);
                //storing trimmed part and its index before sorting
                trimmed.push_back(make_pair(ans, j));
            }
            //sorting based on the trimmed part
            sort(trimmed.begin(), trimmed.end());
            // x-1th ele is the xth smallest. Its index is obtained using .second and stored in res
            res[i] = trimmed[x - 1].second;
        }
        return res;
    }

};
