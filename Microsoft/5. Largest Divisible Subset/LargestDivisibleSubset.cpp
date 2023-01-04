// dp && longest increasing susequence is required ( Striver vdo 41-44 )

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),mx=1,lastIndex=0;
        sort(nums.begin(),nums.end());
        vector<int> ans,hash(n),dp(n,1);
        for(int i=0;i<n;i++){
            hash[i]=i;
          //check all previous divisible elements and increase dp[i] value accordingly
          // hash set constain the index of element which is lastly divisible so as to track the path
          // dp[i]< dp[j]+1 condition is applied for checking the largest subset
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
          // mx store the max length of required subset and lastIndex store the last index of element from the subset whose length is maximum 
            if(dp[i]>mx){
                mx=dp[i];
                lastIndex=i;
            }
        }
      // push all the elements of the largest divisible subset with the help of lastIndex and hash vector which contains the index value of the subset
        ans.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        return ans;
    }
};
