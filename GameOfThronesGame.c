#include<stdio.h>//standard input/output
#include <stdlib.h>//standard library
#include <string.h>
#include<time.h>// for randomizing

//array max length
#define MAX 30

//prototypes of the functions

//auxiliary functions
void funcMenu();
void show_feats();
void start_war();
void list_soldiers();
int select_soldier(int *barrack, int *AI);
void release_soldier(int *barrack);
void list_barrack(int *barrack);
void TheWar(int *barrack);

//supportive functions
void soldierSwitchcase(int *num);
void versus(int *select, int *AISelect);


//characters
struct Soldier {
	int id;
	char name[30];
	int attackPower;
	int stamina;
};

//global defined objects
struct Soldier AryaStark = { .id = 0,.name = "AryaStark",.attackPower = 100,.stamina = 200 };
struct Soldier JonSnow = { .id = 1,.name = "JonSnow",.attackPower = 400,.stamina = 500 };
struct Soldier CerseiLannister = { .id = 2,.name = "CerseiLannister",.attackPower = 200,.stamina = 400 };
struct Soldier DaenerysTargaryen = { .id = 3,.name = "DaenerysTargaryen ",.attackPower = 300,.stamina = 800 };
struct Soldier NightKing = { .id = 4,.name = "NightKing",.attackPower = 500,.stamina = 400 };
struct Soldier SansaStark = { .id = 5,.name = "SansaStark",.attackPower = 50,.stamina = 150 };
struct Soldier TyrionLannister = { .id = 6,.name = "TyrionLannister",.attackPower = 100,.stamina = 600 };
struct Soldier StannisBaratheon = { .id = 7,.name = "StannisBaratheon",.attackPower = 300,.stamina = 300 };
struct Soldier DaarioNaharis = { .id = 8,.name = "DaarioNaharis",.attackPower = 350,.stamina = 300 };
struct Soldier Melisandre = { .id = 9,.name = "Melisandre",.attackPower = 200,.stamina = 350 };

//global defined array variables
int you_soldier[4]; //saves your soldiers
int AI_soldier[4]; //saves AI's soldiers



//main function
int main() {
	funcMenu();
	return 0;
}





//functions
void funcMenu() {
	
	int menu = 0;
	printf("Please select an option to continue:\n");
	printf("1) Show soldier features\n");
	printf("2) Start the war\n");
	printf("Please make your choice:\n");

	scanf("%d", &menu);

	if (menu == 1) {
		show_feats();
	}
	else if (menu == 2) {
		start_war();
	}
	//we make sure that the user entered correctly
	else {
		printf("Please type only 1 or 2\n");
		funcMenu();
	}
}



void show_feats() {

	FILE *fp;
	char SoldierName[MAX];
	int c;
	char fileType[]=".txt";

	list_soldiers();
	
	printf("Please type name of the soldier:\n");
	int i;
	for (i = 0; i < 17; i++) {
		scanf("%c", &SoldierName[i]);
	}
	

	//adds .txt to the end of the file name
	strcat(SoldierName, fileType);

	// open the file on read mode
	fp = fopen(SoldierName, "r");

	// if failed to open exit with fail state
	if (fp == NULL) {
		printf("There is no soldier in this name in the barracks, my lord.\n");
		printf("(Please type exactly like this: NameSurname).\n");
		show_feats();
	}


	while ((c = fgetc(fp)) != EOF) { // print until reach end of file

		printf("%c", c);
	}

	fclose(fp);

}



