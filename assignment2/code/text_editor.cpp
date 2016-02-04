#include <iostream>
#include <string>
#include <stack>

using namespace std;

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
    stack<char> u_opr;
    stack<string> u_opr_str;
    stack<int> u_opr_num; 
    stack<char> r_opr;
    stack<string> r_opr_str;
    stack<int> r_opr_num; 
    
    string tmp_str;
    while(Q--)
    {
        cin >> t;
        switch(t)
        {
            case 'a':
            {
                cin >> tmp_str;
                str.append(tmp_str);
                u_opr.push('a');
                u_opr_str.push(tmp_str);
                r_opr = stack<char>();
                r_opr_str = stack<string>();
                break;
            }
            case 'e':
            {
                //O(k) solution
                //CAN BE IMPROVED
                int k;
                cin >> k;
                tmp_str = str.substr(str.size() - k,k); 
                str.erase(str.size() - k, k);
                u_opr.push('e');
                u_opr_str.push(tmp_str);
                r_opr = stack<char>();
                r_opr_str = stack<string>();
                break;
            }
            case 'g':
            {
                int k;
                cin >> k;
                cout<< str[k]<<endl;
                cout<< str<<endl;
                break;
            }
            case 'u':
            {
                if(!u_opr.empty())
                {
                    if(u_opr.top() == 'e') 
                    {
                        r_opr.push('e');
                        str.append(u_opr_str.top());
                        r_opr_str.push(u_opr_str.top()); 
                        u_opr_str.pop();
                        u_opr.pop();
                    }
                    else if(u_opr.top() == 'a')
                    {
                        r_opr.push('a'); 
                        str.erase(str.size() - u_opr_str.top().length(),u_opr_str.top().length());
                        r_opr_str.push(u_opr_str.top()); 
                        u_opr_str.pop();
                        u_opr.pop();
                    }
                }
                break;
            }
            case 'r':
            {
                if(!r_opr.empty())
                {
                    if(r_opr.top() == 'e') 
                    {
                        str.append(r_opr_str.top());
                        r_opr_str.pop();
                        r_opr.pop();
                    }
                    else if(r_opr.top() == 'a')
                    {
                        str.erase(str.size() - r_opr_str.top().size(),r_opr_str.top().size());
                        r_opr_str.pop();
                        r_opr.pop();
                    }
                }
                break;
            }
            case 'p':
            {
                cout << str <<endl;
                break;
            }
        }
    }
    return 0;
}
