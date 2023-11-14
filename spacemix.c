//.txt data file space combination & transfer to .csv file
//by EC3XXX
//2023/9/6
//tools for ghame_system_modeling to get .csv data file
//easy to draw curves in Matlab or Excel

//DO NOT EDIT FILES THAT ARE CURRENTLY OPENED BY OTHER PROGRAMMES, INCLUDE INPUT FILE, OUTPUT FILE AND TEMP FILE
//THIS WILL CAUSE THE CORRESPONDING FILE POINTER CANNOT BE OPENED

//include files
#include <stdio.h>
#include <stdlib.h>

//define names of files, edit if you need to change these names
#define FINPUT	"test.txt"
#define FOUTPUT	"output.csv"
#define FTEMP	"temp_spacemix.txt"

//main
int main()
{
	//
	FILE *fin, *fout, *ftemp;
	int beg_space = 1;
	char gc, gc2;
	
	//clean old output files and temp files
	remove(FOUTPUT);
	remove(FTEMP);
	
	//fread
	if((fin = fopen(FINPUT,"r")) == NULL)		//read only
	{
		printf("cannot open input file\n");
		return 1;
	}
	if((fout = fopen(FOUTPUT,"w")) == NULL)		//write only, if doesn't exist, create one
	{
		printf("cannot open output file\n");
		return 2;
	}
	if((ftemp = fopen(FTEMP,"w+")) == NULL)		//read&write, if doesn't exist, create one
	{
		printf("cannot create temp file\n");
		return 3;
	}
	
	//space combination
	while((gc = fgetc(fin)) != EOF) //stop when fin reaches the end of input file
	{
		if(gc == ' ')				//space detection
		{
			if(beg_space)			//if last char is space
				continue;			//jump this space
			else					//if last char isn't space
			{
				fputc(gc, ftemp);	//output space in temp file
				beg_space = 1;		//record last space char
			}
		}
		else						//default
		{
			fputc(gc, ftemp);		//output char in temp file
			beg_space = 0;			//clean space record
		}
	}
	
	//transfer space to comma, and avoid transfer " \n" to ",\n", because .csv use only "\n" as enter
	rewind(ftemp);							//reset ftemp
	while((gc = fgetc(ftemp)) != EOF)		//stop when ftemp reaches the end of temp file
	{
		gc2 = fgetc(ftemp);					//next char detection
		if(gc2 != EOF)						//if next char is end of file
			fseek(ftemp,-1,SEEK_CUR);		//to avoid pushback causing endless enter
		
		if(gc == ' ' && gc2 == '\n')		//" \n"detection
			continue;			//jump the space
		else if(gc == ' ' && gc2 != '\n')	//space without enter detection
			fputc(',',fout);				//replace with comma
		else								//default
			fputc(gc, fout);				//output char in output file
	}
	
	//fclose
	fclose(fin);
	fclose(fout);
	fclose(ftemp);
	
	//delete temp file
	remove(FTEMP);
	
	return 0;
}