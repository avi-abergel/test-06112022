#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
// struct to collect counting info about english letters found in a text file.
typedef struct T_letter {  //bug: typedef name of a struct is usually differen than the struct name.
	char small;
	char big;
	int counter;
	struct T_letter* prev;  //bug: no prev
	struct T_letter* next;  //bug: no next
}letter;


//Function to free linked list
void freeList(letter* head) {
	//bug: releseItem is unnecessary
	letter* runItem = head;
	while (runItem != NULL) {
		free(runItem);
		runItem = runItem->next;  //bug: runItem=runItem->next should be after free(runItem).
	}
}
int main()
{
	//Next two string represents all the english alphabets (small and capital)
	char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
	char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int lettersCountArr[26] = { 0 };  //bug: englishalphabet has 26 letters
	char readChar, ch;
	FILE* f;
	f = fopen("myFile.txt", "r");

	// Display the content of myFile.txt and count letters
	printf("the content of myFile.txt :\n");
	while ((readChar = fgetc(f)) != EOF) {  //bug: when using fgetc, to stop the wile we will use the condition fgetc!=EOF
		printf("%c", readChar);
		for (int i = 0; i < strlen(smallAlpha); i++) {  //bug: i++ and not ++i
			if (readChar == smallAlpha[i] || readChar == bigAlpha[i])
				lettersCountArr[i]++;
		}
	}
	fclose(f);

	// Build Linked list from file content
	// Every node represent English letter (small and big).
	letter* HEAD = NULL;
	letter* TAIL = NULL;
	for (int j = 0; j < strlen(smallAlpha); ++j) {
		letter* letterItem = (letter*)malloc(sizeof(letter));
		if (!letterItem) {
			printf("Error Allocating Memory!");  //bug: puts instead of printf
			exit(1);
		}
		letterItem->small = smallAlpha[j]; // bug: cant add an integer to a char, instaed can be written letterItem->small=smallAlpha[j].
		letterItem->big = bigAlpha[j];   //bug: cant add an integer to a char, instaed can be written letterItem->big=bigAlpha[j].
		letterItem->counter = lettersCountArr[j];
		// Creating the linked list
		if (HEAD == NULL)  //bug: not checking if letterItem is the firs item on the list
		{
			HEAD = letterItem;
			TAIL = letterItem;
			letterItem->next = NULL;
			letterItem->prev = NULL;
		}
		else
		{
		 TAIL->next = letterItem;
		 letterItem->prev = TAIL;
		 TAIL = letterItem;
		 TAIL->next = NULL;
		}
	}
	return 0;
}