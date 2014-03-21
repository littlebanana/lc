// Given a collection of intervals, merge all overlapping intervals.
// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18]. 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        class MyComparator
        {
            public:
                bool operator() (const Interval &lhs, const Interval &rhs)
                {
                    return lhs.start < rhs.start;
                };
        };

        // TODO: why static?
        static bool compare(const Interval &lhs, const Interval &rhs)
        {
            return (lhs.start < rhs.start);
        }

        vector<Interval> merge(vector<Interval> &intervals) {
            int n = intervals.size();

            MyComparator comp;
            vector<Interval> sorted = intervals;
            //sort(sorted.begin(), sorted.end(), Solution::compare);
            sort(sorted.begin(), sorted.end(), comp);

            vector<Interval> merged;
            for (int i = 0; i < n; i++)
            {
                if (i == 0 || sorted[i].start > merged.back().end)
                {
                    merged.push_back(sorted[i]);
                }
                else
                {
                    merged.back().end = max(merged.back().end, sorted[i].end);
                }
            }
            return merged;
        }
};

void printIntervals(const vector<Interval> &intervals)
{
    int n = intervals.size();
    for (int i = 0; i < n; i++)
    {
        cout << "[" << intervals[i].start << ", " << intervals[i].end << "]";
        if (i < n-1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    vector<Interval> intervals(4);
    intervals[0].start = 1;
    intervals[0].end = 3;
    intervals[1].start = 2;
    intervals[1].end = 6;
    intervals[2].start = 8;
    intervals[2].end = 10;
    intervals[3].start = 15;
    intervals[3].end = 18;

    printIntervals(intervals);

    Solution solu;
    vector<Interval> merged = solu.merge(intervals);

    printIntervals(merged);

    return 0;
}
