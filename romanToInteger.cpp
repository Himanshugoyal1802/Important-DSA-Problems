/*

        TC - N
        SC - N

we can solve this without using extra space by making a function which takes charachter and returns its
respective value

Code:

class Solution {
public:
    int helper(string s, map<char,int> m ,int i){
        if(i == s.size()){
            return 0;
        }
        
        int val = m[s[i]];
        if(val<m[s[i+1]]){
            val = -val;
        }
        return helper(s,m,i+1) + val;
    }
    
    int romanToInt(string s) {
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        return helper(s,m,0);
    }
};


*/