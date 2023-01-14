/*

        //Brute Force
        TC - N
        SC - N

we can use hashmap to store the frequencies.

*/

/*

        //Better Approach
        TC - N
        SC - 1

by taking XOR of all elements bcz XOR of two same numbers is 0. and by doing this we can get the single
element

*/

/*

    //Optimal Approach
    TC - logn
    SC - 1

by using binary search and breaking out it as a left half and right half

Code:

int findSingleElement(vector < int > & nums) 
{
    int low = 0;
    int high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (mid % 2 == 0) {
            if (nums[mid] != nums[mid + 1]) 
            //Checking whether we are in right half

                high = mid - 1; //Shrinking the right half
            else
                low = mid + 1; //Shrinking the left half
        } else {

            //Checking whether we are in right half
            if (nums[mid] == nums[mid + 1]) 
                high = mid - 1; //Shrinking the right half
            else
                low = mid + 1; //Shrinking the left half
        }
    }

    return nums[low];
}
*/