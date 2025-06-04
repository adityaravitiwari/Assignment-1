bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        visited[node] = 1;
        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 1) {
                return true; 
            }
            if (visited[neighbor] == 0 && dfs(neighbor, graph, visited)) {
                return true;
            }
        }
        
        visited[node] = 2;
        return false;
    }
bool hasCircularDependency(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]); 
        }
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (dfs(i, graph, visited)) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }