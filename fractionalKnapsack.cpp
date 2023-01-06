/*

        //Approach

        TC - nlogn
        SC - 1

firstly, items should be sorted in decreasing order with respect to their value /weight. 
Once the items are sorted we can iterate. Pick up items with weight lesser than or equal to 
the current capacity of the knapsack. In the end, if the weight of an item becomes more than what 
we can carry, break the item into smaller units. Calculate its value according to our current capacity 
and add this new value to our answer.


Code:

class Solution {
   public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

   }
};
*/