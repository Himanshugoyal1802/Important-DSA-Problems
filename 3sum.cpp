/*

            //Brute Force
            TC - n^3 * logn
            SC - n^2

we can iterate over all possible triplets of the given array and check if each triplet is valid, 
push them into an appropriate data structure such as a set of tuples, to remove duplicates.

Code:

vector<vector<int>> threeSum(vector<int> &A) {
   int n = (int)A.size();
   set<vector<int>> solutionSet;
   for (int i = 0; i < n; i++) {
       for (int j = i + 1; j < n; j++) {
           for (int k = j + 1; k < n; k++) {
               if(A[i] + A[j] + A[k] == 0) {
                   vector<int> triples = {A[i], A[j], A[k]};
                   sort(triples.begin(), triples.end());
                   solutionSet.insert(triples);
               }
           }
       }
   }
   vector<vector<int>> answer;
   for (auto x: solutionSet) {
       answer.push_back(x);
   }
   return answer;
}

*/

/*

        //Optimal Approach
        TC - n^2
        SC - 1

fixing the one point and finding the other two elements using two pointer approach

Code :

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
     for(int i=0;i<n;i++){
         int target = K-arr[i];
         int front =i+1;
         int back=n-1;
         while(front<back){
             int sum=arr[front]+arr[back];
             if(sum<target){
                 front++;}
             else if(sum>target){back--; }
             else{
                 int x=arr[front];
                 int y=arr[back];
                 ans.push_back({arr[i],arr[front],arr[back]});
              while(front <back && arr[front]==x){
                  front++;
              }   
                  while(front <back && arr[back]==y){
                  back--;
              }  
             }
         }
         while(i<n && arr[i]==arr[i+1]){
             i++;
         }
     }
    return ans;
}
*/