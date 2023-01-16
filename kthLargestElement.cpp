/*

        //brute force
        TC- nlogn
        SC - 1

sort the array and then find the largest element from back.


*/

/*

    TC - k
    SC - k

using priority queue maxheap minheap
Code:

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i=0;i<nums.size();i++){
            minheap.push(nums[i]);
            if(minheap.size()>k)
                minheap.pop();
        }
        return minheap.top();
    }

*/