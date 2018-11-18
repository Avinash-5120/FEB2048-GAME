//Tried rotating matrix to apply a single function for every option
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct board{
	int **a;
	int size;
	int moves;
	char name[20];
};
struct person{
	char name[20];
	int bestMoves = -1;
	struct tm tm;
	int boardSize;
};
void insertIntoleaderBoard(struct board*);
int binarySearch(int key, int *list, int start, int end)
{
	if (start > end)
		return -1;
	int mid;
	if (start == end)
	{
		if (list[start] == key)
			return start;
		else
			return -1;
	}
	mid = (start + end) / 2;
	if (list[mid] == key)return mid;
	else if (list[mid] > key)
		return binarySearch(key, list, start, mid - 1);
	else
		return binarySearch(key, list, mid + 1, end);
}
int Left(struct board *Board,int *feb){
	int i, j, index, feb1, feb2, mov = -1, win = 0;//if right is not possible -1, 0 if move is possible,1 if won
	for (i = 0; i < Board->size; i++)
	{
		feb1 = 0;
		for (j = 1; j <Board->size ; j++)
		{
			if (Board->a[i][j] == 0)
				continue;
			feb2 = j;
			if (Board->a[i][feb1] == 0)
			{
				Board->a[i][feb1] = Board->a[i][feb2];
				Board->a[i][feb2] = 0;
				mov = 0;
			}
			else
			{
				index = binarySearch(Board->a[i][feb1], feb, 0, (2 * Board->size*Board->size) - 1);
				if (feb[index + 1] == Board->a[i][feb2] || (index!=0&&feb[index - 1] == Board->a[i][feb2]))
				{
					mov = 0;
					Board->a[i][feb1] += Board->a[i][feb2];
					if (Board->a[i][feb1] == feb[(2 * Board->size*Board->size) - 2])
						win = 1;
					Board->a[i][feb2] = 0;
					feb1++;

				}
				else
				{
					Board->a[i][feb1 + 1] = Board->a[i][feb2];
					if (feb1 + 1 != feb2)
					{
						Board->a[i][feb2] = 0;
						mov = 0;
					}
					feb1++;
				}
			}
		}
	}
	return mov + win;
}
int Up(struct board *Board,int *feb){
	int i, j, index, feb1, feb2, mov = -1, win = 0;//if right is not possible -1, 0 if move is possible,1 if won
	for (j = 0; j < Board->size; j++)
	{
		feb1 = 0;
		for (i=1; i<Board->size; i++)
		{
			if (Board->a[i][j] == 0)
				continue;
			feb2 = i;
			if (Board->a[feb1][j] == 0)
			{
				Board->a[feb1][j] = Board->a[feb2][j];
				Board->a[feb2][j] = 0;
				mov = 0;
			}
			else
			{
				index = binarySearch(Board->a[feb1][j], feb, 0, (2 * Board->size*Board->size) - 1);
				if (feb[index + 1] == Board->a[feb2][j] || (index!=0&&feb[index - 1] == Board->a[feb2][j]))
				{
					mov = 0;
					Board->a[feb1][j] += Board->a[feb2][j];
					if (Board->a[feb1][j] == feb[(2 * Board->size*Board->size) - 2])
						win = 1;
					//Board->a[feb2][j] = 0;
					//if (feb1 + 1 != feb2)
					//{
						Board->a[feb2][j] = 0;
					//	mov = 0;
					//}
					feb1++;

				}
				else
				{
					Board->a[feb1 + 1][j] = Board->a[feb2][j];
					if (feb1 + 1 != feb2)
					{
						Board->a[feb2][j] = 0;
						mov = 0;
					}
					feb1++;
				}
			}
		}
	}
	return mov + win;
}
int Down(struct board *Board,int *feb){ 
	int i, j, index, feb1, feb2, mov = -1, win = 0;//if right is not possible -1, 0 if move is possible,1 if won
	for (j = 0; j < Board->size; j++)
	{
		feb1 = Board->size-1;
		for (i =Board->size-2; i>=0; i--)
		{
			if (Board->a[i][j] == 0)
				continue;
			feb2 = i;
			if (Board->a[feb1][j] == 0)
			{
				Board->a[feb1][j] = Board->a[feb2][j];
				Board->a[feb2][j] = 0;
				mov = 0;
			}
			else
			{
				index = binarySearch(Board->a[feb1][j], feb, 0, (2 * Board->size*Board->size) - 1);
				if (feb[index + 1] == Board->a[feb2][j] || (index!=0&&feb[index - 1] == Board->a[feb2][j]))
				{
					mov = 0;
					Board->a[feb1][j] += Board->a[feb2][j];
					if (Board->a[feb1][j] == feb[(2 * Board->size*Board->size) - 2])
						win = 1;
					//Board->a[feb2][j] = 0;
					//if (feb1 + 1 != feb2)
					//{
					Board->a[feb2][j] = 0;
					//	mov = 0;
					//}
					feb1--;

				}
				else
				{
					Board->a[feb1 - 1][j] = Board->a[feb2][j];
					if (feb1 - 1 != feb2)
					{
						Board->a[feb2][j] = 0;
						mov = 0;
					}
					feb1--;
				}
			}
		}
	}
	return mov + win;
}
int Right(struct board *Board,int *feb)
{
	int i, j, index,feb1, feb2,mov=-1,win=0;//if right is not possible -1, 0 if move is possible,1 if won
	for (i = 0; i < Board->size; i++)
	{
		feb1 = Board->size - 1;
		for (j = Board->size - 2; j >= 0; j--)
		{
			if (Board->a[i][j] == 0)
				continue;
			feb2 = j;
			if (Board->a[i][feb1] == 0)
			{
				Board->a[i][feb1] = Board->a[i][feb2];
				Board->a[i][feb2] = 0;
				mov = 0;
			}
			else
			{
				index = binarySearch(Board->a[i][feb1],feb,0, (2 * Board->size*Board->size) - 1);
				if (feb[index + 1] == Board->a[i][feb2] ||(index!=0&& feb[index - 1] == Board->a[i][feb2]))
				{
					mov = 0;
					Board->a[i][feb1]+=Board->a[i][feb2];
					if (Board->a[i][feb1] == feb[(2 * Board->size*Board->size) - 2])
						win = 1;
					Board->a[i][feb2] = 0;
					feb1--;
					
				}
				else
				{
					Board->a[i][feb1 - 1] = Board->a[i][feb2];
					if (feb1 - 1 != feb2)
					{
						Board->a[i][feb2] = 0;
						mov = 0;
					}
					feb1--;
				}
			}
		}
	}
	return mov + win;
}
void drawBoard(struct board *Board)
{
	int i, j;
	system("cls");
	for (i = 0; i < Board->size; i++)
	{
		for (j = 0; j < Board->size; j++)
			printf("%d\t", Board->a[i][j]);
		printf("\n");
	}
	printf("Number of moves %d \n", Board->moves);
}
int placeOne(struct board *Board)
{
	int i, j, random = rand(), k = -1, BSize = (Board->size*Board->size);
	do{
		random = (random + 1) % BSize;
		i = random / Board->size;
		j = random%Board->size;
		k++;
	} while (Board->a[i][j] != 0 && k <= BSize);
	if (k > BSize)
		return -1;
	return random;
}
int hasMove(struct board *Board, int *feb)
{
	int i, j,test;
	for (i = 0; i < Board->size; i++)
	{
		for (j = 0; j < Board->size; j++)
		{
			if (j + 1 != Board->size)
			{
				test = binarySearch(Board->a[i][j] + Board->a[i][j + 1], feb, 0, 30);
				if (test != -1)
					return 1;
			}
			if (i + 1 != Board->size)
			{
				test = binarySearch(Board->a[i][j] + Board->a[i+1][j], feb, 0, 30);
				if (test != -1)
					return 1;
			}

		}
	}
	return 0;
}
int copyFromFile(struct board *Board){
	FILE *r;
	int i;
	r = fopen("savedGame.txt", "r");
	//struct board b;
	if (r == NULL)
		return -1;
	fread(Board, sizeof(struct board), 1, r);
	Board->a = (int**)malloc(sizeof(int*)*Board->size);
	for (i = 0; i < Board->size; i++)
		Board->a[i] = (int*)malloc(sizeof(int)*Board->size);
	for (i = 0; i < Board->size; i++)
	{
		fread(Board->a[i], sizeof(int)*Board->size, 1, r);
	}
	//printf("%d", b.a[1][1]);
	for (i = 0; i < 5; i++)printf("\n");
	for (i = 0; i < 5; i++)printf("\t");
	printf("Welcom back %s\n\t\tpress enter to enter game\n", Board->name);
	getchar();
	fclose(r);
	return 0;
}
void printLeaderBoard(int size){
	struct person liderboardData[21];//, currentPerson;
	int i, j, flag = -1, count = 0;
	//time_t rawtime = time(NULL);
	FILE *read, *write;
	if (size == 2)
		read = fopen("savedLeaderBoard.txt", "r");
	else if (size == 4)
		read = fopen("savedLeaderBoard4.txt", "r");
	if (read == NULL)
	{
		printf("error occured while reading a file \n");
		return;
	}
	//currentPerson.bestMoves = Board->moves;
	//for (i = 0; Board->name[i] != '\0'; i++)
		//currentPerson.name[i] = Board->name[i];
	//currentPerson.boardSize = Board->size;
	//currentPerson.tm = *(localtime(&rawtime));
	for (i = 0; i < 20; i++)
	{
		flag = fread(&liderboardData[i], sizeof(struct person), 1, read);
		if (flag > 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	fclose(read);
	system("cls");
	printf("SN0 \t   DATE       \t  NAME  \t MOVES \t BOARD\n");
	for (i = 0; i < count; i++)
	{
		printf("%d \t %d/%d/%d \t %s\t\t  %d \t  %d\n", i + 1, liderboardData[i].tm.tm_mday, liderboardData[i].tm.tm_mon + 1, liderboardData[i].tm.tm_year + 1900, liderboardData[i].name, liderboardData[i].bestMoves, liderboardData[i].boardSize);
	}
	printf("\n");
}

void initialiser(int option, struct board *Board)
{
	int i, j,returnval=-1, size, next,bordnum;
	if (option == 1)
	{
		size = 2;
	}
	else if (option == 2)
	{
		size = 4;
	}
	else if (option == 3)
	{
		returnval=copyFromFile(Board);
	}
	else if (option == 4)
	{
		printf(" \t enter 2 for 2x2 board and 4 for 4x4 board  : ");
		scanf("%d", &bordnum);
		printLeaderBoard(bordnum);
		system("pause");
		exit(0);
	}
	else
	{
		printf("invalid input\n");
		system("pause");
		exit(0);
	}
	if (returnval == -1)
	{
		Board->a = (int **)malloc(sizeof(int*)*size);
		Board->moves = 0;
		Board->size = size;
		printf("enter your name to continue : ");
		scanf("%s", Board->name);
		for (i = 0; i < size; i++)
		{
			Board->a[i] = (int*)malloc(sizeof(int)*size);
			for (j = 0; j < size; j++)
				Board->a[i][j] = 0;
		}
		next = placeOne(Board);
		i = next / size;
		j = next%size;
		Board->a[i][j] = 1;
		next = placeOne(Board);
		i = next / size;
		j = next%size;
		Board->a[i][j] = 1;
	}
}
void saveGame(struct board *Board)
{
	int i;
	FILE *r,*wfile = fopen("savedGame.txt", "w");
	if (wfile==NULL)
	{
		printf("error occured while saving game :( \n");
	}
	//system("pause");
	fwrite(Board, sizeof(struct board), 1, wfile);
	for (i = 0; i < Board->size; i++)
	{
		fwrite(Board->a[i], sizeof(int)*Board->size, 1,wfile);
	}
	fclose(wfile);
	/*r = fopen("savedGame.txt", "r");
	struct board b;
	fread(&b, sizeof(struct board), 1, r);
	b.a = (int**)malloc(sizeof(int*)*b.size);
	for (i = 0; i < b.size; i++)
		b.a[i] = (int*)malloc(sizeof(int)*b.size);
	for (i = 0; i < Board->size; i++)
	{
		fread(b.a[i], sizeof(int)*Board->size, 1, r);
	}
	printf("%d", b.a[1][1]);
	fclose(r);*/
	printf("Game saved\n");
}
void choiceFun(struct board *Board,int *feb)
{
	int size, i, j, k, next;
	char choice;
	size = Board->size;
	choice = 'p';
	while (choice != 'q')
	{
		drawBoard(Board);
		if (!hasMove(Board, feb))
		{
			printf("%s has lost game with %d moves \n",Board->name,Board->moves);
			break;
		}
		k = -2; getchar();
		printf("\nuse WASD and q to exit  or Z to save and quit : ");
		scanf_s("%c", &choice);
		switch (choice)
		{
		case 'w':;
		case  'W':
			k = Up(Board, feb);
			break;
		case 'd':;
		case 'D':
			k = Right(Board, feb);
			break;
		case 'A':;
		case 'a':
			k = Left(Board, feb);
			break;
		case 's':;
		case 'S':
			k = Down(Board, feb);
			break;
		case 'Z':;
		case 'z':
			saveGame(Board);
			k = 3;
			break;
		default:
			printf("invalid choice try again :)\n");
			system("pause");
		}
		if (k == 3)
			break;
		if (k == -1){ printf(" %c dint work but you have another:)\n", choice); system("pause"); }
		else if (k == 0)
		{
			Board->moves += 1;
			next = placeOne(Board);
			if (next == -1){
				printf("%s has lost game with %d moves \n", Board->name, Board->moves);
				break;
			}
			i = next / size;
			j = next%size;
			Board->a[i][j] = 1;
		}
		else if (k == 1)
		{
			Board->moves += 1;
			drawBoard(Board);
			printf("%s has won game with %d moves\n",Board->name, Board->moves);
			insertIntoleaderBoard(Board);
			break;
		}
	}
}
void insertionSort(struct person *leaderboard, int count, struct person key)
{
	struct person temp;
	int i, j;
	for (i = count-1; i >= 0 && key.bestMoves<leaderboard[i].bestMoves; i--)
	{
		leaderboard[i + 1] = leaderboard[i];
	}
	leaderboard[i + 1] = key;
}
void insertIntoleaderBoard(struct board *Board)
{
	struct person liderboardData[21],currentPerson;
	int i, j,flag=-1,count=0;
	time_t rawtime=time(NULL);
	FILE *read, *write;
	if (Board->size==2)
		read = fopen("savedLeaderBoard.txt", "r");
	else if (Board->size==4)
		read = fopen("savedLeaderBoard4.txt", "r");
	if (read == NULL)
	{
		printf("error occured while reading a file \n");
		return;
	}
	currentPerson.bestMoves = Board->moves;
	for (i = 0; Board->name[i] != '\0'; i++)
		currentPerson.name[i] = Board->name[i];
	currentPerson.name[i] = '\0';
	currentPerson.boardSize = Board->size;
	currentPerson.tm = *(localtime(&rawtime));
	for (i = 0; i < 20; i++)
	{
		flag=fread(&liderboardData[i], sizeof(struct person), 1, read);
		if (flag > 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	fclose(read);
	if (Board->size==2)
		write = fopen("savedLeaderBoard.txt", "w");
	else if (Board->size==4)
		write = fopen("savedLeaderBoard4.txt", "w");
	if (count == 0)
	{
		fwrite(&currentPerson, sizeof(struct person), 1, write);
	}
	else
	{
		insertionSort(liderboardData, count, currentPerson);
		for (i = 0; i <= count && i<20; i++)
		{
			fwrite(&liderboardData[i], sizeof(struct person), 1,read);
		}
	}
}
int main()
{
	
	
	int option;//option is 1 2x2 if 2 4xx4
	int feb[31] = { 1,1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269 };
	struct board *Board; printf("\n\n\n\t\t\t\t\t\tWelcome to Feb2048\n\n");
	printf("======================================================================================================================\n");
	printf("\t\t1 for 2x2 board  \n\t\t2 for 4x4 board \n\t\t3 for last saved game\n\t\t4 for leader Board : ");
	scanf_s("%d", &option);
	getchar();
	Board = (struct board*)malloc(sizeof(struct board));
	initialiser(option, Board);
	choiceFun(Board, feb);
	system("pause");
	return 0;
}