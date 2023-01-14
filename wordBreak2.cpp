/*

        //approach
        TC - exponential
        
Code:

void solve(int ind, string s, unordered_map<string,int> &m , vector<string> &sub, vector<string>&ans){
        if(ind == s.size()){
            if(sub.size()!=0){
                string temp="";
                for(int i=0;i<sub.size();i++){
                    if(i != 0)temp+=" ";
                    
                    temp+=sub[i];
                }
                ans.push_back(temp);
            }
            return;
        }
        
        for(int i=ind; i<s.size();i++){
            string temp = s.substr(ind,i-ind+1);
            if(m.find(temp) != m.end()){
                sub.push_back(temp);
                solve(i+1,s,m,sub,ans);
                sub.pop_back();
            }
        }
    }
    
    
    vector<string> wordBreak(string s, vector<string>& dict) {
        unordered_map<string,int> m;
        for(auto str : dict){
            m[str]++;
        }
        vector<string> ans;
        vector<string> sub;
        
        solve(0,s,m,sub,ans);
        return ans;
    }

*/