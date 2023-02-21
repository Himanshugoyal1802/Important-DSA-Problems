/*
        //Brute force
        TC - n^3
        SC - 1

approach:
first find all the substrings and check each string whether it is palindrome or not and if it is then
check its length.
generating all substrings take n^2 time complexity and checking each substring palindrome take n complexity.

*/

//--------------------------------------------------------------------------------------------------

/*

        //Optimal approach
        TC - n^2
        SC - 1

Approach : 
at each index we will treat it as a center and expand till it generates a palindrome substring and compare length

Code:

class Solution {
public:
    
    int expandFromCenter(string s, int i,int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--,j++;
        }
        return j-i-1;
    }
    
    string longestPalindrome(string s) {
     int start=0,end=0;
        for(int i=0;i<s.size();i++){
            int len1 = expandFromCenter(s,i,i+1);
            int len2 = expandFromCenter(s,i,i);
            
            int len = max(len1,len2);
            if(end-start < len){
                start = i - ((len-1)/2);
                end = i + (len/2);
            }
        }
        return s.substr(start , end - start+1);
    }
    
    
};



*/


//----------------------------------------------------------------------------------------------------

/*

        Using DP
        TC - n^2
        SC - n^2

Code:

string longestPalin (string s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        string ans;
        int maxlen = 0;
        
        for(int diff = 0; diff<n; diff++){
            for(int i=0,j = i+diff; j<n ; i++,j++){
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(diff==1){
                    dp[i][j] = (s[i] == s[j] ? 2:0);
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]>0){
                        dp[i][j] = 2+dp[i+1][j-1];
                    }
                }
                
                if(dp[i][j]){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        ans = s.substr(i,maxlen);
                    }
                }
            }
        }
        return ans;
    }

*/