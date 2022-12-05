/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/

/*

            //Brute Force
            TC - N^2
            SC - 1

start from first element of array and traverse over the array to count its frequency, do the same
for all elements

Code:

vector < int > majorityElement(int arr[], int n) {
  vector < int > ans;
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] == arr[i])
        cnt++;
    }

    if (cnt > (n / 3))
      ans.push_back(arr[i]);
  }

  return ans;
}

*/

//---------------------------------------------------------------------------------------------------

/*

                //Better Approach
                TC - N
                SC - N

use a frequency hashmap

Code :

vector < int > majorityElement(int arr[], int n) {
  unordered_map < int, int > mp;
  vector < int > ans;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  for (auto x: mp) {
    if (x.second > (n / 3))
      ans.push_back(x.first);
  }

  return ans;
}

*/

//--------------------------------------------------------------------------------------------------

/*

                //Optimal Approach
                TC - N
                SC - 1

        //Extended Boyer Moore’s Voting Algorithm

Code :

vector < int > majorityElement(int nums[], int n) {
  int sz = n;
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = nums[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = nums[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
  vector < int > ans;
  count1 = count2 = 0;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }
  if (count1 > sz / 3)
    ans.push_back(num1);
  if (count2 > sz / 3)
    ans.push_back(num2);
  return ans;
}


*/