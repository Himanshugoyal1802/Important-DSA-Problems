/*
        //Brute force
        TC - n*m
        SC - 1

approach:
first we will find first index of pattrn in string str and whenever they matched then we will match the
rest part of pattern

Code:
vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    vector<int>ans;
    for(int i=0;i<str.size();i++){
        if(str[i] == pat[0]){
            int k=i,j=0;
            for(; k<str.size() && j<pat.size(); k++,j++){
                if(str[k] != pat[j]){
                    break;
                }
            }

            if(j == pat.size()){
                ans.push_back(i);
            }
        }
    }
    return ans;
}


*/

//------------------------------------------------------------------------------------------------------

/*
        //Rabin Carp Algorithm
        TC - Average time(n-m+1) , worst case(n*m)
        SC - 1

Code:

vector<int>res;
int d = 256;
    
void solve (string pat,string txt,int q){
    int m = pat.length(),n=txt.length(),p=0,t=0,h=1,j=0;
    for(int i =0; i<m-1;i++){
        h = (h*d)%q;
    }
    for(int i=0; i<m;i++){
        p = (d*p+pat[i])%q;
        t = (d*t+txt[i])&q;
    }
    
    for(int i=0; i<=n-m;i++){
        if(p==t){
            for(j =0; j<m;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==m)
            res.push_back(i+1);
        }
        if(i<n-m){
            t = (d*(t-txt[i]*h)+txt[i+m])%q;
            if(t<0)
                t = t+q;
        }
    }
}
vector <int> search(string pat, string txt)
{
    //code here.
    int q = INT_MAX;
    solve(pat,txt,q);
    if(res.size()==0)
    res.push_back(-1);
    return res;
}

*/