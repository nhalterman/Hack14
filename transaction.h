typedef struct {
  char * UUID;
  char * type;
  double amount;
  char * customerAccount;
  double oldBalance;
  double newBalance;
  char * targetAccount;

}
Transaction;

/*
* This function gets the number of transactions
*/
int getNumTrans(const char *filePath);

/*
* This function reads a file line by line
*/
char **getFileLines(const char *filePath);

/*
* This function creates a new transaction
*/
Transaction * createTransaction(
    const char * UUID,
    const char * type,
    double amount,
    const char * customerAccount,
    double oldBalance,
    double newBalance,
    const char * targetAccount);
