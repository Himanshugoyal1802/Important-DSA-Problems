/*

        //Brute force
        TC - n*k log(n*k)
        SC - 1

merge all arrays in a single array and sort that array
Code:

vector<int> mergeKArrays(vector<vector<int>> &arr) {
   vector<int> sortedArray;
   for (int i = 0; i < arr.size(); i++) {
       for (int j = 0; j < arr[0].size(); j++) {
           sortedArray.push_back(arr[i][j]);
       }
   }
   sort (sortedArray.begin(), sortedArray.end());
   return sortedArray;
}

*/


/*

            //Optimal approach
            TC - n*k* log(k)
            SC - k

use minheap to merge all arrays

Code:

vector<int> mergeKArrays(vector<vector<int>> &arr) {
    // add your logic here
	int n = arr.size() * arr[0].size();
   priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
   for (int i = 0; i < arr.size(); i++) {
       minHeap.push( {arr[i][0], {i, 0} } );
   }
   vector<int> sortedArray;
   while(!minHeap.empty()) {
       sortedArray.push_back(minHeap.top().first);
       pair<int, int> index = {minHeap.top().second.first, minHeap.top().second.second + 1};
       minHeap.pop();
       if (index.second != arr[0].size()) {
           minHeap.push({arr[index.first][index.second], {index.first, index.second}});
       }
   }
   return sortedArray;
}

*/