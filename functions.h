char* sugg();
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
char* sugg(char *word){
	
	char d_word[30];
	int w_len, d_len, occ=0;
	FILE *dict;
	if((dict = fopen("dict.txt","r+"))==NULL)
	{
		printf("Cannot open dictionary file");
		exit(0);
	}
	rewind(dict);
	if(word == '\0'){
		return word;
	}
    // Checking If Word Occurs in the dictionary Or not
	while(fscanf(dict,"%s",d_word)!=EOF){
        
		if(strcmp(word,d_word)==0){
			occ=1;
			return word;
		}}
		fclose(dict);
	// End Checking For Word
	
    //If word does not Occur in Dictionary
	if(occ==0)
	{
		
    int loc=0;
    
    char **sug = (char **)calloc(150,sizeof(char *));
    
    if(sug == NULL)
    {
    	printf("2d array not created");
    	exit(0);
	}
    if((dict = fopen("dict.txt","r+"))==NULL)
	{
		printf("Cannot open dictionary file");
		exit(0);
	}
	
	while(fscanf(dict,"%s",d_word) != EOF)
	{  
		w_len = strlen(word);
		d_len = strlen(d_word);
		int i, j, c_count=0;
		float prob;		
		     // Checking For The Words Of Same Length
			if((word[0] == d_word[0] || word[w_len-1]==d_word[d_len-1]) && w_len == d_len)
			{
				for(i=0; i<d_len; i++)
				{
					for(j=0; j<d_len; j++)
					{
						if(*(word+i)==d_word[j])
						{
							c_count++;
						}
					}
				}
				prob = (float)c_count / d_len; //Calculating the probablity
				if(prob > 0.75)
				{
					if(loc==0)
						{
							sug[loc] = (char *)calloc(strlen(d_word),sizeof(char));
							if(sug[loc]==NULL)
							{
								printf("memory not allocated1");
								exit(0);
							}
			//				strcpy((*sug)[0],d_word);
							strcpy(sug[loc],d_word);
							loc++;
							
						}
						else
						{
							sug[loc] = (char *)calloc(d_len,sizeof(char));
							if(sug[loc]==NULL)
							{
								printf("memory not allocated2");
								exit(0);
							}
							strcpy(sug[loc],d_word);
							loc++;
						
						}
//					printf("Same Length %s %d %f \n",d_word,c_count,prob);
				}
			}
					     // Checking For The Words Of Length - 1
			if((word[0] == d_word[0] || word[w_len-1]==d_word[d_len-1]) && d_len == (w_len-1))
			{
				for(i=0; i<d_len; i++)
				{
					for(j=0; j<d_len; j++)
					{
						if(*(word+i)==d_word[j])
						{
							c_count++;
						}
					}
				}
				prob = (float)c_count / d_len; //Calculating the probablity
				if(prob > 0.75)
				{
					if(loc==0)
					{
							sug[loc] = (char *)calloc(strlen(d_word),sizeof(char));
		//				strcpy((*sug)[0],d_word);
							if(sug[loc]==NULL)
							{
									printf("memory not allocated3");
									exit(0);
							}
							strcpy(sug[loc],d_word);
							loc++;
							
					}
					else
					{
							sug[loc] = (char *)calloc(d_len,sizeof(char));
							if(sug[loc]==NULL)
							{
							printf("memory not allocated4");
							exit(0);
							}
							strcpy(sug[loc],d_word);
							loc++;
						
					}
//					printf(" Length -1 %s %d %f \n",d_word,c_count,prob);
				}
			}
			
					     // Checking For The Words Of Length + 1
			if((word[0] == d_word[0] || word[w_len-1]==d_word[d_len-1]) && d_len == (w_len+1))
			{
				for(i=0; i<d_len; i++)
				{
					for(j=0; j<d_len; j++)
					{
						if(*(word+i)==d_word[j])
						{
							c_count++;
						}
					}
				}
				prob = (float)c_count / d_len; //Calculating the probablity
				if(prob > 0.75)
				{
					if(loc==0)
					{
						sug[loc] = (char *)calloc(strlen(d_word),sizeof(char));
							if(sug[loc]==NULL)
						{
							printf("memory not allocated5");
							exit(0);
						}
		//				strcpy((*sug)[0],d_word);
						strcpy(sug[loc],d_word);
						loc++;
						
					}
					else
					{
							sug[loc] = (char *)calloc(d_len,sizeof(char));
							if(sug[loc]==NULL)
							{
							printf("memory not allocated6");
							exit(0);
							}
							strcpy(sug[loc],d_word);
							loc++;
							
					}
//					printf(" Length +1 %s %d %f \n",d_word,c_count,prob);
				}
			}

    }
    fclose(dict);
//    	strcpy(sug[loc],word);
int choose;
	if(loc==0)
	{  //If no words are found
	 		system("cls");
		    gotoxy(35,9);
			printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			gotoxy(35,10);
			printf("|||||                                                           |||||");
			gotoxy(35,11);
			
			printf("|||||  %s is written incorrectly",word);
			
			gotoxy(35,12);
			printf("|||||                                                           |||||");
			gotoxy(35,13);
			printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			gotoxy(35,14);
			printf("|||||                                                           |||||");
			gotoxy(99,11);
			printf("|||||");
			gotoxy(35,15);
			 puts("|||||                                                           |||||");
			 gotoxy(55,15);
			 puts("The Word was not found");
			 gotoxy(35,16);
			 puts("|||||                                                           |||||");
			 gotoxy(35,17);
			 puts("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			 gotoxy(35,19);
			 printf("Do you want to insert this word into the dictionary?(Press -1) \n");
			 gotoxy(35,21);
			 printf("(Press 0) to continue writing");
			 scanf("%d",&choose);
		 	if((dict = fopen("dict.txt","a+"))==NULL)
			{
			printf("Cannot open dictionary file");
			exit(0);
			}
			 if(choose == -1)
			 {
			 	fputs("\n",dict);
			 	fputs(word, dict);
			 	system("cls");
			 	free(sug);
	   			return word;
	 		}
		     else if(choose==0)
			 {
			 	system("cls");
			 	free(sug);
		     	return word;
			 }
			 fclose(dict);
	}
	else
	{
	// Displaying the words
	int l=15;
		system("cls");
 	for(int k=0; k<loc; k++)
	 {
		    gotoxy(35,9);
			printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			gotoxy(35,10);
			printf("|||||                                                           |||||");
			gotoxy(35,11);
			
			printf("||||| %s is written incorrectly",word);
			
			gotoxy(35,12);
			printf("|||||                                                           |||||");
			gotoxy(35,13);
			printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
			gotoxy(35,14);
			printf("|||||                                                           |||||");
			gotoxy(99,11);
			printf("|||||");
	 		gotoxy(35,l);
	 		printf("|||||");
	 		gotoxy(55,l);
	 		
			printf("%d ---------------- %s \n",k+1,sug[k]);
			
			gotoxy(99,l);
	 		printf("|||||");
	 		
			l++;
	}
	gotoxy(35,l);
	printf("|||||                                                           |||||");
	gotoxy(35,l+1);
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	gotoxy(35,l+2);
	printf("|||||                                                           |||||");
	gotoxy(35,l+3);
	printf("|||||                                                           |||||");
	gotoxy(47,l+3);
	printf("Do you want to use the same word?(Press -1) \n");
	gotoxy(35,l+4);
	printf("|||||                                                           |||||");
	gotoxy(47,l+4);
	printf("(Press 0) to continue writing");
	gotoxy(35,l+5);
	printf("|||||                                                           |||||");
	gotoxy(50,l+5);
	printf("Enter Your Choice : ");
	gotoxy(35,l+6);
	printf("|||||                                                           |||||");
	gotoxy(35,l+7);
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
	int choice = 0;
	gotoxy(75,l+5);
	scanf("%d",&choice);
	if((dict = fopen("dict.txt","a+"))==NULL)
	{
		printf("Cannot open dictionary file");
		exit(0);
	}
    if(choice==-1){
		fputs("\n",dict);
	 	fputs(word, dict);
	 	system("cls");
	 	free(sug);
		return word;	  
 //sprintf(final_sen,"%s %s",final_sen,word);
 		fclose(dict);
	}
	else if(choice==0)
	{
		system("cls");
		return word;
	}
    else
	{
    	system("cls");
    	char *p =sug[choice-1];
    	free(sug);
 	return p;
 	free(sug);
 //sprintf(final_sen,"%s %s",final_sen,sug[choice-1]);
}}}
fclose(dict);
}
