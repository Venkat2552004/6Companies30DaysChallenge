//  Link : https://leetcode.com/problems/image-smoother/
// Microsoft | Day - 15 | Problem - 2

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                res[i][j] = solve(i, j, m, n, img);
        return res;
    }

    int solve(int r, int c,int m, int n, vector<vector<int>>& img){
        int sum = 0, cnt = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int rr = r + i;
                int cc = c + j;
                if(rr >= 0 and rr < m and cc >= 0 and cc < n){
                    sum += img[rr][cc];
                    cnt++;
                }
            }
        }
        return sum / cnt;
    }
};
