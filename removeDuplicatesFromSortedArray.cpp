/*

            //Brute Force 
            TC - Nlogn
            SC - N

use hashset to store elements

Code:
int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

*/

/*

        //Optimal approach
        TC - N
        SC - 1

Code :
int removeDuplicates(vector<int>& nums) {
    int k=0, last=INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i] != last){
            nums[k++] = nums[i];
            last = nums[i];
        }
    }
    return k;
}

*/