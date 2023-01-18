/*

        //Brute force
        TC - n^2
        SC - 1

use two for loops to find the next greater element

Code:

vector<int> getNextGreaterElement (vector<int> &A) {
	int n = A.size();
	vector<int> nextGreater;
	for(int i = 0; i < 2*n; i++) {
		bool possible = false;
		for(int j = i + 1; j < 2*n; j++) {
			if(A[j%n] > A[i%n]) {
				nextGreater.push_back(A[j%n]);
				possible = true;
				break;
			}
		}
		if(!possible) {
			nextGreater.push_back(-1);
		}
	}
	return nextGreater;
}

*/

//--------------------------------------------------------------------------------------------------

/*

        TC - n
        SC - n

using stack

Code:

vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        stack<int>st1;
        
        vector<int>rslt(n,-1);
        for(int i=0;i<2*n;i++){
            if(st1.empty()){
                st1.push(i%n);
            }
            else{
                while(!st1.empty() && (arr[st1.top()] < arr[i%n])){
                    rslt[st1.top()] = arr[i%n];
                    st1.pop();
                }
                st1.push(i%n);
            }
        }
        return rslt;
    }
*/