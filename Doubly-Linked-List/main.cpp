#include <iostream>
#include <cstring>

using namespace std;

class Empolyee{
char name[30];
int salary;
int id;
public:
    Empolyee* pNext;
    Empolyee* pPervious;

    Empolyee(){
    name[0] = '\0';
    salary=0;
    id=0;
    pNext=NULL;
    pPervious=NULL;
    }

    Empolyee(const char* _name,int _salary,int _id){
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
    Empolyee*pStart;
    Empolyee*pEnd;
public:

LinkedList(){
    pStart=pEnd=NULL;
}

void AddList(Empolyee* pItem){
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

void InsertList(Empolyee* pNode){
    Empolyee*pTemp;
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

Empolyee* SearchList(int key){
    Empolyee* pItem=NULL;
    pItem=pStart;
    while(pItem&&pItem->GetId()!=key){
        pItem=pItem->pNext;
    }
    return pItem;
}

void DisplayAll(){
    Empolyee* pItem;
    pItem=pStart;
    while(pItem){
        pItem->PrintEmployee();
        pItem=pItem->pNext;
    }

}

int DeleteList(int id){
    Empolyee*pItem;
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

int main()
{
    LinkedList ls;
    Empolyee* item;
    item=new Empolyee("ahmed",5000,2);
    Empolyee* p;
    p=new Empolyee("mohamed",5000,1);
    Empolyee*p1;
    p1=new Empolyee("abdo",5000,100);


    ls.AddList(item);
    ls.AddList(p);
    ls.AddList(p1);


    ls.DisplayAll();


    return 0;
}




