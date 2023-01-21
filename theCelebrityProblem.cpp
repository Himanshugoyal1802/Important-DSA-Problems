/*

        //Brute force
        TC - n^2
        Sc - n

approach:
we will make two arrays, one of two will store how many peoples knows me and other will store how many 
of them I knows for every index i to n;

Code:

int celebrity(vector<vector<int> >& a, int n) 
{
    vector<int> in(n);
    vector<int> out(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == 1){
                in[j]++;
                out[i]++;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(in[i] == n-1 && out[i] == 0){
            return i;
        }
    }
    
    return -1;
}

*/


//----------------------------------------------------------------------------------------------

/*

        //Optimal approach
        TC - N
        SC - 1

Code:

int celebrity(vector<vector<int> >& a, int n) 
{
    int c = 0;
    for(int i=0;i<n;i++){
        if(a[c][i] == 1){
            c = i;
        }
    }
    
    for(int i=0;i<n;i++){
        if(i!=c && (a[c][i] == 1 || a[i][c] == 0)){
            return -1;
        }
    }
    return c;
}

*/