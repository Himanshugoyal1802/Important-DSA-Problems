/*

            //Brute force 
            TC - N
            SC - N

Make a frequency array and traverse over it to find the answer

*/

//----------------------------------------------------------------------------------------------//

/*
    //If change in array is allowed
            Better Approach
            TC - N;
            SC - 1
    
traverse over the array and go to index to mark it visit. 
put a if condition to check whether we visited the number already or not

Now run a separate loop to check the missing value index

Code:
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int a,b;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i]) - 1]  < 0){
            a = abs(arr[i]);
        }
        else{
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            b = i+1;
            break;
        }
    }
    pair<int,int> p;
    p.first = b;
    p.second = a;
    return p;
}


*/

//----------------------------------------------------------------------------------------------//

/*

            Better Approach
            TC - N;
            SC - 1

without changing the array(USING MATHS)

sum of the first n natural numbers - sum of array
sum of square of first n natural numbers - sum of square of array

Now, if we subtract the sum of all elements of array from sum of all elements from 1 to N, 
that should give us the value for (X – Y). 
X - Missing number
Y - repeating number

X-Y = s
similarly, subtracting the squares give
X^2 - Y^2 = p

solve the two equations

Code : 
vector<int>missing_repeated_number(const vector<int> &A) {
    long long int len = A.size();

    long long int S = (len * (len+1) ) /2;
    long long int P = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<A.size(); i++){
       S -= (long long int)A[i];
       P -= (long long int)A[i]*(long long int)A[i];
    }
     
    missingNumber = (S + P/S)/2;

    repeating = missingNumber - S;

    vector <int> ans;

    ans.push_back(repeating);
    ans.push_back(missingNumber);

    return ans;
}

*/