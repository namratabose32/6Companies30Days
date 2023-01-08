class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<long long int,int> mp; //distance, count of all points at a distance from i
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                // calculate distance....... not taking square root as it will be in decimal which can be rounded or hard to compare and also exact distance is not needed, only number of same distance is needed.
                long long int dx=points[j][0]-points[i][0];
                long long int dy=points[j][1]-points[i][1];
                long long int dist= dx*dx + dy*dy;
                mp[dist]++;
            }
            for(auto x:mp){
                // total number of points whose distance is same is >=2
                if(x.second>=2){
            /*
                 for all the groups of points, number of ways to select 2 from n                    => nP2 = n!/(n - 2)! = n * (n - 1)
            */
                    ans+=x.second * (x.second-1);
                }
            }
        }return ans;
    }
};
