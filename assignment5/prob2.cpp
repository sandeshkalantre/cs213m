#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include "A_star.hpp"

using namespace std;

class node
{
    public:
        vector<int> state;
        int f,g,h;
        
        void print_state()
        {
            for(int i = 0; i < 9;i++)
            {
                cout << state[i];
            }
            cout << endl;
        }
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
        bool operator!=(const node& n) const
        {
            if(state == n.state)
            {
                return false;
            }
            else
            {
                return true;
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
        
        vector<node> get_neighbours() 
        {
            vector<node> neigh;
            //find the position of zero
            int zero_pos;
            for(int i = 0;i < 9;i++)
            {
                if(this->state[i] == 0)
                {
                    zero_pos = i;
                    break;
                }
            }
            vector<int> tmp_state = state;
            if(zero_pos == 0)
            {
                node tmp_node(swap_ele(0,1,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(0,1,tmp_state));
                neigh.push_back(tmp_node1);
            }
            else if(zero_pos == 1)
            {
                node tmp_node(swap_ele(0,1,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(1,2,tmp_state));
                neigh.push_back(tmp_node1);
                node tmp_node2(swap_ele(1,4,tmp_state));
                neigh.push_back(tmp_node2);
            }
            else if(zero_pos == 2)
            {
                node tmp_node(swap_ele(2,1,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(2,4,tmp_state));
                neigh.push_back(tmp_node1);
            }
            else if(zero_pos == 3)
            {
                node tmp_node(swap_ele(3,0,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(3,4,tmp_state));
                neigh.push_back(tmp_node1);
                node tmp_node2(swap_ele(3,6,tmp_state));
                neigh.push_back(tmp_node2);
            }
            else if(zero_pos == 4)
            {
                node tmp_node(swap_ele(4,1,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(4,3,tmp_state));
                neigh.push_back(tmp_node1);
                node tmp_node2(swap_ele(4,5,tmp_state));
                neigh.push_back(tmp_node2);
                node tmp_node3(swap_ele(4,7,tmp_state));
                neigh.push_back(tmp_node3);
            }
            else if(zero_pos == 5)
            {
                node tmp_node(swap_ele(5,2,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(5,4,tmp_state));
                neigh.push_back(tmp_node1);
                node tmp_node2(swap_ele(5,8,tmp_state));
                neigh.push_back(tmp_node2);
            }
            else if(zero_pos == 6)
            {
                node tmp_node(swap_ele(6,3,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(6,7,tmp_state));
                neigh.push_back(tmp_node1);
            }
            else if(zero_pos == 7)
            {
                node tmp_node(swap_ele(7,4,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(7,6,tmp_state));
                neigh.push_back(tmp_node1);
                node tmp_node2(swap_ele(7,8,tmp_state));
                neigh.push_back(tmp_node2);
            }
            else if(zero_pos == 8)
            {
                node tmp_node(swap_ele(8,5,tmp_state));
                neigh.push_back(tmp_node);
                node tmp_node1(swap_ele(8,7,tmp_state));
                neigh.push_back(tmp_node1);
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
    //start.print_state();

    vector<int> end_state;
    for(int i = 0;i < 8;i++)
    {
        end_state.push_back(i+1);
    }
    end_state.push_back(0);
    node end(end_state);

    A_star<node> my_A_star;
    cout << my_A_star.A_star_solve(start,end) << endl;

    return 0;
} 




