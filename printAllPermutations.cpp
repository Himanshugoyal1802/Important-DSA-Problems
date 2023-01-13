/*

        //Brute force
        TC - N! * N
        SC - N

Recursive approach:

generate all permutations using recursion and also maintain a hashmap or visited array to store the
visited elements.

Code:

void helper(vector<int>&nums, int freq[], vector<int>&sub, vector<vector<int>> &rslt){
    if(sub.size() == nums.size()){
        rslt.push_back(sub);
        return;
    }
    
    for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            freq[i] = 1;
            sub.push_back(nums[i]);
            helper(nums,freq,sub,rslt);
            sub.pop_back();
            freq[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> rslt;
    vector<int> sub;
    int freq[nums.size()];
    for(int i=0;i<nums.size();i++)freq[i] = 0;
    helper(nums,freq,sub,rslt);
    return rslt;
    
}


*/

//----------------------------------------------------------------------------------------------------//

/*

            //Optimal Approach
            TC - N! * N
            SC - 1

using backtracking approach : 

Go from index to n – 1 and swap. Once the swap has been done call recursion for the next state.
After coming back from the recursion make sure you re-swap it because for the next element the swap 
will not take place.

Code:

void helper(int ind, vector<int>&nums,vector<vector<int>>&rslt ){
    if(ind == nums.size()){
        rslt.push_back(nums);
        return;
    }
    
    for(int i=ind; i<nums.size();i++){
        swap(nums[ind], nums[i]);
        helper(ind+1,nums,rslt);
        swap(nums[ind], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> rslt;
    helper(0,nums,rslt);
    return rslt;
}

*/

