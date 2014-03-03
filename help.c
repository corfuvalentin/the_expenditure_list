//      help.c
//
//      Copyright 2014 Valentin Corfu <corfuvalentin@yahoo.com>
//
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evidenta_cheltuieli.h"
#include "help.h"


void help(void)
{
    printf("Usage:\n");
    printf("\t./program (v)iew/(i)nsert/(s)elect\n\n");
}

void get_data(month_pay *p)
{
    puts("Enter 'intretinere': ");
        scanf("%lf", &(p->intretinere));
    puts("Enter 'chirie': ");
        scanf("%lf", &(p->chirie));
    puts("Enter 'apometre': ");
        scanf("%lf", &(p->apometre));
    puts("Enter 'gaze': ");
        scanf("%lf", &(p->gaze));
    puts("Enter 'electrica': ");
        scanf("%lf", &(p->electrica));
    puts("Enter 'orange': ");
        scanf("%lf", &(p->orange));
}

void insert_into_file(month_pay *p)
{
    FILE *fp;
    if( (fp = fopen(CFG_FILE, "r")) ==  NULL)
    {
        printf("INFO: File Not exist. '%s' will be creaded now...\n", CFG_FILE);
    }
    else
    {
        puts("INFO: Config file exist. Skip creading it.");
        fclose(fp);
    }
    if( (fp = fopen(CFG_FILE, "a+")) == NULL )
    {
        printf("Error opening file.");
        exit(1);
    }

    fprintf(fp,"\n%s\n", __DATE__);

    fprintf(fp, "intretinere=%lf\n", p->intretinere);
    fprintf(fp, "chirie=%lf\n", p->chirie);
    fprintf(fp, "apometre=%lf\n", p->apometre);
    fprintf(fp, "gaze=%lf\n", p->gaze);
    fprintf(fp, "electrica=%lf\n", p->electrica);
    fprintf(fp, "orange=%lf\n", p->orange);


    fclose(fp);
}

//
// IF date found, show details.
//
void select_data(void)
{
    FILE *fp;
    char date[13+1], buf[100+1];
    int status = 0, i = 0;

    printf("Enter the date and show the details.\nEx: Feb 26 2014\n");
    gets(date);
    if (strlen(date) > 13)
    {
        printf("Error: Date format not correct!\n");
        exit(1);
    }
    date[14] = '\0';

    if( (fp = fopen(CFG_FILE, "r")) == NULL )
    {
        printf("Error opening the file!\n");
        exit(1);
    }
    else
    {
        while( !feof(fp) && status == NO )
        {
            if(fgets(buf, 100, fp) != NULL)
            {
                buf[strlen(buf)-1] = '\0';
                if(strcmp(buf, date) == 0)
                {
                    printf("Date: %s FOUND! with following details:\n", buf);
                    status = YES;
                }
            }
        }

        if( status == YES )
        {
            for(i = 0; i < 6; i++) // How manny element has the structure
            {
                if( fgets(buf, 100, fp) != NULL )
                    printf("\t%d) %s", i, buf);
            }
        }
        else
            printf("No date found!\n");
    }

    fclose(fp);
}

void print_all(void)
{
    FILE *fp;
    char buf[100+1];

    if( (fp = fopen(CFG_FILE, "r")) == NULL )
    {
        printf("Error opening the file!\n");
        exit(1);
    }
    else
    {
         while( !feof(fp) )
         {
            if( fgets(buf, 100, fp) != NULL )
                printf("\t%s", buf);
         }
    }
    fclose(fp);
}
