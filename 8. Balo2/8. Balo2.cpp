#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Kh?i t?o b?ng luu tr? các giá tr? t?i uu
    vector<int> K(W+1, 0);

    // Xây d?ng b?ng luu tr? các giá tr? t?i uu
    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (wt[i] <= w) {
                K[w] = max(K[w], val[i] + K[w-wt[i]]);
            }
        }
    }

    // Tr? v? giá tr? t?i uu
    return K[W];
}

int main() {
    // S? lu?ng v?t ph?m
    int n = 5;
    
    // Tr?ng lu?ng c?a t?ng v?t ph?m
    vector<int> wt = {2, 3, 4, 5, 9};
    
    // Giá tr? c?a t?ng v?t ph?m
    vector<int> val = {3, 4, 5, 6, 10};
    
    // Tr?ng lu?ng t?i da mà balo có th? ch?a
    int W = 12;
    
    // Tìm giá tr? t?i uu
    int max_val = knapsack(W, wt, val, n);
    
    // In k?t qu?
    cout << "Gia tri toi uu la: " << max_val << endl;
    
    return 0;
}

