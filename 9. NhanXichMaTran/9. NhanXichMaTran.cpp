#include <iostream>
#include <vector>

using namespace std;

// Hàm nhân hai ma tr?n
vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int m = A.size(); // s? hàng c?a ma tr?n A
    int n = A[0].size(); // s? c?t c?a ma tr?n A (s? hàng c?a ma tr?n B)
    int p = B[0].size(); // s? c?t c?a ma tr?n B
    
    // Kh?i t?o ma tr?n k?t qu? C
    vector<vector<int>> C(m, vector<int>(p, 0));
    
    // Tính giá tr? các ph?n t? trong ma tr?n k?t qu?
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    // Tr? v? ma tr?n k?t qu?
    return C;
}

int main() {
    // Kh?i t?o hai ma tr?n
    vector<vector<int>> A = {{1, 2, 3},
                             {4, 5, 6}};
                             
    vector<vector<int>> B = {{7, 8},
                             {9, 10},
                             {11, 12}};
    
    // Nhân hai ma tr?n
    vector<vector<int>> C = multiply(A, B);
    
    // In ma tr?n k?t qu?
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[0].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

