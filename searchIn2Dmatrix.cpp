/*

        //Brute Force Approach
        TC - N*M
        SC - 1

Traverse over the matrix to find the target value

*/

//------------------------------------------------------------------------------------------------

/*

                        //Better Appraoch
                            TC- log(m*n)
                            SC - 1


//If complete matrix is in increasing order : 

    => Integers in each row are sorted from left to right.
    => The first integer of each row is greater than the last integer of the previous row

example : 
1  3  5  7
10 11 16 20
23 30 34 60
target = 3

Using binary search approach, treat the matrix as a singular array and apply binary search

Code : 

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)return false;
        int n = matrix.size();      //row size
        int m = matrix[0].size();   //col size
        
        int low = 0;
        int high = (n*m)-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid/m][mid%m] == target){
                return true;
            }
            else if(matrix[mid/m][mid%m] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
}

*/

/*

                    Better Approach
                    TC - n+m
                    SC - 1

Given a matrix mat[][] of size N x M, 
where every row and column is sorted in increasing order, and a number X is given.

example:
10 20 30 40 
11 21 36 43
25 29 39 50
50 60 70 80

target value = 25

Code :

int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int row = 0, col = M-1;
	    while(row<N && col>=0){
	        if(mat[row][col] == X)return 1;
	        else if(mat[row][col] < X){
	            row++;
	        }
	        else{
	            col--;
	        }
	    }
	    return 0;
	}

*/