I.) Graphs Terminologies

    -1.) Terminologies

        -1.) Adjacency
            -If two nodes have a direct edge between them, then they said to be adjacent

        -2.) Degree
            -No. of edges going through that vertex

        -3.) Path
            -Collection of edges to reach from one node to the other node

        -4.) Connected Graphs
            -We call a graph a connected graph if for every two vertices there is a path between them

        -5.) Connected components
            -2.40 min in (2 DS\20 Graphs 1\2 Graphs Terminology\Video)

        -6.) Tree
            -A (connected graph) which does (not have a cycle)

    NOTE :-
        - Min. no. of edges in a connected graph?
            - (n-1) {Basically its a tree}
        - Max. no. of edges in a connected graph?
            - nC2 or n*(n-1)/2

        Conclusion : If the complexity is O(edge)
                     then, {n -> no. of vertices}
                     
                     O(n) <= O(edge) <= O(n^2)  


II.) Graphs ALGORITHMS
   
                    					-> connected
    -1.) Tree is a graph which is -----|
                    					-> does not have any cycle

        -Basically it have n vertices and n-1 edges

    -2.) Spanning Tree
        -Given an undirected and connected graph 
        	a spanning tree is a tree which contains all the vertices in the graph

    NOTE :-
        -For a given graph we can have multiple no. of spanning trees

    -3.) Min Spanning Tree ( MST )
        -Given weighted, connected and undirected graph 
        	the formed spanning tree must have 
        		min. weight

ALGORITHMS :-

	-1.) BFS/DFS :-

----------------------------------------------------
		Sample Input:-         

		4 4                    
		
		0 1
		0 3
		1 2
		2 3
