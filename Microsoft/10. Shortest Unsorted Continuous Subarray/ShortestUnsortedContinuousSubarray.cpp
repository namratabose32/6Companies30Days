class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        for(auto x:nums){
            temp.push_back(x);
        }
        sort(temp.begin(),temp.end());
        int i=0,ans=0;
        // count the 1st series of elements from the nums that are in same position as of sorted array
        for(i=0;i<n;i++){
            if(temp[i]==nums[i])
                ans++;
            else
                break;
        }
        // count the last series of elements from the nums that are in same position as of sorted array
        for(int j=n-1;j>i;j--){
            if(temp[j]==nums[j])
                ans++;
            else
                break;
        }
        return n-ans;
    }
};
