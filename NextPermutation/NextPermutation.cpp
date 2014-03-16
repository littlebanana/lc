// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.
// Here are some examples.
// Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 ¡ú 1,3,2
// 3,2,1 ¡ú 1,2,3
// 1,1,5 ¡ú 1,5,1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void reverse(vector<int> &num, int left, int right)
        {
            while (left < right)
            {
                swap(num[left++], num[right--]);
            }
        }

        // try 1, 2, 4, 3
        // idea find the first A[i] < A[j], where i < j and i start from n-2 down to 0
        // swap them and reverse i+1 up to n-1
        // Complexity: O(N^2)
        void nextPermutation(vector<int> &num) {
            int n = num.size();

            int i = n-2;
            for (; i >= 0; i--)
            {
                int j = n-1;
                for (; j > i && num[i] >= num[j]; j--);

                if (j > i)
                {
                    swap(num[i], num[j]);
                    break;
                }
            }
            reverse(num, i+1, n-1);
        }

        // Complexity: O(N)
        void nextPermutation2(vector<int> &num) {
            int n = num.size();

            int i = n-2;
            for (; i >= 0 && num[i] >= num[i+1]; i--);

            if (i < 0)
            {
                reverse(num, 0, n-1);
            }
            else
            {
                int j = n-1;
                for (; j > i && num[i] >= num[j]; j--);

                swap(num[i], num[j]);
                reverse(num, i+1, n-1);
            }
        }
};

void printVector(const vector<int> &A)
{
    cout << "[";
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if (i < n-1)
        {
            cout << " ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    int A[] = {1, 1, 5};
    vector<int> num(A, A+3);
    printVector(num);

    Solution solu;
    solu.nextPermutation(num);

    printVector(num);

    return 0;
}
