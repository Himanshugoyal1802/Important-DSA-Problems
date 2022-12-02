/*

            Brute force
            TC - (N^2)
            SC - (1)


A simple approach is to start from the first interval and check it with the rest of the intervals. 
If it overlaps with any of the intervals then take the intersection of both the intervals and remove
the second interval. Repeat this process for every interval in the array.

After getting all non-overlapping intervals, arrange them in increasing order according to the start 
element by taking the minimum element one at a time.



            vector<vector<int> > mergeIntervals(vector<vector<int> > &intervals) {
            int n = intervals.size();
            for (int i = 0; i < n; i++) {
                int currentStart = intervals[i][0], currentEnd = intervals[i][1];
                for (int j = 0; j< n; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (currentStart <= intervals[j][1] && currentStart >= intervals[j][0]) {
                        currentStart = min(currentStart, intervals[j][0]);
                        currentEnd = max(currentEnd, intervals[j][1]);
                        intervals[j][0] = INT_MAX;
                        intervals[j][1] = INT_MAX;
                    } else if(currentEnd <= intervals[j][1] && currentStart >= intervals[j][0]) {
                        currentStart = min(currentStart, intervals[j][0]);
                        currentEnd = max(currentEnd, intervals[j][1]);
                        intervals[j][0] = INT_MAX;
                        intervals[j][1] = INT_MAX;
                    }
                }
                intervals[i][0] = currentStart;
                intervals[i][1] = currentEnd;
            }
            int totalIntervals = 0;
            for (int i = 0; i < n; i++) {
                if(intervals[i][0] != INT_MAX) {
                    totalIntervals++;
                }
            }
            vector<vector<int>> ans;
            for (int i = 0; i < totalIntervals; i++) {
                int currentMinStart = INT_MAX, currentMinEnd, indx = -1;
                for (int j = 0; j < n ; j++) {
                    if (intervals[j][0] < currentMinStart) {
                        currentMinStart = intervals[j][0];
                        currentMinEnd = intervals[j][1];
                        indx = j;
                    }
                }
                intervals[indx][0] = INT_MAX;
                intervals[indx][1] = INT_MAX;
                ans.push_back({currentMinStart, currentMinEnd});
            }
            return ans;
            }

*/


/*

                Optimal Approach
                TC - nlogn
                SC - 1

Sorting the array first according to the starting point will help in solving the problem linearly.

The basic idea is that if an interval is not overlapping with its next interval, then it won’t 
overlap with any of the intervals after that as the array is sorted. So merging the intervals will 
be possible while traversing the array.


vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> rslt;
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= end){
                end = max(end , intervals[i][1]);
            }
            else{
                rslt.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        rslt.push_back({start,end});
        return rslt;
    }

*/