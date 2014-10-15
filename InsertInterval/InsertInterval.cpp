// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        int findInsertion(const vector<Interval> &intervals, int pt) {
            int n = intervals.size();
            if (pt < intervals[0].start) {
                return 0;
            }
            if (pt > intervals[n-1].end) {
                return 2 * n;
            }
            int l = 0;
            int r = n - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (pt >= intervals[m].start && pt <= intervals[m].end) {
                    return 2 * m + 1;
                } else if (pt < intervals[m].start) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            return 2 * l;
        }

        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            if (intervals.empty()) {
                return vector<Interval>(1, newInterval);
            }

            int n = intervals.size();
            int lind = findInsertion(intervals, newInterval.start);
            int rind = findInsertion(intervals, newInterval.end);

            vector<Interval> merged;
            if (lind == rind) {
                merged.assign(intervals.begin(), intervals.end());
                if (lind % 2 == 0) {
                    merged.insert(merged.begin() + lind / 2, newInterval);
                }
                return merged;
            }

            int i = 0;
            for (; i < lind / 2; i++) {
                merged.push_back(intervals[i]);
            }

            Interval insert;
            insert.start = min(newInterval.start, intervals[i].start);
            for (; i < (rind - 1) / 2; i++);
            insert.end = max(newInterval.end, intervals[i].end);
            merged.push_back(insert);

            i++;
            for (; i < n; i++) {
                merged.push_back(intervals[i]);
            }
            return merged;
        }
};

int main() {
    vector<Interval> in;
    in.push_back(Interval(0, 5));
    in.push_back(Interval(9, 12));

    for (int i = 0; i < in.size(); i++) {
        cout << "[" << in[i].start << ", " << in[i].end << "] ";
    }
    cout << endl;

    Interval insert(7, 16);
    cout << "[" << insert.start << ", " << insert.end << "]" << endl;

    Solution solu;
    vector<Interval> merged = solu.insert(in, insert);

    for (int i = 0; i < merged.size(); i++) {
        cout << "[" << merged[i].start << ", " << merged[i].end << "] ";
    }
    cout << endl;

    return 0;
}
