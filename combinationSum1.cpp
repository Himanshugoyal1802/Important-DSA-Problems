/*

        //Approach
        TC - exponential 2^t * k (t is target val and k is avg length of subset)
        SC - k*x (x is no of combination found)


Code:

vector<vector<int>> rslt;
    
    void helper(vector<int>& candidates, int target, int index, vector<int>combinations){
        if(target == 0){
            rslt.push_back(combinations);
            return;
        }
        if(target<0 || index>=candidates.size()){
            return;
        }
        while(index < candidates.size()-1 && candidates[index] == candidates[index+1])index++;
        helper(candidates,target,index+1,combinations);
        combinations.push_back(candidates[index]);
        
        helper(candidates,target-candidates[index],index,combinations);
        
        combinations.pop_back();

    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Your code here
        vector<int> combinations;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0,combinations);
        
        sort(rslt.begin(),rslt.end());
        return rslt;
    }
*/