// Transport card record implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include "cardRecord.h"
#include <string.h>

#define LINE_LENGTH 1024
#define NO_NUMBER -999

// scan input line for a positive integer, ignores the rest, returns NO_NUMBER if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return NO_NUMBER;
   else
      return n;
}

// scan input for a floating point number, ignores the rest, returns NO_NUMBER if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if (sscanf(line, "%f", &f) != 1)
      return NO_NUMBER;
   else
      return f;
}

int ifValidID(int);
int readValidID(void) {
   int id;
   printf("Enter card ID: ");
   id=readInt();
   id=ifValidID(id);

   return id;  /* needs to be replaced */
}
int ifValidID(int id){
   if (id>=10000000 && id<=99999999){
      return id;
   }else{
      printf("Not valid. Enter a valid value: ");
      id=readInt();
      return ifValidID(id);
   }
}

float ifValidAmount(float);
float readValidAmount(void) {
   float amount;
   printf("Enter amount: ");
   amount=readFloat();
   amount=ifValidAmount(amount);   
   return amount;  /* needs to be replaced */
}
float ifValidAmount(float amount){
   if (amount<-2.35 || amount>250){
      printf("Not valid. Enter a valid value: ");
      amount=readFloat();
      return ifValidAmount(amount);
   }else{
      return amount;
   }
}

void printCardData(cardRecordT card) {
   printf("-----------------\nCard ID: %d\n",card.cardID);
   if(card.balance>=0){
      printf("Balance: $%.2f\n",card.balance);
   }else{
      float temp_amount = card.balance * -1;
      printf("Balance: -$%.2f\n",temp_amount);
   }
   if (card.balance<5){
      printf("Low balance\n");
   }
   printf("-----------------\n");
   return;  /* needs to be replaced */
}




