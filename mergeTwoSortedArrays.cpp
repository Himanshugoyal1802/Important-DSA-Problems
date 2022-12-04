/*

            //Brute Force Approach(N = n+m)
            TC - NlogN + N + N;
            SC - N

take a new array of size equals to sum of size of both arrays(n+m);
put all the elements in new array from both arrays.
sort the new array
reassign the values from sorted array to given array

*/

/*
            //Better approach
            TC - n*m
            Sc - 1

take two pointers i=0 and j=0 on the both arrays
check if num1[i] < num2[j] then i++
else swap them and now put the element num2[j] to its correct position in num2 array

int i=0,j=0;
while(i<n){

}
*/

/*

            //Optimal Appraoch
            TC - ((n+m) log(n+m))
            SC - 1

put all small elements in first array and large elements in second array
and then sort both the arrays separately

void merge(long long arr1[], long long arr2[], int n, int m)
        {
            int i=n-1;
            int j= 0;
            while(i>=0 && j<m){
                if(arr1[i]>arr2[j]){
                long t = arr1[i];
                arr1[i]=arr2[j];
                arr2[j]=t;
                }
                i--;
                j++;
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        }


*/

/* 
ONE MORE OPTIMAL APPROACH IS USING GAP 
read this on gfg or see strivers video
*/