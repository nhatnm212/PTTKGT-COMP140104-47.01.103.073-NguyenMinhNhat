#include <iostream>
#include <cstring>

using namespace std;

// Hàm d? quy d? tìm chu?i chung dài nh?t
int lcs(string X, string Y, int m, int n) {
    // N?u có m?t trong hai chu?i là r?ng, tr? v? 0
    if (m == 0 || n == 0) {
        return 0;
    }
    
    // N?u kí t? cu?i c?a hai chu?i gi?ng nhau, tính d? dài chu?i chung dài nh?t không tính kí t? cu?i dó
    if (X[m - 1] == Y[n - 1]) {
        return lcs(X, Y, m - 1, n - 1) + 1;
    }
    
    // N?u kí t? cu?i c?a hai chu?i khác nhau, tìm chu?i chung dài nh?t c?a X không tính kí t? cu?i và Y, ho?c c?a Y không tính kí t? cu?i và X, và ch?n chu?i có d? dài l?n nh?t
    return max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
}

int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    int m = X.length();
    int n = Y.length();
    
    cout << "Do dai chuoi chung dai nhat la: " << lcs(X, Y, m, n);
    
    return 0;
}

