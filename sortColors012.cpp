/*

        //Brute Force Approach
        TC - nlogn
        SC - 1

sort the given array

*/

/*

        //Better Approach
        TC - 2N(N+N)
        SC - 1

linearly traverse the array and count the no of zeroes, ones and twos(N)
and then run a loop over the array and set these values accordingly(N)

void sort012(vector<int> &arr, int n){
    int zero = 0;
    int one = 0;
    int two = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            zero++;
        }
        else if(arr[i] == 1){
            one++;
        }
        else{
            two++;
        }
    }
    int i=0;
    for(;i<zero;i++){
        arr[i] = 0;
    }
    int j=0;
    for(;j<one;j++){
        arr[j+i] = 1;
    }
    int k=0;
    for(;k<two;k++){
        arr[i+j+k] = 2;
    }

}

*/

/*

            DUTCH NATIONAL FLAG ALGORITHM
            //Optimal Approach
            TC - (N)
            SC - 1

take three pointers low,mid,high
place low and mid at 0 index and high at last index initially
now run a while loop upto mid<=high and check conditions

 void sortColors(vector<int>& nums) {
        int low=0;
        int mid =0;
        int high = nums.size()-1;

        while(mid<=high){
            switch (nums[mid]){
                case 0:
                    swap(nums[low++] , nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[high--]);
                    break;
            }
        }
}


*/