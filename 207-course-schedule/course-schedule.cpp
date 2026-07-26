class Solution {
public:
    bool isValid(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& resStack, int node){
        visited[node] = true;
        resStack[node] = true;

        for(int neighbour : adj[node]){
            if(!visited[neighbour] && isValid(adj, visited, resStack, neighbour)) return true;
            else if(resStack[neighbour]) return true;
        }

        resStack[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& preReq) {
        vector<vector<int>> adj(numCourses);

        vector<bool> resStack(numCourses, false);
        vector<bool> visited(numCourses, false);

        for(auto& e : preReq) adj[e[1]].push_back(e[0]);

        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && isValid(adj, visited, resStack, i)) return false;
        }

        return true;
    }
};