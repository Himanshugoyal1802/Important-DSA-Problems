/*

        //Binary search
        TC - n*log(m*10^d)  
        SC -1

Code:

#include <bits/stdc++.h> 
double multiply(double val, int n){
    double ans = 1.0;
    for(int i=0;i<n;i++){
        ans *= val;
    }
    return ans;
}

double findNthRootOfM(int n, int m) {
	// Write your code here.
    double low = 0;
    double high = m;
    double eps = 1e-7;
    while((high-low) > eps){
        double mid = (low + high)/2.0;
        if(multiply(mid,n) < m){
            low = mid;
        }
        else{
            high = mid;
        }
    }
    return low;
}

*/