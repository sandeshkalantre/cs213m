#include <iostream>
#include <list>
#include <utility>

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
    
    list<pair<int,int> > memory;
    int memory_size = 0;
    while(M--)
    {
        cin>>K;
        //if K is not in memory
        bool in_memory = false;
        for(list<pair<int,int> >::iterator it = memory.begin(); it != memory.end(); ++it)
        {
            if(it->first == K)
            {
                hit++;
                it->second++;
                list<pair<int,int> >::iterator tmp_it;
                tmp_it = it;
                if(it != memory.begin())
                {
                   it--;
                   if(it->second <= tmp_it->second) 
                   {
                        pair<int,int> tmp_data = *it;
                        *it = *tmp_it;
                        *tmp_it = tmp_data;
                   }
                } 
                in_memory = true; 
                break;
            }
        } 
        //if not in memory
        if(!in_memory)        
        {
            miss++;
            if(memory_size < P)
            {
                memory.push_back(make_pair(K,1));           
                memory_size++;
            }
            else
            {
                memory.pop_back();    
                memory.push_back(make_pair(K,1));           
            }
        } 
    }   
    cout<< hit<<endl;
    cout<< miss<<endl;
    return 0;
}
