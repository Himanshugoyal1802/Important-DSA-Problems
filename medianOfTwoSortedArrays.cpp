/*

            //Brute Force
            TC - n+m
            SC - n+m

approach:
merge the two arrays in a data structure and then find the median of the array


*/

/*

        //Better approach
        TC - n+m
        SC - 1

approach:
Similar to the naive approach, instead of storing the final merged sorted array, we can keep a counter 
to keep track of the required position where the median will exist. First, using the median formula, 
get a position where the median will exist. Then, follow the above approach and instead of storing 
elements in another array, we will increase the counter value. When the counter value is equal to the 
median positions, return element.


*/

/*

        //optimal approach
        TC - log(min(m,n))
        SC - 1

using binary search,

Code:
float median(int num 1[],int num2[],int m,int n) {
    if(m>n)
        return median(nums2,nums1,n,m);//ensuring that binary search happens on minimum size array
        
    int low=0,high=m,medianPos=((m+n)+1)/2;
    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = medianPos - cut1;
        
        int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
        int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
        int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
        
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
}

*/