//poj3481 cww97
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
    int x,y,bf,h;//bf=balance factor,h=height
    Node *l,*r;
};

class AVLTree{
public:
    void Init() { rt = NULL; }
    int H(Node *T){return (T==NULL)?0:T->h;}
    int BF(Node *l,Node *r){//get balance factor
        if (NULL==l && NULL==r) return 0;
        else if (NULL == l) return -r->h;
        else if (NULL == r) return  l->h;
        return l->h - r->h;
    }

    Node *Lrorate(Node *a){//left rorate
        Node *b;
        b=a->r;
        a->r=b->l;
        b->l=a;
        a->h=max(H(a->l),H(a->r)) + 1;
        b->h=max(H(b->l),H(b->r)) + 1;
        a->bf=BF(a->l,a->r);
        b->bf=BF(b->l,b->r);
        return b;
    }
    Node *Rrorate(Node *a){//right rorate
        Node *b;
        b=a->l;
        a->l=b->r;
        b->r=a;
        a->h=max(H(a->l),H(a->r)) + 1;
        b->h=max(H(b->l),H(b->r)) + 1;
        a->bf=BF(a->l,a->r);
        b->bf=BF(b->l,b->r);
        return b;
    }
    Node *LRrorate(Node *a){//left then right
        a->l = Lrorate(a->l);
        Node *c;
        c=Rrorate(a);
        return c;
    }
    Node *RLrorate(Node *a){//right then left
        a->r=Rrorate(a->r);
        Node *c;
        c=Lrorate(a);
        return c;
    }

    void Insert(int x,int y){_Insert(rt,x,y);}
    void _Insert (Node *&T,int x,int y){
        if (NULL==T){
            T=(Node*)malloc(sizeof(Node));
            T->x=x; T->y=y;
            T->bf=0;T->h=1;
            T->l=T->r=NULL;
            return ;
        }
        if      (y < T->y) _Insert(T->l,x,y);
        else if (y > T->y) _Insert(T->r,x,y);
        else return ; //error :the same y

        T->h=max(H(T->l),H(T->r))+1;//maintain
        T->bf=BF(T->l,T->r);

        if (T->bf > 1 || T->bf < -1){//not balanced
            if      (T->bf > 0 && T->l->bf > 0)T=Rrorate(T);
            else if (T->bf < 0 && T->r->bf < 0)T=Lrorate(T);
            else if (T->bf > 0 && T->l->bf < 0)T=LRrorate(T);
            else if (T->bf < 0 && T->r->bf > 0)T=RLrorate(T);
        }
    }

    void Delete(int flag){//flag==1:delete max
        if (NULL==rt){puts("0");return ;}
        Node *t=rt;
        if (flag)while (t->r)t=t->r;
        else     while (t->l)t=t->l;
        printf("%d\n",t->x);
        _Delete(rt,t->y);
    }
    void _Delete(Node *&T,int y){
        if (NULL==T)return ;
        if       (y < T->y){//y at left
            _Delete(T->l,y);
            T->bf=BF(T->l,T->r);
            if (T->bf<-1){
                if (1==T->r->bf)T=RLrorate(T);
                else T=Lrorate(T);//bf==0 or -1
            }
        }else if (y > T->y){//y at right
            _Delete(T->r,y);
            T->bf=BF(T->l,T->r);
            if (T->bf>1){
                if (-1==T->l->bf)T=LRrorate(T);
                else T=Rrorate(T);//bf==0 or 1
            }
        }else {//here is y,,this part is not used in this problem
            if (T->l&&T->r){//left &&right
                Node *t=T;
                while (t->r)t=t->r;
                T->y=t->y;
                T->x=t->x;
                _Delete(T->l,t->y);
                T->bf=BF(T->l,T->r);
                if (T->bf<-1){
                    if (1==T->r->bf)T=RLrorate(T);
                    else T=Lrorate(T);//bf==0 or -1
                }
            }else {//left || right
                Node *t=T;
                if (T->l)T=T->l;
                else if(T->r)T=T->r;
                else {free(T);T=NULL;}
                if (T)free(t);
            }
        }
    }

    //Debug,you will not need it at this problem
    void show(){InOrder(rt);puts("EndShow");}
    void InOrder(Node *T){//print l rt r
        if (NULL==T)return ;
        InOrder(T->l);
        printf("%d:%d ",T->x,T->y);
        InOrder(T->r);
    }
    void Free(){FreeTree(rt);}
    void FreeTree(Node *T){
        if (NULL==T)return ;
        FreeTree(T->l);
        FreeTree(T->r);
        free(T);
    }

private:
    Node *rt;//root
};

int main(){
    //freopen("fuck.in","r",stdin);
    int op,x,y;
    AVLTree T;
    T.Init();
    for (;scanf("%d",&op)==1&&op;){
        if (op==1){
            scanf("%d%d",&x,&y);
            T.Insert(x,y);
        }else if(op==2)T.Delete(1);
        else if (op==3)T.Delete(0);
        else break;//error
        //T.show();
    }
    T.Free();
    return 0;
}
