/*

            TC - V
            SC - 1

int findMinimumCoins(int V) 
{
    // Write your code here
    int coins[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9;
    
    int cnt =0;
    for(int i=n-1;i>=0;i--){
        while(V>=coins[i]){
            cnt++;
            V -= coins[i];
        }
    }
    return cnt;
}


*/

/*

There is one more same question with a few changes, 
and the solution of that problem is using DP (leetcode 322 : coin changes)
must do that problem

*/