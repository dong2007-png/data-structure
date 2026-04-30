#include <iostream>
#include <stdio.h>
using namespace std;
struct ThreadNode
{
    char data;
    ThreadNode* lchild,*rchild;
    int ltag,rtag;

};
class ThreadTree
{
private:
    ThreadNode * root;
    void inThread(ThreadNode* p,ThreadNode *&pre);
    ThreadNode* creat(ThreadNode* p);
    ThreadNode* next(ThreadNode* p);
    void destroy(ThreadNode* p);
public:
    ThreadTree()
    {
        root=NULL;
        root=creat(root);
        ThreadNode* pre=NULL;
        inThread(root,pre);
        if (pre!=NULL) pre->rtag=1;
    }
    ~ThreadTree()
    {
        destroy(root);
    }
    void inOrder();
};



ThreadNode* ThreadTree::creat(ThreadNode* p){
    char ch;
    cin>>ch;
    if (ch=='#')
    {
        p=NULL;
    }else
    {
        p->data=ch;
        p->ltag=0;
        p->rtag=0;
        p->lchild=creat(p->lchild);
        p->rchild=creat(p->rchild);
        ThreadNode* pre;
        inThread(p,pre);

    }
    return p;

};

void ThreadTree::inThread(ThreadNode* p,ThreadNode *&pre)
{
    if (p==NULL) return;
    inThread(p->lchild,pre);
    if (p->lchild==NULL)
    {
        p->ltag=1;
        p->lchild=pre;
    }
    if (pre!=NULL&&pre->rchild==NULL)
    {
        pre->rtag=1;
        pre->rchild=p;
    }
    pre=p;
    inThread(p->rchild,pre);

}

void ThreadTree::inOrder()
{
    ThreadNode* p=root;
    if (p==NULL) return ;
    while (p->ltag==0) p=p->lchild;
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=next(p);
    }

}

ThreadNode* ThreadTree::next(ThreadNode* p)
{
    if (p==NULL) return NULL;
    if (p->rtag==1)
    {
        return p->lchild;
    }else
    {
        p=p->rchild;
        while (p->ltag==0) p=p->lchild;
    }
    return p;
}

void ThreadTree::destroy(ThreadNode* p)
{
    if (p==NULL) return;
    while (p->ltag==0) p=p->lchild;
    ThreadNode* q;
    while (p!=NULL)
    {
        q=next(p);
        delete p;
        p=q;
    }


}

int main()
{
    ThreadTree t;
    t.inOrder();
    cout<<endl;


}




