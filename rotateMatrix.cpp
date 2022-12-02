/*

                                            //Brute force approach
                                            TC - (M*N)
                                            SC - (M*N)

Make a copy of matrix and copy elements in such a way like last row elements become first column
elements and so on

        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
                vector<vector<int>> temp(n,vector<int>(n));

                for(int i = 0; i<n ;i++){
                    for(int j = 0; j<n; j++){
                        temp[j][n-i-1] = matrix[i][j];
                    }
                }

                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        matrix[i][j] = temp[i][j];
                    }
                }

        }

*/


/*

                                        Optimal Approach
                                        TC - (N*M)
                                        SC - (1)

    first take the transpose of given matrix then reverse each row

    void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            for(int i=0;i<n;i++){
                for(int j = 0; j<i; j++){
                    swap(matrix[i][j] , matrix[j][i]);
                }
            }
            
            for(int i = 0; i<n;i++){
                reverse(matrix[i].begin(),matrix[i].end());
            }
        
    }


*/