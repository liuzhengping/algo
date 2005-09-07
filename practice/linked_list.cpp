#include <stdio.h>
#include <malloc.h>
#include <conio.h>
struct node {
    int key; struct node *next; 
} *head, *t, *z;
void init() {
    head = (struct node *) malloc(sizeof *head);
    z = (struct node *) malloc(sizeof *z);
    head->next = z;
    z->next = z;
}
struct node *insertafter(int v, struct node *t) {
    struct node *x;
    x = (struct node *) malloc(sizeof *x);
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}
void p() {
    struct node *i = (struct node *) malloc(sizeof i);
    i = head;
    while(t != z) {
        printf("(%d)", t->key);
        t->next = (struct node *) malloc(sizeof *t);
        t = t->next;
    }    
        //i = (struct node *) malloc(sizeof i);
               
}               
int main() {
    init();
    t = (struct node *) malloc(sizeof *t);
    t->key = 1;
    /*for(int i = 2; i < 10; i++) {
        t->next = (struct node *) malloc(sizeof *t);
        t = t->next;
        t->key = i;
        printf("%d ", t->key);
    }*/
    //t->next = z;
    printf("\n");
    insertafter(1, head);
    insertafter(2, head);
    insertafter(3, head);
    //for(i = head+1; i != z; i++)
      printf("%d ", head->key);
      printf("%d ", head->next->key);
      printf("%d ", head->next->next->key);
      printf("%d ", head->next->next->next->key);
    getch();
    return 0;
}    
