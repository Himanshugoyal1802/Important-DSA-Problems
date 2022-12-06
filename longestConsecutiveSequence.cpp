/*

                //Brute force approach
                TC - NlogN
                SC - 1

sort the array and run a for loop to find the longest consecutive sequence.

Code :

int longestConsecutive(vector<int> nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }

*/


/*

                //Optimal Approach
                TC - N
                SC - N

We will first push all are elements in the HashSet. Then we will run a for loop and check for any 
number(x) if it is the starting number of the consecutive sequence by checking if the HashSet 
contains (x-1) or not. If ‘x’ is the starting number of the consecutive sequence we will keep 
searching for the numbers y = x+1, x+2, x+3, ….. And stop at the first ‘y’ which is not present 
in the HashSet. Using this we can calculate the length of the longest consecutive subsequence. 


Code :

int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i: nums){
            set.insert(i);
        }
        int maxLength = 0;
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i]-1) != set.end()){
                continue;
            }
            else{
                int currNum = nums[i];
                int currStreak = 1;
                while(set.find(currNum+1) != set.end()){
                    currNum++;
                    currStreak++;
                }
                maxLength = max(maxLength , currStreak);
            }
        }
        return maxLength;
    }

*/