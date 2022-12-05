/*

        //Brute Force Approach
        TC - N
        SC - 1

run a for loop upto n and keep on multiplying x

double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}

*/

/*

        //Optimal Approach
        TC - log(n)
        SC - 1

double myPow(double x, int n) {
  double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;
}

*/