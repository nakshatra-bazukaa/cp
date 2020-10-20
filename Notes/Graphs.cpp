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
	                    2.) Union by rank and path compression ((BEST)) { To be studied }----------------------------------------------------------

	        -Complexity is decided by step 3.)
	        -So optimising step 3.) will do the job

			CODE:
				class Edge{
				public:
					int source;
					int dest;
					int weight;
				};
				bool compare(Edge e1, Edge e2){
					return (e1.weight < e2.weight);
				}
				int findParent(int v, int *parent){
					if(parent[v] == v)
						return v;
					return findParent(parent[v], parent);
				}
				void kruskals(Edge *input, int n, int e){
					sort(input, input + e, compare);
					Edge *output = new Edge[n-1];
					int *parent = new int[n];
					f(i, 0, n) parent[i] = i;
					int count = 0;
					int i = 0;
					while(count != n-1){
						Edge currentEdge = input[i++];
						int sourceParent = findParent(currentEdge.source, parent);
						int destParent = findParent(currentEdge.dest, parent);
						if(sourceParent != destParent){
							output[count++] = currentEdge;
							parent[sourceParent] = destParent;
						}
					}
					f(i, 0, n-1)
						if(output[i].source < output[i].dest)
							cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
						else
							cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
					delete [] output;
					delete [] parent;
				}
				int main(){
					int n, e;
					cin>>n>>e;
					Edge *input = new Edge[e];
					f(i, 0, e){
						int s, d, w;
						cin>>s>>d>>w;
						input[i].source = s;
						input[i].dest = d;
						input[i].weight = w; 
					}
					kruskals(input, n, e);
					delete [] input;
				}

		3.) Prims Algorithm: ( To calculate MST of a given graph )
			- Greegy Algorithm

			CODE:
				int findMinVertex(int *weights, bool *visited, int n){
					int minVertex = -1;
					f(i, 0, n)
						if(!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
							minVertex = i;
					return minVertex;						
				}
				void prims(int **edges, int n){
					int *parent = new int[n];
					int *weights = new int[n];
					bool *visited = new bool[n];
					f(i, 0, n){
						visited[i] = false;
						weights[i] = INT_MAX;
					}
					parent[0] = -1;
					weights[0] = 0;
					f(i, 0, n-1){
						int minVertex = findMinVertex(weights, visited, n);
						visited[minVertex] = true;
						f(j, 0, n)
							if(edges[minVertex][j] != 0 && !visited[j] && (edges[minVertex][j] < weights[j])){
								weights[j] = edges[minVertex][j];
								parent[j] = minVertex;			
							}
					}
					f(i, 1, n)
						if(parent[i] < i)
							cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
						else
							cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
					delete [] parent;
					delete [] weights;
					delete [] visited;
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
					prims(edges, n);
					f(i, 0, n)
						delete [] edges[i];
					delete [] edges; 
				}

		4.) Dijkstra
		
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