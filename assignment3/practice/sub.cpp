#include <iostream>
#include <string>

using namespace std;

void subset(string sub, string rest,int* p_count)
{
    if(rest.empty())
    {
        cout << sub << endl;
        (*p_count)++;
        return;
    }
    else
    {
        subset(sub + rest[0],rest.substr(1,rest.length()), p_count);
        subset(sub, rest.substr(1,rest.length()), p_count);
    }
}

int main()
{
    string inp;
    cin >> inp;
    cout << endl;
    int count = 0;
    subset("",inp,&count);
    cout << count << endl;
    return 0;
}
