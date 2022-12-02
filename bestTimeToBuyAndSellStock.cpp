/*

                //Brute Force Approach
                TC - N^2
                SC - 1

The simple solution is to check every possible pair and find the pair which gives maximum profit.

int maxProfit(vector<int> &prices) {
    int profit = 0;
	for(int i = 0; i < prices.size(); i++) {
		for(int j = i + 1; j < prices.size(); j++) {
			profit = max(profit, prices[j] - prices[i]);
		}
	}
	return profit;
}

*/

/*

            //Optimal Approch
            TC - N
            SC - 1

Traverse the given array and while traversing keep updating the minimum price. 
Also, keep updating the maximum difference between the current selling price and minimum price 
during the traversal to get the maximum profit.

int maxProfit(vector<int> &prices) {
    int profit = 0, minPrice = INT_MAX;
	for(int i = 0; i < prices.size(); i++) {
		minPrice = min(minPrice, prices[i]);
		profit = max(profit, prices[i] - minPrice);
	}
	return profit;
}

*/