#include<iostream>
#include<stack>
using namespace std;

class tree
{
public:
    tree *lchild;
    tree *rchild;
    long date;
};

void add(tree *S,int flag)
{
    tree *s=S;
    int q=flag;
    tree *N=new tree;
    N->lchild=NULL;
    N->rchild=NULL;
    long num;
    cout<<"******************************"<<endl;
    cout<<endl;
    cout<<"注：每次只能添加一个结点"<<endl;
    cout<<"由于能力有限，结点数据类型仅限不太大的整数"<<endl;
    cout<<endl;
    cout<<"请输入要添加的结点：";
    cin>>num;
    cout<<endl;
    N->date=num;
    if(q==0)
    {
        s->date=num;
    }
    else
    {
        for(;;)
        {
            if(num<s->date)
            {
                if(s->lchild!=NULL)
                {
                    s=s->lchild;
                    continue;
                }
                else
                {
                    s->lchild=N;
                    break;
                }
            }
            if(num>s->date)
            {
                if(s->rchild!=NULL)
                {
                    s=s->rchild;
                    continue;
                }
                else
                {
                    s->rchild=N;
                    break;
                }
            }
        }
    }
    cout<<"插入成功！"<<endl;
    cout<<endl;
    cout<<"******************************"<<endl;
}

void traversal(tree *S,int flag,int sign)
{
    tree *s=S;
    int q=flag;
    int si=sign;
    int temp=0;
    if(q==0)
    {
        cout<<"******************************"<<endl;
        cout<<"        此二叉树为空！"<<endl;
        cout<<"******************************"<<endl;
    }
    else
    {
        cout<<"******************************"<<endl;
        cout<<"先序遍历二叉树：";

        stack<tree*> z;
        for(;;)
        {
            while((s->lchild!=NULL)||(s->rchild!=NULL))
            {
                if(s->rchild)
                {
                    z.push(s);
                    if(s->lchild==NULL)
                    {
                        break;
                    }
                }
                cout<<s->date<<" ";
                temp++;
                if(s->lchild)
                {
                    s=s->lchild;
                }

            }
            cout<<s->date<<" ";
            temp++;
            if(temp==si)
                break;
            s=z.top();
            z.pop();
            s=s->rchild;
        }
        cout<<endl;
        cout<<"******************************"<<endl;
    }
}

int main()
{
    tree *S=new tree;
    S->lchild=NULL;
    S->rchild=NULL;
    cout<<"******************************"<<endl;
    int flag=0;
    int sign=0;
    for(;;)
    {
        cout<<"插入结点请按1"<<endl;
        cout<<"遍历二叉树请按2"<<endl;
        cout<<"结束程序请按0"<<endl;
        int n;
        cout<<endl;
        cout<<"请输入指令：";
        cin>>n;
        if(n==1)
        {
            add(S,flag);
            flag=1;
            sign++;
        }
        if(n==2)
        {
            traversal(S,flag,sign);
        }
        if(n==0)
        {
            cout<<"******************************"<<endl;
            cout<<"*********程 序 结 束**********"<<endl;
            cout<<"******************************"<<endl;
            return 0;
        }
        if(n!=0&&n!=1&&n!=2)
        {
            cout<<"******************************"<<endl;
            cout<<"  输入错误，请重新输入......"<<endl;
            cout<<"******************************"<<endl;
        }
    }
    return 0;
}
