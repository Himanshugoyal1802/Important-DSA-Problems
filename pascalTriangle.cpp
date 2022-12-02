/*
 // To generate all rows of pascal traingle
                    //TC - N^2

vector<vector<int>> generate(int n) {
        vector<vector<int>> r(n);
        for(int i=0;i<n;i++){
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;
            for(int j = 1;j<i; j++){
                r[i][j] = r[i-1][j] + r[i-1][j-1];
            }
        }
        return r;
}

*/


/*

// To generate nth row of pascal triangle

vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll> r(n);
        
        r[0]=r[n-1]=1;

        ll res=1;

        for(int i=1,up=n-1,down=1;i<n-1;i++){

            res*=up;

            res/=down;

            up--;down++;

        }

        return r;
    }

*/