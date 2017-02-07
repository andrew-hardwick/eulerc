#ifndef BIGINT_H
#define BIGINT_H

#define BIGINT_LENGTH 50
#define BIGINT_CELL 1000000
#define BIGINT int*

BIGINT allocateBigInt();

BIGINT convertStringToBigInt(char*, int);

int multiplyBigIntByScalar(BIGINT, int);

void addBigInt(BIGINT, BIGINT);

void printBigInt(BIGINT);

void balanceBigInt(BIGINT);
#endif
