/*

        //Brute force
        TC - n^2
        SC - 1

approach: 

The simple solution is to find the maximum area among all the possible subarrays.

Code:

int getLargestArea(vector<int> &heights) {
    int n = heights.size();
	int largestArea = 0;
	for (int i = 0; i < n; i++) {
		int currentArea, height = heights[i];
		for (int j = i; j < n; j++) {
			height = min(height, heights[j]);
			currentArea = (j - i + 1) * height;
			largestArea = max(largestArea, currentArea);
		}
	}
	return largestArea;
}

*/

//---------------------------------------------------------------------------------------------------


/*

            //Optimal approach
            TC - N
            SC - N

approach:

we will store previous smaller element's index and next smaller element's index of each index of heights
array by making two arrays.

Code:
int getLargestArea(vector < int > & heights) {

     int n = heights.size();
     vector<int> left(n,0);
     vector<int> right(n,n-1);
     stack<int> st;
     
     for(int i=0;i<n;i++){
          while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
            {
                left[i]=0;
            }
            else
            {
                left[i]=st.top()+1;
               
            }
             st.push(i);
     }
     
     while(!st.empty()) st.pop();
     
     for(int i=n-1; i>=0; i--){
        while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
            {
                right[i]=n-1;
            }
            else
            {
                right[i]=st.top()-1;
               
            }
             st.push(i);
     }
     
     int maxarea = INT_MIN;
     for(int i=0;i<n;i++){
         maxarea = max(maxarea , (right[i] - left[i] + 1) * heights[i]);
     }
     return maxarea;
 }

*/