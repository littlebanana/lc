// Implement strStr().
// Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack. 

#include <iostream>
#include <cstring>  // strlen

using namespace std;

class Solution
{
    public:
        // next[i] = length of the longest proper prefix of P[0...(i-1)] which is also a suffix of P[0...(i-1)]
        // Notice that P[0...(i-1)] is of length i
        // another interpretation of next[i] is as follows.
        // If we have already match i characters, and (i+1)-th character does not match, i.e. P[i] != T[k+i] for some k
        // then we only need to check matches from next[i], i.e. P[next[i]] ?= P[k+i]
        // and we have already match next[i] characters implicitly

        void KMP_builder1(char *P, int next[])
        {
            int l = strlen(P);
            int k = -1;
            next[0] = k;
            for (int i = 1; i <= l; i++)
            {
                while (k >= 0 && P[k] != P[i-1])
                {
                    k = next[k];
                }
                next[i] = (++k);
            }
        }

        void KMP_builder2(char *P, int next[])
        {
            int l = strlen(P);
            next[0] = -1;
            next[1] = 0;
            for (int i = 1; i <= l; i++)
            {
                int k = next[i];  // number of previous matched characters
                for (; ; )
                {
                    if (P[k] == P[i])
                    {
                        next[i+1] = k + 1;
                        break;
                    }
                    else if (k > 0)
                    {
                        k = next[k];
                    }
                    else
                    {
                        next[i+1] = 0;
                        break;
                    }
                }
            }
        }

        char *KMP_matcher2(char *T, char *P)
        {
            int l1 = strlen(T);
            int l2 = strlen(P);

            int next[l2+1];
            KMP_builder2(P, next);

            int k = 0;  // number of current matched characters
            for (int i = 0; i < l1; i++)
            {
                if (P[k] == T[i])
                {
                    k++;
                    if (k == l2)
                    {
                        return (T+i-l2+1);
                    }
                }
                else if (k > 0)
                {
                    k = next[k];
                    i--;
                }
            }
            return NULL;
        }

        char *KMP_matcher1(char *T, char *P)
        {
            int l1 = strlen(T);
            int l2 = strlen(P);

            int next[l2+1];
            KMP_builder2(P, next);

            int k = 0;  // number of current matched characters
            for (int i = 0; i < l1; i++)
            {
                while (k >= 0 && P[k] != T[i])
                {
                    k = next[k];
                }
                k++;
                if (k == l2)
                {
                    return (T+i-l2+1);
                }
            }
            return NULL;
        }

        char *strStr(char *haystack, char *needle)
        {
            if (strlen(needle) == 0)
            {
                return haystack;
            }
            return KMP_matcher2(haystack, needle);
        }
};

int main()
{
    char haystack[] = "mississipi";
    char needle[] = "issipi";

    int l = strlen(needle);

    Solution solu;
    char *p = solu.strStr(haystack, needle);

    cout << (p == NULL ? "null" : p) << endl;

    return 0;
}
