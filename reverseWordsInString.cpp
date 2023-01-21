/*

        //Brute Force
        TC - n
        SC - n

approach:

Push all the words in stack and then make answer string

Code:
string reverseWords(string &s) {
   stack<string> allWords;
   string currentWord = "";
   for(int i = 0; i < s.size(); i++) {
       if(s[i] == ' ') {
           allWords.push(currentWord);
           currentWord = "";
       } else {
           currentWord += s[i];
       }
   }
   allWords.push(currentWord);
   string ans;
   while(!allWords.empty()){
        if(ans.size() == 0){
           ans = allWords.top(); 
        }
        else {
            ans = ans + " " + allWords.top();
        }
        allWords.pop();
   }
   return ans;
}

*/

//---------------------------------------------------------------------------------------------------

/*

        TC - n
        SC - 1

Code:

string reverseWords(string &s){
    string result;
    int n = s.size();
    int i=0;
    while(i<n){
        while(i<n && s[i] == ' ')i++;
        if(i>=n)break;

        int j = i+1;
        while(j<n && s[j] != ' ')j++;

        string sub = s.substr(i,j-i);

        if(result.size() == 0) result = sub;
        else result = sub + " " + result;
        
        i = j+1;
    }
    return result;
}

*/