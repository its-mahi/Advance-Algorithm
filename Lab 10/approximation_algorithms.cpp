/*
 * @author : its_mahi
 * 
 * note : code is not completed, remaining to generalize the code.
*/


#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V; 
	list<int> *adj; 
public:
	Graph(int V){
	    this->V = V;
    	adj = new list<int>[V];
	}
	void addEdge(int v, int w){
	    adj[v].push_back(w); 
    	adj[w].push_back(v); 
	}
	void printVertexCover(){
	    	bool visited[V];
	for (int i=0; i<V; i++)
		visited[i] = false;

	list<int>::iterator i;

	for (int u=0; u<V; u++)
	{
		if (visited[u] == false)
		{
		    
			for (i= adj[u].begin(); i != adj[u].end(); ++i)
			{
				int v = *i;
				if (visited[v] == false)
				{
					visited[v] = true;
					visited[u] = true;
					break;
				}
			}
		}
	}

	
	for (int i=0; i<V; i++)
		if (visited[i])
		cout << i << " ";
}
};



int main()
{
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(3, 2);
	g.addEdge(4, 5);
// 	g.addEdge(6, 0);
// 	g.addEdge(0, 6);
// 	g.addEdge(1, 5);
	
	
	


	g.printVertexCover();

	return 0;
}
