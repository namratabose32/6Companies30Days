class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // left me sara unused values rakh rahe baad me use hone pe nikal denge
        // end will basically contain the previous element/value
        map<int,int> left,end;
        for(auto c:nums)
            left[c]++;
        for(auto i:nums){
            if(left[i]==0) // element hai hi nhi..... phele hi use kr chuke
                continue;
            left[i]--;
            if(end[i-1]>0){ // previous element is present
                end[i-1]--;
                end[i]++;
            }
            // previous element h nhi so abhi naya split krna hoga jiska condition ye h ki minimum 3 element hone chahiye isleye aage ka 2 consicutive element aur remove kr rahe and and last element is stored in end array so that we can check if the further elements can be kept in same split or not
           else if(left[i+1]>0 && left[i+2]>0){   
                left[i+1]--;
                left[i+2]--;
                end[i+2]++;
            }
        // kuch nhi mila means split size is less than 3 so return false
            else{
                return 0;
            }
        }return 1;
    }
};
