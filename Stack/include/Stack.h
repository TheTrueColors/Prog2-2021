#ifndef STACK_H
#define STACK_H

using namespace std;

template <class T>
class Stack
{
     private:

        int length;
        int nElements;
        int tail;

        T* stack;

    public:
        Stack<T>(int maxElements) : length(maxElements) {
        stack = new T [length];
        tail= length;
        for(int i=0;i<length;i++)stack[i]=0;
        nElements=0;
        }

        Stack() : Stack(5) {}

        void push(T data)
        {
            if(this->isFull())
            {
                return;
            }
            else if(this->isEmpty())
            {
                tail=length-1;
                stack[tail]= data;
                tail--;
                nElements++;
                return;
            }
            else
            {
             if(stack[tail+1]==0)tail-=1;
             stack[tail]=data;
             nElements++;
             tail--;
             return;
            }
        }

        int search(T toFind)
        {
          for(int i =0;i<length;i++)
            if(stack[i]==toFind)return i;
          return -1;
        }

        void pop(int rIndex)
        {
            if(nElements==0)
                return;
            else
            {
                for(int i = 0;i<length-1;i++)
                {
                    stack[i]=stack[i+1];
                    stack[i+1]=0;
                }
                nElements--;
            }
        }

        void pop()
        {
            if(nElements==0)
                return;
            else
            {
                stack[length]=0;
                for(int i = length;i>0;i--)
                {
                    stack[i]=stack[i-1];
                    stack[i-1]=0;
                }
                nElements--;
            }


        }

        bool isFull()
        {
          if(tail == 0)return 1;
          else return 0;
        }

        bool isEmpty()
        {
          if(tail == length)return 1;
          else return 0;
        }

        friend ostream& operator<<(ostream& out, const Stack& s)
        {
            out<<"Stack di lunghezza: "<<s.length<<endl;
            for(int i=0;i<s.length;i++)
                out<<s.stack[i]<<endl;
            return out;
        }

        ~Stack()
        {
            delete [] stack;
        }
};

#endif // STACK_H
