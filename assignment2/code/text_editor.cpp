#include <iostream>
#include <string>
#include <stack>

using namespace std;
class operation
{
    public:
        //operation type
        char _type;
        //operation data
        //string in case of append
        string _str;
        //in case of get, erase
        int _k;
        operation();
        add_data(char type, string str, int k);
};
operation::operation()
{
}
operation::operation(char type, string str = "", int k = 0)
{
    _type = type;
    _str = str;
    _k = k;
}

int main()
{
    //number of operations
    int Q;
    cin >> Q;
    //operation
    char t;


    //string
    string str;

    //operation stacks
    stack<operation> undo;
    stack<operation> redo;
    
    string tmp_str;
    operation tmp_opr;
    while(Q--)
    {
        cin >> t;
        switch(t)
        {
            case 'a':
            {
                cin >> tmp_str;
                str.append(tmp_str);
                undo.push(tmp_opr.add_data('a',tmp_str,0));
                break;
            }
            case 'e':
            {
                //O(k) solution
                //CAN BE IMPROVED
                int k;
                cin >> k;
                str.erase(str.size() - k, k);
                undo.push(tmp_opr.add_data('e',"",k));
                break;
            }
            case 'g':
            {
                int k;
                cin >> k;
                cout<< str[k];
                undo.push(tmp_opr.add_data('g',"",k));
                break;
            }
            case 'u':
            {
                break;
            }
            case 'r':
            {
                break;
            }
            case 'p':
            {
                cout << str;
                break;
            }
        }
    }
    return 0;
}
