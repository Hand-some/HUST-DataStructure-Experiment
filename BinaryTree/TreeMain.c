#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <TreeUtil.h>
typedef int ElemType;//make sure that it's a basic data type
typedef int Status;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ARRAY_SIZE 10


Tree ** treeArray = NULL;//init an array for tree array.
int indexTreeArray = 0;//index of empty position for the array above
char *fgetsNoN(char *buf, int bufsize, FILE *stream);
Tree * getTreeFromName(char * name);

//initalize tree array
void initTreeArray() {
	int i = 0;
	for (i = 0; i < ARRAY_SIZE; i++) {
		treeArray[i] = NULL;
	}
}
//move this tree to the end of tree array so we can easily remove it
//if you try to vall this func , make sure tree-T has already been in tree array
void removeTreeFromArray(Tree * T) {

	int index = 0;
	for (index = 0; index < indexTreeArray; index++) {
		if (treeArray[index] == T) {
			break;
		}
	}
	//now "index" points at Tree-T
	if (index == indexTreeArray - 1) {//at the end
		treeArray[indexTreeArray - 1] = NULL;
	} else {
		Tree * tail = treeArray[indexTreeArray - 1];
		treeArray[indexTreeArray - 1] = NULL;
		treeArray[index] = tail;
	}
	indexTreeArray--;

}
//as this func's name... print guiding infomation, input and free
Tree * getTree() {
	Tree * T = NULL;
	printf("\nPlease input the name of the tree you want to control:");
	char * name = (char *)malloc(30 * sizeof(char)); fgetsNoN(name, 30, stdin);
	T = getTreeFromName(name);
	free(name);
	return T;
}
//a logistic func to low donw lines of code
Node * getKeyNode(Tree * T) {
	printf("\nPlease input the key of this node:");
	ElemType key = 0; scanf("%d%*c", &key);
	return FindNode(T, key);
}

//InitBiTree
void IBT1() {
	Tree * T = NULL;
	printf("\nPlease input the name of new list:");
	char * name = (char *)malloc(30 * sizeof(char)); fgetsNoN(name, 30, stdin);
	if (InitBiTree(&T)) {
		printf("Binary Tree has been created\n");
		T->name = name;
		treeArray[indexTreeArray] = T; indexTreeArray++;
	} else { printf("\nFailed! Because there is no more space in stake's memory, we can't creat a new tree.\n"); }
}

//Assign
void A2() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		Node * get = getKeyNode(T);
		if (!get) printERROR(3);
		else {
			printf("\nPlease input the new value of this node:");
			ElemType value = 0; scanf("%d%*c", &value);
			Assign(T, get, value); printf("\nsuccessful\n");
		}
	}
}

//Destory
void DT3() {
	Tree * T = getTree();
	if (T) {
		removeTreeFromArray(T);
		DestroyTree(T);
		printf("\nDone!\n");
	} else {
		printERROR(2);
	}
}

//Parent
void P4() {
	Tree * T = getTree();
	if (T) {//not null
		Node * get = getKeyNode(T);
		if (!get) printERROR(3);//not null
		else {
			Node * parent = Parent(T, get);
			if(parent)printf("the parent node: key=%d value=%d", parent->key, parent->data);
			else printf("no parent-node.\n");

		}
	} else {
		printERROR(2);
	}
}

//ClearBiTree
void CBT5() {
	Tree * T = getTree();
	if (T) {
		ClearBiTree(T);//just clear all data, but still keep its position
		printf("\nDone!\n");
	} else {
		printERROR(2);
	}
}

//LeftChild
void LC6() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		Node * get = getKeyNode(T);
		if (!get) printERROR(3);
		else {
			Node * leftChild = LeftChild(T, get);
			if (!leftChild) printf("this node don't have a left child.\n");
			else printf("its left child: key=%d, value=%d.\n", leftChild->key, leftChild->data);
		}
	}
}

//BiTreeEmpty
void BTE7() {
	Tree * T = getTree();
	if (T) {
		if (BiTreeEmpty(T)) {
			printf("\nIt's not empty\n");
		} else {
			printf("\nIt's empty\n");
		}
	} else {
		printERROR(2);
	}
}

//RightChild
void RC8() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		Node * get = getKeyNode(T);
		if (!get) printERROR(3);
		else {
			Node * rightChild = RightChild(T, get);
			if (!rightChild) printf("this node don't have a right child.\n");
			else printf("its right child: key=%d, value=%d.\n", rightChild->key, rightChild->data);
		}
	}
}

//get tree's depth
void BTD9() {
	Tree * T = getTree();
	if (T) {
		int d = BiTreeDepth(T);
		printf("\nIt's depth is %d.\n", d);
	} else {
		printERROR(2);
	}
}

//LeftSibling
void LS10() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		Node * get = getKeyNode(T);
		if (!get) printERROR(3);
		else {
			Node * leftSibling = LeftSibling(T, get);
			if (!leftSibling) printf("this node don't have a left sibling.\n");
			else {
				printf("its left sibling: key=%d value=%d\n", leftSibling->key, leftSibling->data);
			}
		}
	}
}

