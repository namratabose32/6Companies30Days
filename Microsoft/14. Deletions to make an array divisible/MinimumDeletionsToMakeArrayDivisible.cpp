class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int ans=0;
        // store all the elements in map jisse ki khud hi sort ho jaye bina koi jhanjhat ke ;)
        map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        for(auto x:mp){
            int flag=0; // chaliye khoj shuru krte h
            for(auto c:numsDivide){
                if(c%x.first!=0){
                    flag=1;
                    break; // nhi mila loop se baahar chalo bekar time waste krna
                }
            }
            if(flag==1){
                ans+=x.second; // nhi mila so sara occurance hataao ab
            }else{
                return ans;  // mil gaya guyzzzzzzz
            }
        }return -1; // koi bhi divisible nhi h...... sooo sed :(
    }
};
// hindi me comments dalne ke liye khed h........ pr mazzzzaaaaaaaa ayaaaaaaa :) 
