// Link : https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/
// Goldman Sachs | Day - 3 | Problem - 3


class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n = S.length();
        stack<int> st;
        string ans = "";
        int num = 1;
        for(int i = 0; i < n; i++){
            st.push(num);
            num++;
            if(S[i] == 'I'){
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }
};
