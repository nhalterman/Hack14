/*Hack14
* Programmer: Nicholas Halterman
* Collaborators: Jayden, Dalton, Nate, James, Olivia
* 12/04/19
*
* This program prints out a report for different
* types of transactions, number of transactions, and how much money was
* used in each transaction
*/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "transaction.h"

int main(int argc, char **argv){

  if(argc != 2){
    printf("Please input only 1 argument (.csv file)\n");
    return 1;
  }

  char *inputFile = argv[1];
  char **strArr = getFileLines(inputFile);
  int transCount = getNumTrans(inputFile);

  Transaction **structArr = (Transaction**)malloc(sizeof(Transaction*) * transCount);
  for(int i = 0; i < transCount; i++){
    char* UUID = strtok(strArr[i], ",");
    char* type = strtok(NULL, ",");
    double amount = atof(strtok(NULL, ","));
    char* customerAccount = strtok(NULL, ",");
    double oldBalance = atof(strtok(NULL, ","));
    double newBalance = atof(strtok(NULL, ","));
    char* targetAccount = strtok(NULL, ",");
    structArr[i] = createTransaction(UUID, type, amount, customerAccount, oldBalance, newBalance, targetAccount);
  }

  int paymentCount = 0;
  double paymentTotal = 0.0;
  int transferCount = 0;
  double transferTotal = 0.0;
  int withdrawCount = 0;
  double withdrawTotal = 0.0;
  int debitCount = 0;
  double debitTotal = 0.0;
  int depositCount = 0;
  double depositTotal = 0.0;
  for(int i = 0; i < transCount; i++){
    if(strcmp(structArr[i] -> type, "PAYMENT") == 0){
      paymentTotal += structArr[i] -> amount;
      paymentCount++;
    } else if(strcmp(structArr[i] -> type, "TRANSFER") == 0){
      transferTotal += structArr[i] -> amount;
      transferCount++;
    } else if(strcmp(structArr[i] -> type, "WITHDRAWAL") == 0){
      withdrawTotal += structArr[i] -> amount;
      withdrawCount++;
    } else if(strcmp(structArr[i] -> type, "DEBIT") == 0){
      debitTotal += structArr[i] -> amount;
      debitCount++;
    } else if(strcmp(structArr[i] -> type, "DEPOSIT") == 0){
      depositTotal += structArr[i] -> amount;
      depositCount++;
    } else{
      printf("Check your .csv file to make sure it matches the tokens above!\n");
      return 1;
    }
  }
  int totalCount = paymentCount + transferCount + withdrawCount + debitCount + depositCount;
  double totalMonies = paymentTotal + transferTotal + withdrawTotal + debitTotal + depositTotal;

  //Print Layout
  printf("\n======================================\n\t   Totals Report\n======================================\n");
  printf("Type\t      Count\t \tTotal\n");
  printf("======================================\n");
  printf("Payment %7d %22.2f\nTransfer%7d %22.2f\nWithdraw%7d %22.2f\nDebit%10d %22.2f\nDeposit%8d %22.2f\n", paymentCount, paymentTotal, transferCount, transferTotal, withdrawCount, withdrawTotal, debitCount, debitTotal, depositCount, depositTotal);
  printf("======================================\n");
  printf("Total%10d %22.2f\n", totalCount, totalMonies);

  //Free Structure Memory
  for(int i=0; i<transCount; i++){
    free(structArr[i]);
  }
  free(structArr);

  return 0;
}
