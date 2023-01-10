// TLE........ will upload better solution later as I haven't completed the higher topics
class Solution {
public:
    /*
        4 0 1 3 2
        4 1 0 2 3
        Taking 0 as mid element in nums1 we have left=1 & right=2 in nums2 => ans+= 1*2;
        Taking 1 as mid element in nums1 we have left=1 & right=2 in nums2 => ans+=1*2
        Taking 3 as mid element in nums1 we have left=3 & right=0 in nums2 => ans+=3*0;
    */
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        //Time Complexity : O(n*n)  --------> TLE
        
        long long ans=0;
        map<int,int> mp;
        for(int i=0;i<nums2.size();i++)
            mp[nums2[i]]=i; //value and its index in nums2
        for(int i=1;i<nums1.size()-1;i++){
            long long left=0,right=0;
        //how many elements are at the left of nums1[i] of nums2
            for(int j=0;j<i;j++){
                if(mp[nums1[j]]<mp[nums1[i]])
                    left++;
            }
        //how many elements are at the right of nums1[i] of nums2
            for(int j=i+1;j<nums2.size();j++){
                if(mp[nums1[j]]>mp[nums1[i]])
                    right++;
            }
            ans+=(left*right);
        }return ans;
        
        
    }
};
