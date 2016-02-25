#include <iostream>

using namespace std;
int range_count(int A[],int N,int k,int a,int b)
{
    int *C1 = new int [k + 1];
    int *C2 = new int [k + 1];
    for(int i = 0; i < k+1;i++)
    {
        C1[i] = 0;
        C2[i] = 0;
    }
    for(int i = 0;i < N;i++)
    {
        C1[A[i]] += 1;
        C2[A[i]] += 1;
    }
    for(int i = 1;i < k+1;i++)
    {
        C1[i] = C1[i] + C1[i-1]; 
        C2[k-i] += C2[k+1-i];
    }
    return C1[b] + C2[a] - N;
}

int main()
{
    int N,k;
    cin >> N;
    cin >> k;
    int a,b;
    cin >> a;
    cin >> b;

    int *A = new int [N];
    for(int i = 0;i< N;i++)
    {
       cin >> A[i];
    } 
    cout << range_count(A,N,k,a,b) << endl;
    
    return 0;
}


