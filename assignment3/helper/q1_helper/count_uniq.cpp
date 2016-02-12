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
    if(my_file.init(inp_filename, num_char_line) == -1)
    {
        cout << "File failed to open" << endl;
        return -1;
    } 

    //hash table
    unordered_map< int, int> hash;
    string tmp;
    std::hash<string> str_hash;
    while((tmp = my_file.readNext()) != "")
    {
       //new line in the file
       if(hash.find(str_hash(tmp)) == hash.end())
       { 
           uniq++;
           pair<int,int> tmp_ele(str_hash(tmp),0); 
           hash.insert(tmp_ele);
       }
    }
    cout << uniq << endl;
    my_file.close();
    return 0;
}
