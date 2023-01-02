class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        /*we assume to take the double of the array to perform rotation easily without taking extra time
        -> eg [4,3,2,6] => [4,3,2,6,4,3,2,6]
        -> sliding window approach is used.
        */
        long long n=nums.size(),sum=0,mx=0,fn=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            fn+=(i*nums[i]);
        }mx=fn;
        int l=1;
        while(l<n){
            int r= l+n-1;
            //removing 1st element of previous set
            int remove= (l-1)*nums[l-1];
            //adding next element of doubled array
            int add=r*nums[r%n];
            /*we subtract sum to remove an entire set from the answer
            as (1*3 + 2*2 + 3*6 + 4*4) = sum + (0*3 + 1*2 + 2*6 + 3*4)
            so in every iteration the sum of original array is removed.
            */
            fn=fn+add-remove-sum;
            mx=max(fn,mx);
            l++;
        }
        return mx;
    }
};