//get root node
void R11() {
	Tree * T = getTree();
	if (T) {
		Node * root = T->root;
		if (root) {
			printf("\nRoot node:  key=%d value=%d.\n", root->key, root->data);
		} else {
			printf("\nThis tree is empty.\n");
		}
	} else {
		printERROR(2);
	}
}

//RightSibling
void RS12() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		Node * get = getKeyNode(T);
		if (!get) printERROR(3);
		else {
			Node * rightSibling = RightSibling(T, get);
			if (!rightSibling) printf("this node don't have a right sibling.\n");
			else {
				printf("its right sibling: key=%d value=%d\n", rightSibling->key, rightSibling->data);
			}
		}
	}
}

//Value
void V13() {
	Tree * T = getTree();
	if (T) {
		Node * get = getKeyNode(T);
		if (!get) printERROR(3);
		else {
			printf("its value is %d", Value(T, get));
		}
	} else {
		printERROR(2);
	}
}

//InsertChild
void IC14() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		Node * get = getKeyNode(T);
		if (!get) printERROR(3);
		else {
			Tree * Tnew = NULL;
			printf("\nPlease input the name of the tree you would like to choose to insert:");
			char * name = (char *)malloc(30 * sizeof(char)); fgetsNoN(name, 30, stdin);
			Tnew = getTreeFromName(name);
			free(name);
			if (!Tnew) printf("this new tree don't exist.\n");
			else {
				printf("Please input 1/0 to choose direction ( 0:L 1:R ):");
				int LR = 0; scanf("%d%*c", &LR);
				if (LR == 1 || LR == 0) {
					if (InsertChild(T, get, LR, Tnew)) {
						removeTreeFromArray(Tnew);
						printf("successful!\n");
					} else printf("the postion have been occupied.\n");
				} else {
					printf("wrong option!\n");
				}
			}
		}
	}
}

//DeleteChild
void DC15() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		Node *get = getKeyNode(T);
		if (!get) printERROR(3);
		else {
			printf("Please choose to delete L or R of this node(L->0 R->1)\n");
			int LR = 0; scanf("%d%*c", &LR);
			if (LR == 1 || LR == 0) {
				if (DeleteChild(T, get, LR)) {
					printf("successful!\n");

				} else printf("Failed, the position don't have child.\n");
			} else {
				printf("error happened!\n");
			}
		}
	}
}

//PreOrderTraverse
void POT16() {
	Tree * T = getTree();
	if (T) {
		Node * root = T->root;
		if (root) {
			PreOrderTraverse(T);
		} else {
			printf("\nThis tree is empty.\n");
		}
	} else {
		printERROR(2);
	}
}

//InOrderTraverse
void IOT17() {
	Tree * T = getTree();
	if (T) {
		Node * root = T->root;
		if (root) {
			InOrderTraverse(T);
		} else {
			printf("\nThis tree is empty.\n");
		}
	} else {
		printERROR(2);
	}
}

//PostOrderTraverse
void POT18() {
	Tree * T = getTree();
	if (T) {
		Node * root = T->root;
		if (root) {
			PostOrderTraverse(T);
		} else {
			printf("\nThis tree is empty.\n");
		}
	} else {
		printERROR(2);
	}
}

//LevelOrderTraverse
void LOT19() {
	Tree * T = getTree();
	if (T) {
		Node * root = T->root;
		if (root) {
			LevelOrderTraverse(T);
		} else {
			printf("\nThis tree is empty.\n");
		}
	} else {
		printERROR(2);
	}
}

//Load tree
void LT20() {
	printf("Please input the name of this tree:");
	char * name = (char*)malloc(sizeof(char) * 30); fgetsNoN(name, 30, stdin);
	Tree * T = LoadTree(name);
	if (T) {
		treeArray[indexTreeArray] = T; indexTreeArray++;
		printf("successful\n");
	} else {
		free(name);
		printf("there is not such a tree's name in your disk\n");
	}
}

//save tree
void ST21() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		if (saveTree(T)) {
			printf("Succesful!\n");
		} else {
			printf("Failed to open file\n");
		}
	}
}

