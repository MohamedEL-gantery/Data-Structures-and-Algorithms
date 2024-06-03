#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Employee{
char name[30];
int salary;
int id;
public:
    Employee* pRight;
    Employee* pLeft;

    Employee(){
    name[0] = '\0';
    salary=0;
    id=0;
    pRight=NULL;
    pLeft=NULL;
    }

    Employee(const char* _name,int _salary,int _id){
    strcpy(name,_name);
    salary=_salary;
    id=_id;
    pRight=NULL;
    pLeft=NULL;
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

class BinaryTree{
    private:
    Employee*pParent;

    Employee*insert(Employee*pRoot,Employee*data){
        if(pRoot==NULL){
            data->pRight=NULL;
            data->pLeft=NULL;
            return data;
        }else
        {
        if(data->GetId()<=pRoot->GetId()){
            pRoot->pLeft=insert(pRoot->pLeft,data);
        }
        else
        {
            pRoot->pRight=insert(pRoot->pRight,data);
        }
        return pRoot;
        }

    }

    void InOrder(Employee*pRoot){
        if(pRoot){
            InOrder(pRoot->pLeft);
            cout<<"id: "<<pRoot->GetId()<<endl;
            InOrder(pRoot->pRight);
        }
    }

    void PreOrder(Employee*pRoot){
        if(pRoot){
            cout<<"id: "<<pRoot->GetId()<<endl;
            PreOrder(pRoot->pLeft);
            PreOrder(pRoot->pRight);
        }
    }

    void PostOrder(Employee*pRoot){
        if(pRoot){
            PostOrder(pRoot->pLeft);
            PostOrder(pRoot->pRight);
             cout<<"id: "<<pRoot->GetId()<<endl;
        }
    }

    int getHeight(Employee*pRoot){
        if(pRoot==NULL){
            return 0;
        }
        else
            {
                int x=getHeight(pRoot->pLeft);
                int y=getHeight(pRoot->pRight);
                if(x>y){
                    return x+1;
                }
                else
                {
                    return y+1;
                }
            }
    }

     Employee*deleteTree(Employee*pRoot,int key){
        Employee*p,*p2;
        if(!pRoot){
            return pRoot;
        }

        if(pRoot->GetId()==key){
            if(pRoot->pLeft==pRoot->pRight){
                delete pRoot;
                return NULL;
            }else if(pRoot->pLeft==NULL){
                p=pRoot->pRight;
                delete pRoot;
                return p;
            }else if(pRoot->pRight==NULL){
                p=pRoot->pLeft;
                delete pRoot;
                return p;
            }else
            {
                p2=pRoot->pRight;
                p=pRoot->pRight;
                while(p->pLeft){
                    p=p->pLeft;
                }
                p->pLeft=pRoot->pLeft;
                delete pRoot;
                return p2;
            }
        }
        if(pRoot->GetId()<key){
            pRoot->pRight=deleteTree(pRoot->pRight,key);
        }else
        {
            pRoot->pLeft=deleteTree(pRoot->pLeft,key);
        }
        return pRoot;
     }
    public:
        BinaryTree(){
        pParent=NULL;
        }

        void InsertNode(Employee*data){
        pParent=insert(pParent,data);
        }

        void InOrderTraverse(){
        InOrder(pParent);
        }

        void PreOrderTraverse(){
        PreOrder(pParent);
        }

        void PostOrderTraverse(){
        PostOrder(pParent);
        }

        Employee*SearchTree(int key){
            Employee*pRoot;
            pRoot=pParent;

            while(pRoot&&key!=pRoot->GetId()){
                if(key<pRoot->GetId()){
                    pRoot=pRoot->pLeft;
                }
                else
                {
                    pRoot=pRoot->pRight;
                }
            }
            return pRoot;
        }

        int GetTreeHeight(){
            return getHeight(pParent);
        }

        /*void CountLeaves(){
        cout<<pow(2,GetTreeHeight())<<endl;
        }*/

        void DeleteNode(int key){
            pParent=deleteTree(pParent,key);
        }

};

int main()
{
    Employee*p1;
    p1=new Employee("ahmed",5000,2);
    Employee*p2;
    p2=new Employee("mohamed",5000,1);
    Employee*p3;
    p3=new Employee("abdo",5000,100);
    Employee*p4;
    p4=new Employee("hh",4000,700);

    BinaryTree b1;

    b1.InsertNode(p1);
    b1.InsertNode(p2);
    b1.InsertNode(p3);
    b1.InsertNode(p4);


   b1.InOrderTraverse();
   cout<<"____"<<endl;
   b1.PostOrderTraverse();
   cout<<"____"<<endl;
   b1.PreOrderTraverse();

    b1.DeleteNode(2);
    cout<<"____"<<endl;
    b1.InOrderTraverse();

    return 0;
}
