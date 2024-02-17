#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int size = 0;
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
		size++;
	}
	return size;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	char* str = (char*)malloc(length(head) * sizeof(char));
	int index = 0;
	node* temp = head;
	while(temp->next != NULL){
		str[index] = temp->letter;
		index++;
		temp = temp->next;
	}
	str[index] = temp->letter;
	return str;
}

// inserts character to the linkedlist
// if the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* temp = *pHead;
	if(temp == NULL){
		temp = (node*)malloc(sizeof(node));
		temp->letter = c;
		temp->next = NULL;
		*pHead = temp;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		node* insertion = (node*)malloc(sizeof(node));
		insertion->letter = c;
		insertion->next = NULL;
		temp->next = insertion;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* prev = *pHead;
	node* temp = prev->next;
	while(temp->next != NULL){
		temp = prev->next;
		free(prev);
		prev = temp;
	}
	free(*pHead);
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);

	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}