#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "skel.h"

void show_help_menu()
{
    printf("---------------------------\n");
    printf("usage : mp3tag -[tTaAy] \"value\" file1\n");
    printf("-t \t MODIFIES A TITLE TAG\n");
    printf("-T \t MODIFIES A TRACK TAG\n");
    printf("-a \t MODIFIES AN ARTIST TAG\n");
    printf("-A \t MODIFIES AN ALBUM TAG\n");
    printf("-y \t MODIFIES A  YEAR TAG\n");
    printf("-h \t DISPLAYS HELP INFO\n");
    printf("----------------------------\n");

}

/*********modify title tag************/
int  modify_title(FILE *fp, char *subbuff) 
{
    printf("modify title tag selected\n");
    char buff[4];
    char c;
    int val = 0;
    int i = 0;
    int len = strlen(subbuff);
    int remain = 0;


    fseek(fp, 0L, SEEK_SET);
    while (1)
    {  

	/**********clearing buffer********/
	memset(buff, 0, sizeof(buff));

	while ((c = fgetc(fp)) != 'T' && c != 'A')
	{
	    //printf("%c", c);

	}

	/*************move cursor position******/
	fseek(fp , -1L, SEEK_CUR);
	fread(buff, 4, 1, fp);
	//puts(buff);

	if (strcmp(buff, "TPE2") == 0)
	{
	    fseek(fp ,3L, SEEK_CUR);
	    val = fgetc(fp);
	    remain = val - len;
	    fseek(fp , 2L, SEEK_CUR);
	    //printf("value is %d", val);
	    for (i = 0; i < len; i++)
	    {
		fputc(subbuff[i], fp);

	    }


	    for ( i = 0; i < remain; i++)
	    {
		fputc(0, fp);
	    }
	    break;

	}

    }



}
int  modify_tracknum(FILE *fp, char *subbuff) 
{
    printf("modify track tag selected\n");
    char buff[4];
    char c;
    int val = 0;
    int i = 0;
    int len = strlen(subbuff);
    int remain = 0;


    fseek(fp, 0L, SEEK_SET);
    while (1)
    {  

	/**********clearing buffer********/
	memset(buff, 0, sizeof(buff));

	while ((c = fgetc(fp)) != 'T' && c != 'A')
	{
	    //printf("%c", c);

	}

	/*************move cursor position******/
	fseek(fp , -1L, SEEK_CUR);
	fread(buff, 4, 1, fp);
	//puts(buff);

	if (strcmp(buff, "TRCK") == 0)
	{
	    fseek(fp ,3L, SEEK_CUR);
	    val = fgetc(fp);
	    remain = val - len;
	    fseek(fp , 2L, SEEK_CUR);
	    //printf("value is %d", val);
	    for (i = 0; i < len; i++)
	    {
		fputc(subbuff[i], fp);

	    }


	    for ( i = 0; i < remain; i++)
	    {
		fputc(0, fp);
	    }
	    break;

	}

    }
}


int modify_artisttag(FILE *fp, char *subbuff)
{
    printf("modify album tag selected\n");
    char buff[4];
    char c;
    int val = 0;
    int i = 0;
    int len = strlen(subbuff);
    int remain = 0;


    fseek(fp, 0L, SEEK_SET);
    while (1)
    {  

	/**********clearing buffer********/
	memset(buff, 0, sizeof(buff));

	while ((c = fgetc(fp)) != 'T' && c != 'A')
	{
	    //printf("%c", c);

	}

	/*************move cursor position******/
	fseek(fp , -1L, SEEK_CUR);
	fread(buff, 4, 1, fp);
	//puts(buff);

	if (strcmp(buff, "TALB") == 0)
	{
	    fseek(fp ,3L, SEEK_CUR);
	    val = fgetc(fp);
	    remain = val - len;
	    fseek(fp , 2L, SEEK_CUR);
	    //printf("value is %d", val);
	    for (i = 0; i < len; i++)
	    {
		fputc(subbuff[i], fp);

	    }


	    for ( i = 0; i < remain; i++)
	    {
		fputc(0, fp);
	    }
	    break;

	}

    }
}


int  modify_year(FILE *fp, char *subbuff) 
{
    printf("modify year tag selected\n");
    char buff[4];
    char c;
    int val = 0;
    int i = 0;
    int len = strlen(subbuff);
    int remain = 0;


    fseek(fp, 0L, SEEK_SET);
    while (1)
    {  

	/**********clearing buffer********/
	memset(buff, 0, sizeof(buff));

	while ((c = fgetc(fp)) != 'T' && c != 'A')
	{
	    //printf("%c", c);

	}

	/*************move cursor position******/
	fseek(fp , -1L, SEEK_CUR);
	fread(buff, 4, 1, fp);
	//puts(buff);

	if (strcmp(buff, "TYER") == 0)
	{
	    fseek(fp ,3L, SEEK_CUR);
	    val = fgetc(fp);
	    remain = val - len;
	    fseek(fp , 2L, SEEK_CUR);
	    //printf("value is %d", val);
	    for (i = 0; i < len; i++)
	    {
		fputc(subbuff[i], fp);

	    }


	    for ( i = 0; i < remain; i++)
	    {
		fputc(0, fp);
	    }
	    break;

	}

    }



}
int  modify_genre(FILE *fp, char *subbuff) 
{
    printf("modify genre tag selected\n");
    char buff[4];
    char c;
    int val = 0;
    int i = 0;
    int len = strlen(subbuff);
    int remain = 0;


    fseek(fp, 0L, SEEK_SET);
    while (1)
    {  

	/**********clearing buffer********/
	memset(buff, 0, sizeof(buff));

	while ((c = fgetc(fp)) != 'T' && c != 'A')
	{
	    //printf("%c", c);

	}

	/*************move cursor position******/
	fseek(fp , -1L, SEEK_CUR);
	fread(buff, 4, 1, fp);
	//puts(buff);

	if (strcmp(buff, "TCOM") == 0)
	{
	    fseek(fp ,3L, SEEK_CUR);
	    val = fgetc(fp);
	    remain = val - len;
	    fseek(fp , 2L, SEEK_CUR);
	    //printf("value is %d", val);
	    for (i = 0; i < len; i++)
	    {
		fputc(subbuff[i], fp);

	    }


	    for ( i = 0; i < remain; i++)
	    {
		fputc(0, fp);
	    }
	    break;

	}

    }



}

