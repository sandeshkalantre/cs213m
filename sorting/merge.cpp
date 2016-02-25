#include <iostream>

using namespace std;

void merge_sort(int A[],int start, int end, int N)
{
    //start and end are both inclusive
    if(start == end)
    {
        return;
    }
    int middle = (start +  end) / 2;
    merge_sort(A,start,middle,N);
    merge_sort(A,middle + 1,end,N);
    int *tmp_A = new int [end-start +1];
    for(int i = 0;i < end-start+1;i++)
    {
        tmp_A[i] = A[i + start];
    }

    int l = 0;
    int r = middle - start + 1;
    for(int i = start; i <= end;i++)
    {
        if(l == middle - start + 1)
        {
            A[i] = tmp_A[r];
            r++;
        }
        else if(r == end - start + 1)
        {
            A[i] = tmp_A[l];
            l++;
        }
        else if(tmp_A[l] < tmp_A[r])
        {
            A[i] = tmp_A[l];
            l++;
        }
        else
        {
            A[i] = tmp_A[r];
            r++;
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
    merge_sort(A,0,N-1,N);
    for(int i = 0; i <  N; i++)
    {
        cout << A[i] << endl;
    }

    return 0;
}

