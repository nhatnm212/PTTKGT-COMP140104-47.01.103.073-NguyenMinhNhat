#include <iostream>
using namespace std;

// Hàm tính giá tr? da th?c b?ng phuong pháp Horner
double horner(double poly[], int n, double x)
{
    double result = poly[0];
    for (int i=1; i<n; i++)
        result = result*x + poly[i];
    return result;
}

int main()
{
    int n;
    cout << "Nhap bac cua da thuc: ";
    cin >> n;

    double poly[n];
    cout << "Nhap cac he so cua da thuc: ";
    for (int i=0; i<n; i++)
        cin >> poly[i];

    double x;
    cout << "Nhap x: ";
    cin >> x;

    cout << "Gia tri cua da thuc tai x la: " << horner(poly, n, x) << endl;

    return 0;
}

