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

		// Bfs
		void printBfs(int start, vector<int> adj[]){
		    queue<int> pendingNodes;
		    pendingNodes.push(start);
		    visited[start] = true;
		    while(!pendingNodes.empty()){
		        int front = pendingNodes.front();
		        pendingNodes.pop();
		        cout<<front<<' ';
		        for(auto i : adj[front]){
		            if(!visited[i]){
		                visited[i] = true;
		                pendingNodes.push(i);
		            }
		        }
		    }
		}
		// Dfs
		void printDfs(int start, vector<int> adj[]){
		    cout<<start<<' ';
		    visited[start] = true;
		    for(auto i : adj[start])
		        if(!visited[i])
		            printDfs(i, adj);
		}
		// Main code
		int main() {
			// number of vertices and edges
		    cin >> V >> E;
			
			// Adjacency matrix
		    vector<int> adj[V];
		    for(int i = 0; i<E; i++){
		        int x, y;
		        cin>>x>>y;
		        adj[x].push_back(y);
		        adj[y].push_back(x);
		    }
		    
		    // Flags for visited nodes
		    visited = new bool[V]();
		    
		    // Inside for loop to handle disconnected graphs
		    for(int i = 0; i<V; i++)
		    	if(!visited[i])
		        	printBfs(i, adj); or printDfs(i, adj);    
		    
		    delete [] visited;
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
				int findMinVertex(int *distance, bool *visited, int n){
					int minVertex = -1;
					f(i, 0, n)
						if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
							minVertex = i;
					return minVertex;						
				}
				void dijkstra(int **edges, int n){
					int *distance = new int[n];
					bool *visited = new bool[n];
					f(i, 0, n){
						distance[i] = INT_MAX;
						visited[i] = false;
					}
					distance[0] = 0;
					f(i, 0, n-1){
						int minVertex = findMinVertex(distance, visited, n);
						visited[minVertex] = true;
						f(j, 0, n)
							if(edges[minVertex][j] != 0 && !visited[j]){
								int dist = distance[minVertex] + edges[minVertex][j];
								if(dist < distance[j])
									distance[j] = dist;
							}
					}
					f(i, 0, n)
						cout<<i<<" "<<distance[i]<<endl;
					delete [] visited;
					delete [] distance;
				}
				int main(){
					int n, e;
					cin>>n>>e;
					int **edges = new int*[n];
					f(i, 0, n){
						edges[i] = new int[n];
						f(j, 0, n) edges[i][j] = 0;
					}
					f(i, 0, e){
						int f, s, w;
						cin>>f>>s>>w;
						edges[f][s] = w;
						edges[s][f] = w;
					}
					dijkstra(edges, n);
					f(i, 0, n)
						delete [] edges[i];
					delete [] edges; 
				}