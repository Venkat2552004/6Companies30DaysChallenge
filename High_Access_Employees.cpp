// Link : https://leetcode.com/problems/high-access-employees/description/
// Goldman Sachs | Day - 1 | Problem - 2

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> res;
        //sorting based on emp name;
        sort(access_times.begin(), access_times.end());
        //creating a map where emp_name is key -> maps emp_access_times
        // string ->maps-> vector<strings>
        map<string, vector<string>> mp;
        int n = access_times.size();
        // every time same emp name found, his new access time is pushed backin vector<strings> for the same key(emp_name)
        for(int i = 0; i < n; i++){
            mp[access_times[i][0]].push_back(access_times[i][1]);
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            string emp = it->first;
            vector<string> emp_at =  it->second;
            // for a emp, if acccess times < 3, not valid
            if(emp_at.size() < 3)   continue;
            // if a emp have more than 2 access times, chech if emp is high access or not
            for(int i = 0; i != emp_at.size() - 2; i++){
                // if condition is true when (i, i+1, i+2) access times are in 1-hr-period
                if(considerTimeGap(emp_at[i],emp_at[i + 2])){
                    res.push_back(emp);
                    break;
                }
            }
        }
        return res;
    }

    // substr(start_pos,len);

    bool considerTimeGap(string t1, string t2){
        if(t1.substr(0,2) == t2.substr(0,2))
            return true;
        int hrs1 = stoi(t1.substr(0,2));
        int mins1 = stoi(t1.substr(2,2));
        int hrs2 = stoi(t2.substr(0,2));
        int mins2 = stoi(t2.substr(2,2));
        int time;
        
        if(abs(hrs1 - hrs2) == 1){
            if(hrs1 < hrs2)
                time = (60 - mins1) + mins2;
            else
                time = (60 - mins2) + mins1;
            if(time < 60)
                return true;
        }
        return false;
    }
};
