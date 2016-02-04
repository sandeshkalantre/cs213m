#include <iostream>
using namespace std;

class stack
{
        //maximum size of the stack
        int max_size;
        //stack as an array 
        int* _stack;
        //location of top of the stack
        int top;
    public:
        stack (int size); 
        bool stack_empty();
        void push(int x);
        void pop();
        int* get_top();
        int* get_start();
};

stack::stack (int size = 256)
{
    max_size = size;
    _stack = new int [max_size];
    top = -1;
}

bool stack::stack_empty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack::push(int x)
{
    if(top == max_size - 1)
    {
        cout << "Stack overflow";
        return;
    }
    else
    {
       *(_stack + top + 1) = x;
        top += 1;
        return;
    }
}

void stack::pop()
{
   if(top == -1)
   {
       cout<<"Stack empty" << endl;
       return;
   }
   *(_stack + top) = 0;
   top = top - 1;
}

int* stack::get_top()
{
    if(top == -1)
    {
        cout<< "Stack empty";
        return NULL;
    } 
    else
    {
        return _stack + top;
    }
}

int* stack::get_start()
{
    if(top == -1)
    {
        cout<< "Stack empty";
        return NULL;
    } 
    else
    {
        return _stack;
    }
}

int main()
{
    int N;
    cin >> N;
    stack my_stack;
    while(N--)
    {
        char ch;
        cin >> ch;
        switch(ch)
        {
            case 'E':
            {
                if(my_stack.stack_empty())
                {
                    cout<< "Stack empty"<<endl;
                }
                else
                {
                    cout<< "Stack not empty"<<endl;
                }
                break;
            }
            case 'U': //push
            {
                int x;
                cin >> x;
                my_stack.push(x);
                break;
            }
            case 'O': //pop
            {
                my_stack.pop();
                break;
            }
            case 'P': //print
            {
                if(my_stack.stack_empty())
                {
                    cout<< "Stack empty"<<endl;
                    break;
                }

                int* it = my_stack.get_top();
                int* start = my_stack.get_start();
                for(int* it = my_stack.get_top();it != start-1;it--)
                {
                    cout << *it << " <- ";
                }

                cout<<endl;
                break;
            }
        }
    }
    return 0;
}  

