/*

        //Brute force
        TC- N! * N(exponential)
        SC - N^2

Code:

bool isSafe(vector< string>chess,int col,int row){
    for(int i=0;i<row;i++){
        if(chess[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(chess[i][j]=='Q'){
            return false;
        }
    }
     for(int i=row-1,j=col+1;i>=0&&j<chess[0].size();i--,j++){
        if(chess[i][j]=='Q'){
            return false;
        }
    }
    return true;
}
    
void printNQueens(vector<string>chess,vector<vector<string>>&s , int row) {
    if(chess.size()==0)return;
  if(row==chess.size()){
    s.push_back(chess);
      return;
  }
    
  for(int i=0;i<chess[0].size();i++){
      if(isSafe(chess,i,row)){
          chess[row][i]='Q';
          printNQueens(chess,s ,row+1);
          chess[row][i]='.';
      }
  }
}

vector<vector<string>> solveNQueens(int n) {
        string st="";
        vector<vector<string>>v;
        for(int i=0;i<n;i++){
            st+='.';
        }
        vector<string>s(n,st);
    
        printNQueens(s,v ,0);
        return v;
    }


*/

//---------------------------------------------------------------------------------------------------//

/*

        //Optimal Approach
        TC - N! * N (exponential)
        SC - N

appraoch: This is the optimization of the issafe function. In the previous issafe function, 
we need o(N) for a row, o(N) for the column, and o(N) for diagonal. Here, we will use hashing 
to maintain a list to check whether that position can be the right one or not.


Code:

void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }

*/