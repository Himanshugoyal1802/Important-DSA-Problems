/*

        Brute Force
        TC - n^2
        SC - 1

run two for loop to check the target sum is present in the array or not

Code :

pair<int,int> twoSum(vector<int> &A, int target) {
   pair<int, int> indicesOfSum;
   for (int i = 0; i < A.size(); i++) {
       for (int j = i + 1; j < A.size(); j++) {
           if(A[i] + A[j] == target) {
               return {i, j};
           }
       }
   }
}

*/

/*

            //Optimal Approach
            TC - nlogn
            SC - 1


We observe that sorting the array doesn’t change the answer. (If we have two return the elements not indexes)
So, we can sort the array, and use the 2 pointers technique to find the target sum.

Code :

pair<int,int> twoSum(vector<int> &A, int target) {
   vector<pair<int, int>> sortedAux;
   for (int i = 0; i < A.size(); i++) {
       sortedAux.push_back({A[i], i});
   }
   sort(sortedAux.begin(), sortedAux.end());
   int left = 0, right = A.size() - 1;
   while (left < right) {
       if(sortedAux[left].first + sortedAux[right].first == target) {
           return {sortedAux[left].second, sortedAux[right].second};
       } else if(sortedAux[left].first + sortedAux[right].first < target) {
           left++;
       } else {
           right--;
       }
   }
}

*/


/*

            //Better Approach
            TC - n
            SC - n

To solve this problem in linear time, we can use hashing.

Code :

pair<int,int> twoSum(vector<int> &A, int target) {
    unordered_map<int, int> hashMap;
	for (int i = A.size() - 1; i >= 0; i--) {
		auto it = hashMap.find(target - A[i]);
		if (it != hashMap.end()) {
			return make_pair(it->second, i);
		}
		hashMap[A[i]] = i;
	}
}

*/