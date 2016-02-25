#include <iostream>
using namespace std;

//insertion sort
void sort(int A[],int N)
{
    for(int i = 1; i < N;i++)
    {
        int j = i - 1;
        while (j > 0 && A[j] < A[j-1])
        {
            int tmp = A[j];
            A[j] = A[j-1];
            A[j-1] = tmp;
            j--;
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
    sort(A,N);
    for(int i = 0; i <  N; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}

