#include <math.h>  //C Standard Library for math functions
#include <stdio.h> //C Standard Library for input/output functions
#include <stdlib.h> //C Standard Library for some utility functions
#include <ctype.h> //C Standard Library for character handling functions


//declare void functions

void display_welcome_message();
void display_options();
void display_exit_message();

void binary_operations();
void unary_operations();
void advanced_operations();
void variables();

void binary_advanced();
void unary_advanced();

// 5 memory slots
float a = 0.00;
float b = 0.00;
float c = 0.00;
float d = 0.00;
float e = 0.00;


int main(){

char option;

display_welcome_message();

while (1) {
display_options();
scanf(" %c", &option);
getchar();

 // use if, else statement for check whether or not the user inputted E
    if (option != 'E') {

      // use switch statement to make cases for each option
      switch (option) {
        case 'B':
          binary_operations();
          break;
        case 'U':
          unary_operations();
          break;
        case 'A':
          advanced_operations();
          break;
        case 'V':
          variables();
          break;
        default:
          printf("invalid option. Try again.\n\n");  
          break;
        }
      // if the user inputs E, the loop and the program will end
    } 
    else {
      display_exit_message();
      return 0;
    }
  }
}

void display_welcome_message(){

  printf("Welcome to my Command-Line Calculator (CLC)\n");
  printf("Developer: Jade Luong\n");
  printf("Version: Assignment 3 \n");
  printf("Date: March 31, 2024\n\n");

  // display menu

}

void display_options(){

  printf("\nSelect one of the following items:\n");
  printf("B) - Binary Mathematical Operations, such as addition and "
         "subtraction.\n");
  printf("U) - Unary Mathematical Operations, such as square root, and log.\n");
  printf("A) - Advances Mathematical Operations, using variables, arrays.\n");
  printf("V) – Define variables and assign them values.\n");
  printf("E) - Exit.\n");

}

void binary_operations(){

  float num1, num2, result = 0;
  char op;
// tell user to enter the first floating point number

printf("Please enter the first floating point number:\n");

// validate whether or not the user 
//input a floating point number

while (scanf(" %f", &num1) != 1) {
  printf("Invalid input. Please enter a floating point number:\n");
  // Clear the input buffer
  while (getchar() != '\n');
}

//tell user to enter an operation

printf("Please enter the operation ( + , - , * , / , %% , P , X , I  )\n");
scanf(" %c", &op); // to consume leading whitespace

//check if the operation is valid using a while loop
while (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != 'P' && op != 'X' && op != 'I') {
    printf("Invalid operation\n");
    printf("Please enter the operation ( + , - , * , / , %% , P , X , "
           "I  )\n");
    scanf(" %c", &op);
  } 

// tell user to enter the 2nd floating point number
printf("Please enter the second floating point number:\n");

// Keep telling user to enter the 2nd floating point number to store
// in num2 until it returns a valid number

while (scanf(" %f", &num2) != 1) {
  printf("Invalid input. Please enter a floating point number:\n");
  // Clear the input buffer
  while (getchar() != '\n');  
}

// use switch statement to check the operation the user inputted, make
// cases for each operation

switch (op) {

// use case '+' to add the 2 numbers and put the answer into the
// variable result add break at the end of each case to end processing
// of the case
case '+':
  result = num1 + num2;
  printf("The result is %.2f\n", result);
  break;

  // use case '-' to subtract the 2 numbers and put the answer into the
  // variable result

case '-':
  result = num1 - num2;
  printf("The result is %.2f\n", result);
  break;

  // use case '*' to multiply the 2 numbers and put the answer into the
  // variable result

case '*':
  result = num1 * num2;
  printf("The result is %.2f\n", result);
  break;

/*use if, else statement to check whether or not the user inputted 0 for
num2, since dividing anything by 0 will result in an error

if user did not input 0, use case '/' to divide the 2 numbers and put
the answer into the variable result If the user inputted 0, display the
following text: "Denominator cannot be 0"
*/
case '/':
  if (num2 != 0) {
    result = num1 / num2;
    printf("The result is %.2f\n", result);
  } else {
    printf("Denominator cannot be 0. Try again.\n");
  }
  break;

  // use case '%' to find the remainder of the 2 numbers and put the
  // answer into the variable result

case '%':
  result = fmod(num1, num2);
  printf("The result is %.2f\n", result);
  break;

  // use case 'P' to find the power of the 2 numbers and put the answer
  // into the variable result

case 'P':
  result = pow(num1, num2);
  printf("The result is %.2f\n", result);
  break;

  // use case 'X' to find the maximum of the 2 numbers and put the
  // answer into the variable result

case 'X':
  result = (num1 > num2) ? num1 : num2;
  printf("The maximum is %.2f\n", result);
  break;

  // use case 'I' to find the minimum of the 2 numbers and put the
  // answer into the variable result

case 'I':
  result = (num1 < num2) ? num1 : num2;
  printf("The minimum is %.2f\n", result);
  break;

  // add a default in case the user inputs an invalid option

default:
  printf("Invalid operator\n");
  }
}