void start_war() {
	int AI = 0;
	int option;
	int barrack;
	int barrackSoldiers;
	system("cls");
	
	
	//loop until 5 is selected
	while (option != 5) {
		
		printf("Welcome to Westeros. How can I help you,my lord?\n");
	    printf("1) Show soldiers\n");
	    printf("2) Select your soldiers\n");
	    printf("3) Release a soldier\n");
	    printf("4) Show my army\n");
	    printf("5) Back\n");
		printf("Please make your choice: \n");
		scanf("%d",&option);
		
		switch (option) {

		case 1:
			list_soldiers();
			break;

		case 2:
			select_soldier(&barrack, &AI);
			break;
		case 3:
			release_soldier(&barrack);
			break;
		case 4:
			list_barrack(&barrack);
			break;
		case 5:
			option = 5;
			break;

		default:
			printf("Please choose a valid option\n");
		}
	}
	TheWar(&barrack);
}



void list_soldiers() {
    system("cls");
	printf("0 - AryaStark\n");
	printf("1 - JonSnow\n");
	printf("2 - CerseiLannister\n");
	printf("3 - DaenerysTargaryen\n");
	printf("4 - NightKing\n");
	printf("5 - SansaStark\n");
	printf("6 - TyrionLannister\n");
	printf("7 - StannisBaratheon\n");
	printf("8 - DaarioNaharis\n");
	printf("9 - Melisandre\n");
}



int select_soldier(int *barrack, int *AI) {


	//AI zero for user, one for AI

	int num;
	int random;
	srand(time(0)); // for randomizing with time

	list_soldiers(); // showing soldiers

	printf("Please type the id of the soldier to select 4 soldiers:\n");
	if (*barrack < 4) { // if there is less than 4 people
		int i;
		for (i = 0; i < 4; i++) {
			if (*AI == 1) { // for AI it works random
				random = (rand() % (9 - 0 + 1)) + 0;
				num = random;
				AI_soldier[i] = num; // saves AI's selected soldier id's. Defined globally
			}
			else {
				printf("%d. soldier:",i+1);
				scanf("%d", &num);
				you_soldier[i] = num; // saves your selected soldier id's.Defined globally
			}

			(*barrack)++;
			soldierSwitchcase(&num);// this is the important part
		}

	}
	else if (*barrack == 4) { // you cant add more than 4 people
		printf("You have reached the maximum capacity of your barrack with 4 soldiers, my lord.\n");
	}

	if (*AI == 1) {
		return *AI_soldier;
	}
	else {
		return *you_soldier;
	}
}


void release_soldier(int *barrack) {
	system("cls");
	int select;
	char more;
	if (*barrack > 0) { // if there is soldier in barrack
        list_soldiers();
        printf("Soldiers in our barrack:%d,%d,%d,%d\n", you_soldier[0], you_soldier[1], you_soldier[2], you_soldier[3]);
		int x = 0;
		int i = 0;
		int j = 0;
		while (j < 4) { // you can release max 4 soldier from your barrack
			
			while (i < 4) { // check if soldier number match with our soldiers in barrack
				printf("Select soldier to release:\n");
			    scanf("%d", &select);
				if (you_soldier[i] == select) {
					soldierSwitchcase(&select);
					printf("Released, my lord\n");
					(*barrack)--;
					j++;
					printf("Would you like to release more soldiers,sir?(Y/N): ");
					scanf(" %c",&more);
					if(more=='n'||more=='N'){ 
					   j=4;
					}
				}
				else { // probably user typed the number wrong
					printf("Can't find the soldier, my lord.");

				}
				i++;
			}


		}

	}
	else if (*barrack == 0) {
		printf("You do not have a soldier in your barrack to release, my lord.\n");
	}
}



void list_barrack(int *barrack) {
	system("cls");
	list_soldiers();
	int i;
	if (*barrack > 0) {
		for (i = 0; i < *barrack; i++) { // to show soldier number in our barrack
			printf("%d ", you_soldier[i]);
		}

	}
	else if (*barrack == 0) {
		printf("No soldier to show in your barrack, my lord.\n");
	}
}


