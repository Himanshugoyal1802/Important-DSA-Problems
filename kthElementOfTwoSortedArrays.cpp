/*

        //Brute force
        TC - (m+n)*log(m+n)
        SC - m+n

Code:
int getKthElement(vector<int> firstArr, vector<int> secondArr, int k) {
    vector<int> mergedArr;
    for(int i = 0; i < firstArr.size(); i++) {
        mergedArr.push_back(firstArr[i]);
    }
    for(int i = 0; i < secondArr.size(); i++) {
        mergedArr.push_back(secondArr[i]);
    }
    sort(mergedArr.begin(), mergedArr.end());
    return mergedArr[k - 1];
}

*/


//------------------------------------------------------------------------------------------------------

/*

        //Optimal approach
        TC - log(n*m)
        SC - 1

we will use binary search and divide them into left half and right half in the size of k

Code:

int getKthElement(vector<int> &row1, vector<int> &row2, int k) {
   // add logic here
	int m = row1.size();
	int n = row2.size();
	
	if(m > n)return getKthElement(row2,row1,k);
    int low = max(0,k-n);
    int high = min(k,m);
    
    while(low <= high){
        int cut1 = (low+high) >> 1;
        int cut2 = k-cut1;
        
        int left1 = cut1 == 0 ? INT_MIN : row1[cut1-1];
        int left2 = cut2 == 0 ? INT_MIN : row2[cut2-1];
        
        int right1 = cut1 == m ? INT_MAX : row1[cut1];
        int right2 = cut2 == n ? INT_MAX : row2[cut2];
        
        if(left1 <= right2 && left2 <= right1){
            return max(left1,left2);
        }
        else if(left1 > right2){
            high = cut1-1;
        }
        else{
            low = cut1+1;
        }
    }
    return 1;
	
}

*/