//codevs1285 宠物收养所
//by cww97
#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 0xfffffff
#define BASE 1000000
using namespace std;
int ans=0;
struct Node{
    int x,bf,h;//bf=balance factor,h=height
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

    void Insert(int x){_Insert(rt,x);}
    void _Insert (Node *&T,int x){
        if (NULL==T){
            T=(Node*)malloc(sizeof(Node));
            T->x=x;
            T->bf=0;T->h=1;
            T->l=T->r=NULL;
            return ;
        }
        if      (x < T->x) _Insert(T->l,x);
        else if (x > T->x) _Insert(T->r,x);
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

    void GetPet(int x){//get pet or person
        if (NULL==rt){return ;}
        int small=0,large=INF;
        //printf("x=%d\n",x);
        int flag;
        if (Find(rt,x,small,large)){
            printf("find %d\n",x);
            _Delete(rt,x);
        }else if (small==0)flag=1;
        else if (large==INF)flag=0;
        else if (large-x<x-small)flag=1;
        else flag=0;

        if (!flag){//choose large
            _Delete(rt,small);
            ans=(ans+x-small)%BASE;
        }else {
            _Delete(rt,large);
            ans=(ans+large-x)%BASE;
        }
    }
    bool Find(Node *T,int x,int &small,int &large){
        if (NULL==T)return 0;
        if (x==T->x)return 1;
        if (x<T->x){
            large=min(large,T->x);
            return Find(T->l,x,small,large);
        }else{
            small=max(small,T->x);
            return Find(T->r,x,small,large);
        }
    }
    void _Delete(Node *&T,int x){
        if (NULL==T)return ;
        if       (x < T->x){//y at left
            _Delete(T->l,x);
            T->bf=BF(T->l,T->r);
            if (T->bf<-1){
                if (1==T->r->bf)T=RLrorate(T);
                else T=Lrorate(T);//bf==0 or -1
            }
        }else if (x > T->x){//y at right
            _Delete(T->r,x);
            T->bf=BF(T->l,T->r);
            if (T->bf>1){
                if (-1==T->l->bf)T=LRrorate(T);
                else T=Rrorate(T);//bf==0 or 1
            }
        }else {//here is x
            if (T->l&&T->r){//left &&right
                Node *t=T->l;
                while (t->r)t=t->r;
                T->x=t->x;
                _Delete(T->l,t->x);
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
        printf("%d ",T->x);
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
    freopen("fuck.in","r",stdin);
    int n,x,op,a=0,b=0;
    scanf("%d",&n);
    AVLTree T; T.Init();
    for (;n--;){
        scanf("%d%d",&op,&x);
        //if pets>people put pets into the tree
        //else put people into the tree
        if (op==0){//come a pet
            a++;
            if (a>b)T.Insert(x);//more pet
            else T.GetPet(x);//more people
        }else{//come a person
            b++;
            if (a<b)T.Insert(x);//more people
            else T.GetPet(x);//more pet
        }
    }
    printf("%d\n",ans%BASE);
    T.Free();
    return 0;
}
