#include <iostream>

using namespace std;
void count(int A[],int N,int k)
{
    int *C = new int [k+1];
    int *B = new int [N];
    for(int i = 0;i < k+1;i++)
    {
        C[i] = 0;
    }
    for(int i = 0;i < N;i++)
    {
        C[A[i]] += 1;
    }
    //C[x] now stores how many times x occurs in A
    for(int i = 1;i < k+1;i++)
    {
        C[i] = C[i] + C[i-1];
    }
    //C[x] now stores how many elements are less than or equal to x in A
    for(int i = N-1;i >= 0;i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]] -= 1;
    }
    //copy sorted array into A
    for(int i = 0;i < N;i++)
    {
        A[i] = B[i];
    }
    return;
}

int main()
{
    int N;
    cin >> N;
    int k;
    cin >> k;
    int *A = new int [N];
    for(int i = 0; i <  N; i++)
    {
        cin >> A[i];
    }
    count(A,N,k); 
    for(int i = 0; i <  N; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}

