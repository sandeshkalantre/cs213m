#include <iostream>
using namespace std;

void max_heapify(int A[], int i, int N)
{
    int largest = i;
    if(2*i + 1 < N && A[2*i + 1] > A[i])
    {
        largest = 2*i +1;
    }
    if(2*i + 2 < N && A[2*i + 2] > A[largest])
    {
        largest = 2*i + 2;
    }
    if(largest != i)
    {
        int tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        max_heapify(A, largest,N);
    }
    return;
}

void min_heapify(int A[], int i, int N)
{
    int smallest = i;
    if(2*i + 1 < N && A[2*i + 1] < A[i])
    {
        smallest = 2*i +1;
    }
    if(2*i + 2 < N && A[2*i + 2] < A[smallest])
    {
        smallest = 2*i + 2;
    }
    if(smallest != i)
    {
        int tmp = A[i];
        A[i] = A[smallest];
        A[smallest] = tmp;
        min_heapify(A, smallest,N);
    }
    return;
}

void build_max_heap(int A[],int N)
{
    for(int i = N/2 - 1;i >= 0;i--)
    {
       max_heapify(A,i,N);
    }
    return;
} 

void build_min_heap(int A[],int N)
{
    for(int i = N/2 - 1;i >= 0;i--)
    {
       min_heapify(A,i,N);
    }
    return;
} 

void heap_sort(int A[], int N)
{
    build_max_heap(A,N);
    for(int i = N-1;i > 0;i--)
    {
        int tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        max_heapify(A,0,N-(N-i));
    }
    return; 
} 

int main()
{
    int N;
    cin >> N;
    int *A = new int [N];
    
    for(int i = 0; i < N;i++)
    {
        cin >> A[i];
    }
    heap_sort(A,N);
    for(int i = 0; i < N;i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}
