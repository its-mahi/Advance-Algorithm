/**
 * @author : its_mahi
*/

//Karger's Min cut algorithm
#include <bits/stdc++.h>
using namespace std;

//Implementing DSU data structure for merging the nodes.
int find(int node, vector<int> &parent) {
        // If the node is the parent of 
        // itself then it is the leader 
        // of the tree. 
        if(node == parent[node]) return node;
        
        //Else, finding parents and also 
        // compressing the paths.
        return parent[node] = find(parent[node],parent);
}

 // Union function 
void Union(int u, int v, vector<int> &parent) {
        u = find(u, parent);
        v = find(v, parent);
        parent[v] = u;
}

int count_edges(vector<vector<int>> &g) {
    //Basically checking the upper Triangle part of the adj. matrix to find edges n/2. 
    int counter = 0;
    int i, j;
    int n = g.size();
    for(i=0; i<n ;i++) {
        for(j = i+1; j<n; j++) {
            if(g[i][j] == 1) counter++;
        }
    }
    return counter;
}

void create_edge_matrix(vector<vector<int>> &g, int e[][2]) {
    int i, j; 
    int n = g.size();
    int x = 0;
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(g[i][j] == 1) {
               e[x][0]=i;
               e[x][1]=j;
               x++;
            }
        }
    }
}

int main() {
//   cout << "Provide no of vertices in graph:\n";
   int n = 4;
//   cin >> n;
   
   srand(time(NULL));
//   cout << "Provide graph :\n";
   vector<vector<int>> graph = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};   //Adj. matrix
   
//   for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> graph[i][j];
//         }    
//   }
    int mincut = INT_MAX;
    
   for(int k = 0; k<100*n*n; k++) {
       vector<int> parent(n);
       for(int i=0; i<n; i++) {
           parent[i] = i;
       }
       
       int m = count_edges(graph);
       
       //Creating edge matrix 
       int edges[m][2];
       create_edge_matrix(graph, edges);
       
       //Iterating till we dont have V and V-S, (at that we'll have n = 2)
       while(n > 2) {
           int u, v;
           int e = rand() % m;  //Selecting random edge from Edge- matrix
           u = edges[e][0];
           v = edges[e][1];
           
           int set1 = find(u, parent);
           int set2 = find(v, parent);
           
           //Checking if both vertices are in same grp or not, if set1 == set2 then they are in same gropu bcuz they'll have same leader.
           
           if(set1 != set2) {
                    // cout << "Contracting vertices " << u << " and " << v << endl;
                    // Merging vertices u and v into one.
                    Union(u,v,parent);
                    // Reducing count of vertices by 1.
                    n--;
            }
       }
       
        // cout << "Edges needs to be removed : " << endl;
        int ans = 0;
     
        cout << endl;
        for(int i=0; i<m; i++) {
                // Finding leader element to which
                // edges[i].u belongs.
                int set1 = find(edges[i][0],parent);
                // Finding leader element to which
                // edges[i].v belongs.
                int set2 = find(edges[i][1],parent);
                
                // If they are not in the same set, means one is in V and other is in V-S
                if(set1 != set2) {
                    // cout << edges[i][0] << " <----> " << edges[i][1] << endl;
                    // Increasing the ans. 
                    ans++;
                }
        }
        if(ans < mincut) mincut = ans;
        // cout << ans << endl;
   }
    cout << "Min. cut size is : " << mincut << endl;
    return 0;
}
