#include <bits/stdc++.h>

using namespace std;

const int N=1000, M=1000; //Is N big enough?
int r[N][N]; // adjacency matrix
int order[N], v[N], top_place;
int comp[N]; // component id
int curr_comp;

void dfs(int a) {
	if (v[a]) return;
	v[a] = 1;
	for (int i = 0; i < N; i++)
		if(r[a][i]) dfs(i);
	top_place--;
	order[top_place] = a;
}

// dfs on the reversed graph
void dfs_rev(int a) {
	if(v[a]) return;
	v[a] = 1;
	comp[a] = curr_comp;
	for(int i=0; i<N; i++) 
		if(r[i][a]) dfs_rev(i); 
}

void top() {
	int i;
	top_place = N;
	for(i=0; i<N; i++) v[i]=0;
	for(i=0; i<N; i++) if(!v[i]) dfs(i);
}

void scc() {
	int i;
	top();
	for(i=0; i<N; i++) v[i]=0;
	for(i=0; i<N; i++)
	{
		int j = order[i];
		if (!v[j]) {
			curr_comp = j;
			dfs_rev(j);
		}
	}
}