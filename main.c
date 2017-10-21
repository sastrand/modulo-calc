// Sascha Strand
// 2017-10-21
// Modulo Calculator

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {

  char token[64];
  char ch = '0';
  int i = 0;

  printf("*--------------------------------------------------------------------------------------------------*\n");
  printf("| Please enter the modulo expression to be calculated in the form A %% B where A and B are integers |\n");
  printf("| Enter Q to quit                                                                                  |\n");
  printf("*--------------------------------------------------------------------------------------------------*\n\n");

  while(1) {

	ch = getchar();
	if (ch == 'Q') {
           printf("bye\n");
           return 0;
        }

	// get first number
        i = 0;
	while (isdigit(ch)) {
	   token[i] = ch;
	   i++;
	   ch = getchar();
	}
	token[i] = '\0';

	// convert first number to int
	int firstnumber = atoi(token);

	// throw away input until next number
	while (!isdigit(ch)) {
	   ch = getchar();
	}

	// get second number
	i = 0;
	while (isdigit(ch)) {
	   token[i] = ch;
	   i++;
	   ch = getchar();
	}
	token[i] = '\0';

	// convert second number to int
	int secondnumber = atoi(token);

	// perform modulo
	int result = firstnumber % secondnumber;
	printf("%d %% %d = %d\n\n", firstnumber, secondnumber, result);
  }
}
