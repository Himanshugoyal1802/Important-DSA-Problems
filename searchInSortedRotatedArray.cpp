
/*

        //Brute Force
        TC - n
        SC - 1

by doing simple linear search we can find the index of key.
Code:

int getElementIndex(vector<int> array, int target) {
   int indx = -1;
   for (int i = 0; i < array.size(); i++) {
       if (array[i] == target) {
           indx = i;
       }
   }
   return indx;
}

*/


/*

        //Optimal approach
        TC - logn
        SC - 1

using binary search we can find the index
Code:

int search(int* arr, int n, int target) {

    int low = 0, high = n-1;

    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target)return mid;
        
        //left half sorted
        if(arr[low]<= arr[mid]){
            
            if(target>=arr[low] && target<=arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        //right half sorted
        else{
            if(target>=arr[mid] && target<=arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}

*/