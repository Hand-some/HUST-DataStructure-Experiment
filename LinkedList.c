#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef int ElemType;//make sure that it's a basic data type
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1

//this is the struct taking the ture data
typedef struct lnode {
	ElemType data;
	struct lnode * next;
} LNode;

//this is the struct as the head node taking some infomation of this linked list
typedef struct sqlist {
	int length;
	char * name;
	LNode * head;
}SqList;


Status InitList(SqList ** L);
void DestoryList(SqList * L);
void ClearList(SqList * L);
Status ListEmpty(SqList * L);
int ListLength(SqList * L);
Status GetElem(SqList * L, int i, ElemType * e);
int LocateElem(SqList * L, ElemType * e);
Status PriorElem(SqList * L, ElemType * cur_e, ElemType * pre_e);
Status NextElem(SqList * L, ElemType * cur_e, ElemType * next_e);
Status ListInsert(SqList * L, int i, ElemType * e);
void ListDelete(SqList * L, int i, ElemType * e);
Status ListTraverse(SqList * L);
Status SaveList(SqList * L);
Status LoadList(SqList ** L, char * name);
char *fgetsNoN(char *buf, int bufsize, FILE *stream);

int main() {
	SqList * L = NULL;
	int op = 1;
	while (op) {
		system("cls");	printf("\n");
		printf("      Menu for Linear Table On Sequence Structure \n");
		if (L != NULL) {
			printf("  List:%s  is under your control .\n", L->name);
		}
		printf("-------------------------------------------------\n");
		printf("    	  1. InitList		8. PriorElem\n");
		printf("    	  2. DestroyList	9. NextElem \n");
		printf("    	  3. ClearList		10. ListInsert\n");
		printf("    	  4. ListEmpty		11. ListDelete\n");
		printf("    	  5. ListLength		12. ListTraverse\n");
		printf("    	  6. GetElem		13. SaveList\n");
		printf("    	  7. LocateElem		14. LoadList\n");
		printf("    	  0. Exit\n");
		printf("-------------------------------------------------\n");
		printf("    Please select your option [0~12]:");
		scanf("%d%*c", &op);

		int pos = 0;
		ElemType * cur = (ElemType *)malloc(sizeof(ElemType));

		switch (op) {
		case 1://IntiaList
			printf("\nPlease input the name of new list.\n");
			char * name = (char *)malloc(30 * sizeof(char)); fgetsNoN(name, 30, stdin);

			if (InitList(&L) == OK) printf("Linear Table has been created！\n");
			else printf("\nFailed! Because there is no more space in stake's memory, we can't creat a new table.\n");
			L->name = name;
			break;
		case 2://DestoryList
			if (L == NULL) printf("You should init or load first!\n");
			else DestoryList(L);
			break;
		case 3://ClearList
			if (L == NULL) printf("You should init or load first!\n");
			else ClearList(L);
			break;
		case 4://ListEmpty
			if (L == NULL) printf("You should init or load first!\n");
			else {
				if (ListEmpty(L)) {
					printf("\n----This list is empty.\n");
				} else {
					printf("\n----This list is not empty.\n");
				}
			}
			break;
		case 5://ListLength
			if (L == NULL) printf("You should init or load first!\n");
			else printf("\n----The length of this list is %d.\n", ListLength(L));
			break;
		case 6://GetElem
			if (L == NULL) printf("You should init or load first!\n");
			else {
				printf("\nPlease input the element's position.\n");
				scanf("%d%*c", &pos);

				ElemType * get = (ElemType *)malloc(sizeof(ElemType));
				if (GetElem(L, pos, get)) {
					printf("\n----The element you get is %d.\n", *get);
				} else {
					printf("\n----Failed! The position you input is out of bound.\n");
				}
				free(get);
			}
			break;
		case 7://LocateElem
			if (L == NULL) printf("You should init or load first!\n");
			else {
				printf("\nPlease input the model element.\n");
				scanf("%d%*c", cur);
				pos = LocateElem(L, cur); pos++;
				if (pos != 0) {
					printf("\n----The index of the first element equal with yours is %d.\n", pos);
				} else {
					printf("\n----Failed! It seems like that we don't have such element.\n");
				}
			}
			break;
		case 8://PriorElem
			if (L == NULL) printf("You should init or load first!\n");
			else {
				printf("\nPlease input the beginning element:");
				scanf("%d%*c", cur);

				int pos = LocateElem(L, cur);
				if (pos != -1) {
					ElemType * get = (ElemType *)malloc(sizeof(ElemType));
					if (PriorElem(L, cur, get)) {
						printf("\n----Failed! The element you select don't have a prior element.\n");
					} else {
						printf("\n----The prior element you get is %d.\n", *get);
						free(get);
					}
				} else {
					printf("\n----Failed! We can't find such a element.\n");
				}

			}
			break;
		case 9://NextElem
			if (L == NULL) printf("You should init or load first!\n");
			else {
				printf("\nPlease input the beginning element:");
				scanf("%d%*c", cur);

				int pos = LocateElem(L, cur);
				if (pos != -1) {
					ElemType * get = (ElemType *)malloc(sizeof(ElemType));
					if (NextElem(L, cur, get)) {
						printf("\n----Failed! The element you select don't have a next element.\n");
					} else {
						printf("\n----The next element you get is %d.\n", *get);
						free(get);
					}
				} else {
					printf("\n----Failed! We can't find such a element.\n");
				}
			}
			break;
		case 10://ListInsert
			if (L == NULL) printf("You should init or load first!\n");
			else {
				printf("\n---Please input the position:");
				scanf("%d%*c", &pos);
				printf("\n---Please input the element:");
				ElemType * elemNew = (ElemType *)malloc(sizeof(ElemType));
				scanf("%d%*c", elemNew);

				if (ListInsert(L, pos, elemNew)) {
					printf("\n----Successful!\n");
				} else {
					printf("\n----Failed! The position you input is out of bound.\n");
				}
				free(elemNew);
			}
			break;
		case 11://ListDelete
			if (L == NULL) printf("You should init or load first!\n");
			else {
				printf("\n---Please input the position:");
				scanf("%d%*c", &pos);
				ElemType * elem = (ElemType *)malloc(sizeof(ElemType));
				ListDelete(L, pos, elem);
				printf("\n----Successfully delete element:%d!\n", *elem);
				free(elem);
			}
			break;
		case 12://ListTraverse
			if (L == NULL) printf("You should init or load first!\n");
			else if (!ListTraverse(L)) printf("\nThis list is empty!\n");
			break;
		case 13://SaveList
			if (L == NULL) printf("You should init or load first!\n");
			else {
				if (SaveList(L)) {
					printf("Successful!\n ");
				} else {
					printf("We can't open this file.\n ");
				}
			}
			break;
		case 14://LoadList
			printf("\n---Please input list's name:");
			char * nameIn = (char *)malloc(30 * sizeof(char));
			fgetsNoN(nameIn, 30, stdin);
			if (LoadList(&L, nameIn)) {
				printf("\n---Successfully load!\n");
			} else {
				printf("\n---Loading failed!\n");
			}
			break;
		case 0://Exit
			break;
		}
		free(cur);
		Sleep(1000);
	}
	printf("See you!\n");
	return 0;
}

