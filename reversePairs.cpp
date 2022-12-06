/*

        //Brute force
        TC - N^2
        SC - 1
    
use to for loops to count the reverse pairs

*/

//------------------------------------------------------------------------------------------------

/*

        //optimal approach
        TC - nlogn + n + n
        SC - n

use merge sort algorithm to find reverse pairs

Code : 

int merge(vector<int> &nums, int low, int mid, int high){
        int i = low, j = mid+1;
        int count = 0;
        for(i = low; i<= mid; i++){
            while(j<=high && nums[i] > 2LL * nums[j]){
                j++;
            }
            count += (j-(mid+1));
        }
        vector<int>temp;
        int left = low, right = mid+1;
        while(left <= mid && right <= high){
            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left++]);
        }
        while(right <= high){
            temp.push_back(nums[right++]);
        }
        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low];
        }
        return count;
    }

    int mergesort(vector<int> &nums, int low, int high){
        int inv = 0;
        if(high>low){
            int mid = low + (high-low)/2;
            inv = mergesort(nums,low,mid);
            inv += mergesort(nums,mid+1,high);
            inv += merge(nums,low,mid,high);
        }
        return inv;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }

*/