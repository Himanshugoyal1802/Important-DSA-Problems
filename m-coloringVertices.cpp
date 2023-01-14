/*

        //Naive approach
        TC - m^n
        SC - n

approach:
We try to generate all the possible configurations of colors. Then we check if any node and its 
neighbors have their colors equal. Once we find a valid configuration, we can return true. Else, 
after exhaustively searching for all the possible configurations we return false.

Code:

bool isSafe(vector<vector<int>> adjMatrix, int color[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if(adjMatrix[i][j] && color[j] == color[i]) {
				return false;
			}
		}
	}
	return true;
}
bool colorGraph(vector<vector<int>> adjMatrix, int m, int index, int color[], int n) {
	if(index == n) {
		return ((isSafe(adjMatrix, color, n));
	}
	for(int j = 1; j <= m; j++) {
		color[index] = j;
		if(colorGraph(adjMatrix, m, index + 1, color, n)) {
			return true;
		}
		color[index] = 0;
	}
	return false;
}
bool isColoringPossible(vector<vector<int>> adjMatrix, int m) {
	int n = adjMatrix.size();
    int color[n];
	memset(color, 0, sizeof(color));
	for(int i = 0; i < n; i++) {
		if(adjMatrix[i][i]) {
			return false;
		}
	}
	return colorGraph(adjMatrix, m, 0, color, n);
}

*/

///-----------------------------------------------------------------------------------------------------------


/*

        //optimal approach
        TC - m^n (average case complexity must be improved)
        SC - n

approach:
We approach the problem with a backtracking-based approach, trying to prune through many impossible 
cases. The idea is to assign colors to the vertexes one by one starting from vertex 0. Before 
assignment of the current color, we check if applying the current color is valid, else we backtrack 
through the configuration to find another valid configuration. If no valid configuration is found, we 
return false.

Code:

bool isSafe(bool graph[101][101], int color[], int n, int node, int c){
        for(int k=0;k<n;k++){
            if(k != node && graph[k][node] == 1 && color[k]== c)return false;
        }
        return true;
    }

    bool helper(int node , bool graph[101][101], int color[], int m, int n){
        if(node == n){
            return true;
        }
        
        for(int c=1;c<=m;c++){
            if(isSafe(graph,color,n,node,c)){
                color[node] = c;
                
                if(helper(node+1, graph, color, m,n) == true){
                    return true;
                }
                
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        return helper(0,graph,color,m,n);
    }
*/
