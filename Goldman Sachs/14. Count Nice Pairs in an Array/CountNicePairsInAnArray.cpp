class Solution {
public:
    int rev(int n){ //function to reverse a number
        int r=0;
        while(n>0){
            r=r*10+n%10;
            n/=10;
        }return r;
    }
    //      nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
    //-->   nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
    int countNicePairs(vector<int>& nums) {
        int ans=0,mod=1e9+7;
        unordered_map<int,int> mp;
        for(int i=nums.size()-1;i>=0;i--){
            int x= nums[i]-rev(nums[i]);
            // if number found in map count its occurance till now in ans and add +1 in map.
            if(mp.find(x)!=mp.end()){
                ans=(ans+mp[x])%mod;
                mp[x]++;
            }
            else
                mp[x]++;
        }return ans;
    }
};
