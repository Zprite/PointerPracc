#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <windows.h>
#define BUFFERSIZE 50
#define nIllegal_chars 5

void print_sentence(char*);
void print_name(char*);
char* get_sentence();
char* get_name();
int nSetninger = 0;

int main()
{
	char* name1 = get_name();
	printf("Navnet ditt er: ");
	print_name(name1);
	printf("\n\n Press any key to continue. . .");
	_getch();
}

void print_sentence(char* x)
{
	int i = 0;
	while (x[i] != '\0')
	{
		printf("%c", x[i]);
		i++;
	}
	printf("\n");
}

void print_name(char* x)
{
	int i = (strlen(x)-1);
	int endof_lastname;
	while (x[i] != ' ')
	{
		i--;
		endof_lastname = i;
	}
	while (i < strlen(x))
	{
		printf("%c", x[i]);
		i++;
	}
	printf(", ");
	for (int i = 0; i < endof_lastname; i++)
	{
		printf("%c", x[i]);
	}
}

char* get_sentence()
{
	int nLetters = 0;
	char* string = (char*)malloc(BUFFERSIZE * sizeof(char));
	char input = '@'; 
	int i = 0;
	while (input != '\n')
	{
		input = getchar();
		string[i] = input;
		i++;
		nLetters++;
	}
	string[i] = '\0';
	nSetninger++;
	return string;
}

char* get_name()
{
	char* string = (char*)malloc(BUFFERSIZE * sizeof(char));
	char input = '@';
	int i = 0;
	printf("Skriv inn fornavn: ");
	while (input != '\n')
	{
		input = getchar();
		if (input != '\n') { string[i] = input; }
		else { string[i] = ' '; }
		i++;
	}
	input = '@';
	printf("Skriv inn etternavn: ");
	while (input != '\n')
	{
		input = getchar();
		if (input != '\n') { string[i] = input; }
		else { string[i] = '\0'; }
		i++;
	}
	nSetninger++;
	return string;
}
