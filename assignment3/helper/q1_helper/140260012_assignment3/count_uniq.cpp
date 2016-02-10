#include <iostream>
#include "mfile.hpp"
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    string inp_filename;
    cin >> inp_filename;

    int num_char_line;
    cin >> num_char_line;

    //number of unique lines in the file
    int uniq = 0;

    MFile my_file;
    my_file.init(inp_filename, num_char_line); 

    //hash table
    unordered_map< string, int> hash;
    string tmp;
    while((tmp = my_file.readNext()) != "")
    {
       //new line in the file
       if(hash.find(tmp) == hash.end())
       { 
           uniq++;
           pair<string,int> tmp_ele(tmp,0); 
           hash.insert(tmp_ele);
       }
    }
    cout << uniq << endl;
    my_file.close();
    return 0;
}