void unary_operations(){

    float num1, result = 0;
    char op;
// get an operator from user
printf("Please enter an operator: (S, L, E, C, F)\n");
scanf(" %c", &op);

// use while loop to check if the user inputted a valid operator

while (op != 'S' && op != 'L' && op != 'E' && op != 'C' && op != 'F') {
    printf("Invalid operation\n");
    printf("Please enter an operator: (S, L, E, C, F)\n");
    scanf(" %c", &op);
  }

// tell user to enter the first floating point number
printf("Please enter the first floating point number:\n");

// Keep telling user to enter the first floating point number to store
// in num1 until it returns a valid number

while (scanf(" %f", &num1) != 1) {
  printf("Invalid input. Please enter a floating point number:\n");
  // Clear the input buffer
  while (getchar() != '\n');          
}

// use switch statement and make cases for each operation

switch (op) {

// use case 'S' to square root the number and put the answer into the
// variable result
case 'S':
  result = sqrt(num1);
  printf("The square root is %.2f\n", result);
  break;

  // use case 'L' to log the number and put the answer into the variable
  // result
case 'L':
  result = log(num1);
  printf("The logarithm is %.2f\n", result);
  break;

  // use case 'E' to exponentiate the number and put the answer into the
  // variable result

case 'E':
  result = exp(num1);
  printf("The exponentiation is %.2f\n", result);
  break;

  // use case 'C' to ceil the number and put the answer into the
  // variable result

case 'C':
  result = ceil(num1);
  printf("The ceiling is %.2f\n", result);
  break;

  // use case 'F' to floor the number and put the answer into the
  // variable result

case 'F':
  result = floor(num1);
  printf("The floor is %.2f\n", result);
  break;

  // add a default in case the user inputs an invalid option

default:
  printf("Invalid operator.\n");
  }
}

void variables(){

  char slot;
printf("Enter memory slot (a/b/c/d/e): ");
  scanf(" %c", &slot); // reads memory slot input
  getchar();

  while (slot < 'a' || slot > 'e') {
    printf("Invalid memory slot. Try again.\n");
    scanf(" %c", &slot);
    getchar();
  } 

  // Update memory slot with what the user inputted
  switch (slot) {
  case 'a':
    printf("Enter the value for memory slot a: ");
    scanf(" %f", &a);
    break;
  case 'b':
    printf("Enter the value for memory slot b: ");
    scanf(" %f", &b);
    break;
  case 'c':
    printf("Enter the value for memory slot c: ");
    scanf(" %f", &c);
    break;
  case 'd':
    printf("Enter the value for memory slot d: ");
    scanf(" %f", &d);
    break;
  case 'e':
    printf("Enter the value for memory slot e: ");
    scanf(" %f", &e);
    break;
  default:
    printf("Invalid memory slot\n");
    break;
  }
}

void advanced_operations(){

  char option;

  // display the menu for case A
  printf("Advanced Operations:\n");
  printf("B. Binary Operations with variables\n");
  printf("U. Unary Operations with variables\n");
  printf("E. Exit to Main Menu\n");

  // use a while loop so the user stays in case A until they input E to
  // exit to main menu

  while (1) {

    // ask user to input an option
    printf("Please select your option ( B , U , E )\n");
    scanf(" %c", &option);
    getchar();

    // use switch statement to make cases for each option
    switch (option) {
    case 'B':
      binary_advanced();
      break;
      case 'U':
      unary_advanced();
      break;

    case 'E':
      printf("Returning to main menu.\n");
      break;

    // add a default in case user inputs an invalid option
    default:
      printf("Invalid option.\n");
      break;
    }

  if (option == 'E') {
    break;
    }
  }
}

