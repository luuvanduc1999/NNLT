
#include<iostream>
using namespace std;

#define TInfo int
typedef struct node_s
{
    TInfo Value;
    node_s *Next;
} Node;

typedef struct list_s
{
    Node *Head;
    Node *Tail;
    int Count;
} List;

Node *CreateNode(TInfo value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->Next = 0;
    node->Value = value;
    return node;
}

List *CreateList()
{
    List *list = (List *)malloc(sizeof(List));
    list->Head = list->Tail = 0;
    list->Count = 0;
    return list;
}

void RemoveAll(List *list)
{
    for (int i = 0; i < list->Count; i++)
    {
        Node *node = list->Head;
        list->Head = node->Next;
        free(node);
    }
    list->Count = 0;
}

void Destroy(List *list)
{
    RemoveAll(list);
    free(list);
}
void Append(List *list, TInfo value)
{
    Node *node = CreateNode(value);
    if (list->Count++ == 0)
        list->Head = node;
    else
        list->Tail->Next = node;
    list->Tail = node;
}

void VisitCore(TInfo value)
{
    cout << value << endl;
}

void Visit(List *list)
{
    Node *p = list->Head;
    while (p)
    {
        VisitCore(p->Value);
        p = p->Next;
    }
}

void main()
{
    List *lst = CreateList();
    int A[] = { 2, 1, 8, 3, 7, 6, 4, 9, 5, 0 };

    for (int i = 0; int a = A[i]; i++)
        if (a % 2)
            Append(lst, a);

    Visit(lst);

    Destroy(lst);
    system("pause");
}
