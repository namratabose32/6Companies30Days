class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> arr,int size,vector<int> res,int index,int target){
        if(size==0 && target==0){
            ans.push_back(res);
            return;
        }
        if(target<0 || size==0 || index>=arr.size())
            return;
        res.push_back(arr[index]);
        solve(arr,size-1,res,index+1,target-arr[index]);
        res.pop_back();
        solve(arr,size,res,index+1,target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr={1,2,3,4,5,6,7,8,9};
        vector<int> res;
        solve(arr,k,res,0,n);
        return ans;
    }
};
