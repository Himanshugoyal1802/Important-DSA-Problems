/*

        //Brute Force Approach
        TC - N^3

Run three loops, get all possible subarrays in two loops and their sum in another loop, 
then return the maximum of them.
}

*/

/*

        //Better Approach
        TC- N^2

If we optimise the above approach, we can get sum of all possible subarrays in two loops only,
then return the maximum so far.


int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            int curr_sum = 0;
            for(int j=i; j<nums.size(); j++){
                curr_sum += nums[j];
                //cout<<curr_sum<<endl;
                max_sum = max(max_sum, curr_sum);
            }
        }
    return max_sum;
    }
*/



/*

            Optimal Approach
            TC - N
            SC - 1

int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum > maxSum){
                maxSum = sum;
            }
            if(sum<0)sum = 0;
        }
    return maxSum;
}

*/