#include <stdio.h>
#include "skel.h"
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int i = 0;
    int size;
    char ch;
    char subbuff[20];

    /*************command line check****************/
    if (argc > 4)
    {
	printf("READ FILE ERROR IN MP3\n");
    }

    /********************argument check*************/
    if (strcmp(argv[1], "-r") == 0)
    {

	fp = fopen(argv[2], "r");


	printf("-------------------------------------------------\n");
	printf("MY VERSION IS    \t");
	for (i = 0; i < 3; i++)
	{
	    ch = fgetc(fp);
	    printf("%c", ch);

	}
	printf("\n");

	size = find_size(fp);
	printf("size             \t%fmb\n",(float) (size/(1024 * 1024)));
	title_find(fp);
	extract_image(fp, size);

    }


    /*****************help command**************/
    if (strcmp(argv[1], "--help") == 0)
    {
	fp = fopen(argv[2], "r");

	show_help_menu();

    }

    /*****************************************/


    if (strcmp(argv[1], "-t") == 0)
    {
	fp = fopen(argv[3], "r+");
	strcpy(subbuff, argv[2]);
	modify_title(fp, subbuff);
    }

    /**************************************/

    if (strcmp(argv[1], "-T") == 0)
    {
	fp = fopen(argv[3], "r+");
	strcpy(subbuff, argv[2]);
	modify_tracknum(fp, subbuff);
    }

    /***********************************/

    if (strcmp(argv[1], "-a") == 0)
    {
	fp = fopen(argv[3], "r+");
	strcpy(subbuff, argv[2]);
	modify_artisttag(fp, subbuff);
    }
    /********************************/
    if (strcmp(argv[1], "-y") == 0)
    {
	fp = fopen(argv[3], "r+");
	strcpy(subbuff, argv[2]);
	modify_year(fp, subbuff);
    }
    /******************************/

    if (strcmp(argv[1], "-g") == 0)
    {
	fp = fopen(argv[3], "r+");
	strcpy(subbuff, argv[2]);
	modify_genre(fp, subbuff);
    }

    /******************************/

    fclose(fp);

}




