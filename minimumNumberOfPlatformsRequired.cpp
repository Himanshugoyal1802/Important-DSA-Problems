/*

        //Brute force 
        TC - n^2
        SC - 1

Take each interval of arrival and departure one by one and count the number of overlapping time 
intervals. This can easily be done using nested for-loops. Maintain the maximum value of the count 
during the process and return the maximum value at the end.

Code:

 int countPlatforms(int n,int arr[],int dep[])
 {
    int ans=1; //final value
    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
           {
               count++;
           }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;
 }
*/



/*

            //Optimal Approach
            TC - nlogn
            SC - 1

At first we need to sort both the arrays. When the events will be sorted, it will be easy to track the 
count of trains that have arrived but not departed yet. Total platforms needed at one time can be found 
by taking the difference of arrivals and departures at that time and the maximum value of all times 
will be the final answer.

Code:

int countPlatforms(int n,int arr[],int dep[])
 {
    sort(arr,arr+n);
    sort(dep,dep+n);
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
 }
*/