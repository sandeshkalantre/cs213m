#include <iostream>
using namespace std;

int partition(int A[],int p,int r)
{
    //choosing the pivot x
    int x = A[r];
    int i = p-1;
    for(int j = p;j <= r-1;j++)
    {
        if(A[j] <= x)
        {
            i++;
            int tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    int tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp; 
    return i+1;
}

void sort(int A[],int p,int r)
{
    if(p < r)
    {
        int q = partition(A,p,r);
        sort(A,p,q-1);
        sort(A,q+1,r);
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
    sort(A,0,N-1);
    for(int i = 0; i <  N; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}

