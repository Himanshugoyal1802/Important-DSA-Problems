/*
            //Recursive Approach
            TC - 2^(m*n)
            SC - m+n(path recursive calls stack)
#include <bits/stdc++.h>
int f(int i,  int j){
    if(i == 0 && j == 0)return 1;
    if(i<0 || j<0)return 0;
    int up = f(i-1,j,dp);
    int left = f(i,j-1,dp);
    return up+left;
}
int uniquePaths(int m, int n) {
    // Write your code here.
    return f(m-1,n-1);
}
*/

/*
        //Memoization
        TC - (m*n)
        SC - (m+n) + (m*n)
#include <bits/stdc++.h>
int f(int i,  int j, vector<vector<int>> &dp){
    if(i == 0 && j == 0)return 1;
    if(i<0 || j<0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    int up = f(i-1,j,dp);
    int left = f(i,j-1,dp);
    return dp[i][j] = up+left;
}
int uniquePaths(int m, int n) {
    // Write your code here.
    vector<vector<int>> dp(m , vector<int> (n,-1));


    return f(m-1,n-1 , dp);
}
*/

/*
            //Optimal Approach DP Tabulation
            TC - (m*n)
            SC - (m*n)
    int uniquePaths(int m, int n) {
    // Write your code here.
    vector<vector<int>> dp(m , vector<int> (n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0)dp[i][j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i>0){
                   up = dp[i-1][j];
                }
                if(j>0) left = dp[i][j-1];

                dp[i][j] = up+left;
            }
        }
    }

    return dp[m-1][n-1];
}
*/

/*

                //Most Optimal Approach
                TC - O(n-1) or O(m-1)
                SC - 1

From start to reach the end we need a certain number of rightward directions and a certain number of
downward directions. So we can figure out we need n-1 no. of rightward direction and m-1 no. of
downward direction to reach the endpoint.

Since we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward
direction or m-1 downward direction and calculate the combinations ( ie: m+n-2 C n-1 or m+n-2 C m-1)
we’ll get the total number of paths.

Approach: The approach of this solution is very simple just use a for loop to calculate
the m+n-2 C n-1  or m+n-2 C m-1

Code :
int uniquePaths(int m, int n) {
    int N = n + m - 2;  
    int r = m - 1;
    double res = 1;

    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}
*/