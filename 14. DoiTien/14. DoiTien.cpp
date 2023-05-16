#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.rbegin(), coins.rend()); // S?p x?p c�c lo?i ti?n theo gi� tr? gi?m d?n
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (m >= coins[i]) { // N?u s? ti?n c�n l?i c?n d?i l?n hon ho?c b?ng gi� tr? c?a lo?i ti?n hi?n t?i
            ans += m / coins[i]; // Th�m s? lu?ng lo?i ti?n hi?n t?i du?c d?i du?c v�o k?t qu?
            m %= coins[i]; // C?p nh?t l?i s? ti?n c�n l?i c?n d?i
        }
    }
    cout << ans << "\n";
    return 0;
}