void soldierSwitchcase(int *num) {
	
	switch (*num) {

	case 0:
		printf("%d-%s (sword,%d,%d)\n", AryaStark.id, AryaStark.name, AryaStark.attackPower, AryaStark.stamina);
		break;

	case 1:
		printf("%d-%s (ice,%d,%d)\n", JonSnow.id, JonSnow.name, JonSnow.attackPower, JonSnow.stamina);
		break;
	case 2:
		printf("%d-%s (sword,%d,%d)\n", CerseiLannister.id, CerseiLannister.name, CerseiLannister.attackPower, CerseiLannister.stamina);
		break;
	case 3:
		printf("%d-%s (sword,%d,%d)\n", DaenerysTargaryen.id, DaenerysTargaryen.name, DaenerysTargaryen.attackPower, DaenerysTargaryen.stamina);
		break;
	case 4:
		printf("%d-%s (ice,%d,%d)\n", NightKing.id, NightKing.name, NightKing.attackPower, NightKing.stamina);
		break;
	case 5:
		printf("%d-%s (sword,%d,%d)\n", SansaStark.id, SansaStark.name, SansaStark.attackPower, SansaStark.stamina);
		break;
	case 6:
		printf("%d-%s (sword,%d,%d)\n", TyrionLannister.id, TyrionLannister.name, TyrionLannister.attackPower, TyrionLannister.stamina);
		break;
	case 7:
		printf("%d-%s (sword,%d,%d)\n", StannisBaratheon.id, StannisBaratheon.name, StannisBaratheon.attackPower, StannisBaratheon.stamina);
		break;
	case 8:
		printf("%d-%s (sword,%d,%d)\n", DaarioNaharis.id, DaarioNaharis.name, DaarioNaharis.attackPower, DaarioNaharis.stamina);
		break;
	case 9:
		printf("%d-%s (fire,%d,%d)\n", Melisandre.id, Melisandre.name, Melisandre.attackPower, Melisandre.stamina);
		break;
	default:
		printf("Please choose a valid option(0-9)\n");
	}
}


void TheWar(int *barrack) {
    system("cls");
	int AI = 0; // AI/you
	int game = 1; // used for making war loop

	int select;
	int AISelect;

	int menu2 = 0;

	int theRandom;
	srand(time(0));


	printf("Please select an option to continue:\n");
	printf("1) Show soldier’ features\n");
	printf("2) Start the war\n");
	printf("Please make your choice:");
	scanf("%d", &menu2);
    system("cls");

	//first scene

	list_soldiers();
	printf("###############################################################\n");
	printf("							YOU									 ");
	//YOU
	select_soldier(barrack, &AI);


	printf("###############################################################\n");
	printf("###############################################################\n");
	//AI
	printf("							AI									 ");
	AI = 1;
	printf("AI selects:");
	select_soldier(barrack, &AI);
	printf("###############################################################\n");









	//war loop

	while (game) {
		system("cls");
		printf("###############################################################\n");
		printf("							YOU									 ");
		//YOU
		//YOU
		int i = 0;
		int j = 0;
		int x = 0;
		while (j < 1) {


			printf("Our soldier numbers:");
			for (x = 0; x < *barrack; x++) { // to show soldier number in our barrack
				printf("%d ", you_soldier[x]);
			}
			printf("Select soldier to attack:");
			while (i < 5) {
				scanf("%d", &select);
				if (you_soldier[i] == select) {
					soldierSwitchcase(&select);
					printf("I am ready, my lord\n");
					j++;
				}
				else {
					printf("Please select one of our soldiers numbers(%d,%d,%d,%d)\n", you_soldier[0], you_soldier[1], you_soldier[2], you_soldier[3]);
				}
				i++;
			}

		}




		printf("###############################################################\n");
		printf("###############################################################\n");
		//AI
		printf("							AI									 ");
		// smart cast by AI
		soldierSwitchcase(&AISelect);

		printf("###############################################################\n");

		//fight
		versus(&select, &AISelect);

		//check for game over



	}


}
void versus(int *select, int *AISelect) {}
