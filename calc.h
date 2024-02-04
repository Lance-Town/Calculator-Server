/* calc.c
 *
 * By: Lance Townsend
 *
 * Holds the function prototypes for the calculator 
 *
 */


#ifndef CALC_H
#define CALC_H

// perform calculations based on input
int calculate(char*, int, int);

// split the equation into tokens, and ensure that
// it has the correct prefix notation
int tokenize(const char*);

#endif /* CALC_H */
