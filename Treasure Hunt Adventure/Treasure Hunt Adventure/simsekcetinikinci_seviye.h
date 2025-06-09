//
//  ikinci_seviye.h
//  Treasure Hunt Adventure
//
//  Created by Muhammed Şimşek on 26.04.2025.
//

#ifndef IKINCI_SEVIYE_H
#define IKINCI_SEVIYE_H

#include <stdio.h>

// İkinci seviye kutu yapısı
typedef struct Second_Level_Box {
    int point;
    int box_number;
    int user_on_the_box;
    int move_forward;
    int back_forward;
    struct Second_Level_Box* next;
    struct Second_Level_Box* prev;
} Second_Level_Box;

extern Second_Level_Box* dhead;

int dice(void);
int random_point(void);

Second_Level_Box* d_boxkutulariOlustur(void);
Second_Level_Box* yeni_dbox(void);
void ikinci_seviyeyi_oynat(void);

#endif /* IKINCI_SEVIYE_H */
