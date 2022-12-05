/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.
*/

/*

        //Brute Force
        TC - N^2
        SC - 1

 Start from the first element of the array and count the number of times it occurs in the array.
 If the count is greater than the floor of N/2 then return that element as the answer.
 If not, proceed with the next element in the array and repeat the process.



*/

//-------------------------------------------------------------------------------------------------

/*

        //Better Approach
        TC - N
        SC - N

make a frequency hashmap to stores frequency

Code :
int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>(n/2)){
                return nums[i];
            }
        }
        return -1;
    }

*/

//---------------------------------------------------------------------------------------------

/*

        //Optimal Approach
        TC - N
        SC - 1

                            // Moore's Voting Algorithm

Code :
 int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if(num==candidate) count += 1;
            else count -= 1;
        }

        return candidate;
    }

*/