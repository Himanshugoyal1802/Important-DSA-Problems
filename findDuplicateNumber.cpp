/*

            //Brute force approach
            TC - nlogn
            SC - 1

sort the given array and then return the duplicate number

*/

/*

                Better Approach
                TC - n
                SC - n

use a hashmap to store the frequency and then return the element whose frequency is 2

*/

/*

                Optimal Approach
                TC - n
                SC -1

Use slow and fast pointer appraoch

int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;      
    }

*/

