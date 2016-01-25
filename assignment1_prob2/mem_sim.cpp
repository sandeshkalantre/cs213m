#include <iostream>
#include <list>
#include <utility>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    int N,P,M,K;
    // N - maximum id of the pages
    cin >> N;
    // P - maximum number of page frames in the memory
    cin >> P;
    // M - number of page references
    cin >> M;
    
    int hit,miss;
    hit = 0;
    miss = 0;
   
    //list of pairs (page ID, frequency) 
    list<pair<int,int> > memory;
    //dynamic size of memory 
    int memory_size = 0;
   
    //position of each page in memory
    vector<bool> position(N,false); 
    //last postion to insert from
    int last_pos = 0;
    
    while(M--)
    {
        cin>>K;

        //if not in memory
        if(!position[K])        
        {
            miss++;
            if(memory_size < P)
            {
                list < pair<int,int> >::iterator it = memory.end();
                advance(it,-last_pos);
                memory.insert(it,make_pair(K,1));           
                memory_size++;
                position[K] = true;
            }
            else
            {
                position[memory.back().first] = false;
                memory.pop_back();    
                list<pair<int,int> >::iterator it = memory.end();
                advance(it,-last_pos);
                memory.insert(it,make_pair(K,1));           
                position[K] = true;
            }
        } 
        else
        {
            //search for K in memory
            for(list <pair<int,int> >::iterator it = memory.begin(); it != memory.end(); ++it)
            {
                //hit
                if(it -> first == K)
                {
                    //update number of hits
                    hit++;
                    //update the frequency
                    it->second++;
                    
                    
                    list < pair<int,int> >::iterator hit_it;
                    hit_it = it;
                    
                    while(it != memory.begin() && (it -> second <= hit_it -> second))
                    {
                        it--;
                    }
                    it++;
                    memory.insert(it,*hit_it);
                    memory.erase(hit_it); 
                    break;
                }
            } 

        }
    }   
    cout<< hit<<endl;
    cout<< miss<<endl;
    return 0;
}
