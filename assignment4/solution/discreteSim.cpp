#include <iostream>
#include <vector>
#include "minMaxHeap.hpp"

class microbe
{
    public:
        //identity
        int mic_id;
        int initial_strength;
        int strength;
        int n;
        //is the microbe infected
        bool is_infected;
        //is the microbe dead
        bool is_dead;

        microbe(int iden,int str)
        {
            mic_id = iden;
            strength = str;
            initial_strength = str;
            n = (((mic_id + strength) * 29 ) % 37) + 7;
            is_infected = false;
            is_dead = false;
        }

};

class event
{
    public:
        //time at which the evnet will occur
        int time;
        //birth is same as divison
        //birth - '2', infection - '1', death - '0'
        int type;
        //microbe identity
        int mic_id;

        event(int t,int ty,int id)
        {
            time = t;
            type = ty;
            mic_id = id;
        }

        bool operator<(const event& ev)
        {
           if(this->time < ev.time)
           {
              return true;
           }
           else if(this -> time == ev.time)
           {
               //two events on same microbe
               if(this -> mic_id == ev.mic_id)
               {
                   if(this -> type < ev.type)
                   {
                       return true;
                   }
                   else
                   {
                       return false;
                   }
               }
               //divison of multiple microbes 
               else if(this -> mic_id < ev.mic_id)
               {
                   return true;
               }
               else
               {
                   return false;
               }

           }
           else
           {
               return false;
           }
        } 


};

class Pred: public Predicate<event> {
    public:
    int id_to_delete; 
    Pred(int id)
    {
        id_to_delete = id;
    }
    bool toDelete (event ev) {
    return (ev.mic_id == id_to_delete);
  }
};


int main()
{
    int N;
    cin >> N;
    vector<microbe> microbe_vector;
    MinMaxHeap<event> event_heap;
    for(int i = 0;i < N;i++)
    {
        int str;
        cin >> str;
        microbe tmp_mic(i,str);
        microbe_vector.push_back(tmp_mic);
    } 
    int M;
    cin >> M;
    while(M--)
    {
        int id,time;
        cin >> id;
        cin >> time;
        // 1 is infection type of event
        event tmp_ev(time,1,id);
        event_heap.insert(tmp_ev);
    }
    int T;
    cin >> T;

    //start the simulation
    //add the initial division events;
    for(int i = 0;i < microbe_vector.size();i++)
    {
        // 2 is birth or divison event
        event tmp_ev(microbe_vector[i].n,2,microbe_vector[i].mic_id);
        event_heap.insert(tmp_ev);
    }
    int t = 0;
    event ev = event_heap.getMin();
    t = ev.time;
    while(t <= T)
    {
        //cout << "Time" << t << endl;
        event_heap.deleteMin();
        //death
        if(ev.type == 0)
        {
            //deletion is not really needed from microbe_vector
            microbe_vector[ev.mic_id].is_dead = true;
            Pred obj(ev.mic_id);
            event_heap.deleteElems(obj);
            cout << "d " << ev.mic_id << " " << t << endl;
        }
        else if(ev.type == 1)
        {
            microbe_vector[ev.mic_id].is_infected = true;
            //delete all other division events
            Pred obj(ev.mic_id);
            event_heap.deleteElems(obj);

            //schedule death
            event tmp_ev(t + microbe_vector[ev.mic_id].strength,0,ev.mic_id); 
            event_heap.insert(tmp_ev);

            //cout <<"i "<< ev.mic_id << " " << t << endl;
        }
        //birth event
        else if(ev.type == 2)
        {
            //decrement strength of parent
            microbe_vector[ev.mic_id].strength -= 1;
            if(microbe_vector[ev.mic_id].strength == 0) 
            {
               //schedule death
               event tmp_ev(microbe_vector[ev.mic_id].n + t,0,ev.mic_id);
               event_heap.insert(tmp_ev);
            }
            else
            {
                //schedule next division
                event tmp_ev1(microbe_vector[ev.mic_id].n + t,2,ev.mic_id);
                event_heap.insert(tmp_ev1);
            }

            //birth of child
            int new_id = microbe_vector.size();
            microbe tmp_mic(new_id,microbe_vector[ev.mic_id].initial_strength);
            microbe_vector.push_back(tmp_mic);
            //schedule his division
            event tmp_ev(microbe_vector[new_id].n + t,2,new_id);
            event_heap.insert(tmp_ev);
            
            cout << "b " << new_id << " " << t << endl;
        }
        ev = event_heap.getMin();
        t = ev.time;

    }
    int final_pop = 0;
    for(int i = 0;i < microbe_vector.size();i++)
    {
        if(microbe_vector[i].is_dead == false)
        {
            final_pop++;
        }
    }
    cout << final_pop << endl;
             


    return 0;
}
