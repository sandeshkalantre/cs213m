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
   
    //list of pairs (page ID, frequency) 
    list<pair<int,int> > memory;
    //dynamic size of memory 
    int memory_size = 0;
   
    //position of each page in memory
    vector<int> position(N,-1); 
    while(M--)
    {
        cin>>K;
        //if K is in memory
        bool in_memory = false;

        //search for K in memory
        for(list <pair<int,int> >::iterator it = memory.begin(); it != memory.end(); ++it)
        {
            //hit
            if(it -> first == K)
            {
                //update the bool since K is in memory
                in_memory = true; 
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
        
        //if not in memory
        if(!in_memory)        
        {
            miss++;
            if(memory_size < P)
            {
                list < pair<int,int> >::iterator it = memory.end();
                while(it != memory.begin() && it -> second == 1)
                {
                    it--;
                }
                memory.insert(it,make_pair(K,1));           
                memory_size++;
            }
            else
            {
                memory.pop_back();    
                list<pair<int,int> >::iterator it = memory.end();
                while(it != memory.begin() && it -> second == 1)
                {
                    it--;
                }
                memory.insert(it,make_pair(K,1));           
            }
        } 
    }   
    cout<< hit<<endl;
    cout<< miss<<endl;
    return 0;
}
