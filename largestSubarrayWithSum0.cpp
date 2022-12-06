/*

            //Brute Force Approach
            TC - N^2
            SC - 1

find all the subarrays and check their sum

static int solve(int[] a){
	int  max = 0;
	for(int i = 0; i < a.length; ++i){
		int sum = 0;
		for(int j = i; j < a.length; ++j){
			sum += a[j];
			if(sum == 0){
				max = Math.max(max, j-i+1);
			}
		}
	}
	return max;
}

*/

/*

            //Optimal Approach
            TC - N
            SC - N

Use a hashmap to store prefix sum

int maxLen(vector<int>&nums, int n)
    {   
        // Your code here
        unordered_map<int,int> map;
        int currSum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            if(currSum == 0){
                ans = i+1;
            }
            if(map.find(currSum)!=map.end()){
                ans = max(ans , i-map[currSum]);
            }
            else{
                map[currSum] = i;
            }
        }
        return ans;
    }

*/