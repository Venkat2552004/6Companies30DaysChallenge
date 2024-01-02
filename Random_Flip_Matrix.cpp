// Link : https://leetcode.com/problems/random-flip-matrix
// Goldman Sachs | Day - 2 | Problem - 2

class Solution {
public:
    int m, n;
    set<int> s;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        s.clear();
    }
    
    vector<int> flip() {
        while(true){
            // instead of a matrix, assume arranging it in a 1D array of size m * n(logical)
            // generating a random number in range 0 to (m * n) - 1
            int num = rand() % (m * n);
            // if that is not sent before, inserting in set and returning that (row,col)
            if(s.find(num) == s.end()){
                s.insert(num);
                //after we arrange 0 to m*n - 1 in 1D array, row(x) = x / n and col(x) = x % n where n = no.of columns
                return {num / n, num % n};
            }
        }
    }
    
    void reset() {
        s.clear();
    }
};
