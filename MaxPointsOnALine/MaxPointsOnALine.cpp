// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
    public:
        static double slope(const Point &p1, const Point &p2)
        {
            if (p1.x == p2.x && p1.y == p2.y)
            {
                return -numeric_limits<double>::infinity();
            }
            if (p1.x == p2.x)
            {
                return numeric_limits<double>::infinity();
            }
            return (double)(p1.y - p2.y)/(double)(p1.x - p2.x);
        }

        // use hash table to record the slopes and counts
        int maxPoints1(vector<Point> &points) {
            int n = points.size();
            int maxP = 0;
            unordered_map<double,int> sets;
            for (int i = 0; i < n; i++)
            {
                int thisP = 1;
                int sameP = 0;
                sets.clear();
                for (int j = i+1; j < n; j++)
                {
                    double s = Solution::slope(points[i], points[j]);
                    if (s == -numeric_limits<double>::infinity())
                    {
                        sameP++;
                        continue;
                    }

                    auto it = sets.find(s);
                    if (it != sets.end())
                    {
                        it->second++;
                        thisP = max(thisP, it->second);
                    }
                    else
                    {
                        sets.insert(pair<double,int>(s,2));
                        thisP = max(thisP, 2);
                    }
                }
                thisP += sameP;
                maxP = max(maxP, thisP);
            }
            return maxP;
        }

        class MyComparator
        {
            public:
                MyComparator(const Point &p) : pivot(Point(p.x, p.y)) {}

                bool operator() (const Point &p1, const Point &p2)
                {
                    double s1 = Solution::slope(pivot, p1);
                    double s2 = Solution::slope(pivot, p2);
                    return (s1 < s2);
                }

            private:
                Point pivot;
        };

        class MyEquator
        {
            public:
                MyEquator(const Point &p) : pivot(Point(p.x, p.y)) {}

                bool operator() (const Point &p1, const Point &p2)
                {
                    double s1 = Solution::slope(pivot, p1);
                    double s2 = Solution::slope(pivot, p2);
                    return (s1 == s2);
                }

            private:
                Point pivot;
        };

        int maxPoints2(vector<Point> &points) {
            int n = points.size();
            int maxP = 0;
            for (int i = 0; i < n; i++)
            {
                int thisP = 1;
                int sameP = 0;

                MyComparator comp(points[i]);
                sort(points.begin()+i+1, points.end(), comp);

                int j = i+1;
                while (j < n && Solution::slope(points[j], points[i]) == -numeric_limits<double>::infinity())
                {
                    j++;
                    sameP++;
                }
                if (j < n)
                {
                    MyEquator equal(points[i]);
                    j++;
                    int prevP = 2;
                    while (j < n)
                    {
                        if (equal(points[j-1], points[j]))
                        {
                            prevP++;
                        }
                        else
                        {
                            thisP = max(thisP, prevP);
                            prevP = 2;
                        }
                        j++;
                    }
                    thisP = max(thisP, prevP);
                }
                thisP += sameP;
                maxP = max(maxP, thisP);
            }
            return maxP;
        }
};

int main()
{
    vector<Point> points(7);
    points[0].x = -4;
    points[0].y = -4;
    points[1].x = -9;
    points[1].y = -651;
    points[2].x = -4;
    points[2].y = 4;
    points[3].x = -8;
    points[3].y = -582;
    points[4].x = -3;
    points[4].y = 3;
    points[5].x = -9;
    points[5].y = -651;
    points[6].x = 9;
    points[6].y = 651;

    Solution solu;
    cout << solu.maxPoints1(points) << endl;

    return 0;
}