void binary_advanced(){
char op, ap4, ap5 = 0; // declare variables for binary operations
char input1[10], input2[10]; // Assuming maximum variable length is 10
float num3, num4 = 0;        
float result = 0;

//tell user to enter 2 numbers/variables and an operation
printf("Please enter a floating point number or a variable (a/b/c/d/e): ");
scanf(" %9s", input1); //limit input to 9 characters
printf("Please enter an operation ( + , - , * , / , %%, P, X, I): ");
scanf(" %c", &op);
printf("Please enter second floating point number or a variable (a/b/c/d/e): ");
scanf(" %9s", input2); //limit input to 9 characters

//check if string length is 1 and if it is an alphabet letter
if (strlen(input1) == 1 && isalpha(input1[0])) {
ap4 = input1[0];
}
//check if variable is within range
//make switch caes for each variable
if (ap4 >= 'a' && ap4 <= 'e') {
  switch (ap4) {
    case 'a':
      num3 = a;
      break;
    case 'b':
      num3 = b;
      break;
    case 'c':
      num3 = c;
      break;
    case 'd':
      num3 = d;
      break;
    case 'e':
      num3 = d;
      break;
    }
  }
//if it's not within range, check if it's a number
else {
  char *endptr; // declare pointer to end of string
  num3 = strtof(input1, &endptr); // convert string to float
  // Check if conversion was successful
  if (endptr != input1) { //if it's not a number, display error message
  } 
  else {
    printf("Invalid input.\n");
  }
}
//check if string length is 1 and if it is an alphabet letter
if (strlen(input2) == 1 && isalpha(input2[0])) {
  ap5 = input2[0];
}
//check if variable is within range
//make switch caes for each variable
if (ap5 >= 'a' && ap5 <= 'e') {
// If the input is a variable (a, b, c, d, e)
  switch (ap5) {
    case 'a':
      num4 = a;
      break;
    case 'b':
      num4 = b;
      break;
    case 'c':
      num4 = c;
      break;
    case 'd':
      num4 = d;
      break;
    case 'e':
      num4 = e;
      break;
    }
  }
//if it's not within range, check if it's a number
else {
  char *endptr;// declare pointer to end of string
  num4 = strtof(input2, &endptr); //turn string to float
  // Check if conversion was successful
  if (endptr != input2) {
  } 
  else {
    printf("Invalid input.\n");
  }
}
//make a switch case for each operation
switch (op) {
  case '+':
    result = num3 + num4;
    printf("result is %f \n", result);
    break;
  case '-':
    result = num3 - num4;
    printf("result is %f \n", result);
    break;
  case '*':
    result = num3 * num4;
    printf("result is %f \n", result);
    break;
  case '/':
    result = num3 / num4;
    printf("result is %f \n", result);
    break;
  case '%':
    result = fmod(num3, num4);
    printf("Result is %f \n",  result);
    break;
  case 'P':
    result = pow(num3, num4);
    printf("Result is %f \n", result);
    break;
  case 'X':
    result = fmax(num3, num4);
    printf("result = %f\n", result);
    break;
  case 'I':
    result = fmin(num3, num4);
    printf("result = %f\n", result);
    break;
  default: //if user inputs an invalid operation, display error message
    printf("Invalid operator\n"); 
    break;
  }
} //end of binary_advanced

void unary_advanced(){
  char ap1; //declare variable for unary operations
  char input[10], ap5; //length of 10
  float num5 = 0;
  float result = 0;

  //tell user to enter a number/variable and an operation
  printf(" U) - Unary Mathematical Operations\n");
  printf("Please enter the first number or a variable name (a/b/c/d/e): ");
  scanf(" %9s", input); //limit input to 9 characters

  printf("Please enter the operation (S,L,E,C,F): ");
  scanf(" %c", &ap1);
  //check if string length is 1 and if it is an alphabet letter
  if (strlen(input) == 1 && isalpha(input[0])) {
    ap5 = input[0]; //store the variable in ap5
   }
    if (ap5 >= 'a' && ap5 <= 'e') {
    // If the input is a variable (a, b, c, d)
      switch (ap5) {
        case 'a':
          num5 = a;
          break;
        case 'b':
          num5 = b;
          break;
        case 'c':
          num5 = c;
          break;
        case 'd':
          num5 = d;
          break;
        case 'e':
          num5 = e;
          break;
        }
      } 
      //if it's not within range, check if it's a number
      else {
        char *endptr; // declare pointer to end of string
        num5 = strtof(input, &endptr); // convert string to float
        // Check if conversion was successful
          if (endptr != input) {
            printf("You entered the float: %f\n", num5);
          } else {
        printf("Invalid input.\n");
      }
    }
  //make a switch case for each operation
  switch (ap1) {
    case 's':
    case 'S':
    result = sqrt(num5);
    break;
  case 'l':
  case 'L':
    result = log(num5);
    break;
  case 'e':
  case 'E':
    result = exp(num5);
    break;
  case 'c':
  case 'C':
    result = ceil(num5);
    break;
  case 'f':
  case 'F':
    result = floor(num5);
    break;
  default: //in case user inputs an invalid operation, display error message
    printf("Invalid operator\n");
    break;
  }
  printf("The result is %f \n", result);
  } 

void display_exit_message(){
  printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!\n");
}




