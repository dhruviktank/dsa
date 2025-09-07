#include <iostream>
#include <vector>
using namespace std;

void rotateImage(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int i = 0;
    while (i <= n/2) {
        for (int j = i; j < n-i-1; j++) {
            swap(matrix[i][j], matrix[j][n - i - 1]);
            swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
            swap(matrix[i][j], matrix[n - j - 1][i]);
        }
        i++;
    }
}

void print1Dmatrix(vector<int> matrix) {
    for (int i = 0 ; i < matrix.size(); i++) {
        cout << matrix[i] << " ";
    }
}

void print2Dmatrix(vector<vector<int>> matrix) {
    for (auto row : matrix) {
        print1Dmatrix(row);
        cout << endl;
    }
}

int main() { 
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16}};
    print2Dmatrix(matrix);
    rotateImage(matrix);
    print2Dmatrix(matrix);
    return 0;
}