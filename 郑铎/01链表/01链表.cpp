#include<iostream>
#include<string>
using namespace std;

class L
{
public:
    string A;
    L *next;
};
void add(L *Z)
{
    L *p=Z;
    L *N=new L;
    N->next=NULL;
    while(p->next)
    {
        p=p->next;
    }
    p->next=N;
    string m;
    cout<<"请输入新增链表的内容：";
    cin>>m;
    cout<<endl;
    N->A=m;
    cout<<"添加成功！"<<endl;
}
void out(L *Z)
{
    L *p=Z;
    string m;
    cout<<"请输入您要删除链表的内容：";
    cin>>m;
    while(p->next->A!=m)
    {
        p=p->next;
    }
    p->next=p->next->next;
    cout<<endl;
    cout<<"删除成功！"<<endl;
}
void change(L *Z)
{
    L *p=Z;
    string m;
    cout<<"请输入修改之前链表的内容：";
    cin>>m;
    while(p->next->A!=m)
    {
        p=p->next;
    }
    string nm;
    cout<<"请输入修改之后链表的内容：";
    cin>>nm;
    p->next->A=nm;
    cout<<endl;
    cout<<"修改成功！"<<endl;
}
void show(L *Z)
{
    L *p=Z;
    cout<<"储存内容如下："<<endl;
    while(p->next)
    {
        cout<<p->next->A<<endl;
        p=p->next;
    }
    cout<<"显示完成！"<<endl;
}
int main()
{
    L *Z=new L;
    Z->next=NULL;
    int n;
    for(;;)
    {
        cout<<"************************"<<endl;
        cout<<"请选择你对链表的操作："<<endl;
        cout<<"#增加链表请按1"<<endl;
        cout<<"#删除链表请按2"<<endl;
        cout<<"#修改链表请按3"<<endl;
        cout<<"#显示所有的储存内容请按4"<<endl;
        cout<<"#结束程序请按0"<<endl;
        cout<<"******您的命令：";
        cin>>n;
        cout<<endl;
        if(n==1)
        {
            add(Z);
        }
        if(n==2)
        {
            out(Z);
        }
        if(n==3)
        {
            change(Z);
        }
        if(n==4)
        {
            show(Z);
        }
        if(n==0)
        {
            cout<<"<<<程序已结束>>>"<<endl;
            break;
        }
        if(n>4||n<0)
        {
            cout<<"<<<无此命令，请重新输入>>>"<<endl;
            cout<<endl;
        }
    }
    return 0;
}
