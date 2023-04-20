#include <iostream>
using namespace std;

class linklist
{
private :
    struct node {
        int data;
        node *next;
    }*head;

public:
    linklist()
    {
        head=NULL;
    }

    void append(int num)
    {
        node *t=head,*temp;
        if(head==NULL) {
            t=new node;
            t->data=num;
            t->next=NULL;
            head=t;
        }

        else {
            while(t->next!=NULL)
                t=t->next;

            temp=new node;
            temp->data=num;
            temp->next=NULL;
            t->next=temp;
        }
    }

    void split(linklist a,linklist b)
    {
        node *temp=head;
        while(temp!=NULL) {
            if(temp->data>=0)
                a.append(temp->data);
            else
                b.append(temp->data);
            temp=temp->next;
        }
    }


    void display()
    {
        node *t=head;
        while(t!=NULL) {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    ~linklist()
    {
        node *t;
        while(head!=NULL) {
            t=head->next;
            delete head;
            head=t;
        }
    }
};

int main()
{
    linklist A,B,C;
    A.append(7);
    A.append(-5);
    A.append(3);
    A.append(-1);
    A.append(20);
    A.append(1);
    A.append(78);
    A.append(0);
    A.append(56);
    A.append(-91);
    A.append(10);
    A.append(15);
    A.append(-661);
    A.append(0301);
    A.append(61565);
    A.append(-561);
    A.split(B,C);
    cout<<"elements of B:\n";
    B.display();
    cout<<"elements of C:\n";
    C.display();
    return 0;
}
