#include <iostream>

using namespace std;

class Stack{
int*arr;
int size;
int tos;
public:
    Stack(){
        size=5;
        arr=new int[size];
        tos=0;
    }

    Stack(int _size){
        size=_size;
        arr=new int[size];
        tos=0;
    }

    Stack(const Stack& oldObj){
        size=oldObj.size;
        tos=oldObj.tos;
        arr=new int[size];
        for(int i=0;i<oldObj.tos;i++){
            arr[i]=oldObj.arr[i];
        }
    }

    ~Stack(){
        delete []arr;
    }

    int IsFull(){
    return tos==size;
    }

    void Push(int value){
        if(!IsFull()){
            arr[tos]=value;
            tos++;
        }else
        {
        cout<<"FULL"<<endl;
        }
    }
    int SequentialSearch(int num){
        int i=0,found=0;
        while((!found)&&i<size){
            if(num ==arr[i]){
                found=1;
            }else
            {
                i++;
            }
        }
        if(found){
            return i;
        }else
        {
        return -1;
        }
    }
};



int main()
{
    Stack s1(7);
    s1.Push(10);
    s1.Push(15);
    s1.Push(7);
    s1.Push(9);
    s1.Push(12);
    s1.Push(120);
    s1.Push(-12);
    cout<<s1.SequentialSearch(9)<<endl;

    return 0;
}
