// LEETCODE 73

/*
                                    //Brute Force
                                    TC - (N*M) * (N+M)
                                    SC - (N*M)
class Solution {
public:

    void markZero(int i, int j,vector<vector<int>>& t){
        int n = t.size();
        int m = t[0].size();

        for(int k = 0; k<n ;k++){
            t[k][j] = 0;
        }
        for(int k=0; k<m; k++){
            t[i][k] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> t(n , vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                t[i][j] = matrix[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    markZero(i,j,t);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j] = t[i][j];
            }
        }
    }
};

*/

/*
                                                        //BETTER APPROACH
                                                        TC - (N*M) for traversing
                                                        SC - (N) + (M) for making two arrays
class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> rows(n,-1);
        vector<int> cols(m,-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rows[i] == 0 || cols[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

*/



/*

                                            //Optimal Approach
                                            TC - (N*M)
                                            SC- (1)

class Solution {
public:


    //optimizing better approach to optimal approach by appending the two extra rows in to the given matrix
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int row = 1;
        int col = 1;

        //checking first row has any value equals to zero
        for(int j=0 ; j<m;j++){
            if(matrix[0][j] == 0)row = 0;
        }

        //checking first col has any value equals to zero
        for(int i=0 ; i<n;i++){
            if(matrix[i][0] == 0)col = 0;
        }

        //checking left rows and cols value and if any elements is zero set corresponding row and col 0 index value to zero
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //checking first row and if any element is 0 make corresponding col of every row to zero
        for(int j = 1;j<m;j++){
            if(matrix[0][j] == 0){
                for(int i = 1;i<n;i++){
                    matrix[i][j] = 0;
                }
            }
        }

        //checking first col and if any element is 0 make corresponding row of every col to zero
        for(int i =1 ;i<n;i++){
            if(matrix[i][0] == 0){
                for(int j=1;j<m;j++){
                    matrix[i][j] = 0;
                }
            }
        }

        //if initially given matrix's first row has any zero then set whole row to zero
        if(row == 0){
           for(int j=0 ; j<m;j++){
                matrix[0][j] = 0;
            }
        }

        //if initially given matrix's first col has any zero then set whole column to zero
        if(col == 0){
            for(int i=0;i<n ;i++){
                matrix[i][0] = 0;
            }
        }
    }
};

*/