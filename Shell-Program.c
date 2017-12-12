#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void displayMenu();
void mySystem (const char* str);

int main(){
	boolean = true;

	while(boolean) {
		int choice;

		displayMenu();
		fscanf("%d", &choice); // Taking the user input
		expr[0] = 0;

		switch (choice){

			// For reading a file
			case 1:{
				char name_path [50];
				printf("Enter the name of the path: \n");
				scanf("%s",&name_path);
				snprintf(expr, 50, "more %s", name_path);
				break;
				
			}
			// For changing file permissions
			case 2: {
				char name_path[50];
				unsigned int permissions;

				printf("Enter the name of the path: \n");
				fscanf("%s",&name_path);
				printf("Enter the permissions in octal form: \n");
				fscanf("%o",&permissions);

				snprintf(expr,50,"chmode %o %s",permissions, name_path);
				break;
			}
			// For changing the owner
			case 3:{
				char name_path[50];
				char owner[20];

				printf("Enter the name of the path: \n");
				fscanf("%s",&name_path);
				printf("Enter the name of the new owner: \n");
				fscanf("%s",&owner);

				snprintf(expr,70,"chown %s %s",owner,name_path);
				break;
			}
			// For creating the directory
			case 4: {
				char name_path[50];

				printf("Enter the name of the path: \n");
				fscanf("%s",&name_path);

				snprintf(expr,50,"mkdir %s", name_path);
				break;
			}
			// For removing the directory
			case 5: {
				char name_path[50];

				printf("Enter the name of the path: \n");
				fscanf("%s",&name_path);

				snprintf(expr,50,"rmdir %s",name_path);
				break;
			}
			// For creating a Symlink
			case 6:{
				char path_one[50], path_two[50];

				printf("Enter the name of the path: \n");
				fscanf("%s",&path_one);
				printf("Enter the symlink name: \n");
				fscanf("%s",&path_two);

				snprintf(expr,50,"ln -s %s %s",path_one,path_two);
				break;
			}
			// For displaying file information
			case 7:{
				char name_path[50];

				printf("Enter the name of the path: \n");
				fscanf("%s",&name_path);

				snprintf(expr,50,"ls -l %s",name_path);
				break;
			}
			// For changing the directory
			case 8: {
				char name_path[50];

				printf("Enter the name of the directory path: \n");
				fscanf("%s",&name_path);

				snprintf(expr,50,"cd %s",name_path);
				break;
			}
			// For renaming the file
			case 9: {
				char file_one[50], file_two[50];

				printf("Enter the current name of the file: \n");
				fscanf("%s",&file_one);
				printf("Enter the new name of the file: \n");
				fscanf("%s",&file_two);

				snprintf(expr,50,"mv %s %s",file_one,file_two);
				break;
			}
			// For moving a file
			case 10: {
				char name_path[50];
				
				printf("Enter the name of the file you'd like to move: \n");	
				fscanf("%s",&name_path);			

				snprintf(expr,50,"rm %s",name_path);
				break;
			}
			// For removing the file
			case 11: {
				char name_path[50];

				printf("Enter the name of the file you'd like to remove: \n");
				fscanf("%s",&name_path);	

				snprintf(expr,50,"rm %s",name_path);
				break;
			}
			// For showing the process status
			case 12: {
				snprintf(expr,50,"ps aux|more");
				break;
			}
			// For breaking the program - KILL
			case 13:{ 
				int pid;

				printf("Enter the pid: \n");
				scanf("%d",&pid);

				snprintf(expr,50,"kill -9 %d", pid);
				break;
			}
			default: {
				printf("You did not enter the valid input! \n");
				boolean = false;
				return 0;
			}

			mySystem(expr);

		}
	}
}

void displayMenu(){
	printf("Enter the number for the choice on the menu: \n");
	printf("\n");
	printf(" 1 Read a file \n");
	printf(" 2 Change file permissions \n");
	printf(" 3 Change file owner \n");
	printf(" 4 Create the directory \n");
	printf(" 5 Remove the directory \n");
	printf(" 6 Create a symlink \n");
	printf(" 7 Display file information \n");
	printf(" 8 Change directory \n");
	printf(" 9 Rename a file \n");
	printf(" 10 Move a file \n");
	printf(" 11 Remove a file \n");
	printf(" 12 Show process status \n");
	printf(" 12 Quit the program \n");
}

void mySystem(const char* str){ 
	int f = fork();
	if (f == 0){ // Child process

		// An execute "execlp" function
		execlp("bash", "bash", "-c", str, NULL);
	}
	else { // Parent Process

		int status;
		wait(&status);
		return status;
	}

}
