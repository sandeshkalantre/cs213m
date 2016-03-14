#include <iostream>
#include "mfile.hpp"
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
//CORRECTED SOLUTION NOW TAKES CARE OF DIFFERENT STRING SAME HASH PROBLEM

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
    //second int stores the line numbers with same hash
    unordered_map< unsigned long, vector<int>> hash;

    //temp string for storing a single line
    string tmp;
    //string hash function
    //returns UNSIGNED int
    std::hash<string> str_hash;

    //line number
    int ln_no = -1;
    //number of hash collisions
    int evil = 0;
    while((tmp = my_file.readNext()) != "")
    {
       ln_no++;
       unsigned long tmp_hash = str_hash(tmp);
       unordered_map<unsigned long, vector<int> >::iterator it = hash.find(tmp_hash);
       if(it == hash.end())
       { 
           //new hash, new line for sure
           uniq++;
           vector<int> tmp_ln_no_vec(1,ln_no);
           pair<unsigned long,vector<int> > tmp_ele(tmp_hash,tmp_ln_no_vec); 
           hash.insert(tmp_ele);
       }
       else
       {
           //look for a collision
           bool found = false;
           //look at all srings having this hash
           vector<int> same_hash_ln_no = it->second;
           vector<string> strings_same_hash = my_file.readLines(same_hash_ln_no);
           for(vector<string>::iterator it1 = strings_same_hash.begin();it1 != strings_same_hash.end();it1++)
           {
               if(tmp == *it1)
               {
                   found = true;
                   break;
               }
           }
           if(!found)
           {
               //hash collision
               //YAY
               //update the ln_no list for future use
               (it->second).push_back(ln_no);
               //obvously
               uniq++;
               evil++;
           }
       }
    }
    
    cout << uniq << endl;
    //cout << evil << endl;
    my_file.close();
    return 0;
}
