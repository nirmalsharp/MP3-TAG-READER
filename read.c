#include <stdio.h>
#include "skel.h"
#include <string.h>
#include <stdlib.h>



int title_find(FILE *fp)
{
    char c;
    char buff[5];
    char subbuff[3];
    int val;
    int i = 0;



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

	/**************title artist************/
	if(strcmp (buff, "TPE2") == 0)
	{
	    //printf("--------------------\n");
	    printf("TITLE ARTIST        \t"); 
	    fseek(fp , 3L, SEEK_CUR);
	    val = fgetc(fp);

	    fseek(fp , 2L, SEEK_CUR);

	    for (i = 0; i < val; i++)
	    {
		c = fgetc(fp);
		if (isprint(c))
		{
		    printf("%c",c);
		}
	    }

	    fseek(fp, -1L, SEEK_CUR);
	    printf("\n");
	    //c = fgetc(fp);
	    //printf("%c", c);
	}

	/**********title version 2*******/
	if (strcmp (buff, "TIT2") == 0)
	{
	    //printf("-------------------\n");
	    printf("ALBUM            \t"); 
	    fseek(fp , 3L, SEEK_CUR);
	    val = fgetc(fp);

	    fseek(fp , 2L, SEEK_CUR);

	    for (i = 0; i < val; i++)
	    {
		c = fgetc(fp);
		if (isprint(c))
		{
		    printf("%c",c);
		}
	    }

	    printf("\n");

	}

	/**************album name***************/

	if (strcmp (buff, "TALB") == 0)
	{
	    //printf("---------------------\n");
	    printf("MOVIE TITLE        \t"); 
	    fseek(fp , 3L, SEEK_CUR);
	    val = fgetc(fp);

	    fseek(fp , 2L, SEEK_CUR);

	    for (i = 0; i < val; i++)
	    {
		c = fgetc(fp);
		if (isprint(c))
		{
		    printf("%c",c);
		}
	    }
	    printf("\n");
	}

	if (strcmp (buff, "TYER") == 0)
	{

	    //printf("-----------------------\n");
	    printf("MOVIE YEAR        \t"); 
	    fseek(fp , 3L, SEEK_CUR);
	    val = fgetc(fp);

	    fseek(fp , 2L, SEEK_CUR);

	    for (i = 0; i < val; i++)
	    {
		c = fgetc(fp);
		if (isprint(c))
		{
		    printf("%c",c);
		}
	    }
	    printf("\n");
	}

	if (strcmp (buff, "TCOM") == 0)
	{
	    //printf("--------------------\n");
	    printf("COMPOSER           \t"); 
	    fseek(fp , 3L, SEEK_CUR);
	    val = fgetc(fp);

	    fseek(fp , 2L, SEEK_CUR);

	    for (i = 0; i < val; i++)
	    {
		c = fgetc(fp);
		if (isprint(c))
		{
		    printf("%c",c);
		}
	    }
	    printf("\n");
	}


	if (strcmp (buff, "TRCK") == 0)
	{
	    //printf("--------------------\n");
	    printf("TRACK POSITION  \t"); 
	    fseek(fp , 3L, SEEK_CUR);
	    val = fgetc(fp);

	    fseek(fp , 2L, SEEK_CUR);

	    for (i = 0; i < val; i++)
	    {
		c = fgetc(fp);
		if (isprint(c))
		{
		    printf("%c",c);
		}
	    }
	    printf("\n");
	}


	if (strcmp (buff, "APIC") == 0)
	{

	    //printf("---------------------\n");
	    printf("IMAGE EMBEDDED  \t"); 
	    fseek(fp , 3L, SEEK_CUR);
	    val = fgetc(fp);

	    fseek(fp , 2L, SEEK_CUR);

	    for (i = 0; i < val; i++)
	    {
		c = fgetc(fp);
		if (isprint(c))
		{
		    printf("%c",c);
		}
	    }
	    printf("\n");
	    printf("-----------------------------------------------\n");
	    break;
	}

    }

}

int find_size(FILE *fp)
{
    int size;
    fseek(fp , 0L, SEEK_END);
    size = ftell(fp);
    return size;



}

/*****this function is about extract image**************/

int extract_image (FILE *fp, int size)
{
    //printf("a");
    FILE *fp1;
    fp1 = fopen("album.jpg", "w");
    unsigned char c;
    char buff[4];
    int i, start_index, end_index;
    int count  = 0;
    //printf("size is %d\n", size);

    fseek(fp , 0L, SEEK_SET);


    while (1)
    {
	memset(buff, 0, sizeof(buff));

	while ((c = fgetc(fp)) != 'A')
	{


	}

	fseek(fp , -1L, SEEK_CUR);
	fread(buff, 4, 1, fp);
	if (strcmp(buff, "APIC") == 0)
	{
	    break;
	}



    }


    if (strcmp(buff, "APIC") == 0)
    {
	fseek(fp , 0L, SEEK_CUR);


	for (i = 0; i < size; i++)
	{
	    c = fgetc(fp);
	    if (c == 0XFF)
	    {
		c = fgetc(fp);
		if (c == 0XD8)
		{
		    break;
		}
	    }
	}


	start_index = i;

	for (i = 0; i < size; i++)
	{
	    c = fgetc(fp);
	    if (c == 0XFF)
	    {
		c = fgetc(fp);
		if (c == 0xD9)
		{
		    break;
		}
	    }
	}

	end_index = i;

    }


    fseek(fp , 0L, SEEK_SET);


    while (1)
    {
	memset(buff, 0, sizeof(buff));

	while ((c = fgetc(fp)) != 'A')
	{


	}

	fseek(fp , -1L, SEEK_CUR);
	fread(buff, 4, 1, fp);
	if (strcmp(buff, "APIC") == 0)
	{
	    break;
	}

    }




    if (strcmp(buff, "APIC") == 0)
    {
	fseek(fp , start_index, SEEK_CUR);
	for (i = 0; i < end_index; i++)
	{
	    c = fgetc(fp);
	    fputc(c, fp1);
	    //printf("%x", c);
	}

	fclose(fp1);


    }

}
