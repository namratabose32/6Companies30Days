class Solution {
public:
    int trailingZeroes(int n) {
        // 5*2 makes 10 & 10 itself
        // therefore 5 10 15 25 30.... etc will make trailing zeros of 1 2 3 4 5..... etc
        int ans=0;
        while(n>=5){
            ans+=n/5;
            n/=5;
        }
    /*
        n=100
        ans = 100/5 + 20/5 + 4/5 = 20+4+0=24
    */
        return ans;
    }
};
