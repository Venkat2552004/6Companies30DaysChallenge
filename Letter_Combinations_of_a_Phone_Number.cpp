// Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Goldman Sachs | Day - 2 | Problem - 3

class Solution {
public:
    void solve(vector<string>&res, string ans, map<char,string>& nums, string digits, int i){
        if(ans.length() == digits.length()){
            res.push_back(ans);
            return;
        }
        // for each character from possible chars for a number
        for(char c : nums[digits[i]])
            solve(res, ans + c, nums, digits, i + 1);// consider that character in a recursive call
        
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0)
            return res;
        string ans = "";
        map<char, string> nums;
        // each number maps to its respective possible characters
        nums['2'] = "abc";
        nums['3'] = "def";
        nums['4'] = "ghi";
        nums['5'] = "jkl";
        nums['6'] = "mno";
        nums['7'] = "pqrs";
        nums['8'] = "tuv";
        nums['9'] = "wxyz";
        solve(res, ans, nums, digits, 0);
        return res;
    }
};
