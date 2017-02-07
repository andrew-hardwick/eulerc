#ifndef COMMON_UTLS_H
#define COMMON_UTLS_H

#define BIGINT_LENGTH 50
#define BIGINT_CELL 1000000
#define BIGINT int*

int isPrime(int num);

int isPalindrome(int num);

char*  genPrime(long index);

int numFactors(long val);

BIGINT allocateBigInt();

BIGINT convertStringToBigInt(char*, int);

int multiplyBigIntByScalar(BIGINT, int);

void addBigInt(BIGINT, BIGINT);

void printBigInt(BIGINT);

void balanceBigInt(BIGINT);
#endif
