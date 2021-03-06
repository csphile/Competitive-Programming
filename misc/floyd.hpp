// floyd warshall algorithm
// construct r[][] to be the weighted graph
// r[i][j] = infinity if there is no i->j edge;
// r[i][i] = 0 for each i;

for(k=0; k<n; k++) 
	for(i=0; i<n; i++) 
		for(j=0; j<n; j++)
			r[i][j] <?= r[i][k]+r[k][j];

// ultimate shortest path Algorithm:
construct r[][], r[i][j] = infinity if there is no i->j edge;
r[i][i] = 0 for each i;
for(k=0; k<n; k++) 
	for(i=0; i<n; i++) 
		for(j=0; j<n; j++)
			r[i][j] <?= r[i][k]+r[k][j];

if(r[i][j] is infinity)
	return "infinity"; // no path

for(k=0; k<n; k++) 
	if(r[k][k] < 0 && r[i][k] <infinity && r[k][j]<infinity)
		return "-infinity"; // a negative cycle
return r[i][j];