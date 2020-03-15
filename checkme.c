#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include<conio.h>
#include "functions.h"

void name();

int main(){
	
	
	char *words ;
	int len;
	char c;
	int pos=0;
 	words = (char *)malloc(1*sizeof(char));
//	char sen[100];
//	char words[50][30]; //can store 10 words of 10 characters
	char *final_sen=  (char *)malloc(100*sizeof(char));
	strcpy(final_sen ," ");
	int i=0,j,n,cnt=0;
    name();
    
    gotoxy(20,18);
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	gotoxy(20,19);
	printf("|||||                     |||||                                                                   |||||");
	gotoxy(20,20);
	printf("||||| Input Your Sentence |||||");
	gotoxy(20,21);
	printf("|||||                     |||||                                                                   |||||");
	gotoxy(118,20);
	printf("|||||");
	gotoxy(20,22);
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	gotoxy(55,20);
	c=getche();
	do
	{	
		if(c==' ' || c==13)
		{	
			words[i] = '\0';
			for(int i=0; words[i]!='\0'; i++)
		    {
		        if(words[i]>='A' && words[i]<='Z')
		        {
		        	
		            words[i] = words[i] + 32;
				}
		   	 }
					char *s = sugg(words);
					int temp =strlen(s)+1;
					strcat(final_sen," ");
					strcat(final_sen,s);
					if(s!=NULL)
					{
					free(words);
					name();
				    
				    gotoxy(20,18);
					printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
					gotoxy(20,19);
					printf("|||||                     |||||                                                                   |||||");
					gotoxy(20,20);
					printf("||||| Input Your Sentence |||||");
					gotoxy(20,21);
					printf("|||||                     |||||                                                                   |||||");
					gotoxy(118,20);
					printf("|||||");
					gotoxy(20,22);
					printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
					gotoxy(55,20);
				
					if(pos >45)
					{
						gotoxy(55,21);
						
					}
					else
					{
						printf("%s ",final_sen);
					words = (char *)malloc(1*sizeof(char));
					i=0;
					cnt++;
					}	
					}
				//			memset(words, 0, sizeof(words));
					
				
							
		}
		else
		{
			words[i]=c;
			int temp = strlen(words)+1;
			words = (char *)realloc(words,temp*sizeof(char));
			i++;
			pos++;
		}}while((c=getche())!=13);
		
}


void name(){
	char name[8][10][20] = {
		{
			" ******** ",
			"**********",
			"***      *",
			"***       ",
			"***       ",
			"***       ",
			"***       ",
			"***      *",
			"**********",
			" ******** ",			
		},
		
		{
			" **    ** ",
			"***    ***",
			"***    ***",
			"***    ***",
			"**********",
			"**********",
			"***    ***",
			"***    ***",
			"***    ***",
			" **    ** ",
		},
		
		{
			" *********",
			"**********",
			"***       ",
			"***       ",
			"**********",
			"**********",
			"***       ",
			"***       ",
			"**********",
			" *********",
		},
		
		{
			" ******** ",
			"**********",
			"***      *",
			"***       ",
			"***       ",
			"***       ",
			"***       ",
			"***      *",
			"**********",
			" ******** ",			
		},
		
		{
			" **    ***",
			"***   *** ",
			"***  ***  ",
			"*** ***   ",
			"******    ",
			"******    ",
			"*** ***   ",
			"***  ***  ",
			"***   *** ",
			" **    ***",
		},
		
		{
			"      ",
			"      ",
			"      ",
			"      ",
			"      ",
			"      ",
			"      ",
			"      ",
			"      ",
			"      ",
		},
		
		{
			"***          ***",
			"****        ****",
			"*****      *****",
			"******    ******",
			"*** ***  *** ***",
			"***  ******  ***",
		    "***   ****   ***",
			"***          ***",
			"***          ***",
			"***          ***",
			 
		},
		
		{
			" *********",
			"**********",
			"***       ",
			"***       ",
			"**********",
			"**********",
			"***       ",
			"***       ",
			"**********",
			" *********",
		}
		
	};
		
		int i,j=5;;

		for(i=0; i<10; i++){
			
		    gotoxy(25,j);
			printf("%s",name[0][i]);
			printf(" %s",name[1][i]);
			printf(" %s",name[2][i]);
			printf(" %s",name[3][i]);
			printf(" %s",name[4][i]);
			printf(" %s",name[5][i]);
			printf(" %s",name[6][i]);
			printf(" %s",name[7][i]);
			
			printf("\n");
			j++;
		}

}
