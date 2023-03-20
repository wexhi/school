#include  <iostream>
using  namespace  std;

typedef  struct  node
{
    int  data;
    struct  node* next;
}NODE;

NODE* create(int  n)
{
    NODE* p, * h;
    int  i, x;
    h = new  NODE;
    h->next = NULL;
    for (i = n; i > 0; i--)
    {
        p = new  NODE;
        cin >> x;
        p->data = x;


    }
    return  h;
}

void  printlist(NODE* h)
{
    NODE* current = h;
    while (current->next != NULL)
    {
        current = current->next;
        cout << current->data << "  ";
    }
}

int  main()
{
    int  n;
    NODE* head;
    cin >> n;


    printlist(head);
    return  0;
}