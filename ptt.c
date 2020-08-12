//Pomodoro timer and tracker This program will count down and track your pomodoro's.
//Done and works perfect. Made with Scispow
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
//1000 = 1 seconds 

int COUNT_DOWN;
int REST_TIME;
int WORK_TIME;
int LAST_REST_TIME;
int LAST_WORK_TIME;
int TOTAL_STEPS = 0;
int POMODORO_REST=900;
int LAST_POMODORE_REST;

int main() {

	//SET CPU PRIORITY
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);

	printf("Enter Minute: ");
	scanf("%d", &COUNT_DOWN);
	while (1) {

			int SECONDS = COUNT_DOWN * 6000;
			REST_TIME = SECONDS / 500;
			WORK_TIME = SECONDS / 100;

			system("CLS");

			while (LAST_WORK_TIME = WORK_TIME) {
				printf("%d pomodoro completed.\n\n", TOTAL_STEPS);
				printf("Please study hard for %d mins\n", COUNT_DOWN);
				printf("%d SECONDS LEFT", WORK_TIME = WORK_TIME - 1);
				Sleep(1000);
				system("CLS");
				LAST_WORK_TIME = LAST_WORK_TIME + 1;
			}
			TOTAL_STEPS++;

			if (TOTAL_STEPS >= 4) {
				TOTAL_STEPS = 0;
				while (LAST_POMODORE_REST = POMODORO_REST) {
					printf("4 Pomodoro Completed! Rest for %d seconds.", POMODORO_REST = POMODORO_REST - 1);
					Sleep(1000);
					system("CLS");
					LAST_POMODORE_REST = LAST_POMODORE_REST + 1;
				}
				main();
				
			}
			else {

				while (LAST_REST_TIME = REST_TIME) {
					printf("%d pomodoro completed.\n\n", TOTAL_STEPS);
					printf("Please rest for %d seconds.\n", REST_TIME = REST_TIME - 1);
					Sleep(1000);
					system("CLS");
					LAST_REST_TIME = LAST_REST_TIME + 1;
				}
			}
			
	}
}
