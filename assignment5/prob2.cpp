#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include "A-star.hpp"

using namespace std;

class node
{
    public:
        vector<int> state;
        int f,g,h;

        node(vector<int> tmp_state)
        {
            state = tmp_state;
            f = 0;
            g = 0;
            h = 0;
        }

        int calculate_h(node end)
        {
            return 0;
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
            if(state == n.state)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        //utility swap
        vector<int> swap_ele(int i,int j,vector<int> state) const
        {
            vector<int> result = state;
            int tmp = result[i];
            result[i] = result[j];
            result[j] = tmp;
            return result;
        }
        
        vector<node> get_neighbours() const
        {
            vector<node> neigh;
            //find the position of zero
            int zero_pos;
            for(int i = 0;i < 9;i++)
            {
                if(state[i] == 0)
                {
                    zero_pos = i;
                }
            }
            vector<int> tmp_state = state;
            if(zero_pos == 0)
            {
                neigh.push_back(swap_ele(0,1,tmp_state));
                neigh.push_back(swap_ele(0,3,tmp_state));
            }
            else if(zero_pos == 1)
            {
                neigh.push_back(swap_ele(0,1,tmp_state));
                neigh.push_back(swap_ele(1,2,tmp_state));
                neigh.push_back(swap_ele(1,4,tmp_state));
            }
            else if(zero_pos == 2)
            {
                neigh.push_back(swap_ele(2,5,tmp_state));
                neigh.push_back(swap_ele(1,2,tmp_state));
            }
            else if(zero_pos == 3)
            {
                neigh.push_back(swap_ele(0,3,tmp_state));
                neigh.push_back(swap_ele(3,4,tmp_state));
                neigh.push_back(swap_ele(3,6,tmp_state));
            }
            else if(zero_pos == 4)
            {
                neigh.push_back(swap_ele(4,1,tmp_state));
                neigh.push_back(swap_ele(4,3,tmp_state));
                neigh.push_back(swap_ele(4,5,tmp_state));
                neigh.push_back(swap_ele(4,7,tmp_state));
            }
            else if(zero_pos == 5)
            {
                neigh.push_back(swap_ele(5,2,tmp_state));
                neigh.push_back(swap_ele(5,4,tmp_state));
                neigh.push_back(swap_ele(5,8,tmp_state));
            }
            else if(zero_pos == 6)
            {
                neigh.push_back(swap_ele(6,3,tmp_state));
                neigh.push_back(swap_ele(6,7,tmp_state));
            }
            else if(zero_pos == 7)
            {
                neigh.push_back(swap_ele(7,4,tmp_state));
                neigh.push_back(swap_ele(7,6,tmp_state));
                neigh.push_back(swap_ele(7,8,tmp_state));
            }
            else if(zero_pos == 8)
            {
                neigh.push_back(swap_ele(8,7,tmp_state));
                neigh.push_back(swap_ele(8,5,tmp_state));
            }
            return neigh;
        }

};

int main()
{
    vector<int> inp;
    for(int i = 0;i < 9;i++)
    {
        int tmp;
        cin >> tmp;
        inp.push_back(tmp);
    }

    node start(inp);

    vector<int> end_state;
    for(int i = 0;i < 9;i++)
    {
        end_state.push_back(i);
    }
    node end(end_state);

    A_star<node> my_A_star;
    cout << my_A_star.A_star_solve(start,end) << endl;

    return 0;
} 




