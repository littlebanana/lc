#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        // Approach 1: Use Hash table
        // O(N) space and complexity
        vector<int> twoSum(vector<int> &numbers, int target) {
            int L = numbers.size();
            unordered_map<int,int> tab;
            for (int i = 0; i < L; i++)
            {
                unordered_map<int,int>::iterator it = tab.find(numbers[i]);
                if (it != tab.end())
                {
                    vector<int> result;
                    int i1 = (it->second > i ? i : it->second);
                    int i2 = (it->second > i ? it->second : i);
                    result.push_back(i1+1);
                    result.push_back(i2+1);
                    return result;
                }
                else
                {
                    tab.insert(pair<int,int>(target-numbers[i],i));
                }
            }
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
