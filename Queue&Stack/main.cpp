#include <iostream>
#include"Queue.h"
#include<fstream>
#include<thread>

using namespace std;

void load(string fileName, Queue<int>& q)
{
    cout<<"thread created"<<endl;
   ifstream in(fileName);
    while(in.good())
    {
        int e;
        string n;
        getline(in,n);
        e = stoi(n);
        q.enqueue(e);
    }
}

int main()
{
    ofstream out("dequeue.txt");
    Queue<int> q;
    thread load_th(load, "enqueue.txt", ref(q));
    load_th.join();
    q.canc(2211);
    /*q.deqeueue(out);
    q.deqeueue(out);
    q.deqeueue(out);
    q.deqeueue(out);
    q.deqeueue(out);
    q.deqeueue(out);*/
    cout<<q;

    return 0;
}
