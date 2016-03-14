#include "stdafx.h"
#include <iostream>
#include<conio.h>
#include <vector>
#include<string>
using namespace std;

class node
{
public:
     node* next;
     node* down;
     int row;
     int col;
     int data;

    node(int ro, int co, int x)
    {
        this->row = ro;
        this->col = co;
        this->data = x;
        next = NULL;
        down = NULL;
    }

    node()
    {
        down = NULL;
        next = NULL;
    }
};


class linkList
{
public:
    vector<node*> head;

    node** cols;
    int col;
    int row;

    linkList() { }

    linkList(int row, int col)
    {
        this->col = col;
        this->row = row;
        cols = new node*[col];
        for (int var = 0; var < col; ++var) {
            cols[var] = new node();
        }
    }

    void createhead(int headcount)
    {
        for (int i = 0; i < headcount; i++)
        {
            node* q = new node();
//            head.push_back(q);
            head.push_back(q);
            head[i] = new node();
        }
    }

    void Biuldlinklist(node* p)
    {
        node* checker = head[p->row];


        if(checker->next != NULL)
            while (checker->next != head[p->row])
                checker = checker->next;

        checker->next = p;
        p->next = head[p->row];

        if (head[p->col]->down == NULL)
        {
            head[p->col]->down = p;
            p->down = head[p->col];
            cols[p->col] = p;
        }
        else
        {
            cols[p->col]->down = p;
            p->down = head[p->col];
            cols[p->col] = p;
        }
    }

    void printLinkList(int r, int c)
    {
        for (int i = 0; i < r; i++)
        {
            cout << "head (row) " << i << " : ";
            node *q = head[i]->next;
            if (q == NULL)
                cout << "NULL" << endl;
            else
            {
                while (q != head[i])
                {
                    cout << q->row << "," << q->col << "," << q->data;
                    if (q->next != head[i])
                        cout << " -> ";
                    q = q->next;
                }
                cout << endl;
            }
        }

        cout << "----------" << endl;
        for (int i = 0; i < c; i++)
        {
            cout << "head (col) " << i << " : ";
            node* q = head[i]->down;
            if (q == NULL)
                cout << "Null" << endl;
            else
            {
                while (q != head[i])
                {
                    cout << q->row << "," << q->col << "," << q->data;
                    if (q->down != head[i])
                        cout << " -> ";
                    q = q->down;
                }
                cout << endl;
            }
        }
        cout << endl << endl;
    }

    void printmatrix(int r, int c, int v)
    {
        cout << r << " " << c << " " << v << endl;
        for (int i = 0; i < r; i++)
        {
            node *q = head[i]->next;
            if(q != NULL){
                while (q != head[i])
                {
                    cout << q->row << " " << q->col << " " << q->data << endl;
                    q = q->next;
                }
            }
        }
    }

    linkList* add(linkList* l1, linkList* l2)
    {
        linkList* sum = new linkList(l1->row, l1->col);
        sum->createhead(l1->head.size());
        node* a;
        node* b;
        unsigned int headcounter = 0;

        while (headcounter < l1->head.size())
        {
            a = l1->head[headcounter]->next;

            b = l2->head[headcounter]->next;
            if(a != NULL && b != NULL)
            {
                while (a != l1->head[headcounter] && b != l2->head[headcounter])
                {
                    if (a->col == b->col)
                    {
                        node* q = new node(a->row, a->col, a->data + b->data);
                        sum->Biuldlinklist(q);
                        a = a->next;
                        b = b->next;
                    }
                    else if (a->col < b->col)
                    {
                        node* q = new node(a->row, a->col, a->data);
                        sum->Biuldlinklist(q);
                        a = a->next;
                    }
                    else if (a->col > b->col)
                    {
                        node* q = new node(b->row, b->col, b->data);
                        sum->Biuldlinklist(q);
                        b = b->next;
                    }
                }
            }
            if(a != NULL)
            {
                while (a != l1->head[headcounter])
                {
                    node* q = new node(a->row, a->col, a->data);
                    sum->Biuldlinklist(q);
                    a = a->next;
                }
            }

            if(b != NULL)
            {
                while (b != l2->head[headcounter])
                {
                    node* q = new node(b->row, b->col, b->data);
                    sum->Biuldlinklist(q);
                    b = b->next;
                }
            }

            headcounter++;
        }
        return sum;
    }
};


//////////////////////////////////////////////////////////////////////////


int main()
{
    cout << "First Matrix" << endl;

    int row, col, value;
    cin >> row >> col >> value;

    int headcount;

    if (row >= col)
        headcount = row;
    else
        headcount = col;

    linkList* sparse1 = new linkList(row, col);

    sparse1->createhead(headcount);

    for (int i = 0; i < value; i++)
    {
        int r, c, v;
        cin >> r >> c >> v;
        node* p = new node(r, c, v);

        sparse1->Biuldlinklist(p);
    }

    sparse1->printLinkList(row, col);


    ///////////////////////// second input //////////////////////////

    int row2, col2, value2;

    cout << "Second Matrix" << endl;

    cin >> row2 >> col2 >> value2;

    if (row2 >= col2)
        headcount = row2;
    else
        headcount = col2;

    linkList* sparse2 = new linkList(row2, col2);

    sparse2->createhead(headcount);

    for (int i = 0; i < value2; i++)
    {
        int r, c, v;
        cin >> r >> c >> v;
        node* p = new node(r, c, v);

        sparse2->Biuldlinklist(p);
    }

    sparse2->printLinkList(row2, col2);

    cout << "#############answer#############" << endl;


    if(row != row2 || col != col2)
    {
        cout << endl <<  "ERROR : rows or cols are not equal" << endl;
        return 0;
    }

    cout << "Sum of Matrix1 and Matrix2" << endl;

    linkList* sum = new linkList();
    sum = sum->add(sparse1, sparse2);

    sum->printmatrix(row, col, value);

    sum->printLinkList(row, col);

    return 0;
}