----------------------------------------------------

		int V, E;
		bool *visited;
		vector<int> *edges;

		// BFS
		void printBfs(int start){
		    queue<int> pendingNodes;
		    pendingNodes.push(start);
		    visited[start] = true;
		    while(!pendingNodes.empty()){
		        int front = pendingNodes.front();
		        pendingNodes.pop();
		        cout<<front<<' ';
		        for(auto i : edges[front]){
		            if(!visited[i]){
		                visited[i] = true;
		                pendingNodes.push(i);
		            }
		        }
		    }
		}
		// DFS
		void printDfs(int start){
		    cout<<start<<' ';
		    visited[start] = true;
		    for(auto i : edges[start])
		        if(!visited[i])
		            printDfs(i);
		}
		// Main code
		int main() {
			// number of vertices and edges
		    cin >> V >> E;

			// Adjacency matrix
		    edges = new vector<int>[V];
		    for(int i = 0; i<E; i++){
		        int v1, v2;
		        cin>>v1>>v2;
		        edges[v1].push_back(v2);
		        edges[v2].push_back(v1);
		    }

		    // Flags for visited nodes
		    visited = new bool[V]();
		    
		    // Inside for loop to handle disconnected graphs
		    for(int i = 0; i<V; i++)
		    	if(!visited[i])
		        	printBfs(i);    
		    
		    delete [] visited;
		    delete [] edges;
		  	return 0;
		}

		
		
	-2.) Kruskals ALGORITHM: ( To calculate MST of a given graph )
		- Greegy Algorithm

        -1.) Take input -> O(E) { Unopmitsable }
        -2.) Sort input array -> O(E*log(E)) { Unopmitsable }
        -3.) Pick n-1 edges and put in MST {*** Optmisable ***}
                |
                |
                --> 1.) Union - find O(E*V)
                    2.) Union by rank and path compression O(E*log(V)) ((BEST)) { To be studied }----------------------------------------------------------

        -Complexity is decided by step 3.)
        -So optimising step 3.) will do the job

		CODE:
			class Edge{
			public:
			    int v1, v2, weight;
			};

			int V, E;
			Edge *edges, *mst;
			int *parent;

			int findParent(int v){
			    return (parent[v] == v) ? v : findParent(parent[v]);
			}
			void kruskals(){
			    int count = 0, i = 0;
			    while(count != V-1){
			        Edge currentEdge = edges[i++];
			        int v1Parent = findParent(currentEdge.v1);
			        int v2Parent = findParent(currentEdge.v2);
			        if(v1Parent != v2Parent){
			            mst[count++] = currentEdge;
			            parent[v1Parent] = v2Parent;
			        }
			    }
			}
			bool compare(Edge e1, Edge e2){
			    return (e1.weight < e2.weight);
			}
			int main(){
			    cin>>V>>E;
			    
			    edges = new Edge[E];
			    mst = new Edge[V-1];
			    parent = new int[V];
			    
			    for(int i = 0; i<V; i++)
			    	parent[i] = i;
			    
			    for(int i = 0; i<E; i++){
			        int v1, v2, weight;
			        cin>>v1>>v2>>weight;
			        edges[i].v1 = v1;
			        edges[i].v2 = v2;
			        edges[i].weight = weight; 
			    }
			    
			    sort(edges, edges + E, compare);
			    
			    kruskals();
			    
			    for(int i = 0; i<V-1; i++){
			        if(mst[i].v1 < mst[i].v2)
			            cout<<mst[i].v1<<" "<<mst[i].v2;
			        else
			            cout<<mst[i].v2<<" "<<mst[i].v1;
			        
			    	cout<<" "<<mst[i].weight<<endl;
				}
			}

		3.) Prims Algorithm: ( To calculate MST of a given graph )
			- Greegy Algorithm

			CODE:
				int V, E;
				bool *visited;
				int *parent;
				int *weight;

				int findMinVertex(){
				    int minVertex = -1;
				    for(int i = 0; i < V; i++)
				        if(!visited[i] && (minVertex == -1  || weight[i] < weight[minVertex]))
				            minVertex = i;
				    return minVertex;
				}
				void prims(vector<pair<int,int>> adj[]){
				    for(int i = 0; i < V; i++){
				        int minVertex = findMinVertex();
				        visited[minVertex] = true;
				        for(auto j : adj[minVertex])
				            if(!visited[j.first] && j.second > 0 && weight[j.first] > j.second){
				                    weight[j.first] = j.second;
				                    parent[j.first] = minVertex;
				            }
				    }
				}
				int main(){
				  	cin>>V>>E;
				    
				    visited = new bool[V]();
				    parent = new int[V]();
				    weight = new int[V]();
				    
				    for(int i = 1; i < V; i++)
				    	weight[i] = INT_MAX;
				    
				    vector<pair<int,int>> adj[V];
				  	for(int i = 0; i<E; i++){
				    	int v1, v2, w;
				        cin>>v1>>v2>>w;
				        adj[v1].push_back(make_pair(v2, w));
				        adj[v2].push_back(make_pair(v1, w));
				  	}
				    
				  	prims(adj);
				    
				    for(int i = 1; i < V; i++){
				        if(i < parent[i])
				            cout<<i<<" "<<parent[i];
				        else
				            cout<<parent[i]<<" "<<i;
				        cout<<" "<<weight[i]<<endl;
				    }
				    
				    delete [] visited;
				    delete [] parent;
				    delete [] weight;

				  	return 0;
				}

		4.) Dijkstra
 			- Gives shortest path from source to a destination
 					-------------	   ------      -----------
		
			CODE:
				1.) O(V*E)
					
					#include<bits/stdc++.h>
					using namespace std;

					#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
					#define ll long long
					#define in(n) ll n; cin>>n;
					#define inS(n) string n; cin>>n;
					#define inArr(arr, n) vl arr(n); f(i, 0, n) cin>>arr[i];
					#define pb push_back
					#define F first
					#define S second
					#define endl "\n"
					#define mod 1000000007
					#define f(i, s, e) for(int i = s; i<=e; i++)


					// Global arrays and variables
					ll V, E;
					vector<pair<ll, ll>> edges[100001]; // {F->edge, S->dist between two edges}
					bool vis[100001];
					ll dist[100001];

					// Finding the vertex with min distance which is still unvisited
					ll findMinDistVert(){ // O(V)
						ll vert_with_min_dist = -1;
						f(i, 1, V)
							if(!vis[i] && (vert_with_min_dist == -1 || dist[i] < dist[vert_with_min_dist]))
								vert_with_min_dist = i;
						return vert_with_min_dist;
					}
					void dijkstras(){
						fill(dist, dist+100001, 1000000000LL*E + 1LL); // Filling dist array with infinity initially
						dist[1] = 0;

						// Running loop for V times
						f(i, 1, V){//O(V)
							ll vert_with_min_dist = findMinDistVert(); // O(V)
							vis[vert_with_min_dist] = true;
							for(auto edge : edges[vert_with_min_dist]) //O(E)
								dist[edge.F] = min(dist[edge.F], dist[vert_with_min_dist] + edge.S);
						}
					}
					void solve(int t){
						cin>>V>>E;
						f(i, 1, E){
							in(vert1) in(vert2) in(dist)
							edges[vert1].pb({vert2, dist});
						}

						dijkstras();

						f(i, 1, V)
							cout<<dist[i]<<' ';
					}
					int main() {
						IO
					    int t = 1;
					    // in(t)
					    f(i, 1, t) solve(i);
						return 0;
					}
				2.) O(E*log(V))
					#include<bits/stdc++.h>
					using namespace std;

					#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
					#define ll long long
					#define in(n) ll n; cin>>n;
					#define inS(n) string n; cin>>n;
					#define inArr(arr, n) vl arr(n); f(i, 0, n) cin>>arr[i];
					#define pb push_back
					#define F first
					#define S second
					#define endl "\n"
					#define mod 1000000007
					#define f(i, s, e) for(int i = s; i<=e; i++)

					ll V, E;
					vector<pair<ll, ll>> edges[100001]; // {F->edge, S->dist between two edges}
					bool vis[100001];
					ll dist[100001];
					priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> minDistVertpq; //minimum priority queue with {F->distance from source, S->Node}

					void dijkstras(){
						fill(dist, dist+100001, 1000000000LL*E + 1LL); // Filling dist array with infinity initially
						dist[1] = 0;
						minDistVertpq.push({0, 1}); // Because distance from source to source is 0

						while(!minDistVertpq.empty()){
							auto minDistVert = minDistVertpq.top(); // O(log(V))
							minDistVertpq.pop();
							ll vert = minDistVert.S; 
							if(vis[vert])
								continue;
							vis[vert] = true;
							for(auto edge : edges[vert]){
								if(dist[edge.F] > dist[vert] + edge.S){
									dist[edge.F] = dist[vert] + edge.S;
									minDistVertpq.push({dist[edge.F], edge.F}); // O(log(V))
								}
							}
						}
					}
					void solve(int t){
						cin>>V>>E;
						f(i, 1, E){ 
							in(vert1) in(vert2) in(dist)
							edges[vert1].pb({vert2, dist});
						}

						dijkstras(); 

						f(i, 1, V)
							cout<<dist[i]<<' ';
					}
					int main() {
						IO
					    int t = 1;
					    // in(t)
					    f(i, 1, t) solve(i);
						return 0;
					}
				


Tips:
	1.) For weighted graphs:
	
		class Edge {
			public:
				int v;
				int d;
				Edge(int v, int d){
					this->v = v;
					this->d = d;
				}
		};

		vector<Edge> edges[100001];
