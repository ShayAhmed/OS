#include <stdio.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<string.h>
#include<stdlib.h>
//gcc OS_project1.c -g -o proj1 -lreadline
//-g to compile and -lreadline to inlcude readline library
int main(){
	printf("program start");
	int cpid;
	char *inString;
	char * tok;


	while(inString = readline("$:")){

		int counter = 0;
		tok = strtok(inString," ");
		//char * temp = strtok(inString," ");
		while (tok != NULL)
		{
			counter++;
			printf("%s\n",tok);
			tok = strtok(NULL," ");
			/* code */
		}
		printf("%i\n",counter);
		tok = strtok(inString," ");
		printf("token: %s\n",tok);
		char * arguments[counter];
		counter = 0;
		while (tok != NULL)
		{
			
			//counter++;
			printf("%s\n",tok);
			//arguments[counter] = tok;
			arguments[counter] = (char *)malloc(strlen(tok)+1);
			strcpy(arguments[counter],tok);
			//strcpy(arguments[counter],tok);
			printf("here");
			tok = strtok(NULL," ");
			counter++;
			/* code */
		}

		


		cpid = fork();
		if(cpid == 0){
			printf("child \n");
			execlp(inString,inString,(char *)NULL);
		}else{
			printf("parent \n");
			wait((int *)NULL);
		}
	}
	//something readline("$")
	// while(1){
			
	// }
}
