class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, int node, vector<int>& result){
        visited[node] = true;
        recStack[node] = true;

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                if(isCycle(adj, visited, recStack, neighbour, result)) return true;
            }
            else if(recStack[neighbour]) return true;
        }

        recStack[node] = false;
        result.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        for(auto& e : pre) adj[e[1]].push_back(e[0]);

        vector<bool> visited(numCourses, false);
        vector<bool> resStack(numCourses, false);

        vector<int> result;

        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && isCycle(adj, visited, resStack, i, result)) return {};
        }
        reverse(result.begin(), result.end());
        return result;

    }
};