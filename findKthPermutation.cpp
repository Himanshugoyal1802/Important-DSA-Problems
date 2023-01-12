/*

            //Brute force
            Tc - N!*N + N! logN
            SC - N

Approach:

The extreme naive solution is to generate all the possible permutations of the given sequence.  
This is achieved using recursion and every permutation generated is stored in some other data 
structure (here we have used a vector). Finally, we sort the data structure in which we have stored 
all the sequences and return the Kth sequence from it.

Code:

vector<string> result;
void permute(string s, string possible) {
	if(s.size() == 0) {
		result.push_back(possible);
		return;
	}
	for(int i = 0; i < s.size(); i++) {
		string left = s.substr(0, i);
		string right = s.substr(i + 1, s.size() - i - 1);
		string total = left + right;
		permute(total, possible + s[i]);
	}
}
string getKthPermutation(int n, int k) {
    string permutation = "";
	result.clear();
	for(int i = 1; i <= n; i++) {
		permutation += to_string(i);
	}
	permute(permutation, "");
	return result[k - 1];
}
*/


//--------------------------------------------------------------------------------------//

/*

        //Optimal approach
        TC - n^2
        SC - n

Code:

string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1;
    string ans="";
    vector<int>num;
    for(int i=1;i<n;i++){
        fact = fact*i;
        num.push_back(i);
    }
    num.push_back(n);
    k= k-1;
    while(true){
        ans = ans + to_string(num[k/fact]);
        num.erase(num.begin()+k/fact);
        if(num.size() == 0)break;
        
        k = k%fact;
        fact = fact / num.size();
    }
    return ans;
}
*/