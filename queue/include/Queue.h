#define QUEUE_H

#include<iostream>

using namespace std;

template <class T>
class queue
{
    private:

        int length;
        int nElements;
        int tail = -1;

        T* coda;

    public:
        queue<T>(int maxElements) : length(maxElements) {
        coda = new T [length];
        for(int i=0;i<length;i++)coda[i]=0;
        nElements=0;
        }

        queue() : queue(5) {}

        void enqueue(T data)
        {
            if(this->isFull())
            {
                return;
            }
            else if(this->isEmpty())
            {
                tail=0;
                coda[tail]= data;
                tail++;
                nElements++;
                return;
            }
            else
            {
             if(coda[tail-1]==0)tail-=1;
             coda[tail]=data;
             nElements++;
             tail++;
             return;
            }
        }

        int search(T toFind)
        {
          for(int i =0;i<length;i++)
            if(coda[i]==toFind)return i;
          return -1;
        }

        void dequeu(int rIndex)
        {
            if(nElements==0)
                return;
            else
            {
                coda[rIndex]=0;
                for(int i = rIndex;i<length-1;i++)
                {
                    coda[i]=coda[i+1];
                    coda[i+1]=0;
                }
                nElements--;
            }
        }

        void dequeu()
        {
            if(nElements==0)
                return;
            else
            {
                coda[0]=0;
                for(int i = 0;i<length-1;i++)
                {
                    coda[i]=coda[i+1];
                    coda[i+1]=0;
                }
                nElements--;
            }


        }

        bool isFull()
        {
          if(tail == length)return 1;
          else return 0;
        }

        bool isEmpty()
        {
          if(tail == -1)return 1;
          else return 0;
        }

        friend ostream& operator<<(ostream& out, const queue& q)
        {
            out<<"Coda di lunghezza: "<<q.length<<endl;
            for(int i=0;i<q.length;i++)
                out<<q.coda[i]<<endl;
            return out;
        }

        ~queue()
        {
            delete [] coda;
        }


};

