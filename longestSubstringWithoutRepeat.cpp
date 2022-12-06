/*

            //Brute Force 
            TC - N^3 || N^2(for generating substring)
            SC - N(to store them in a set)

generate all the substrings and check the non repeating substring

Code :

int longestSubstringWithoutRepeat(string s) {
    int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int flag = 1;
			map<int, int> uniqueCharacterCount;
			for (int index = i; index <= j; index++) {
				if (uniqueCharacterCount[s[index] - 'a'] == 1) {
					flag = 0;
					break;
				}
				uniqueCharacterCount[s[index] - 'a'] = 1;
			}
			if (flag == 1) {
				ans = max (ans, j - i + 1);
			}
		}
	}
	return ans;
}
*/

//---------------------------------------------------------------------------------------------------

/*

            //Better Approach
            TC - N + N
            SC - N

use sliding window approach and maintain a set to store occurred charachters

We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point 
of substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move 
forward and check for the duplicate occurrence of the current element if found then ‘left’ pointer 
will be shifted ahead so as to delete the duplicate elements.

Code :

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}

*/

/*

            //Optimal Approach
            TC - N 
            SC - N

In this approach, we will make a map that will take care of counting the elements and maintaining 
the frequency of each and every element as a unity by taking the latest index of every element.


Code:

int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
*/

/*

        //Most Optimal Approach
        TC - N
        SC - 1

The problem can be solved efficiently by storing the last index of every character found while 
traversing the array. The idea is if we encounter an element that has occurrence before, then the 
current unique substring must have starting point after the previous occurrence of the current 
character.

Code:

int longestSubstringWithoutRepeat(string s) {
    int n = s.size();
	int longestSubstring = 0;
	vector<int> previousIndex (26, - 1);
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (previousIndex[s[i] - 'a'] >= start) {
			start = previousIndex[s[i] - 'a'] + 1;
		}
		previousIndex[s[i] - 'a'] = i;
		longestSubstring = max(longestSubstring, i - start + 1);
	}
	return longestSubstring;
}
*/