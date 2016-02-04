#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N;
    cin >> N;
   
    stack<char> sym_st; 
    char ch;
    while(N--)
    {
        cin >> ch;
        if(ch == '(')
        {
            sym_st.push(ch);
        }
        else if(sym_st.top() == '(' && ch == ')')
        {
           sym_st.pop();
        }
        else
        {
            cout<<"Not Balanced";
            return 0;
        }
    }
    if(sym_st.empty())
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Not Balanced";
    }
    return 0;
}    

