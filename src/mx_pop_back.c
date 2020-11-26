#include "../inc/libmx.h"

void mx_pop_back(t_list **head){
    if(*head == NULL) return;
    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    t_list *temp = *head;
    while(temp->next->next != NULL) temp = temp->next;
    t_list *last = temp;
    free(last->next);
    last->next = NULL;
}
