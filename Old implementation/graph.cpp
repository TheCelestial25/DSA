#include <bits/stdc++.h>
using namespace std;

bool visited[100] = {0};
bool rec[100];

// Adjacency list implementation of graph
void addEdge(vector<int> G[], int u, int v) {
	G[u].push_back(v);

	// uncomment below for undirected graph
	// G[v].push_back(u);
}

void printG(vector<int> G[], int n) {
	for(int v = 0; v < n; v++) {
		cout << v << ": ";
		for(auto x : G[v]) cout << "->" << x << " ";
			cout << endl;
	}
}

void DFSIterative(vector<int> G[], int n, int start, int target) {
	stack<int> st;
	bool visited[n] = {0};
	st.push(start);
	while(!st.empty()) {
		int v = st.top();
		st.pop();
		if(!visited[v]) {
			visited[v] = true;
			cout << v << " ";
			for(auto x : G[v])
				st.push(x);
		}
	}
}

void BFS(vector<int> G[], int n, int start, int target) {
	queue<int> q;
	bool visited[n] = {0};
	q.push(start);
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		if(!visited[v]) {
			visited[v] = true;
			cout << v << " ";
			for(auto x : G[v])
				q.push(x);
		}
	}
}

// Based on adjacency list implementation
void Dijkstra(vector<pair<int,int>> G[], int n, int source) {
	priority_queue<pair<int,int>> pq; // <dist,vertex>
	int dist[n];
	for(int i=0; i<n; i++) dist[i] = INT_MAX;

	pq.push(make_pair(0, source));
	dist[source] = 0;

	while(!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		for(int x=0; x<G[v].size(); x++) {
			int weight = G[v][x].second;
			if(dist[G[v][x].first] > dist[v] + weight) {
				dist[G[v][x].first] = dist[v] + weight;
				pq.push(make_pair(dist[v] + weight, G[v][x].first));
			}
		}
	}
	printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);
}

void bellmanFord(int graph[][3], int V, int E, 
                 int src) 
{ 
    // Initialize distance of all vertices as infinite. 
    int dis[V]; 
    for (int i = 0; i < V; i++) 
        dis[i] = INT_MAX; 
  
    // initialize distance of source as 0 
    dis[src] = 0; 
  
    // Relax all edges |V| - 1 times. A simple 
    // shortest path from src to any other 
    // vertex can have at-most |V| - 1 edges 
    for (int i = 0; i < V - 1; i++) { 
  
        for (int j = 0; j < E; j++) { 
            if (dis[graph[j][0]] + graph[j][2] < 
                               dis[graph[j][1]]) 
                dis[graph[j][1]] =  
                  dis[graph[j][0]] + graph[j][2]; 
        } 
    } 
  
    // check for negative-weight cycles. 
    // The above step guarantees shortest 
    // distances if graph doesn't contain 
    // negative weight cycle.  If we get a 
    // shorter path, then there is a cycle. 
    for (int i = 0; i < E; i++) { 
        int x = graph[i][0]; 
        int y = graph[i][1]; 
        int weight = graph[i][2]; 
        if (dis[x] != INT_MAX && 
                   dis[x] + weight < dis[y]) 
            cout << "Graph contains negative"
                    " weight cycle"
                 << endl; 
    } 
  
    cout << "Vertex Distance from Source" << endl; 
    for (int i = 0; i < V; i++) 
        cout << i << "\t\t" << dis[i] << endl; 
}

