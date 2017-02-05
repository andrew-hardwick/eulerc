#ifndef COMMON_UTLS_H
#define COMMON_UTLS_H

#define BIGINT_LENGTH 50
#define BIGINT_CELL 10000

int isPrime(int num);

int isPalindrome(int num);

char*  genPrime(long index);

int numFactors(long val);

int* allocateBigInt();

int* convertStringToBigInt(char*);
#endif
