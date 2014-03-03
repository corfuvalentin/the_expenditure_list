//      evidenta_cheltuieli.h
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


#ifndef EVIDENTA_CHELTUIELI_H
#define EVIDENTA_CHELTUIELI_H

typedef struct data {
    double intretinere;
    double chirie;
    double apometre;
    double gaze;
    double electrica;
    double orange;
} month_pay;

#define YES 1
#define NO 0

#define CFG_FILE "evidence.cfg"

#endif
