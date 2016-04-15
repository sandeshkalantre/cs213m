#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template<class T>
class A_star
{
    public:
        //returns the minimum cost
        //I have assumed all costs are integers
        int A_star_solve(T start, T end)
        {
            list<T> open;
            list<T> closed;

            //initialization 
            start.g = 0;
            open.push_back(start);
            while(!open.empty())
            {
                typename list<T>::iterator it_current = min_element(open.begin(),open.end());
                T current = *it_current;
                if(*it_current == end)
                {
                    //golden bullet
                    return (*it_current).f;
                }

                vector<T> neighbours = (*it_current).get_neighbours();
                closed.push_back(*it_current);
                open.erase(it_current);

                for(int i = 0;i < neighbours.size();i++)
                {
                    T v = neighbours[i];
                    //v.print_state();
                    if(count(closed.begin(),closed.end(),v) == 0)
                    {
                        typename list<T>::iterator it = find(open.begin(),open.end(),v);
                        if(count(open.begin(),open.end(),v) == 0)
                        {
                            //1 is the cost of going from current to neighbours of current
                            //here I have assumed it to be 1, in general one can have a function inside class T
                            v.g = current.g + 1;
                            v.h = v.calculate_h(end);
                            v.f = v.g + v.h;
                            open.push_back(v); 
                        }
                        else
                        {
                            int tent = current.g + 1;
                            if(tent < (*it).g)
                            {
                                T tmp_node = *it;
                                tmp_node.g = tent;
                                tmp_node.f = (*it).g + (*it).h;
                                open.erase(it);
                                open.push_back(tmp_node);
                            }

                        }
                    }
                }
             
            }
            return -1;
        }
};
