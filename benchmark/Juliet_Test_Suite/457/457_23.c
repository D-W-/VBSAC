// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
 /*
 * @description
 * CWE: 457 Use Uninitialized Variable
 */
#include "457.h"


const int GLOBAL_CONST_TRUE = 1; /* true */
const int GLOBAL_CONST_FALSE = 0; /* false */
const int GLOBAL_CONST_FIVE = 5; 

int globalTrue = 1; /* true */
int globalFalse = 0; /* false */
int globalFive = 5; 

int globalReturnsTrue() 
{
    return 1;
}

int globalReturnsFalse() 
{
    return 0;
}

int globalReturnsTrueOrFalse() 
{
    return (rand() % 2);
}

void printHexCharLine (char charHex)
{
    printf("%d\n", (int)charHex);
}

void printLine (const char * line)
{
    if(line != NULL) 
    {
        printf("%s\n", line);
    }
}

void printIntLine (int intNumber)
{
    printf("%d\n", intNumber);
}

void printLongLine (int64_t longIntNumber)
{
    printf("%ld\n", longIntNumber);
}

void printDoubleLine(double doubleNumber) 
{
    printf("%g\n", doubleNumber);
}

static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */

#ifndef OMITBAD

void bad23()
{
    int data;
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printIntLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void good23()
{
    int data;
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Ensure data is initialized before use */
        data = 5;
        printIntLine(data);
    }
}

#endif /* OMITGOOD */

int main(){
    good23();
	bad23();
    return 1;
}