#include <iostream>
#include "minMaxHeap.cpp"

using namespace std;
int main()
{
    int N;
    cin >> N;
    MinMaxHeap<int> my_heap;
    while(N--)
    {
        char op;
        cin >> op;
        switch(op)
        {
            case 'i':
                int num;
                cin >> num;
                my_heap.insert(num);
                break;

            case 'd':
                my_heap.deleteMin();
                break;

            case 'D':
                my_heap.deleteMin();
                break;

            case 'g':
                cout << my_heap.getMin(); 
                break;

            case 'G':
                cout << my_heap.getMax(); 
                break;

            case 'p':
                my_heap.print();
                break;

        }
    }
    return 0;
}

