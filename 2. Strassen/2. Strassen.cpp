#include <iostream>
using namespace std;

// Hàm chia ma tr?n thành 4 ph?n b?ng nhau
void split(int** A, int** A11, int** A12, int** A21, int** A22, int n)
{
    int m = n/2;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<m; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+m];
            A21[i][j] = A[i+m][j];
            A22[i][j] = A[i+m][j+m];
        }
    }
}

void merge(int** C11, int** C12, int** C21, int** C22, int** C, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j+n] = C12[i][j];
            C[i+n][j] = C21[i][j];
            C[i+n][j+n] = C22[i][j];
        }
    }
}

// Hàm k?t h?p 4 ph?n thành m?t ma tr?n
void join(int** C, int** C11, int** C12, int** C21, int** C22, int n)
{
    int m = n/2;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<m; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j+m] = C12[i][j];
            C[i+m][j] = C21[i][j];
            C[i+m][j+m] = C22[i][j];
        }
    }
}

// Hàm c?ng hai ma tr?n
void add(int** A, int** B, int** C, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Hàm tr? hai ma tr?n
void subtract(int** A, int** B, int** C, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Hàm nhân ma tr?n theo thu?t toán Strassen
void strassen(int** A, int** B, int** C, int n)
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // T?o ma tr?n con
    int m = n/2;
    int** A11 = new int*[m];
    int** A12 = new int*[m];
    int** A21 = new int*[m];
    int** A22 = new int*[m];
    int** B11 = new int*[m];
    int** B12 = new int*[m];
    int** B21 = new int*[m];
    int** B22 = new int*[m];
    for (int i=0; i<m; i++)
    {
        A11[i] = new int[m];
        A12[i] = new int[m];
        A21[i] = new int[m];
        A22[i] = new int[m];
        B11[i] = new int[m];
        B12[i] = new int[m];
        B21[i] = new int[m];
        B22[i] = new int[m];
    }

    // Chia ma tr?n A và B thành 4 ph?n
    split(A, A11, A12, A21, A22, n);
    split(B, B11, B12, B21, B22, n);

    // T?o các ma tr?n con
    int** S1 = new int*[m];
    int** S2 = new int*[m];
    int** S3 = new int*[m];
    int** S4 = new int*[m];
    int** S5 = new int*[m];
    int** S6 = new int*[m];
    int** S7 = new int*[m];
    int** S8 = new int*[m];
    int** S9 = new int*[m];
    int** S10 = new int*[m];
    int** P1 = new int*[m];
    int** P2 = new int*[m];
    int** P3 = new int*[m];
    int** P4 = new int*[m];
    int** P5 = new int*[m];
    int** P6 = new int*[m];
    int** P7 = new int*[m];
    for (int i=0; i<m; i++)
    {
        S1[i] = new int[m];
        S2[i] = new int[m];
        S3[i] = new int[m];
        S4[i] = new int[m];
        S5[i] = new int[m];
        S6[i] = new int[m];
        S7[i] = new int[m];
        S8[i] = new int[m];
        S9[i] = new int[m];
        S10[i] = new int[m];
        P1[i] = new int[m];
        P2[i] = new int[m];
        P3[i] = new int[m];
        P4[i] = new int[m];
        P5[i] = new int[m];
        P6[i] = new int[m];
        P7[i] = new int[m];
    }

    // Tính S1 d?n S10
    subtract(B12, B22, S1, m);
    add(A11, A12, S2, m);
    add(A21, A22, S3, m);
    subtract(B21, B11, S4, m);
    add(A11, A22, S5, m);
    add(B11, B22, S6, m);
    subtract(A12, A22, S7, m);
    add(B21, B22, S8, m);
    subtract(A11, A21, S9, m);
    add(B11, B12, S10, m);

    // Tính P1 d?n P7
    strassen(A11, S1, P1, m);
    strassen(S2, B22, P2, m);
    strassen(S3, B11, P3, m);
    strassen(A22, S4, P4, m);
    strassen(S5, S6, P5, m);
    strassen(S7, S8, P6, m);
    strassen(S9, S10, P7, m);

    // Tính ma tr?n k?t qu?
    int** C11 = new int*[m];
    int** C12 = new int*[m];
    int** C21 = new int*[m];
    int** C22 = new int*[m]; 
    for (int i=0; i<m; i++)
    {
        C11[i] = new int[m];
        C12[i] = new int[m];
        C21[i] = new int[m];
        C22[i] = new int[m];
    }

    // Tính các ph?n c?a ma tr?n k?t qu?
    add(P5, P4, C11, m);
    subtract(C11, P2, C11, m);
    add(C11, P6, C11, m);
    add(P1, P2, C12, m);
    add(P3, P4, C21, m);
    add(P5, P1, C22, m);
    subtract(C22, P3, C22, m);
    subtract(C22, P7, C22, m);

    // G?p các ph?n d? t?o ma tr?n k?t qu?
    merge(C11, C12, C21, C22, C, n);

    // Gi?i phóng b? nh?
    for (int i=0; i<m; i++)
    {
        delete[] A11[i];
        delete[] A12[i];
        delete[] A21[i];
        delete[] A22[i];
        delete[] B11[i];
        delete[] B12[i];
        delete[] B21[i];
        delete[] B22[i];
        delete[] S1[i];
        delete[] S2[i];
        delete[] S3[i];
        delete[] S4[i];
        delete[] S5[i];
        delete[] S6[i];
        delete[] S7[i];
        delete[] S8[i];
        delete[] S9[i];
        delete[] S10[i];
        delete[] P1[i];
        delete[] P2[i];
        delete[] P3[i];
        delete[] P4[i];
        delete[] P5[i];
        delete[] P6[i];
        delete[] P7[i];
        delete[] C11[i];
        delete[] C12[i];
        delete[] C21[i];
        delete[] C22[i];
    }
    delete[] A11;
    delete[] A12;
    delete[] A21;
    delete[] A22;
    delete[] B11;
    delete[] B12;
    delete[] B21;
    delete[] B22;
    delete[] S1;
    delete[] S2;
    delete[] S3;
    delete[] S4;
    delete[] S5;
    delete[] S6;
    delete[] S7;
    delete[] S8;
    delete[] S9;
    delete[] S10;
    delete[] P1;
    delete[] P2;
    delete[] P3;
    delete[] P4;
    delete[] P5;
    delete[] P6;
    delete[] P7;
    delete[] C11;
    delete[] C12;
    delete[] C21;
    delete[] C22;
}
int main()
{
    int n = 4; // Kích thu?c ma tr?n
    int** A = new int*[n];
    int** B = new int*[n];
    int** C = new int*[n];
    for (int i=0; i<n; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    // Kh?i t?o giá tr? cho ma tr?n A và B
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3; A[0][3] = 4;
    A[1][0] = 5; A[1][1] = 6; A[1][2] = 7; A[1][3] = 8;
    A[2][0] = 9; A[2][1] = 10; A[2][2] = 11; A[2][3] = 12;
    A[3][0] = 13; A[3][1] = 14; A[3][2] = 15; A[3][3] = 16;

    B[0][0] = 17; B[0][1] = 18; B[0][2] = 19; B[0][3] = 20;
    B[1][0] = 21; B[1][1] = 22; B[1][2] = 23; B[1][3] = 24;
    B[2][0] = 25; B[2][1] = 26; B[2][2] = 27; B[2][3] = 28;
    B[3][0] = 29; B[3][1] = 30; B[3][2] = 31; B[3][3] = 32;

    // G?i hàm Strassen d? nhân hai ma tr?n A và B
    strassen(A, B, C, n);

    // Hi?n th? ma tr?n k?t qu?
    cout << "Ma tran ket qua:" << endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Gi?i phóng b? nh?
    for (int i=0; i<n; i++)
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;
}
