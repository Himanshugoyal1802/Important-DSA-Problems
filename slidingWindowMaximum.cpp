/*

        //Brute Force
        TC - N^2
        SC - 1

approach : 
We can use two nested loops to select the current window and then iterate in the current window to 
find the minimum element in that window and push it in the vector.

Code:

vector<int> maxSlidingWindow(vector<int> &A, int k) {
    int n = A.size();
	vector<int> answer;
	for(int i = 0; i < n; i++) {
		int mx = INT_MIN;
		for(int j = i; j < i + k; j++) {
			mx = max(mx, A[j]);
		}
		answer.push_back(mx);
	}
	while(answer.size() > n - k + 1) {
		answer.pop_back();
	}
	return answer;
}
*/


//----------------------------------------------------------------------------------------------------

/*

        //Optimal approach
        TC - n
        SC - n

approach:
we will use deque

Code:

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // add your logic here
	deque<int> dq;
    vector<int> ans;
    
    for(int i=0;i<nums.size();i++){
        if(!dq.empty() && (dq.front() == i-k)) dq.pop_front();
        
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1)ans.push_back(nums[dq.front()]);
    }
    return ans;
}

*/