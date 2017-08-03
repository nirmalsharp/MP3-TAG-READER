#include <stdio.h>

int findsize(FILE *fp);
int title_find(FILE *fp);
int check(FILE *fp);
void show_help_menu();
int modify_title(FILE *fp, char *buff);
int extract_image(FILE *fp, int size);
int modify_tracknum(FILE *fp, char *buff);
int modify_artisttag(FILE *fp, char *subbuff);
