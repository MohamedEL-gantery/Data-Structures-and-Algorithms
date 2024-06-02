#include <iostream>
#include <cstring>

using namespace std;

class Employee{
char name[30];
int salary;
int id;
public:
    Employee* pNext;
    Employee* pPervious;

    Employee(){
    name[0] = '\0';
    salary=0;
    id=0;
    pNext=NULL;
    pPervious=NULL;
    }

    Employee(const char* _name,int _salary,int _id){
    strcpy(name,_name);
    salary=_salary;
    id=_id;
    pNext=NULL;
    pPervious=NULL;
    }

    void SetName(const char* _name){
        strcpy(name, _name);
    }

    void SetId(int _id){
        id=_id;
    }

    void SetSalary(int _salary){
        salary=_salary;
    }

    const char* GetName() const{
        return name;
    }

    int GetSalary(){
        return salary;
    }

    int GetId(){
        return id;
    }

    void PrintEmployee() const {
        cout<<name<<endl;
        cout<<id<<endl;
        cout<<salary<<endl;
    }
};

class LinkedList{
protected:
    Employee*pStart;
    Employee*pEnd;
public:

LinkedList(){
    pStart=pEnd=NULL;
}

void AddList(Employee* pItem){
    if(!pStart){
        pItem->pNext=NULL;
        pItem->pPervious=NULL;
        pStart=pEnd=pItem;
    }
    else
        {
        pEnd->pNext=pItem;
        pItem->pPervious=pEnd;
        pItem->pNext=NULL;
        pEnd=pItem;
        }
}

void InsertList(Employee* pNode){
    Employee*pTemp;
    if(pStart==NULL){
        AddList(pNode);
        }else
        {
            pTemp=pStart;
            while(pTemp&&pTemp->GetId()<pNode->GetId()){
                pTemp=pTemp->pNext;
            }
            if(!pTemp){
                AddList(pNode);
            }
            else if(pTemp==pStart)
                {
                    pNode->pNext=pStart;
                    pTemp->pPervious=NULL;
                    pStart->pPervious=pNode;
                    pStart=pNode;
                }
            else
                {
                pTemp->pPervious=pNode;
                pNode->pNext=pTemp;
                pNode->pPervious=pTemp->pPervious;
                pTemp->pPervious->pNext=pNode;
                }
            }
}

Employee* SearchList(int key){
    Employee* pItem=NULL;
    pItem=pStart;
    while(pItem&&pItem->GetId()!=key){
        pItem=pItem->pNext;
    }
    return pItem;
}

void DisplayAll(){
    Employee* pItem;
    pItem=pStart;
    while(pItem){
        pItem->PrintEmployee();
        pItem=pItem->pNext;
    }

}

int DeleteList(int id){
    Employee*pItem;
    int retFlag=1;
    pItem=SearchList(id);
    if(!pItem){
        retFlag=0;
    }
    else
    {
        if(pStart==pEnd){
            pStart=pEnd=NULL;
        }
        else if(pItem==pStart)
            {
                pStart=pItem->pNext;
                pStart->pPervious=NULL;
            }
        else if(pItem==pEnd)
            {
                pEnd=pItem->pPervious;
                pEnd->pNext=NULL;
            }else
            {
                pItem->pPervious->pNext=pItem->pNext;
                pItem->pNext->pPervious=pItem->pPervious;
            }
            delete pItem;
    }
    return retFlag;
}
};

class Stack:private LinkedList{
public:
    Stack():LinkedList(){}

    void Push(Employee*e){
    AddList(e);
    }

    Employee* Pop(){
    Employee* pNode;
    pNode=pEnd;
    if(pEnd){
        if(pEnd==pStart){
            pEnd=pStart=NULL;
        }else{
            pEnd=pEnd->pPervious;
            pEnd->pNext=NULL;
            }
        }
     return pNode;
    }

    Employee* SearchStack(int key){
    return SearchList(key);
    }

    int DeleteStack(int key){
    return DeleteList(key);
    }

    void DisplayAll(){
    LinkedList::DisplayAll();
    }
};

int main()
{
    Employee* item;
    item=new Employee("ahmed",5000,2);
    Employee* p;
    p=new Employee("mohamed",5000,1);
    Employee*p1;
    p1=new Employee("abdo",5000,100);

    Stack s1;

    s1.Push(item);
    s1.Push(p);
    s1.Push(p1);

    s1.DisplayAll();

    s1.Pop();

    s1.DisplayAll();



    return 0;
}
