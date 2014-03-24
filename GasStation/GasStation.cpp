// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
// You begin the journey with an empty tank at one of the gas stations.
// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
// Note:
// The solution is guaranteed to be unique. 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

            // tank = running sum of the gas left in the tank from the previous start
            // Claim: if i is the first position when tank < 0, can not start the trip from start to i
            // Proof: tank(start->i) = tank(start->j) + tank(j->i) < 0 and tank(start->j) > 0
            //        so tank(j->i) < 0, therefore the car will fail to complete the trip if it starts at j

            int total = 0;
            int tank = 0;
            int n = gas.size();
            int start = 0;
            for (int i = 0; i < n; i++)
            {
                total += (gas[i]-cost[i]);
                tank += (gas[i]-cost[i]);
                if (tank < 0)
                {
                    start = i+1;
                    tank = 0;
                }
            }
            return (total < 0 ? -1 : start);
        }
};

int main()
{
    vector<int> gas(4);
    vector<int> cost(4);
    gas[0] = 0;
    cost[0] = 1;
    gas[1] = 1;
    cost[1] = 3;
    gas[2] = 10;
    cost[2] = 6;
    gas[3] = 1;
    cost[3] = 2;

    Solution solu;
    cout << solu.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
