#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
    public:
        class SlopeComparator
        {
            public:
                SlopeComparator(Point p) : pivot(p) {}

                bool operator() (const Point &lhs, const Point &rhs)
                {
                    if (lhs.x == pivot.x && rhs.x == pivot.x)     // vertical
                    {
                        return false;
                    }
                    if (lhs.x == pivot.x)
                    {
                        double r_slope = (double)(rhs.y - pivot.y)/(rhs.x - pivot.x);
                        return (r_slope < 0);
                    }
                    if (rhs.x == pivot.x)
                    {
                        double l_slope = (double)(lhs.y - pivot.y)/(lhs.x - pivot.x);
                        return (l_slope >= 0);
                    }
                    double l_slope = (double)(lhs.y - pivot.y)/(lhs.x - pivot.x);
                    double r_slope = (double)(rhs.y - pivot.y)/(rhs.x - pivot.x);
                    if (l_slope >= 0 && r_slope >= 0)
                    {
                        return (l_slope < r_slope);
                    }
                    if (l_slope < 0 && r_slope < 0)
                    {
                        return (l_slope > r_slope);
                    }
                    return (l_slope > r_slope);
                }

            private:
                Point pivot;
        };

        int maxPoints(vector<Point> &points) {
            int N = points.size();
            if (N < 2)
            {
                return N;
            }
            int maxcount = 2;
            for (int i = 0; i < N-1; i++)
            {
                // the pivot in the outer loop is points[i]
                unordered_map<double,int> slopetab;
                int thiscount = 0;
                int vcount = 0;
                int same = 1;
                for (int j = i+1; j < N; j++)
                {
                    if (points[j].x == points[i].x && points[j].y == points[i].y)
                    {
                        same++;
                    }
                    else if (points[j].x == points[i].x) // vertical line
                    {
                        vcount++;
                    }
                    else
                    {
                        double slope = (double)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                        cout << slope << endl;
                        unordered_map<double,int>::iterator it = slopetab.find(slope);
                        if (it != slopetab.end())
                        {
                            it->second++;
                            thiscount = max(it->second, thiscount);
                        }
                        else
                        {
                            slopetab.insert(pair<double,int>(slope,1));
                            thiscount = max(1, thiscount);
                        }
                    }
                }
                cout << "same = " << same << endl;
                cout << "vcount = " << vcount << ", thiscount = " << thiscount << endl;
                thiscount = max(vcount, thiscount) + same;
                cout << "thiscount = " << thiscount << endl;
                maxcount = max(thiscount, maxcount);
            }
            return maxcount;
        }
};

int main()
{
    vector<Point> points;
    points.push_back(Point(84,250));
    points.push_back(Point(0,0));
    points.push_back(Point(1,0));
    points.push_back(Point(0,-70));
    points.push_back(Point(0,-70));
    points.push_back(Point(1,-1));
    points.push_back(Point(21,10));
    points.push_back(Point(42,90));
    points.push_back(Point(-42,-230));

    Solution solu;
    cout << solu.maxPoints(points) << endl;

    return 0;
}