Status SaveList(SqList * L) {
	FILE * fP = fopen(L->name, "wb");
	if (fP != NULL) {
		LNode * p = L->head;
		while (p != NULL) {
			fwrite(p->data, sizeof(ElemType), 1, fP);
			p = p->next;
		}
		fclose(fP);
		return TRUE;
	} else {
		printf("File open error\n ");
		fclose(fP);
		return FALSE;
	}
}

Status LoadList(SqList ** Lp, char * name) {
	SqList * L = *Lp;
	if (L != NULL) {
		DestoryList(L);
		L = NULL;
	}
	if (InitList(Lp) != OK) return FALSE;
	L = *Lp;
	L->name = name;
	FILE * fP = fopen(L->name, "rb");
	if (fP != NULL) {
		LNode * newP = (LNode *)malloc(sizeof(LNode));
		LNode * p = newP;
		int flag = 1;

		while (fread(&( newP->data ), sizeof(ElemType), 1, fP)) {
			L->length++;
			if (flag) {
				L->head = newP;
				flag = 0;
			} else {
				p->next = newP;
			}
			newP->next = NULL;
			p = newP;
			newP = (LNode *)malloc(sizeof(LNode));
		}
		free(newP);//because the last p is useful
		fclose(fP);

		return TRUE;
	} else {
		printf("File open error\n ");
		fclose(fP);
		return FALSE;
	}
}

