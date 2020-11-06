// Given n persons and n jobs 
// Given a n*n matrix with corrosponding costs to assign a job to a person 
// find min cost to assign n jobs to n person in min cost possible 


#include<bits/stdc++.h>
using namespace std;

int minCost(int **cost, int n, int p, int mask){
	if(p >= n)
		return 0;
	int mi = INT_MAX;
	for(int i = 0; i<n; i++){
		if(!(mask&(1<<i))){
			int ans = minCost(cost, n, p+1, mask|(1<<i)) + cost[p][i];
			mi = (ans<mi) ? ans : mi;
		}
	}
	return mi;
}
int main(){
	int n;
	cin>>n;
	int **cost = new int*[n];
	for (int i = 0; i < n; ++i)
		cost[i] = new int[n];
	
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin>>cost[i][j];
		
	cout<<minCost(cost, n, 0, 0);
}