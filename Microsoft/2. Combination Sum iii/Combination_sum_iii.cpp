class Solution {
public:
    // recursion using pick / non-pick technique
    vector<vector<int>> ans;
    void solve(vector<int> arr,int size,vector<int> res,int index,int target){
        if(size==0 && target==0){
            ans.push_back(res);
            return;
        }
        if(target<0 || size==0 || index>=arr.size())
            return;
        //take
        res.push_back(arr[index]);
        solve(arr,size-1,res,index+1,target-arr[index]);
        res.pop_back();
        //not take
        solve(arr,size,res,index+1,target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // tak an array from 1-9 and choose the target sum of n from k elements.
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        vector<int> res;
        solve(arr,k,res,0,n);
        return ans;
    }
};
