//
//	OFF LIBRARY
//	v.1.0.0
//	@frenziedcode
//

/* ------------------------ HEADER ------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Library
{
	char bookName[50];
	char authorName[50];
	char publicationDate[5];
};

/* ------------------------ END ------------------------ */

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
		printf("The book has been added");
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
			fclose(file);
		}
	}
}

int main() 
{

	printf("\n\n");
	printf("📚 OFF LIBRARY"); //Exec Header
	printf("\n\n");

	/*  -------------------- */

	int selectOption;

	printf("MENU\n\n");
	printf("1. [Add Book]\n2. [List of Books]\n\n\n");
	scanf("%d", &selectOption);

	if (selectOption == 1)
	{
		printf("ADD BOOK\n");
		addBook();		
	}
	if (selectOption == 2)
	{
		printf("LIST OF BOOKS\n");
		listBook();
	}

	return 0;
}