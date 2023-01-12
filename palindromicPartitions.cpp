/*

                TC - exponential
                
approach : 

we try to make partition at every index but before that we check the partitioned substring is 
palindrome or not.
if it is palindrome then we make a partition at that index otherwise we move to next index

Code:

 bool isPalindrome(string s, int i, int j){
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++,j--;
    }
    return true;
}

void helper(string s, int ind, vector<string>&sub, vector<vector<string>> &res){
    if(ind == s.size()){
        res.push_back(sub);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(isPalindrome(s,ind,i)){
            sub.push_back(s.substr(ind,i-ind+1));
            helper(s,i+1,sub,res);
            sub.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string>sub;
    helper(s,0,sub,res);
    return res;
}

*/