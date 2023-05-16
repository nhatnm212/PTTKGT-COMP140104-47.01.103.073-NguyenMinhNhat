#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Kh?i t?o b?ng luu tr? c�c gi� tr? t?i uu
    vector<vector<int>> K(n+1, vector<int>(W+1, 0));

    // X�y d?ng b?ng luu tr? c�c gi� tr? t?i uu
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w) {
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            } else {
                K[i][w] = K[i-1][w];
            }
        }
    }

    // Tr? v? gi� tr? t?i uu
    return K[n][W];
}

int main() {
    // S? lu?ng v?t ph?m
    int n = 5;
    
    // Tr?ng lu?ng c?a t?ng v?t ph?m
    vector<int> wt = {2, 3, 4, 5, 9};
    
    // Gi� tr? c?a t?ng v?t ph?m
    vector<int> val = {3, 4, 5, 6, 10};
    
    // Tr?ng lu?ng t?i da m� balo c� th? ch?a
    int W = 12;
    
    // T�m gi� tr? t?i uu
    int max_val = knapsack(W, wt, val, n);
    
    // In k?t qu?
    cout << "Gia tri toi uu la: " << max_val << endl;
    
    return 0;
}

