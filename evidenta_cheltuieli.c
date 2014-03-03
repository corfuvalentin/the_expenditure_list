//      evidenta_cheltuieli.c
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

#include "evidenta_cheltuieli.h"
#include "help.h"

int main(int argc, char** argv)
{
    struct data *p;
    p=(month_pay*)malloc(sizeof(month_pay));
    //TO DO: check if malloc fail!

    if(argc != 2)
    {
        help();
        exit(1);
    }

    switch( argv[1][0] )
    {
        case 'v':
        {
            printf("Selected viewing mode.\n");
            print_all();
            break;
        }
        case 'i':
        {
            printf("Selected inserting mode.\n");
            get_data(p);
            insert_into_file(p);
            break;
        }
        case 's':
            printf("Selected searching mode.\n");
            select_data();
            break;

        default:
        {
            printf("Error! Option not found!\n");
            help();
            exit(1);
            break;
        }
    }

    return 0;
}

