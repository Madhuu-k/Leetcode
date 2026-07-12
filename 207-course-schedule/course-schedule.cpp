class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& resStack){
        visited[node] = true;
        resStack[node] = true;

        for(int neighbour : adj[node]){
            if(!visited[neighbour] && dfs(neighbour, adj, visited, resStack)) return true;
            else if(resStack[neighbour]) return true;
        }

        resStack[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& e : prerequisites) adj[e[1]].push_back(e[0]);
        
        vector<bool> visited(numCourses, false);
        vector<bool> resStack(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && dfs(i, adj, visited, resStack)) return false;
        }

        return true;
    }
};