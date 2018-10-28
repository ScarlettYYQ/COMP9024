// Linked list of transport card records implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cardLL.h"
#include "cardRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    cardRecordT data;
    struct node *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;
//   NodeT *current;
/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: to creat a new linked list, and there is no loop in this function.
List newLL() {
   List list=malloc(1 * sizeof(List));
   list->head=malloc(1 * sizeof(NodeT));
   list->head->next=NULL;
   return list;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: There has one 'while' loop to distory the linked list.
void dropLL(List listp) {
   NodeT *p;
   p = listp->head;
   while (p != NULL) {
      NodeT *temp = p->next;
      free(p);
      p = temp;
   }
   free(listp);
   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: There has one 'for' loop to delete a specific node.
void removeLL(List listp, int cardID) {
   NodeT *p;
   for (p = listp->head; p->next != NULL; p = p->next){
      if(p->next->data.cardID==cardID){
         p->next=p->next->next;
         printf("Card removed.\n");
         return;
      }
   }
   printf("Card not found.\n");
   return;  /* needs to be replaced */
}

// Time complexity: O(1)
// Explanation: no loop in this insert function of stage2.
//stage2
//void insertLL(List listp, int cardID, float amount) {
//   NodeT *new = malloc(1 * sizeof(NodeT));  // create new list element
//   cardRecordT card;
//   card.cardID=cardID;
//   card.balance=amount;
//   (*new).data=card;
//   new->next = listp->head->next;          // link to beginning of list
//   listp->head->next=new;
//   printf("Card added.\n");
//   //printf("%d,%.2f", (new->data).cardID,(new->data).balance);
//   return;  /* needs to be replaced */
//}

//stage3
// Time complexity: O(n)
// Explanation: There has one 'for' loop to insert a specific node by ascending order.
void insertLL(List listp, int cardID, float amount) {
   NodeT *new = malloc(1 * sizeof(NodeT));  // create new list element
   new->data.cardID=cardID;
   new->data.balance=amount;
   new->next=NULL;
   if (listp->head->next== NULL){
      listp->head->next=new;
      printf("Card added.\n");
      return;
   }else{
      NodeT *p;
      for (p = listp->head; p->next != NULL; p = p->next){
         if (new->data.cardID < p->next->data.cardID){
            new->next = p->next;
            p->next=new;  
            printf("Card added.\n"); 
            return;       
         }if (new->data.cardID == p->next->data.cardID){
            p->next->data.balance= new->data.balance+p->next->data.balance;
            printf("-----------------\nCard ID: %d\n",(p->next->data).cardID); 
            if((p->next->data).balance>=0){
               printf("Balance: $%.2f\n",(p->next->data).balance);
            }else{
               float temp_amount = (p->next->data).balance * -1;
               printf("Balance: -$%.2f\n",temp_amount);
            }
            if ((p->next->data).balance<5){
               printf("Low balance\n");
            }
            printf("-----------------\n");
            return;       
         }
      }
      p->next=new;
      printf("Card added.\n");
      return;
   }   
}

// Time complexity: O(n)
// Explanation: This function has one 'for' loop to compute the average balance.
void getAverageLL(List listp, int *n, float *balance) {
   *n=0;
   *balance=0;
   NodeT *p;
   for (p = listp->head->next; p != NULL; p = p->next){
      *n+=1;
      *balance+=(p->data).balance;
   }
   printf("Number of cards on file: %d\n",*n);
   if (*balance>=0){
      printf("Average balance: $%.2f\n",*balance/(*n));
   }else{
      printf("Average balance: -$%.2f\n",(*balance/(*n))*-1);
   }
   return;  /* needs to be replaced */
}

// Time complexity: O(n)
// Explanation: This function has one 'for' loop to print all node's data of a linked list.
void showLL(List listp) {
   NodeT *p;
   for (p = listp->head->next; p != NULL; p = p->next){
      printf("-----------------\nCard ID: %d\n",(p->data).cardID);
      if((p->data).balance>=0){
         printf("Balance: $%.2f\n",(p->data).balance);
      }else{
         float temp_amount = (p->data).balance * -1;
         printf("Balance: -$%.2f\n",temp_amount);
      }
      if ((p->data).balance<5){
         printf("Low balance\n");
      }
      printf("-----------------\n");
   }
   return;  /* needs to be replaced */
}
