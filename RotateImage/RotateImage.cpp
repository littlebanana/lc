// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
// Follow up:
// Could you do this in-place?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            int n = matrix.size();
            for (int l = 0; l < n/2; l++) {
                // layer
                for (int i = 0; i < n-2*l-1; i++) { 
                    // offset
                    int tmp = matrix[l][l+i];
                    matrix[l][l+i] = matrix[n-1-l-i][l];
                    matrix[n-1-l-i][l] = matrix[n-1-l][n-1-l-i];
                    matrix[n-1-l][n-1-l-i] = matrix[l+i][n-1-l];
                    matrix[l+i][n-1-l] = tmp;
                }
            }
        }

        void rotate2(vector<vector<int> > &matrix) {
            // flip along diagonal and flip along central vertical
            int n = matrix.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            for (int i = 0; i < n; i++) {
                int l = 0;
                int r = n - 1;
                while (l < r) {
                    swap(matrix[i][l++], matrix[i][r--]);
                }
            }
        }
};

void printImage(const vector<vector<int> > &image) {
    int m = image.size();
    int n = image[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > img(4,vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            img[i][j] = i+j+1;
        }
    }

    printImage(img);

    Solution solu;
    solu.rotate(img);

    printImage(img);

    return 0;
}
