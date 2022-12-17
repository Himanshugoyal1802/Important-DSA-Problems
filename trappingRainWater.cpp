/*

        //Brute Force 
        TC - N^2
        SC - 1

find leftmax and rightmax at every index of arr and then add the result:
ans += min(leftmax, rightmax) - arr[i];

Code :
 
int trap(vector < int > & arr) {
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

*/

/*

        //Optimal Approach
        TC - N
        SC - N

instead of finding leftmax and rightmax at every index, we will store them in a prefix and suffix array

Code :
int trap(vector<int>& arr) {
    int n = arr.size();
    vector<int> pre(n), suf(n);
    int maxi = arr[0];
    for(int i=0;i<n;i++){
        maxi = max(maxi,arr[i]);
        pre[i] = maxi;
    }

    maxi = arr[n-1];
    for(int i=n-1;i>=0;i--){
        maxi = max(maxi,arr[i]);
        suf[i] = maxi;
    }

    int rslt=0;
    for(int i=0;i<n;i++){
        rslt += min(pre[i],suf[i]) - arr[i];
    }
    return rslt;
}


*/

/*

            //Optimal Appraoch
            TC - N
            SC - 1

using two pointer approach and maintaining leftmax and rightmax

Code:

int trap(vector<int>& arr) {
    int n = arr.size();
    int l = 0, r = n-1;
    int leftmax = 0, rightmax = 0;
    int ans = 0;

    while(l<=r){
        if(arr[l]<=arr[r]){
            if(arr[l]>=leftmax){
                leftmax = arr[l];
            }
            else{
                ans += leftmax - arr[l];
            }
            l++;
        }

        else{
            if(arr[r]>=rightmax){
                rightmax = arr[r];
            }
            else{
                ans += rightmax - arr[r];
            }
            r--;
        }
    }
    return ans;
}


*/