#include <iostream>
#include <fstream>
using namespace std;
class notepad
{
private:
    /* data */
public:
    typedef struct node
    {
        char c;
        node *next = NULL;
    } node, *pn;
    typedef struct row
    {
        pn n;
        row *next = NULL;
    } row, *pr;
    pr r = new row;
    void read(char c[])
    {   
        ifstream in(c);
        if (!in.is_open()) {
        char cmd[50];
        cout << c << ": No such file.\nDo you want to create one?(y/n)" << endl;
        char a=cin.get();
        if (a=='y')
        write(c);
        else if(a!='n')
        cout <<"无效输入.";
        cin.getline(cmd, 50);       
        return;
        }

        int t;
        r->n = new node; // 头结点
        pn p = r->n;
        pr l = r;
        while ((t = in.get()) != -1)
        {
            p->next = new node;
            p = p->next;
            p->c = t;
            if (t == '\n')
            {
                r = r->next = new row;
                p = r->n = new node;
            }
        }
        r = l;
        in.close();
    }

    pr find(int i)
    { // 查找第i行
        pr l = r;
        while (--i){
            if ((l = l->next)==NULL)
            throw 0;
        }            
        return l;
    }

    pn getnext(pr &l, pn &p, int *x)
    {
        if (p->next != NULL)
        {
            p = p->next;
            x[1]++;
        }

        else if (l->next != NULL)
        {
            l = l->next;
            p = l->n->next;
            x[0]++;
            x[1] = 1;
        }
        else
            return NULL;
        return p;
    }
    pr getnext(pr r){
        if ((r=r->next)==NULL)
        throw 0;
        return r;        
    }
    pn getnext(pn p){
        if ((p=p->next)==NULL)
        throw 0;
        return p;        
    }
    void print(int i)
    { // 打印第i行
        pr f = find(i);
        pn p = f->n;
        while (p->next != NULL)
        {
            p = p->next;
            cout << p->c;
        }
    }
    void print(int i, int j)
    { // 打印第i~j行
        for (int x = i; x <= j; x++)
            print(x);
    }
    void insert(int i)
    { // 插入新行于第i行
        pr f = find(i - 1);
        pr r = new row;
        r->n = new node;
        r->n->next = new node;
        r->n->next->c = '\n';
        r->next = f->next;
        f->next = r;
    }
    void insert(int i, int j, char c)
    { // 在第i行第j个字符后插入字符c
        pr f = find(i);
        pn n = f->n;
        while (j--)
            n = getnext(n);
        pn p = new node;
        p->c = c;
        p->next = n->next;
        n->next = p;
    }
    void insert(int i, int j, char c[])
    { // 在第i行第j个字符后插入字符串c
        while (*c != '\0')
        {
            insert(i, j++, *c++);
        }
    }
    void del(int i, int j)
    { // 删除第i行第j个字符
        pr f = find(i);
        pn n = f->n;
        while (--j)
            n = getnext(n);
        pn p = getnext(n);
        n->next = p->next;
        free(p);
    }
    void del(int i, int j, int k)
    { // 删除第i行第j个字符及后的k-1个字符
        while (k--)
            del(i, j);
    }
    void delr(int i)
    { // 删除第i行
        pr f = find(i - 1);
        pr t = getnext(f);
        f->next = t->next;
        free(t);
    }
    void delr(int i, int j)
    { // 删除第i~j行
        int k = j - i + 1;
        while (k--)
            delr(i);
    }
    void nextval(int n[], char c[])
    {
        n[1] = 0;
        n[2] = c[0] == c[1] ? 0 : 1;
        int i = 2;
        int j = 1;
        while (c[i] != 0)
        {
            if (c[i - 1] == c[j - 1])
            {
                i++;
                j++;
                n[i] = j;
                if (c[i - 1] == c[j - 1])
                {
                    n[i] = n[j];
                }
            }
            else if (j != 1)
            {
                j = n[j];
            }
            else
            {
                n[++i] = 1;
                if (c[i - 1] == c[0])
                {
                    n[i] = 0;
                }
            }
        }
    }
    int KMP(int no, char *c, int *x)
    {
        int i = 1;
        int cou = 0;
        char *t = c;
        while (*t++ != '\0')
            cou++;
        int n[cou + 1];
        nextval(n, c);
        pr l = find(no);
        pn p = r->n;
        while (i != cou + 1)
        {

            if (p == NULL)
                return 0;
            if (i == 0 || p->c == *(c + i - 1))
            {
                getnext(l, p, x);
                i++;
            }
            else if (i == 1)
                getnext(l, p, x);
            else
                i = n[i];
        }
        return x[1] = x[1] - cou;
    }
    void write(char c[])
    {
        ofstream out(c);
        int x[2] = {1, 0};
        pn p = r->n;
        pr l = r;
        while (getnext(l, p, x) != NULL)
            out << p->c;
        out.close();
    }
    int kuohao()
    {
        pn n = new node;
        pn p = r->n;
        int x[2] = {0, 1};
        pr l = r;
        while (p = getnext(l, p, x))
        {
            if (p->c == 123 || p->c == 40)
            {
                pn t = new node;
                t->c = p->c;
                t->next = n;
                n = t;
            }
            else if (p->c == 41)
            {
                if (n->c != 40)
                    return 0;
                pn t = n;
                n = n->next;
                free(t);
            }
            else if (p->c == 125)
            {
                if (n->c != 123)
                    return 0;
                pn t = n;
                n = n->next;
                free(t);
            }
        }
        if (n->next != NULL)
            return 0;
        return 1;
    }
    notepad(/* args */);
    ~notepad();
};

notepad::notepad(/* args */)
{
}

notepad::~notepad()
{
}
