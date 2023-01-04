//Topological sort is used in which it is compulsory to be a DAG(Directed Acyclic Graph)

// we only check if the graph is cyclic or acyclic by the help of Kahn's Algorithm(Topological sort using BFS)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // store values in adjacent matrix i.e u->v for graph
        vector<int> adj[numCourses];
        for(auto x:prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        // calculate the indegree of a node i.e. number of incomming nodes
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto x: adj[i])
                indegree[x]++;
        }
        queue<int> q;
        // stores all the nodes which have indegree of 0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        // topographical sort is performed.... all the nodes whose indegree are 0 are stored in array after execution
        while(!q.empty()){
            int top=q.front();
            q.pop();
            topo.push_back(top);
            // nodes with indegree 0 evaluates for its adjacent node and decreases its indegree value
            for(auto x:adj[top]){
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        // if size of topo is equal to all the nodes present in graph then it is acyclic graph so we can do all the courses
        if(topo.size()==numCourses)
            return 1;
        return 0;
    }
};
