class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // create adjacent matrix to store the vertices of graph
        vector<pair<long long,long long>> adj[n];
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        // dijkstra's algorithm
        
        // priority queue jisse ki heap me daalte hi minimum distance ke hisab se sort ho jaaye
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0}); // time, node
        vector<long long> totaltym(n,LONG_MAX),ways(n,0);
        int mod=(int)(1e9+7);
        totaltym[0]=0; // minimum time store krne ke liye har ek node ka
        ways[0]=1; // kitna minimum distance wala path/way bana ab tak uss node ke liye
        while(!pq.empty()){
            long long time=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            // agar current node ke aage jaane ka time minimum time se zada h toh lena hi nhi h........ quki minimum time chahiye na... iss execution time bachega
            if(time>totaltym[node])
                continue;
            // ab uss node ke haar ek adjacent node ke liye check karo.... tabhi na sara nodes check kr payenge
            for(auto x:adj[node]){
                long long adjNode=x.first;
                long long adjtym=x.second;
                // abhi ka time agar total minimum time se chota h matlb sb refresh karo aur queue me ek naya [time,node] daalo jisse ki minimum khoje
                if(time+adjtym<totaltym[adjNode]){
                    totaltym[adjNode]=adjtym+time;
                    pq.push({totaltym[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                // minimum time equal ho jaye current path ke time se toh bs increase krdo number of ways ko
                else if(adjtym+time==totaltym[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        // last tak pahuchne ka sara ways... last node ka ways return krdo
        return ways[n-1]%mod;
    }
};
//Hindi me comments dalne ke liye khed h :)
