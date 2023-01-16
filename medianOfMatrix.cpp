/*

        //Brute force 
        TC - n*m log(n*m)
        SC - n*m

approach:
Store the elements in an array and then sort the array, then find the median of the array

Code:
int calculateMedianOfMatrix(vector<vector<int>> &matrix) {
   vector<int> arr;
   int rowSize = matrix.size(), columnSize = matrix[0].size();
   for(int i = 0; i < rowSize; i++) {
       for(int j = 0; j < columnSize; j++) {
           arr.push_back(matrix[i][j]);
       }
   }
   sort(arr.begin(), arr.end());
   int medianIndx =(arr.size() / 2);
   return arr[medianIndx];

*/


//-----------------------------------------------------------------------------------------------------


/*

        //Optimal approach
        TC - log(max-min) * r * log(c)
        The binary search from min to max will be performed in log(max - min) time 
        and the upper_bound() function will take log(c) time which will be performed for each row.

        SC - 1

By the use of the binary search algorithm, this problem can be solved much efficiently. 
Since there will be exactly (r * c)/2 numbers less than the median so we will find the [(r * c)/2 +1]th 
number.

-> First, find the minimum and maximum element in the matrix to get the lower bound and upper bound of the binary search.
The minimum element can be found by comparing the first element of each row and the maximum element can 
be found by comparing the last element of each row.

->Then we apply binary search on this range.
Take mid = (maximum + minimum)/2 and get the count of numbers less than mid in each row by using the 
upper_bound() function and change the value of minimum or maximum accordingly.
If the count of numbers less than the mid is less(r * c) / 2 then the median must be in the 
second half otherwise the median must be in the first half.


Code:

int binarySearch(vector<vector<int>> &matrix, int r, int low,  int high, int requiredIndx) {
   if(high > low) {
       int mid =(high + low) / 2, currentIndx = 0;
       for(int i = 0; i < r; i++) {
           currentIndx += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
       }
       if(currentIndx < requiredIndx) {
           return binarySearch(matrix, r, mid+1, high, requiredIndx);
       } else {
           return binarySearch(matrix, r, low, mid, requiredIndx);
       }
   }
   return low;
}
int calculateMedianOfMatrix(vector<vector<int>> &matrix) {
   int rowSize = matrix.size(), columnSize = matrix[0].size();
   int low = INT_MAX, high = INT_MIN;
   for(int i = 0; i < rowSize; i++) {
       low = min(matrix[i][0], low);
       high = max(matrix[i][columnSize-1], high);
   }
   int requiredIndx =(rowSize * columnSize + 1) / 2;
   return binarySearch(matrix, rowSize, low, high,  requiredIndx);
}

*/