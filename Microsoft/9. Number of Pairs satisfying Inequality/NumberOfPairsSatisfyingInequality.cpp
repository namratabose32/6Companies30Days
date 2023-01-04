/*
    Step 1::
    Rewriting the inequality--
    (nums1[i] - nums2[i]) <= (nums1[j] - nums2[j]) + diff

    Step 2::
    Make a new array/vector c which stores nums1[i]-nums2[i].
    or c[i] = nums1[i]-nums2[i] for 0 <= i <= n - 1.

    Step 3::
    Problem reduces to find i , j such that 0 <= i < j <= n - 1 and
    c[i] <= c[j] + diff
    Now, divide and conquer method is used with the help of merge sort to count the number of pairs
*/
class Solution {
public:
    long long cnt=0;
    
    void countPair(vector<int> &nums,int start,int mid,int end, int diff){
        int l=start,r=mid+1;
        while(l<=mid && r<=end){
            if(nums[l]<=(nums[r]+diff)){
                // all elements from nums[r] to nums[end] >= nums[l]
                cnt+=(end-r+1);
                l++;
            }else{
                r++;
            }
        }
        // finally sort the array from start to end using 2 pointer stl for better time complexity
        sort(nums.begin()+start,nums.begin()+end+1);
        return;
    }
    
    void mergeSort(vector<int> &nums,int start,int end,int diff){
        if(start==end)
            return;
        int mid=(start+end)/2;
        // simply divide and conquer method is used
        mergeSort(nums,start,mid,diff);
        mergeSort(nums,mid+1,end,diff);
        // sort from last part of divide & conquer and return sorted array so that calculation becomes easy but the position is not affected
        countPair(nums,start,mid,end,diff);
        return;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            arr[i]=nums1[i]-nums2[i];
        mergeSort(arr,0,n-1,diff);
        return cnt;
    }
};
