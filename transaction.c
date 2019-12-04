//Transaction.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "transaction.h"

int getNumTrans(const char *filePath){
  char buff[1000];
  FILE *f = fopen(filePath, "r");
  int transCounter = atoi(fgets(buff, sizeof(buff), f));
  fclose(f);

  return transCounter;
}

char **getFileLines(const char *filePath){
  FILE *f = fopen(filePath, "r");

  if(f == NULL){
    return NULL;
  }

  char buff[1000];
  int transCounter = atoi(fgets(buff, sizeof(buff), f));
  char **strArr = (char**)malloc(sizeof(char*) * transCounter);

  for(int i = 0; i < transCounter; i++){
    int bufferSize = strlen(buff);
    if(buff[bufferSize - 1] == '\n'){
      buff[bufferSize - 1] = '\0';
    }
    strArr[i] = (char *)malloc(sizeof(char) * strlen(fgets(buff, sizeof(buff), f)) + 1);
    strcpy(strArr[i], buff);
  }
  fclose(f);

  return strArr;
}

Transaction * createTransaction(
  const char * UUID,
  const char * type,
  double amount,
  const char * customerAccount,
  double oldBalance,
  double newBalance,
  const char * targetAccount){

    Transaction * transaction = (Transaction *)malloc(sizeof(Transaction) + 1);

    transaction -> UUID = (char *)malloc(sizeof(char) * strlen(UUID) + 1);
    strcpy(transaction -> UUID, UUID);
    transaction -> type = (char *)malloc(sizeof(char) * strlen(type) + 1);
    strcpy(transaction -> type, type);
    transaction -> amount = amount;
    transaction -> customerAccount = (char *)malloc(sizeof(char) * strlen(customerAccount) + 1);
    strcpy(transaction -> customerAccount, customerAccount);
    transaction -> oldBalance = oldBalance;
    transaction -> newBalance = newBalance;
    transaction -> targetAccount = (char *)malloc(sizeof(char) * strlen(targetAccount) + 1);
    strcpy(transaction -> targetAccount, targetAccount);

    return transaction;
  }
