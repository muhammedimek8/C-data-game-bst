//
//  Utility.h
//  Treasure Hunt Adventure
//
//  Created by Muhammed Şimşek on 27.04.2025.
//

#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include "simsekcetinikinci_seviye.h"
#include "simsekcetinilk_seviye.h"

extern Second_Level_Box* dhead;

void print_linked_list(First_Level_Box* neredeyim);
void print_doubley_linked_list(Second_Level_Box* head, Second_Level_Box* neredeyim);
Second_Level_Box* dilerle(Second_Level_Box** temp, int ilerleme, int* point);
Second_Level_Box* dgerile(Second_Level_Box** temp, int gerileme, int* point);
char get_input(void);

void writeToFile(const char* filename, const char* username, const char* level, int point);
void printUserScores(const char* filename, const char* username);

#endif /* UTILITY_H */
