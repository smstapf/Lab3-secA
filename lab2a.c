/*
 * lab2a.c
 *
 *  Created on: Sep 7, 2017
 *      Author: sms2d7
 */


#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#define INT_SIZE 16

int main()
{
	unsigned short number;
	char choice;

	printf("What number would you like to display in binary?");
	scanf("%hu", &number);
	printf("In what way would you like the computer to calculate the binary representation? \nA. Arithmetic operation \nB. Bitwise Operation\n");
	choice = getchar();
	choice = getchar();

	switch (choice)
	{
		case 'A':
		{
			unsigned short original = number;
			int remainder;
			long binary = 0;
			long i = 1;

			while (number != 0)
			{
				remainder = number % 2;
				number = number / 2;
				binary = binary + (remainder*i);
				i = i * 10;
			}
			printf("The binary representation of %hi using arithmetic operation is %li", original, binary);
			break;
		}
		case 'B':
		{
			int index;
			int i;
			int bin[INT_SIZE];

			index = INT_SIZE - 1;

			while (index >= 0)
			{

				bin[index] = number & 1;
				index--;
				number >>= 1;
			}

			printf("Converted binary: ");
			for (i = 0; i<INT_SIZE; i++)
			{
				printf("%d", bin[i]);
			}
		}
	}

	return 0;
}
