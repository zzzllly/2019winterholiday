#include<iostream>
using namespace std;
class student
{
public:
    char name;
    int age;
    student *next;

};
student *creatlist(int n)
{

    student *h=new student;
    student *p,*s;
    p=h;
    int i;
    for(i=0; i<n; i++)
    {
        s=new student;
        cout<<"input name and age:";
        cin>>s->name>>s->age;
        s->next=NULL;
        p->next=s;
        p=p->next;
    }

    return h;

}

void increase(student *h)
{
    cout<<"which node do you want insert"<<endl;
    int n,i;
    cin>>n;
    student *p=h;
    for(i=0; i<n-1; i++)
    {
        p=p->next;
    }
    student *s=new student;
    cout<<"input the name you want to insert:";
    cin>>s->name>>s->age;
    s->next=p->next;
    p->next=s;


}

void removee(student *h)
{
    cout<<"which node do you want to delete£º";
    int n,i;
    cin>>n;
    student *p=h;
    for(i=0; i<n-1; i++)
    {
        p=p->next;
    }
    p->next=p->next->next;


}

void change(student *h)
{
    cout<<"input the name you want change:";
    char namee;
    cin>>namee;
    student *p=h->next;
    while(p)
    {
        if(p->name==namee)
        {
            int n;
            cout<<"input the age you want to become£º";
            cin>>n;
            p->age=n;
            //    break;
        }
        p=p->next;
    }

}

void output(student *h)
{
    student *p=h->next;
    while(p)
    {
        cout<<"output the name and age:";
        cout<<p->name<<" "<<p->age<<endl;
        p=p->next;
    }

}
int main()
{
    int n;
    cout<<"n=";
    cin>>n;
    student *h= creatlist(n);
    increase(h);
    removee(h);
    change(h);
    output (h);
    return 0;
}
