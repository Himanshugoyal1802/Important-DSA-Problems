/*

        //Brute Force
        TC - addNum() -> O(1), getMedian() -> O(n * logn).
        SC - addNum() ->O(n), getMedian() -> O(n).

In the naive approach, we can naively keep storing the elements in a dynamic array, 
and keep sorting the array and calculating the median naively according to the given formula, 
each time the getMedian() function is called.

Code:
class MedianCalculator {
public:

	vector<int> elements;
    MedianCalculator() {
		elements.clear();
    }
    
    void addNum(int num) {
		elements.push_back(num);
    }
    
    float getMedian() {
		vector<int> aux = elements;
		sort(aux.begin(), aux.end());
		if(aux.size() % 2 == 0) {
			return (aux[aux.size() / 2] + aux[aux.size() / 2 - 1]) / 2.0;
		}
		else {
			return (float)aux[aux.size() / 2];
		}
    }
};
*/

//-------------------------------------------------------------------------------------------------

/*

            //Optimal approach
            TC  - addNum() -> O(logn), getMedian() -> O(logn).
            SC - addNum() -> O(n), getMedian() -> O(n).


approach:

we will use two heaps (minheap,maxheap)
One heap will store the larger half of the array, and the other heap will store the smaller half of the 
array in descending order. When the current length is even, we take the top elements of both the heaps 
and take their average. Else, we return the top of the appropriate heap as the median.

Code:

class MedianCalculator {
public:

	priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianCalculator() {
    }
    
    void addNum(int num) {
		if(maxheap.empty() && minheap.empty()){
            maxheap.push(num);
        }
        else{
            if(maxheap.top() < num){
                minheap.push(num);
            }
            else{
                maxheap.push(num);
            }
        }
        
        int n = maxheap.size();
        int m = minheap.size();
        
        if(n-m == 2 || n-m == -2){
            if(n>m){
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);
            }
            else{
                int element = minheap.top();
                minheap.pop();
                maxheap.push(element);
            }
        }
    }
    
    float getMedian() {
		int n = maxheap.size();
        int m = minheap.size();
        
        if((n+m)%2==0){
            return ((double)(maxheap.top()) + (double)minheap.top()) / 2.0;
        }
        else{
            if(n>m){
                return (double)maxheap.top();
            }
            return (double)minheap.top();
        }
    }
};
*/