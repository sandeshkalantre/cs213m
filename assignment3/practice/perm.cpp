#include<iostream>
#include<string>

using namespace std;

//recursively compute all permutations of a string
void permute(string permutation_so_far, string rest,int *count)
{
    if(rest.empty())
    {
        cout << permutation_so_far << endl;
        (*count) += 1;
        return;
    }
    else
    {
        for(int i = 0; i < rest.length(); i++)
        {
            string tmp_rest = rest.substr(0,i) + rest.substr(i+1,rest.length());
            permute(permutation_so_far + rest[i],tmp_rest,count);
        }
    }
}
int main()
{
    string str;
    cin >> str;
    string tmp = "";
    cout << endl;
    int count = 0;
    permute(tmp,str,&count);
    cout << count << endl;
    return 0;
} 
