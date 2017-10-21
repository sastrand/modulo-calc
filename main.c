// Sascha Strand
// 2017-10-21
// Modulo Calculator

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TOKEN_SIZE 10

int main(void) {

  char token[TOKEN_SIZE];
  char ch = '0';
  int i = 0;
  char first_negative = 0;
  char second_negative = 0;

  printf("*--------------------------------------------------------------------------------------------------*\n");
  printf("| Please enter the modulo expression to be calculated in the form A %% B where A and B are integers |\n");
  printf("| Enter Q to quit                                                                                  |\n");
  printf("*--------------------------------------------------------------------------------------------------*\n\n");

  while(1) {

	ch = getchar();
	if (ch == 'Q' || ch == 'q') {
           printf("bye\n");
           return 0;
        }

        // check if first number is negative
        if (ch == '-') {
          first_negative = 1;
          ch = getchar();
        }

	// get first number
        i = 0;
	while (isdigit(ch) && i < TOKEN_SIZE - 1) {
	   token[i] = ch;
	   i++;
	   ch = getchar();
	}
	token[i] = '\0';

        // check for buffer max reached
        if (i == TOKEN_SIZE - 1) {
           printf("Your first number is too large\n");
           return 1;
        }

	// convert first number to int
	int first_number = atoi(token);
        if (first_negative) first_number = first_number * -1;

	// throw away input until next number
	while (!isdigit(ch) && ch != '-') {
	   ch = getchar();
	}

        // check if second number is negative
        if (ch == '-') {
          second_negative = 1;
          ch = getchar();
        }

	// get second number
	i = 0;
	while (isdigit(ch) && i < TOKEN_SIZE - 1) {
	   token[i] = ch;
	   i++;
	   ch = getchar();
	}
	token[i] = '\0';
 
        // check for buffer max reached
        if (i == TOKEN_SIZE - 1) {
           printf("Your second number is too large\n");
           return 1;
        }

	// convert second number to int
	int second_number = atoi(token);
        if (second_negative) second_number = second_number * -1;
        
	// check for 0 divisor and perform modulo
        if (second_number != 0) { 
	  int result = first_number % second_number;
	  printf("%d %% %d = %d\n\n", first_number, second_number, result);
	} else {
	  printf("Setting the divisor = 0 returns a floating point exception.\n\n");
	}

        first_negative = 0;
        second_negative = 0;
  }
}
