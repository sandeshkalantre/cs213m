#include <iostream>

using namespace std;

void bubble(int A[], int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - 1; j++)
        {
            if(A[j] > A[j+1])
            {
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
    return;
}

int main()
{
    int N;
    cin >> N;
    int *A = new int [N];
    for(int i = 0; i <  N; i++)
    {
        cin >> A[i];
    }
    bubble(A,N);
    for(int i = 0; i <  N; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}

