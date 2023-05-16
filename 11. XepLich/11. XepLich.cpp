#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 20;

int n, k;
vector<int> t[MAXN]; // M?ng vector ch?a các bu?i h?c c?a t?ng ngày

// Ki?m tra xem th?i gian t? start d?n end có trùng v?i th?i gian c?a các bu?i h?c dã du?c s?p x?p tru?c dó hay không
bool isAvailable(int day, int start, int end) {
    for (int i = 0; i < t[day].size(); i += 2) {
        if (start >= t[day][i+1] || end <= t[day][i]) {
            continue;
        }
        return false;
    }
    return true;
}

// Ð? quy d? s?p x?p các bu?i h?c vào t?ng ngày
bool schedule(int day, int start, int end, int count) {
    if (count == k) {
        return true;
    }
    if (end > 21) {
        return false;
    }
    if (start >= 21) {
        return schedule(day+1, 9, 10, count);
    }
    if (day > n) {
        return false;
    }
    if (isAvailable(day, start, end)) {
        t[day].push_back(start);
        t[day].push_back(end);
        if (schedule(day, start+1, end+1, count+1)) {
            return true;
        }
        t[day].pop_back();
        t[day].pop_back();
    }
    return schedule(day, start+1, end+1, count);
}

int main() {
    cin >> n >> k;
    if (n*2 < k) {
        cout << "NO\n";
        return 0;
    }
    if (!schedule(1, 9, 10, 0)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < t[i].size(); j += 2) {
            cout << i << " " << t[i][j] << " " << t[i][j+1] << "\n";
        }
    }
    return 0;
}

