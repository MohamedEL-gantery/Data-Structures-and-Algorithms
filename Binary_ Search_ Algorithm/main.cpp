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

    int BinarySearch(int num){
        int found=0;
        int low=0;
        int high=size;
        int mid;
        while(!(found)&&(low<=high)){
            mid=(high+low)/2;
            if(arr[mid]>num){
               high=mid-1;
            }
            else if(arr[mid]<num){
                low=mid+1;
            }
            else
            {
                found=1;
            }
        }
         if(found){
                return mid;
            }
            else
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
    s1.Push(20);
    s1.Push(25);
    s1.Push(30);
    s1.Push(35);
    s1.Push(40);

    int num;
    cout<<"Enter Number : "<<endl;
    cin>>num;
    int result=s1.BinarySearch(num);

    if(result == -1){
        cout<<"Number not found"<<endl;
    }
    else{
        cout<<"Number: "<<num<<" At index: "<<result<<endl;
    }



    return 0;
}
