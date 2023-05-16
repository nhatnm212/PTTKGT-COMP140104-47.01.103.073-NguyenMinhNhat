#include <iostream>
#include <cstring>

using namespace std;

// H�m d? quy d? t�m chu?i chung d�i nh?t
int lcs(string X, string Y, int m, int n) {
    // N?u c� m?t trong hai chu?i l� r?ng, tr? v? 0
    if (m == 0 || n == 0) {
        return 0;
    }
    
    // N?u k� t? cu?i c?a hai chu?i gi?ng nhau, t�nh d? d�i chu?i chung d�i nh?t kh�ng t�nh k� t? cu?i d�
    if (X[m - 1] == Y[n - 1]) {
        return lcs(X, Y, m - 1, n - 1) + 1;
    }
    
    // N?u k� t? cu?i c?a hai chu?i kh�c nhau, t�m chu?i chung d�i nh?t c?a X kh�ng t�nh k� t? cu?i v� Y, ho?c c?a Y kh�ng t�nh k� t? cu?i v� X, v� ch?n chu?i c� d? d�i l?n nh?t
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

