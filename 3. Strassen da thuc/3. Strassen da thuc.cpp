#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> a, vector<int> b);
vector<int> subtract(vector<int> a, vector<int> b);
vector<int> multiply(vector<int> a, vector<int> b);
vector<int> strassen(vector<int> a, vector<int> b);

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {5, 6, 7, 8};

    vector<int> c = strassen(a, b);

    cout << "Ket qua: ";
    for (int i=0; i<c.size(); i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;

    return 0;
}

vector<int> add(vector<int> a, vector<int> b)
{
    int n = a.size();
    vector<int> c(n);
    for (int i=0; i<n; i++)
    {
        c[i] = a[i] + b[i];
    }
    return c;
}

vector<int> subtract(vector<int> a, vector<int> b)
{
    int n = a.size();
    vector<int> c(n);
    for (int i=0; i<n; i++)
    {
        c[i] = a[i] - b[i];
    }
    return c;
}

vector<int> multiply(vector<int> a, vector<int> b)
{
    int n = a.size();
    vector<int> c(2*n-1);
    for (int i=0; i<2*n-1; i++)
    {
        c[i] = 0;
        for (int j=0; j<=i; j++)
        {
            if (j<n && i-j<n)
            {
                c[i] += a[j] * b[i-j];
            }
        }
    }
    return c;
}

vector<int> strassen(vector<int> a, vector<int> b)
{
    int n = a.size();
    if (n == 1)
    {
        vector<int> c(1);
        c[0] = a[0] * b[0];
        return c;
    }

    int m = n / 2;

    vector<int> a1(m), a2(m), b1(m), b2(m);
    for (int i=0; i<m; i++)
    {
        a1[i] = a[i];
        a2[i] = a[i+m];
        b1[i] = b[i];
        b2[i] = b[i+m];
    }

    vector<int> s1 = subtract(b2, b1);
    vector<int> s2 = add(a1, a2);
    vector<int> s3 = add(a1, b1);
    vector<int> s4 = subtract(a2, a1);
    vector<int> s5 = add(b1, b2);
    vector<int> s6 = subtract(b2, a2);
    vector<int> s7 = add(a1, a2);
    vector<int> s8 = subtract(b1, b2);
    vector<int> s9 = add(s3, s5);
    vector<int> s10 = add(s2, s4);

    vector<int> p1 = strassen(a1, s1);
    vector<int> p2 = strassen(s2, b2);
    vector<int> p3 = strassen(s3, b1);
    vector<int> p4 = strassen(a2, s6);
    vector<int> p5 = strassen(s7, s5);
    vector<int> p6 = strassen(s10, s9);
    vector<int> p7 = strassen(s4, s8);

    vector<int> c(2*n-1);
    for (int i=0; i<n; i++)
    {
        c[i] = p5[i] + p4[i] - p2[i] + p6[i];
        c[i+n] = p1[i] + p2[i] + p3[i] + p5[i] - p7[i];
    }
    return c;
}

