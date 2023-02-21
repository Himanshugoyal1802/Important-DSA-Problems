/*

        //Brute Force
        TC - n^2
        SC - 1

Take the first string and check its charachters with all other strings. 

Code:

string longestCommonPrefix(vector<string> &strs) {
    // add your logic here
	string ans="";
	int n = strs.size();

    for(int i=0;i<strs[0].size();i++){
        char s = strs[0][i];
        bool check = true;
        
        for(int j=1;j<n;j++){
            if(strs[j][i] != s){
                check = false;
                break;
            }
        }

        if(check == false){
            break;
        }
        else{
            ans.push_back(s);
        }
    }
    return ans;
}

*/

//--------------------------------------------------------------------------------------------------

/*

        //Optimal appraoch
        TC - nlogn 
        SC - 1

approach:
we will sort the string array and compare first and last strings only bcz all the strings in btw these
two must have the same prefix as they are sorted lexicographically

Code:
string longestCommonPrefix(vector<string> str) {
   sort (str.begin(), str.end());
   int n = str.size() - 1;
   string lcp;
   for (int i = 0; i < min (str[0].size(), str[n].size()); i++) {
       if (str[0][i] == str[n][i]) {
           lcp += str[0][i];
       } else {
           break;
       }
   }
   return lcp;
}

*/