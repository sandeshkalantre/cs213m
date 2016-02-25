#include <iostream>

using namespace std;
int power_10(int d)
{
    int result = 1;
    for(int i = 0;i < d;i++)
    {
        result *= 10;
    }
    return result;
}
//counting sort on the dth digit
void count(int A[],int N,int d)
{
    //d is the digit to look at
    int k = 9;
    int *C = new int [k+1];
    int *B = new int [N];
    for(int i = 0;i < k+1;i++)
    {
        C[i] = 0;
    }
    for(int i = 0;i < N;i++)
    {
        C[(A[i]/power_10(d)) % 10] += 1;
    }
    //C[x] now stores how many times x occurs in A
    for(int i = 1;i < k+1;i++)
    {
        C[i] = C[i] + C[i-1];
    }
    //C[x] now stores how many elements are less than or equal to x in A
    for(int i = N-1;i >= 0;i--)
    {
        B[C[(A[i]/power_10(d)) % 10] - 1] = A[i];
        C[(A[i]/power_10(d)) % 10] -= 1;
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
    int d;
    cin >> d;
    int *A = new int [N];
    for(int i = 0; i <  N; i++)
    {
        cin >> A[i];
    }
    for(int i =0;i < d;i++)
    {
        count(A,N,i);
    }
    for(int i = 0; i <  N; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}

