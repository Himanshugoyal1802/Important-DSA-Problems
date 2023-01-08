/*

        TC - exponential

Approach - At every recursive call, we try to fit one of the current array element and see whether it 
is valid to add that current element to attain the given sum. Whenever we attain the given target, 
we return the current list of elements that gave the target sum and recurse for other choices.

Note: Since here each integer can be used once, we will sort the given array and while selecting an 
array element for the recursive call we will make sure that it is not equal to the previous element 
in the array.


Code:

void findAllCombinations(vector<int> &A, int val, int start, int sum, vector<int> &currentCombination, vector<vector<int>> &allCombinations) {
	if(sum == val) {
		allCombinations.push_back(currentCombination);
		return;
	}
	for (int i = start; i < A.size(); i++) {
		if(A[i] + sum > val) {
			continue;
		}
		if(i > start && A[i] == A[i - 1]) {
			continue;
		}
		currentCombination.push_back(A[i]);
		findAllCombinations(A, val, i + 1, sum + A[i], currentCombination, allCombinations);
		currentCombination.pop_back();
	}
}
vector<vector<int> >combinationSum(vector<int> &A, int val) {
	vector<vector<int>> allCombinations;
    vector<int> currentCombination;
	sort(A.begin(), A.end());
	findAllCombinations(A, val, 0, 0, currentCombination, allCombinations);
	return allCombinations;
}
*/