#include<iostream>
using namespace std;
struct Binode
{
    char data;
    Binode *lchild, *rchild;
};
class Bitree
{
private:
    Binode *root;
public:
    Bitree()
    {
        root = creat(root);

    }
    ~Bitree()
    {
        release(root);
    }
    Binode* creat(Binode* bt);
    void release(Binode* bt);
    Binode* preorder(Binode* bt);
    Binode* inorder(Binode* bt);
    Binode* postorder(Binode* bt);
    Binode* getroot(Binode* bt)
    {
        return root;
    }

};
Binode* Bitree::creat(Binode* bt)
{
    char ch;
    cin>>ch;
    if (ch=='#')
    {
        return NULL;
    }else
    {
        bt=new Binode;
        bt->data=ch;
        bt->lchild=creat(bt->lchild);
        bt->rchild=creat(bt->rchild);

    }
    return bt;

}

void Bitree::release(Binode* bt)
{
    if (bt==NULL)
    {
        return;
    }
    release(bt->lchild);
    release(bt->rchild);
    delete bt;
}

Binode* Bitree::preorder(Binode* bt)
{
    if (bt!=NULL)
    {
        cout<<bt->data<<" ";
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
    return bt;
}
Binode* Bitree::inorder(Binode* bt)
{
    if (bt!=NULL)
    {
        inorder(bt->lchild);
        cout<<bt->data<<" ";
        inorder(bt->rchild);

    }
    return bt;
}
Binode* Bitree::postorder(Binode* bt)
{
    if (bt!=NULL)
    {
        postorder(bt->lchild);
        postorder(bt->rchild);
        cout<<bt->data<<" ";
    }
    return bt;
}

