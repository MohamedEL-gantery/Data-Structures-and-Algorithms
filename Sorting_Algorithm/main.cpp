#include<iostream>
using namespace std;

class Stack{
private:
    int* arr;
    int size;
    int tos;

    void Swap(int&x,int&y){
    int temp=x;
    x=y;
    y=temp;
    }
public:

    Stack(){
    size=0;
    tos=0;
    arr=new int [size];
    }

    Stack(int _size){
    size=_size;
    tos=0;
    arr=new int [size];
    }

    Stack(const Stack& oldObj){
    size=oldObj.size;
    tos=oldObj.tos;
    arr=new int[size];
    for(int i=0 ; i<oldObj.tos ;i++){
        arr[i]=oldObj.arr[i];
    }
    }


    ~Stack(){
    delete [] arr;
    }

    int IsFull(){
    return tos==size;
    }

   void Puah(int value){
    if(!IsFull()){
        arr[tos]=value;
        tos++;
    }else{
     cout<<"Full"<<endl;
    }
   }

   void SelectonSorting(){
   int i,j,min;
   for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(i!=min){
                Swap(arr[i],arr[min]);
            }
    }
   }

   void BubbleSorting(){
   int i,j,swapped;
   for(i=1;i<size;i++){
    swapped=0;
    for(j=0;j<size-i;j++){
        if(arr[j]>arr[j+1]){
            Swap(arr[j],arr[j+1]);
            swapped=1;
        }
    }
    if(!swapped){
        break;
        }
    }
   }

   void InsertionSorting(){
   int i,j,value;
   for(i=1;i<size;i++){ //10,60,80,90
    value=arr[i];//10
    j=i-1;//2
    while(j>=0&&arr[j]>value){
        arr[j+1]=arr[j];
        j=j-1;//-1
    }
    arr[j+1]=value;
    }
   }

   void Print(){
   for(int i=0;i<size;i++){
    cout<<arr[i]<<"\t";
    }
   }

};

int main()
{
    int num;
    cout<<"Enter Size : "<<endl;
    cin>>num;

    Stack s(num);

    for(int i=0;i<num;i++){
        int value;
        cout<<"Enter Value for arr :"<<i<<endl;
        cin>>value;
        s.Puah(value);
    }

    s.SelectonSorting();
    cout<<"Selection"<<endl;
    s.Print();

    s.InsertionSorting();
    cout<<"Insertion"<<endl;
    s.Print();

    s.BubbleSorting();
    cout<<"Bubble"<<endl;
    s.Print();

    return 0;
}
