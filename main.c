//
//	OFF LIBRARY
//	v.1.0.0
//	@frenziedcode
//

/* ------------------------ HEADER ------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EXIT_FLAG = 0;

struct Library
{
	char bookName[50];
	char authorName[50];
	char publicationDate[5];
};

/* ------------------------ END ------------------------ */

int menuHome (int *selectOption)
{
	printf("\n\n");
	printf("📚 OFF LIBRARY"); printf("\e[2m v.1.0.2 \e[0m"); //Exec Header
	printf("\n\n");

	/*  --------------- */


	printf("➤ MENU\n\n");
	printf("1. [Add Book]\n");
	printf("2. [List of Books]\n");
	printf("3. [Exit]\n\n");
	printf("Select one option: ");
	scanf("%d", &*selectOption);
	printf("\n");

	getchar();

	return (*selectOption);
}

void addBook()
{
	struct Library newBook;

	printf("Book name: ");
	fgets(newBook.bookName, 50, stdin);
	puts(newBook.bookName);

	printf("Author: ");
	fgets(newBook.authorName, 50, stdin);
	puts(newBook.authorName);

	printf("Year of publication: ");
	fgets(newBook.publicationDate, 5, stdin);
	puts(newBook.publicationDate);


	FILE *file = fopen("books.txt", "a"); //Create books.txt
	if (file != NULL)
	{
		fprintf(file, "%s%s%s\n", newBook.bookName, newBook.authorName,newBook.publicationDate);
		fclose(file);
		printf("\n\n");
		printf("The book has been added\n");

	} 
	else
	{
		printf("Try again later");
	}
}

void listBook()
{
	printf("\n");

	FILE *file = fopen("books.txt", "r");
	if (file != NULL)
	{
		struct Library library;

		while(fscanf(file,"%s", library.bookName) != EOF)
		{
			printf(" Nome: %s\n Author: %s\n Publication: %s\n\n ", library.bookName, library.authorName, library.publicationDate);
			printf("-----------------------------------\n");
		}

		fclose(file);
	}
	if (file == NULL)
	{
		printf("There are no books on your shelf\n");
	}
}


/* ------------------------ MAIN ------------------------ */


int main() 
{

	int selectOption;

	while(!EXIT_FLAG)
	{
		menuHome(&selectOption);

		if (selectOption == 1)
		{
			printf("\n\n");
			printf("➤ ADD BOOK\n\n");
			addBook();	

		}
		else if (selectOption == 2)
		{
			printf("\n\n");
			printf("LIST OF BOOKS\n");
			listBook();
		}
		else if ( selectOption == 3)
		{
			printf("Closing program...\n\n");
			exit(0);
		}
		else  if (selectOption == 4)
			EXIT_FLAG = 1;

	}

	return 0;
}


/* ------------------------ END ------------------------ */

