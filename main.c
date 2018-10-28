/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Transport card manager

     COMP9024 18s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "cardRecord.h"
#include "cardLL.h"

void printHelp();
void CardLinkedListProcessing();

int main(int argc, char *argv[]) {
   if (argc == 2) {
      int num = atoi(argv[1]);
      cardRecordT *record=malloc(num * sizeof(cardRecordT));
      assert(record != NULL);
      for(int i=0;i<num;i++){
         (record[i]).cardID=readValidID();
         (record[i]).balance=readValidAmount();
      }float total=0;
      for(int j=0;j<num;j++){
         total+=record[j].balance;
         printCardData(record[j]);
      }
      printf("Number of cards on file: %d\n",num);
      if (total>=0){
         printf("Average balance: $%.2f\n",total/num);
      }else{
         printf("Average balance: -$%.2f\n",(total/num)*-1);
      }
      free(record);

      /*** Insert your code for stage 1 here ***/
      
   } else {
      CardLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void CardLinkedListProcessing() {
   int op, ch;
   int l;
   int n;
   float balance;
//   float *balance=malloc(1*sizeof(float));
//   int *n=malloc(1*sizeof(int));
//   float *balance=&balance1;
//   int *n=&n1;
   List list = newLL();   // create a new linked list
   
   while (1) {
      printf("Enter command (a,g,p,q,r, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }

      switch (op) {

         case 'a':
         case 'A':
            
            insertLL(list, readValidID(), readValidAmount());
            
            /*** Insert your code for adding a card record ***/

	    break;

         case 'g':
         case 'G':
            
//            float *balance = (float *)malloc(1 * sizeof(float));
//            int *n=malloc(1 * sizeof(int));
            //getAverageLL(list,(list->head->data).cardID,(list->head->data).balance);
            getAverageLL(list,&n,&balance);
            
            /*** Insert your code for getting average balance ***/

	    break;
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
            showLL(list);
            /*** Insert your code for printing all card records ***/

	    break;

         case 'r':
         case 'R':
            l=readValidID();
            removeLL(list,l);
            /*** Insert your code for removing a card record ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" a - Add card record\n" );
   printf(" g - Get average balance\n" );
   printf(" h - Help\n");
   printf(" p - Print all records\n" );
   printf(" r - Remove card\n");
   printf(" q - Quit\n");
   printf("\n");
}