Status InitList(SqList ** Lp) {
	*Lp = (SqList *)malloc(sizeof(SqList));

	SqList * L = *Lp;
	L->length = 0;
	L->head == NULL;//I didn't set any space for the head node for saving space
	//the name part space will be spaced by outside
	return OK;
}

void DestoryList(SqList * L) {
	
	ClearList(L);

	free(L->name);
	free(L);
}

void ClearList(SqList * L) {
	LNode * p = L->head;
	LNode * pNext = p;
	//free all data in this list
	while (p->next != NULL) {
		pNext = p->next;
		free(p);
		p = pNext;
	}
	free(p);
	L->length = 0;
}

Status ListEmpty(SqList * L) {
	if (L->length == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int ListLength(SqList * L) {
	return L->length;
}

Status GetElem(SqList * L, int i, ElemType * e) {
	if (i > L->length || i < 1) {
		return FALSE;
	}//Index out of bound exception

	int count = 0;//this count variable is according to the usual
	LNode * p = L->head;
	while (p != NULL) {
		count++;
		if (count == i) {
			*e = p->data;
			return OK;
		}
		p = p->next;
	}
	return FALSE;

}

Status PriorElem(SqList * L, ElemType * cur_e, ElemType * pre_e) {
	LNode * p = L->head;
	while (p != NULL) {

		if (p->next->data == *cur_e) {//if the condition is true, then the point now is the prior one
			*pre_e = p->data;
			return OK;
		}
		p = p->next;
	}
	return FALSE;//including two situation(no such elemType in this list or cur_e is the head one)
}

Status NextElem(SqList * L, ElemType * cur_e, ElemType * next_e) {
	LNode * p = L->head;
	while (p != NULL) {
		if (p->data == *cur_e) {
			if (p->next != NULL) {
				*next_e = p->next->data;
				return OK;
			}
		}
		p = p->next;
	}
	return FALSE;//including two situation(no such elemType in this list or cur_e is the last one)
}

Status ListInsert(SqList * L, int i, ElemType * e) {
	int count = 0;
	LNode * p = L->head;
	if (i>L->length || i<1) {
		return FALSE;
	}
	if (i = 1) {//insert to be the first one
		LNode * newP = (LNode *)malloc(sizeof(LNode));
		newP->data = *e;
		newP->next = L->head;
		L->head = newP;
	} else {
		while (p != NULL) {
			count++;//fit as usual
			if (count == i-1) {//find the prior
				LNode * newP = (LNode *)malloc(sizeof(LNode));
				newP->data = *e;
				LNode * pNext = p->next;
				p->next = newP;
				newP->data = pNext;//exchange the next pointer
				L->length++;
				return OK;
			}
			p = p->next;
		}
	}

	return FALSE;
}

void ListDelete(SqList * L, int i, ElemType * e) {
	int count = 0;
	LNode * p = L->head;
	if (i>L->length || i<1) {
		return FALSE;
	}
	if (i == 1) {
		LNode * freeP = L->head;
		L->head = L->head->next;
		free(freeP);
	}
	while (p != NULL) {
		count++;//fit as usual
		if (count == i-1) {//find the prior ( p->next would never be null
			LNode * freeP = p->next;
			p->next = p->next->next;
			free(freeP);
			L->length--;
			return OK;
		}

		p = p->next;
	}
	return FALSE;

}

Status ListTraverse(SqList * L) {
	int i;
	printf("\n-----------all elements -----------------------\n");
	//for (i = 0; i<L->length; i++) printf("%d ", L->elem[i]);
	LNode * p = L->head;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n------------------ end ------------------------\n");
	return L->length;//return the length of list
}

int LocateElem(SqList * L, ElemType * e) {
	int count = 0;
	LNode * p = L->head;
	while (p != NULL) {
		count++;
		if (p->data == *e) return count;
		p = p->next;
	}
	return -1;
}

char *fgetsNoN(char *buf, int bufsize, FILE *stream) {
	char * returnP = fgets(buf, bufsize, stream);
	int i = 0;
	while (buf[i] != '\n') {
		i++;
	}
	buf[i] = '\0';
	return returnP;
}