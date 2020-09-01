List Insert(List L, ElementType X) {
    List c1 = L, current = NULL, head = L, c2 = NULL;
    current = (List*)malloc(sizeof(List));
    current->Data = X;
    current->Next = NULL;
    c2 = current;
    while (c2) {
        if (c1 == head && X< head->Data) {
            current = c2;
            c2 = c2->Next;//¸üÐÂÕë
            current->Next = c1;
            head = current;
            continue;
        }
        else if (c1->Next) {
            if (c2->Data >= c1->Data&& c2->Data <= c1->Next->Data) {
                current = c2;
                c2 = c2->Next;
                current->Next = c1->Next;
                c1->Next = current;
                continue;
            }
        }
        if (c2->Data >= c1->Data && c1->Next == NULL) {
            current = c2;
            c2 = c2->Next;
            c1->Next = current;
            current->Next = NULL;
            continue;
        }
        else {
            c1 = c1->Next;
        }
    }
    return head;
}