//insert a new node to a given parent node
void IN22() {
	Tree * T = getTree();
	if (!T) printERROR(2);
	else {
		printf("Please input the key of new node:");
		ElemType key = 0; scanf("%d%*c", &key);
		if (FindNode(T, key)) {
			printf("there has been a node with the same key\n");
			return;
		}
		printf("Please input the value of new node:");
		ElemType value = 0; scanf("%d%*c", &value);
		Node * newNode = (Node*)malloc(sizeof(Node));
		newNode->key = key;
		newNode->data = value;
		newNode->left = NULL; newNode->right = NULL;
		if (!BiTreeEmpty(T)) {//it's empty now
			T->root = newNode;
			T->length++;
			printf("successful\n");
		} else {
			printf("Please input the key of parent of this node:");
			ElemType parentKey = 0; scanf("%d%*c", &parentKey);
			Node * parentNode = FindNode(T, parentKey);
			if (!parentNode) { printf("there isn't such a node with this key.\n"); return; }

			printf("Please choose left or right( 0:left 1: right ):");
			int LR = 0; scanf("%d%*c", &LR);
			if (LR == 0 && parentNode->left == NULL) {
				parentNode->left = newNode;
				T->length++;
			} else if (LR == 1 && parentNode->right == NULL) {
				parentNode->right = newNode;
				T->length++;
			}
		}
	}
}
//Quickly Create a binary tree with a pre-order array
void QCT23(){
    Tree * T = NULL;
	printf("\nPlease input the name of new list:");
	char * name = (char *)malloc(30 * sizeof(char)); fgetsNoN(name, 30, stdin);

	T = (Tree*)malloc(sizeof(Tree));
	if(!T) exit(1);

	T->name = name;
    T->root = NULL;
    T->length = 0;

    printf("\nPlease input the pre-order-traverse( null-># ) data of new list:");
    createTreeQuickly(&(T->root));
    printf("\nPlease input the pre-order-traverse key ( split by space ) of new list:");
    valueKeyFromQuick(T->root);
    getchar();
	if (T->root) {
		printf("Binary Tree has been created\n");
		T->name = name;
		treeArray[indexTreeArray] = T; indexTreeArray++;
	} else { printERROR(1); }
}

//print the top-layer menu
void printMenu() {
	system("cls");	printf("\n");
	printf("          Menu for Binary Tree\n");
	printf("-----------------Trees List----------------------\n");
	int i = 0;
	for(i = 0; i < indexTreeArray; i++){
        printf("%s ,",treeArray[i]->name);
	}
	printf("\n-------------------------------------------------\n");
	printf("    	  1. InitBiTree\t\t\t2. Assign\n");
	printf("    	  3. DestroyTree\t\t4. Parent \n");
	printf("    	  5. ClearBiTree\t\t6. LeftChild\n");
	printf("    	  7. BiTreeEmpty\t\t8. RightChild\n");
	printf("    	  9. BiTreeDepth\t\t10. LeftSibling\n");
	printf("    	  11. Root\t\t\t12. RightSibling\n");
	printf("    	  13. Value\t\t\t14. InsertChild\n");
	printf("    	  15. DeleteChild\t\t16. PreOrderTraverse\n");
	printf("    	  17. InOrderTraverse\t\t18. PostOrderTraverse\n");
	printf("    	  19. LevelOrderTraverse\t20. LoadTree\n");
	printf("    	  21. saveTree\t\t\t22. InsertNode\n");
	printf("    	  23. QuickCreateTree\n");
	printf("    	  0. Exit\n");
	printf("-------------------------------------------------\n");
}

int main() {

	treeArray = (Tree **)malloc(sizeof(Tree*) * ARRAY_SIZE);//init an array for tree array.(max size is 10)
	initTreeArray();
	indexTreeArray = 0;//index for the array above
	int op = 1;
	while (op) {
		printMenu();//print the top-layer menu
		printf("    Please select your option [0~12]:");
		scanf("%d%*c", &op);

		switch (op) {
		case 1://InitBiTree
			IBT1(); break;
		case 2://Assign
			A2(); break;
		case 3://Destroy
			DT3(); break;
		case 4://Parent
			P4(); break;
		case 5://ClearBiTree
			CBT5(); break;
		case 6://LeftChild
			LC6(); break;
		case 7://Empty
			BTE7(); break;
		case 8://RightChild
			RC8(); break;
		case 9://Depth
			BTD9(); break;
		case 10://LeftSibling
			LS10(); break;
		case 11://Root
			R11(); break;
		case 12://RightSibling
			RS12(); break;
		case 13://get value
			V13(); break;
		case 14://InsertChild
			IC14(); break;
		case 15://DeleteChild
			DC15(); break;
		case 16://PreOrderTraverse
			POT16(); break;
		case 17://InOrderTraverse
			IOT17(); break;
		case 18://PostOrderTraverse
			POT18(); break;
		case 19://LevelOrderTraverse
			LOT19(); break;
		case 20://LoadTree
			LT20();
			break;
		case 21://Save tree
			ST21();
			break;
		case 22://InsertNode
			IN22(); break;
        case 23://create a binary tree in a fast way
            QCT23();break;
		case 0:
			op = 0;
			break;
		}
		system("pause");
	}
	printf("\nSee you\n");
	return 0;
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

//get tree node
Tree * getTreeFromName(char * name) {
	int i = 0;
	for (i = 0; i < indexTreeArray; i++) {
		if (!strcmp(treeArray[i]->name, name)) {
			return treeArray[i];
		}
	}
	return NULL;
}
