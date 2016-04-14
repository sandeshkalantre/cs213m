#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "A-star.hpp"

using namespace std;

class node
{
    public:
        string word;
        int f,g,h;

        node(string tmp_word)
        {
            word = tmp_word;
            f = 0;
            g = 0;
            h = 0;
        }

        int calculate_h(node end)
        {
            int ham = 0;
            for(int i = 0;i < word.length();i++)
            {
                if(word[i] != end.word[i])
                {
                    ham++;
                }
            }
            return ham/2;
        }

        bool operator<(const node& n) const
        {
            if(f < n.f)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool operator==(const node& n) const
        {
            if(word == n.word)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool operator!=(const node& n) const
        {
            if(word == n.word)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        
        vector<node> get_neighbours() const
        {
            vector< node > neigh;
            string swap_word = word;
            string ini_word = word;
            int len = word.length();
            for(int i = 0;i < len;i++)
            {
                for(int j = i+1;j < len ;j++)
                {
                    char ch = swap_word[i];
                    swap_word[i] = swap_word[j];
                    swap_word[j] = ch;

                    node tmp_node(swap_word);
                    neigh.push_back(tmp_node);
                    swap_word = ini_word;
                }
            }
            return neigh;
        }

};

int main()
{
    string inp1,inp2;
    cin >> inp1 >> inp2;
    node start(inp1);
    node end(inp2);
    A_star<node> my_A_star;
    cout << my_A_star.A_star_solve(start,end) << endl;

    return 0;
} 




