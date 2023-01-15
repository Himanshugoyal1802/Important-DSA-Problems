/*

        //Approach
        TC - nlogn 
        SC - 1

using binary search
Code:

bool isPossible(int arr[], int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;
    
    for(int i=0; i<n; i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
    int findPages(int A[], int N, int M) 
    {
        //code here
        int s=0;
        int sum = 0;
        for(int i=0; i<N; i++){
            sum += A[i];
        }
        
        int e = sum;
        int ans = -1;
        int mid = s + (e-s)/2;
        
        if(N<M)
            return ans;
        
        while(s<=e){
            if(isPossible(A,N,M,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

*/