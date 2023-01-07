// Method 1: TC:O(nums*numsDivide) + O(log nums)

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


//method 2 : using gcd  -------> TC: O(N)+O(log N)

class Solution {
public:
    int gcd(int a,int b){
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int ans=0;
        map<int,int> mp;
        for(auto x:nums)
            mp[x]++;
        // find greatest common divisor of numsDivide so as to easily find 1st element from nums which can divide all the elements of numsDivide
        int g=numsDivide[0];
        for(auto x:numsDivide){
            g=gcd(g,x);
        }
        // since map sorts all the elements so we can easily find the sortest element and time complexity can decrease a little bit if there are repitation of elements which are non-divisible
        for(auto x:mp){
            if(g%x.first==0){
                return ans;
            }
            else{
                ans+=x.second;
            }
        }return -1;
    }
};
