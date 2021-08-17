#include<iostream>
using namespace std;

struct s10{
    s10 *w; int x;
};

struct s9{
    int y; s9 *z;
};

struct s8{
    s10 *t; int u; s9 *v;
};

struct s6{
    int n; char o; s8 *p;
};

struct s7{
    s6 *q; int r; s7 *s;
};



struct s5{
    int l; s7 *m;
};

struct s4{
    s6 *j; s5 *k;
};

struct s3{
    s4 *g; s3 *h; s5 *i;
};

struct s2{
    char e; s3 *f;
};

struct s1{
    s1 *a; int b; s2 *c; s1 *d;
};

int main(){
    s1 level1;
    level1.c = new s2;
    level1.c->f = new s3;
    level1.c->f->g = new s4;
    level1.c->f->g->j = new s6;
    level1.c->f->g->k = new s5;
    level1.c->f->g->k->m = new s7;
    level1.c->f->g->j->p = new s8;
    level1.c->f->g->j->p->t= new s10;
    level1.c->f->g->j->p->v= new s9;
    
    cin >> level1.b >> level1.c->f->g->k->m->r >> level1.c->f->g->j->p->u;

    if(level1.c->f->g->j->p->u % 2){
        level1.c->f->g->j->p->v->y = level1.b;
        level1.c->f->g->j->p->t->x = level1.c->f->g->k->m->r;
    } else{
        level1.c->f->g->j->p->t->x =level1.b;
        level1.c->f->g->j->p->v->y = level1.c->f->g->k->m->r;
    }
    
    cout << level1.b << " " << level1.c->f->g->k->m->r << " " << level1.c->f->g->j->p->u << " " << level1.c->f->g->j->p->t->x << " "
    << level1.c->f->g->j->p->v->y << endl;

    delete level1.c->f->g->j->p->v, level1.c->f->g->j->p->t, level1.c->f->g->j->p, level1.c->f->g->k->m, level1.c->f->g->k = new s5, level1.c->f->g->j, level1.c->f->g,  level1.c->f;
}