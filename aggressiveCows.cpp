/*

        //Brute Force
        TC - N*M
        SC - 1

Approach:
first sort the array and then we start placing cows with a minimal distance of 1 and upto to df btw largest
element of array to smallest element of array. Evert time we try to place cows with every possible distance

Code:

#include <bits/stdc++.h>

using namespace std;
bool isCompatible(vector < int > inp, int dist, int cows) {
  int n = inp.size();
  int k = inp[0];
  cows--;
  for (int i = 1; i < n; i++) {
    if (inp[i] - k >= dist) {
      cows--;
      if (!cows) {
        return true;
      }
      k = inp[i];
    }
  }
  return false;
}
int main() {
  int n = 5, m = 3;
  vector<int> inp {1,2,8,4,9};
  //---------------------------------------------------------------------------------//
                //IMPORTANT CODE
  sort(inp.begin(), inp.end());
  int maxD = inp[n - 1] - inp[0];
  int ans = INT_MIN;
  for (int d = 1; d <= maxD; d++) {
    bool possible = isCompatible(inp, d, m);
    if (possible) {
      ans = max(ans, d);
    }
  }
  //-------------------------------------------------------------------------------//
  cout << "The largest minimum distance is " << ans << '\n';
}

*/

/*

        //Optimal approach
        TC - n*log(m)
        SC - 1

approach:
instead of trying every possible distance in the naive approach, here we will apply binary search

Code:
 bool isPossibleToPlace(int n, int k, vector<int> &stalls, int dist){
        int cnt = 1 , lastCowPos = stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i] - lastCowPos >= dist){
                cnt++;
                lastCowPos = stalls[i];
            }
            if(cnt == k)return true;
        }
        return false;
 }

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int ans=0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossibleToPlace(n,k,stalls,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
}


*/