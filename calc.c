/* calc.c
 *
 * By: Lance Townsend
 *
 * Calculator for the server
 */

#include <limits.h>
#include <stdlib.h>
#include <string.h>


// perform calculations based on input
int calculate(char* operator, int operandOne, int operandTwo) {
   int returnVal = 0;

   switch (*operator) {
      case '+':
         returnVal = operandOne + operandTwo;
         break;
      case '-':
         returnVal = operandOne - operandTwo;
         break;
      case '*':
         returnVal = operandOne * operandTwo;
         break;
      case '/':
         returnVal = operandOne / operandTwo;
         break;
      case '%':
         returnVal = operandOne % operandTwo;
         break;
   }
   return returnVal;
}

// split the equation into tokens, and ensure that
// it has the correct prefix notation
int tokenize(const char* equation) {
   const char *delim = " ";
   char *operator;
   char* token;
   char copy[255];
   int operandOne = 0;
   int operandTwo = 0;
   int i = 0;
   int correctInput = 0;

   // copy the input, as strtok modifies input
   strcpy(copy, equation);

   // break the equation into tokens separated by spaces
   token = strtok(copy, delim);

   while (token != NULL) {
      if (atoi(token) != 0 || (strcmp(token, "0") == 0 && token[0] == '0')) {
         // is an integer value
         if (i == 1) {
            correctInput++;
            operandOne = atoi(token);
         } else if (i == 2) {
            correctInput++;
            operandTwo = atoi(token);
         } else {
            // there is invalid input
            return INT_MIN;
         }
      } else {
         // is the operator
         if (i == 0) {
            correctInput++;
            operator = token;
         }
      }
     i++;
     token = strtok(NULL, delim);
   }

   // check if there is incorrect input
   if (correctInput != 3) {
      return INT_MIN;
   }

   return calculate(operator, operandOne, operandTwo);
}
