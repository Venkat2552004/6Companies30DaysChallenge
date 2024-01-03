// Link : https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
// Goldman Sachs | Day - 3 | Problem - 2

class DataStream {
public:
    int value, k, size, cnt;
    string str;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        str = "";
        size = 0;
        cnt = 0;
    }
    
    bool consec(int num) {
        str += to_string(num);
        if(num == value){
            cnt++;
        }
        else
            cnt = 0;
        size = str.length();
        if(size < k)
            return false;
        if(cnt >= k)
            return true;
        return false;
    }
};
