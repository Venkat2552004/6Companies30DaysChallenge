
// Link : https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/
// Goldman Sachs | Day - 1 | Problem - 1

#define ll long long

class Solution {
public:
    int minimizeSet(int div1, int div2, int uniqueCnt1, int uniqueCnt2) {
        //approach using binary search
        ll  l = 1, h = INT_MAX, res = INT_MAX, mid; // didn't worked when h = 1e9 + 1 and idk why
        while(l <= h){
            mid = (l + h) / 2;
            // remainig no.of elements that are not divisible by div1 upto mid
            ll cnt1 = mid - (mid / div1);
            // remainig no.of elements that are not divisible by div2 upto mid
            ll cnt2 = mid - (mid / div2);
            // remainig no.of elements that are not divisible by div1 and div2
            ll GCD = findGCD(div1, div2);
            ll LCM = (ll)((ll)div1 * (ll)div2) / GCD;
            ll cnt3 = mid - (mid / LCM);
            // if satisfies the condition, save result and search for next possible minimum
            if(cnt1 >= uniqueCnt1 and cnt2 >= uniqueCnt2 and cnt3 >= uniqueCnt1+uniqueCnt2){
                res = min(res, mid);
                h = mid - 1;
            }
            //else search in the next half
            else
                l = mid + 1;
        }
        return res;
    }

    long long findGCD(int a, int b){
        if(b == 0)  return a;
        return findGCD(b, a % b);
    }
};
