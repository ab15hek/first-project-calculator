#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char options();
double FunctionB(double first, double second, char operator);
double FunctionU(double first, char operator);
void FunctionE();

int main() {
  char operator;
  char operation;
  double first;
  double second;
  double a, b, c, d, e = 0;
  char input;
  char mode = ' ';

  // To exit the program (option E): exit(0);

  printf("Welcome to my Command-Line Calculator\n");
  printf("Developer: Abishek Bhandari ");
  printf("Version: 3 \n");
  printf("Date format (dd/mm/yy): 2022-11-30 \n");
  operation = options();

  while (operation != 'e' && operation != 'E') {

    if (operation != 'B' && operation != 'b' && operation != 'U' &&
        operation != 'u' && operation != 'e' && operation != 'E' &&
        operation != 'a' && operation != 'A' && operation != 'V' &&
        operation != 'v') {
      printf("INVALID ENTRY\nSelect Another Option: ");
    }

    switch (operation) {
    case ('B'):
    case ('b'):
      printf("enter first number: ");
      scanf("%lf", &first);
      printf("select operator (+,-,*,/,%%,P,X,I): ");
      scanf(" %c", &operator);
      printf("enter second number: ");
      scanf("%lf", &second);
      printf("\n %lf %c %lf = %lf", first, operator, second,
             FunctionB(first, second, operator));

      break;
    case 'U':
    case 'u':
      printf("enter first number: ");
      scanf("%lf", &first);
      printf("select operator (S,L,E,C,F): ");
      scanf(" %c", &operator);
      printf("\n %lf %c = %lf", first, operator, FunctionU(first, operator));
      break;
    case 'V':
    case 'v':
      printf("Enter a single variable ranging from a to e: ");
      scanf(" %c", &input);
      while (input != 'a' && input != 'b' && input != 'c' && input != 'd' &&
             input != 'e') {
        printf("Variable cannot be an integer, and must be from the range a - "
               "e\n");
        scanf(" %c", &input);

        if (input == '0' || input == '1' || input == '2' || input == '3' ||
            input == '4' || input == '5' || input == '6' || input == '7' ||
            input == '8' || input == '9') {

          printf("Variable cannot be an integer, and must be from the range a "
                 "- e\n");
          scanf(" %c", &input);
        }
      }
      if (input == 'a') {
        printf("Enter a value for variable 'a'.\n");
        scanf("%lf", &a);
      } else if (input == 'b') {
        printf("Enter a value for variable 'b'.\n");
        scanf("%lf", &b);
      } else if (input == 'c') {
        printf("Enter a value for variable 'c'.\n");
        scanf("%lf", &c);
      } else if (input == 'd') {
        printf("Enter a value for variable 'd'.\n");
        scanf("%lf", &d);
      } else if (input == 'e') {
        printf("Enter a value for variable 'e'.\n");
        scanf("%lf", &e);
      }
      break;
    case 'A':
    case 'a':
      printf("--------------------------------------------\n");
      printf("[Advanced Mode] ");
      printf("select operation:\n");
      printf("[B] Binary Mathematical Operation: \n");
      printf("[U] Unary Mathematical Operations: \n");
      printf("[E] Exit Advanced Mode: \n\n");

      while (mode != 'E' && mode != 'e') {
        scanf(" %s", &mode);
        if ((mode == 'B') || (mode == 'b')) {
          double first;
          double second;
          char operator;
          char input1[255], input2[255];

          printf("Enter number or variable for first value\n");
          scanf(" %s", input1);

          switch (input1[0]) {
          case 'a':
            first = a;
            break;
          case 'b':
            first = b;
            break;
          case 'c':
            first = c;
            break;
          case 'd':
            first = d;
            break;
          case 'e':
            first = e;
            break;
          default:
            first = (double)atof(input1);
          }
          printf("Enter operator ( +, -, *, / , %%, P, X, I):\n");
          scanf(" %c", &operator);
          printf("Enter number or variable for second value\n");
          scanf(" %s", input2);
          switch (input2[0]) {
          case 'a':
            second = a;
            break;
          case 'b':
            second = b;
            break;
          case 'c':
            second = c;
            break;
          case 'd':
            second = d;
            break;
          case 'e':
            second = e;
            break;
          default:
            second = (double)atof(input2);
          }
          if (operator== '+') {
            printf("%lf + %lf = %lf \n", first, second, (first + second));
            printf("\nPlease select an option [B,U,E]: ");
          } else if (operator== '-') {
            printf("%lf - %lf = %lf \n", first, second, (first - second));
            printf("\nPlease select an option [B,U,E]: ");
          } else if (operator== '*') {
            printf("%lf * %lf = %lf \n", first, second, (first * second));
            printf("\nPlease select an option [B,U,E]: ");
          } else if (operator== '/') {
            if (second != 0) {
              printf("%lf / %lf = %lf \n\n", first, second, (first / second));
              printf("\nPlease select an option [B,U,E]: ");
            } else
              printf("Division by 0 is invalid please try again");

          } else if (operator== '%') {
            printf("the remainder of %lf and %lf is %lf \n\n", first, second,
                   fmod(first, second));
            printf("\nPlease select an option [B,U,E]: ");
          } else if ((operator== 'P') || (operator== 'p')) {
            printf("%lf to the power of %lf is %lf \n\n", first, second,
                   pow(first, second));
            printf("\nPlease select an option [B,U,E]: ");
          } else if ((operator== 'X') || (operator== 'x')) {
            if (first == second) {
              printf("Same value, maximum does not exist");
              printf("\nPlease select an option [B,U,E]: ");
            } else
              printf("between %lf and %lf, %lf is the maximum \n\n", first,
                     second, fmax(first, second));
            printf("\nPlease select an option [B,U,E]: ");
          } else if ((operator== 'I') || (operator== 'i')) {
            if (first == second) {
              printf("Same value, minimum does not exist");
              printf("\nPlease select an option [B,U,E]: ");
            } else
              printf("between %lf and %lf, %lf is the minimum \n\n", first,
                     second, fmin(first, second));
            printf("\nPlease select an option [B,U,E]: ");
          } else {
            printf("Invalid Input of Number or Operator");
            printf("\nPlease select an option [B,U,E]: ");
            break;
          }
        } else if ((mode == 'U') || (mode == 'u')) {
          double first;
          char operator;
          char input[250];
          printf("Enter number or variable\n");
          scanf(" %s", input);

          switch (input[0]) {

          case 'a':
            first = a;
            break;
          case 'b':
            first = b;
            break;
          case 'c':
            first = c;
            break;
          case 'd':
            first = d;
            break;
          case 'e':
            first = e;
            break;
          default:
            first = atof(input);
          }
          printf("Enter operator (S for square root, L for logarithm (logx), E "
                 "for exponentiation (e),\nC for smallest integer greater than "
                 "/ equal to x, or F for the largest integer greater than / "
                 "equal to x):\n");
          scanf(" %c", &operator);
          if ((operator== 'S' || operator== 's')) {
            if (first >= 0) {
              printf("the square root of %lf is %lf", first, sqrt(first));
            } else
              printf("Inputs Less Then 0 Are Invalid");
          } else if ((operator== 'L' || operator== 'l')) {
            printf("the log of %lf is %lf", first, log10(first));
          } else if ((operator== 'E' || operator== 'e')) {
            printf("the exponiential of %lf is %lf", first, exp(first));
          } else if ((operator== 'C' || operator== 'c')) {
            printf("the ceiling of %lf is %lf", first, ceil(first));
          } else if ((operator== 'F' || operator== 'f')) {
            printf("the floor of %lf is %lf", first, floor(first));
          } else {
            printf("Invalid Input of Operation or Number, Try Again.\n");
            break;
          }

        } else
          printf("invalid input [B,U,E]");
      }
    }
    operation = options();
    mode = ' ';
  }
  FunctionE();
}
char options() {
  char op;
  puts("\n-----------------------------------------");
  printf("\n[Normal Mode] ");
  printf("select operation:\n");
  printf("[B] Binary Mathematical Operation: \n");
  printf("[U] Unary Mathematical Operations: \n");
  printf("[A] Advances Mathematical Operations: \n");
  printf("[V] Define variables and assign them values: \n");
  printf("[E] Exit: \n");
  scanf(" %c", &op);
  return op;
}
double FunctionB(double first, double second, char operator) {
  double ans;
  if (operator== '+') {
    ans = first + second;
  } else if (operator== '-') {
    ans = first - second;
  } else if (operator== '*') {
    ans = first * second;
  } else if (operator== '/') {
    if (second != 0) {
      ans = first / second;
    } else
      printf("Division by 0 is invalid please try again");
  } else if (operator== '%') {
    ans = fmod(first, second);
  } else if ((operator== 'P') || (operator== 'p')) {
    ans = pow(first, second);
  } else if ((operator== 'X') || (operator== 'x')) {
    if (first == second) {
      printf("Same value, maximum does not exist");
    } else
      ans = fmax(first, second);
  } else if ((operator== 'I') || (operator== 'i')) {
    if (first == second) {
      printf("Same value, minimum does not exist");
    } else
      ans = fmin(first, second);
  } else {
    printf("Invalid Input of Number or Operator");
  }
  return ans;
}
double FunctionU(double first, char operator) {
  double ans;
  if ((operator== 'S' || operator== 's')) {
    if (first >= 0) {
      ans = sqrt(first);
    } else
      printf("Inputs Less Then 0 Are Invalid");
  } else if ((operator== 'L' || operator== 'l')) {
    ans = log10(first);
  } else if ((operator== 'E' || operator== 'e')) {
    ans = exp(first);
  } else if ((operator== 'C' || operator== 'c')) {
    ans = ceil(first);
  } else if ((operator== 'F' || operator== 'f')) {
    ans = floor(first);
  }
else
puts("INVALID TRY AGAIN");

  return ans;
}
void FunctionE() {
  printf("\n--------------------------------------------\n");
  printf("Exiting...");
  printf("\nThanks for using my Simple Calculator. Hope to see you again soon. Goodbye!");
  exit(0);
}