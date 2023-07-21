/**
 * @author : its-mahi
*/

// Ford-Fulkarson Algorithm
#include <bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent) {
    int n = rGraph.size();
    vector<bool> vis(n, false);
    
    queue<int> q;
    q.push(s);
    
    vis[s] = 1; //Making source visited.
    parent[s] = -1;  //No parent of Source.
    
    while(! q.empty()) {
        int u = q.front();
        q.pop();
        for(int v=0; v<n; v++) {
            if(!vis[v] and rGraph[u][v] > 0) {
                if(v == t) {
                    parent[v] = u; 
                    return true;  // Returns true if there is path from source to sink.
                }
                q.push(v);
                vis[v] = 1;   //Node is Visited.
                parent[v] = u;
            }
        }
    }
    return false;
}

int fordfulkerson(vector<vector<int>> &G, int s, int t) {
    int n = G.size();
    vector<vector<int>> residualGraph(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            residualGraph[i][j] = G[i][j]; // Initialize residual graph with original capacities
        }
    }

    vector<int> parent(n);

    int max_flow = 0;

    while (BFS(residualGraph, s, t, parent)) {
        int bottleneck = INT_MAX;
        
        //Finding Bottleneck Capacity
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            bottleneck = min(bottleneck, residualGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= bottleneck;
            residualGraph[v][u] += bottleneck;
        }

        max_flow += bottleneck;
    }

    return max_flow;
}


int main() {
    int n;
    cout << "Enter no. of nodes :\n";
    cin >> n;
    
    vector<vector<int>> graph(n , vector<int> (n, 0));
    
    cout << "Provide Graph such that value of g[i][j] is flow value b/w i -> j:\n";
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> graph[i][j];
        }
    }
    
    int source, sink;
    cout << "Provide source and sink:\n";
    cin >> source >> sink;
    
    cout << "Min. flow in network is : " << fordfulkerson(graph, source, sink);
    
    return 0;
}
