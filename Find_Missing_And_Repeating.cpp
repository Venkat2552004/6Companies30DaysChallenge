// Link : https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/
// Goldman Sachs | Day - 3 | Problem - 1

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int miss, twice;
        bool valid[n + 1] = {false};
        for(int i = 0; i < n; i++){
            if(valid[arr[i]])
                twice = arr[i];
            else
                valid[arr[i]] = true;
        }
        for(int i = 1; i <= n; i++){
            if(valid[i] == false){
                miss = i;
                break;
            }
        }
        return {twice, miss};
    }
};
