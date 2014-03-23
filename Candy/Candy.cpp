// There are N children standing in a line. Each child is assigned a rating value.
// You are giving candies to these children subjected to the following requirements:
//    Each child must have at least one candy.
//    Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give? 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int sum = 0;
        int prev = 0;  // # of candy assign to previous child with the highest rate
        int n = ratings.size();
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || ratings[i] == ratings[i-1])
            {
                sum += 1;
                prev = 1;
            }
            else if (ratings[i] > ratings[i-1])
            {
                prev++;
                sum += prev;
            }
            else    // ratings[i] < ratings[i-1]
            {
                // scan the consecutive decresing sequence from i-1, i, ..., j-1
                int j = i;
                for (; j < n && ratings[j] < ratings[j-1]; j++);
                
                int l = j-i;
                sum += (l+1)*l/2;       // # for i to j-1
                if (prev < l+1)         // extra for i-1
                {
                    sum += (l+1-prev);
                }
                
                prev = 1;
                i = j-1;    // attention: for loop will automatically increment i, need decrement it
            }
        }
        return sum;
    }
};

int main()
{
    vector<int> ratings(6);
    ratings[0] = 3;
    ratings[1] = 1;
    ratings[2] = 1;
    ratings[3] = 2;
    ratings[4] = 1;
    ratings[5] = 0;

    Solution solu;
    cout << solu.candy(ratings) << endl;

    return 0;
}
