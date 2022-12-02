/*

        //Brute force Approach 
            -find all the permutations first and sort them , then find the position of given
            given permutation in all the permutations and return the next permutation from that position
            AND if the given permuation is the last permutation then return the very first permutation from
            our sorted permuations

            TC - (N! * N) bcz there are N! orders and N is the length of every array

*/



/*
        //Optimal approach
        //TC - (N)
        // SC - (1)

vector<int> nextPermutation(int n, vector<int> nums){
        // code here
        int k,l;
        for(k = n-2 ; k>=0; k--){
            if(nums[k] < nums[k+1]){
                break;
            }
        }
        
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(l = n-1; l>k; l--){
                if(nums[l] > nums[k]){
                    break;
                }
            }
            swap(nums[l] , nums[k]);
            reverse(nums.begin()+ k+1, nums.end());
        }
        
        return nums;
}


*/