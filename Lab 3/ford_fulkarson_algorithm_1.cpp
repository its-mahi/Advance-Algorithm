/**
 * @author : its-mahi
*/

// Ford-Fulkarson Algorithm
#include <bits/stdc++.h>
using namespace std;

bool bfs(int n, vector<vector<int>> graph, int s, int t, vector<int> &parent) {
    vector<int> visited(n, 0);
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        for(int v=0 ; v<n ; v++) {
            if(visited[v] == 0 && graph[u][v] > 0) {
                if(v == t) {
                    parent[v] = u;
                    return true;
                }
                else {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = 1;
                }
            }
        }
    }
    
    return false;
}

int ford_fulkerson(int n, vector<vector<int>> graph, int s, int t) {
    int max_flow = 0;
    vector<int> parent(n, 0);
    
    bool is_augmented_path_present = bfs(n, graph, s, t, parent);
    while(is_augmented_path_present == true) {
        int bottle_neck_cap = INT_MAX;
        
        for(int v=t ; v!=s ; v=parent[v]) {
            int u = parent[v];
            bottle_neck_cap = min(bottle_neck_cap, graph[u][v]);
        }
        
        for(int v=t ; v!=s ; v=parent[v]) {
            int u = parent[v];
            graph[u][v] -= bottle_neck_cap;
            graph[v][u] += bottle_neck_cap;
        }
        
        max_flow += bottle_neck_cap;
        is_augmented_path_present = bfs(n, graph, s, t, parent);
    }
    
    return max_flow;
}

int main() {

    int n = 6;
    vector<vector<int>> graph;
    
    graph.push_back({0,16,13,0,0,0});
    graph.push_back({0,0,10,12,0,0});
    graph.push_back({0,4,0,0,14,0});
    graph.push_back({0,0,9,0,0,20});
    graph.push_back({0,0,0,7,0,4});
    graph.push_back({0,0,0,0,0,0});
    
                       
    int max_flow = ford_fulkerson(n, graph, 0, 5);
    
    cout << "Max flow of Graph : " << max_flow << endl;
    
    return 0;
}
