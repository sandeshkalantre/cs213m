#include <iostream>
#include "mfile.hpp"
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
//CORRECTED SOLUTION NOW TAKES CARE OF DIFFERENT STRING SAME HASH PROBLEM
//we just get the set of repeated lines or lines which have the same hash and count the number of unique lines directly by comparing the string values

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
    //second int stores the line no first it was observed
    unordered_map< unsigned long, int> hash;

    //store line numbers of repeated lines and check them the hard way
    //may have duplicates which are removed later
    //since the number of duplicates is small, its size is small
    vector<int> repeated_line_no;

    string tmp;
    std::hash<string> str_hash;

    int ln_no = -1;
    while((tmp = my_file.readNext()) != "")
    {
       //increase the line no
       ln_no++;
       //new line in the file
       unsigned long tmp_hash = str_hash(tmp);
       if(hash.find(tmp_hash) == hash.end())
       { 
           uniq++;
           pair<unsigned long,int> tmp_ele(tmp_hash,ln_no); 
           hash.insert(tmp_ele);
       }
       else
       {
           repeated_line_no.push_back((hash.find(tmp_hash))->second);
           repeated_line_no.push_back(ln_no);
       }
    }
    //at the end ln_no =number of lines - 1

   //remove duplicates from repeated_line_no 
    set<int> s;
    unsigned size = repeated_line_no.size();
    for( unsigned i = 0; i < size; ++i ) s.insert( repeated_line_no[i] );
    //the size of repeated_line_no is size of set of duplicate lines
    repeated_line_no.assign( s.begin(), s.end() ); 
    int lines_only_once = ln_no + 1 - repeated_line_no.size();
    
    //THE GIVEN API FUNCTION readLines did not seem to work correctly
    //Hence, used the API to implement my own readLines
    MFile my_file1;
    if(my_file1.init(inp_filename, num_char_line) == -1)
    {
        cout << "File failed to open" << endl;
        return -1;
    } 

    vector<string> repeated_lines;
    sort(repeated_line_no.begin(),repeated_line_no.end());
    int counter = 0;
    int line_number = -1;
    while((tmp = my_file1.readNext()) != "")
    {
        line_number++;
        while(repeated_line_no[counter] == line_number)
        {
            counter++;
            repeated_lines.push_back(tmp);
        }
    }
    
    //Now we just count number of unique lines in repeated_line vector
    unordered_map<string, int> string_map;
    int n_uniq = 0;
    for(vector<string>::iterator it = repeated_lines.begin();it != repeated_lines.end();it++)
    {
       tmp = *it; 
       if(string_map.find(tmp) == string_map.end())
       {
           n_uniq++;
           pair<string,int > tmp_ele_str(tmp,0); 
           string_map.insert(tmp_ele_str);
       }
    }
        
    

    cout << lines_only_once + n_uniq << endl;
    my_file.close();
    return 0;
}
