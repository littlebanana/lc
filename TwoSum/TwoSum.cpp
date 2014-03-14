// Given an array of integers, find two numbers such that they add up to a specific target number.
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
// Please note that your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution.
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // Approach 1: Use Hash table
        // O(N) space and complexity
        vector<int> twoSum(vector<int> &numbers, int target)
        {
            vector<int> idx;
            unordered_map<int,int> tab;
            int L = numbers.size();
            for (int i = 0; i < L; i++)
            {
                unordered_map<int,int>::iterator it = tab.find(numbers[i]);
                if (it != tab.end())
                {
                    idx.push_back(it->second);
                    idx.push_back(i+1);
                    return idx;
                }
                else
                {
                    tab.insert(pair<int,int>(target-numbers[i],i+1));
                }
            }
            return idx;
        }

        // Approach 2: Sort array and use two pointers
        // will have some problems with the shuffled indicies
        // TODO
};

int main()
{
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(9);
    numbers.push_back(1);

    Solution solu;
    vector<int> result = solu.twoSum(numbers, 9);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}
