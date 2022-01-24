int sumOfLinkedList (struct node *p) {
    int sum = 0;    
    while (p!=NULL) {        
        sum = sum + p->next;
        p = p->next;
    }
    return sum;
}