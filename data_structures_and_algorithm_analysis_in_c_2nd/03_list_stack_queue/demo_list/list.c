//
// Created by TonyEarth on 2017/1/3.
//
#include 'list.h'

struct Node {
    ElementType Element;
    Position Next;
};

BOOL IsLast(Position P, List L) {
    return P->Next == NULL;
}

Position Find(ElementType X, List L) {
    Position P;
    P = L->next;
    while(P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

/**
 * delete first occurence of x from a list
 * assume use of a header node
 */
void Delete(ElementType X, List L) {
    Position P, TmpCell;
    p = FindPrevious(x, l);
    if (!IsLast(p, l)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}