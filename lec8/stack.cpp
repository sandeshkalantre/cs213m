#include <iostream>
using namespace std;

class stack
{
        //stack on the heap
        int* _stack;
        //top of the stack
        int* _top;
        //max size
        int _size;
    public:
        stack(int);
        void push(int x);
        bool is_empty();
        bool is_full();
        void pop();
        int peek();
        void print();
};

stack::stack(int max_size = 256)
{
    _size = max_size;
    _stack = new int [_size];
    _top = NULL;
}

bool stack::is_empty()
{
    if(_top == NULL)
    {
        return true;
    }
    else
    {
       return false;
    } 
}

bool stack::is_full()
{
    if(_top == _stack + _size -1)
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
    //stack is empty
    if(_top == NULL)
    {
        _top = _stack;
        *_top = x;
        return;
    }
    else
    {
        if(is_full())
        {
            cout<< "Stack overflow" << endl;
            return;
        }
        else
        {
            _top++;
            *_top = x;
            return;
        }
    }
}

void stack::pop()
{
    if(is_empty())
    {
        cout<<"Stack empty"<<endl;
        return;
    }
    else
    {
        if(_stack == _top)
        {
            //stack empty
            _top = NULL;
            return;
        }
        else
        {
            _top--;
            return;
        }
    }
}

int stack::peek()
{
    if(is_empty())
    {
        cout<<"Stack empty"<<endl;
        return 0;
    }
    else
    {
        return *_top;
    }
}

void stack::print()
{
    if(_top == NULL)
    {
        cout<<"Stack empty"<<endl;
        return;
    }
    else
    {
        for(int* it = _stack;it != _top;it++)
        {
            cout<< *it << " -> ";
        }
        cout<<*_top<<endl;
        return;
    }
}

int main()
{
    int N;
    cin >> N;
    int S;
    stack my_stack(S);
    char ch;
    while(N--)
    {
        cin >> ch;
        switch(ch)
        {
            case 'P'://print
            {
                my_stack.print();
                break;
            }
            case 'E'://isempty
            {
                if(my_stack.is_empty())
                {
                    cout<<"Stack empty"<<endl;
                }
                else
                {
                    cout<<"Stack not empty"<<endl;
                }
                break;
            }
            case 'U'://push
            {   
                int x;
                cin >> x;
                my_stack.push(x);
                break;
            }
            case 'O'://pop
            {
                my_stack.pop();
                break;
            }
            case 'F'://is full
            {
                if(my_stack.is_full())
                {
                    cout<<"Stack full"<<endl;
                }
                else
                {
                    cout<<"Stack not full"<<endl;
                }
                break;
            }
            case 'K'://peek
            {
                cout<<my_stack.peek()<<endl;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}