void floydWarshall(vector<vector<int>> g) {
	int INF = 99999;
	int n = g.size();
	int dp[n][n];

	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++) 
			dp[i][j] = g[i][j];

	for(int k=0; k<n; k++) 
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(dp[i][k] + dp[k][j] < dp[i][j])
					dp[i][j] = dp[i][k] + dp[k][j];

	cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < n; i++)  
    {  
        for (int j = 0; j < n; j++)  
        {  
            if (dp[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dp[i][j]<<"     ";  
        }  
        cout<<endl;  
    }
}
  

/* Weighted edge implementation
void addEdge(vector<pair<int,int>> adj[], int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} */

void DFS(vector<int> adj[], int n, int source, int target) {
	if(source ==  target) return;
	visited[source] = true;
	cout << source << " ";

	for(auto x : adj[source])
		if(!visited[x])
			DFS(adj, n, x, target);
}

// Detect cycle in directed graph using DFS
bool isCycleDirected(vector<int> adj[], int n, int source) {
	if(!visited[source]) {
		visited[source] = true;
		rec[source] = true;
		for(auto x : adj[source]) {
			if(!visited[x] and isCycleDirected(adj, n, x))
				return true;
			else if(rec[x])
				return true;
		}
	}
	rec[source] = false;
	return false;
}

bool cycleDirected(vector<int> adj[], int n) {
	for(int i=0; i<n; i++) {
		rec[i] = false;
		visited[i] = false;
	}
	for(int i=0; i<n; i++) 
		if(isCycleDirected(adj, n, i)) 
			return true;
	return false;
}


/*
1. Find the farthest vertex form any source
2. Find the farthest vertex from this vertex
Works! Has some proof
*/
// int mx = INT_MIN;
// int mxv = -1;
// void longestPath(vector<int> adj[], int v, int curr) {
// 	visited[v] = true;
// 	int currmax = curr;
// 	for(int u : adj[v]) {
// 		// cout << v << " " <<  u << " " << visited[u] << endl;
// 		if(!visited[u])
// 			longestPath(adj, u, curr + 1);
// 	}
// 	if(curr > mx) {
// 		mx = curr; 
// 		mxv = v;
// 	}
// }

struct kEdge {
	int src, dest, weight;
	// kEdge(int a, int b, int c) {
	// 	this->src = a;
	// 	this->dest = b;
	// 	this->weight = c;
	// }
};

int find(vector<int> parent, int u) {
	if(u == parent[u]) return u;
	int t = find(parent, parent[u]);
	parent[u] = t; // path compression
	return t;
}

void Union(vector<int> &parent, vector<int> rank, int u, int v) {
	int x = find(parent, u);
	int y = find(parent, v);
	if(rank[x] == rank[y]) {
		parent[x] = y;
		rank[y]++;
	}
	else if(rank[y] > rank[x]) parent[x] = y;
	else parent[y] = x;
}

int mstcomp(const kEdge a, const kEdge b) {
	return a.weight < b.weight;
}

vector<kEdge> Kruskal(vector<kEdge> G, int n) {
	int edge = 0;
	vector<kEdge> ans;
	sort(G.begin(), G.end(), mstcomp);
	vector<int> parent(n);
	vector<int> rank(n);
	for(int i=0; i<n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
	int i=0;
	while(i < n-1 and edge < G.size()) {
		kEdge next_edge = G[edge++];
		int x = find(parent, next_edge.src);
		int y = find(parent, next_edge.dest);

		if(x != y) {
			i++;
			Union(parent, rank, x, y);
			ans.push_back(next_edge);
		}
	}
	return ans;
}

int findMinForPrim(vector<int> cost, bool included[]) {
	int m = INT_MAX;
	int mi = 0;
	for(int i=0; i<cost.size(); i++) 
		if(cost[i] < m and !included[i]) {
			m = cost[i]; 
			mi = i;
		}
	return mi;
}

vector<kEdge> Prims(vector<vector<int>> g, int n) {
	bool included[n] = {0};
	vector<int> cost(n);
	int parent[n] = {0};
	cost[0] = 0;
	for(int i=1; i<g.size(); i++) cost[i] = INT_MAX;

	int i = 0;
	while(i++ < n) {
		// for(int x : cost) cout << x << " ";
		// 	cout << endl;
		// for(int x : included) cout << x << " ";
		// 	cout << endl;
		int u = findMinForPrim(cost, included);
		// cout << u << endl << endl;
		included[u] = true;

		for(int v=0; v<n; v++) {
			if(g[u][v] and cost[v] > g[u][v] and !included[v])
				cost[v] = g[u][v], parent[v] = u;
		}
	}

	vector<kEdge> ans;
	for(int i=0;i<n; i++) {
		if(included[i]) {
			kEdge temp;
			temp.src = parent[i];
			temp.dest = i;
			temp.weight = cost[i];
			ans.push_back(temp);
		}
	}
	return ans;
}

void topoDFS(vector<int> adj[], int n, int u, stack<int> &s) {
	visited[u] = true;
	for(int v : adj[u]) {
		if(!visited[v])
			topoDFS(adj, n, v, s);
	}
	s.push(u);
}

void topologicalSort(vector<int> adj[], int n) {
	stack<int> s;
	for(int u=0;u<n; u++) {
		if(!visited[u]) {
			topoDFS(adj, n, u, s);
		}
	}

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

void articulationDFS(vector<int> g[], int n, int u, int parent[], bool ap[], int disc[], int low[], int time) {
	disc[u] = low[u] = ++time;
	visited[u] = true;
	int child = 0;

	for(int v : g[u]) {
		if(!visited[v]) {
			parent[v] = u;
			child++;

			articulationDFS(g,n,v,parent,ap,disc,low,time);
			low[u] = min(low[u], low[v]);

			// If this u is root, this condition is inside the loop because children increase
			if(child > 1 and parent[u] == -1) ap[u] = true;

			// If baccha cannot reach to any node seen before baap
			if(parent[u] != -1 and low[v] >= disc[u]) ap[u] = true;
		}
		// this is the case of backedge and low updation, leave parent from this case
		else if(parent[u] != v)
			low[u] = min(low[u], disc[v]);
	}
}

void articulation(vector<int> g[], int n) {
	memset(visited, 0, sizeof visited);
	int parent[n];
	bool ap[n] = {0};
	int disc[n] = {0};
	int low[n] = {0};
	for(int i=0; i<n; i++)
		parent[i] = -1;

	int time = 0;
	for(int u=0; u<n; u++) 
		if(!visited[u]) articulationDFS(g, n, u, parent, ap, disc, low, time);

	for(int i=0; i<n; i++) 
		if(ap[i]) cout << i << " ";
}

bool augmentedPathBFS(vector<vector<int>> rem, int parent[], int s, int t) {
	queue<int> q;
	int n = rem.size();
	q.push(s);
	bool visited[n] = {0};
	visited[s] = true;
	// parent[s] = -1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		visited[u] = true;
		for(int v=0; v<n; v++) {
			if(rem[u][v] > 0 and !visited[v]) {
				parent[v] = u;
				visited[v] = true;
				q.push(v);
			}
		}
	}

	return visited[t];
}


int fordFulkerson(vector<vector<int>> g, int s, int t) {
	int n = g.size();
	vector<vector<int>> rem(n, vector<int> (n,0));
	int parent[n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			rem[i][j] = g[i][j];

	int max_flow = 0;

	while(augmentedPathBFS(rem, parent, s, t)) {
		int bottleneck = INT_MAX;
		for(int v=t; v!=s;v = parent[v]) {
			int u = parent[v];
			bottleneck = min(bottleneck, rem[u][v]);
		}

		for(int v=t; v!=s; v = parent[v]) {
			int u = parent[v];
			rem[u][v] = rem[u][v] - bottleneck;
			rem[v][u] = rem[v][u] + bottleneck;
		}

		max_flow += bottleneck;
	}

	return max_flow;
}

int main() {

	return 0;
}