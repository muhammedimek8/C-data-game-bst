//
//  ilk_seviye.h
//  Treasure Hunt Adventure
//
//  Created by Muhammed Şimşek on 26.04.2025.
//

#ifndef ilk_seviye_h
#define ilk_seviye_h


typedef struct First_Level_Box {
    int point;
    int box_number;
    int user_on_the_box;
    struct First_Level_Box* next;
  
} First_Level_Box;


extern First_Level_Box* head ;
int dice(void);
int random_point(void) ;
First_Level_Box* kutulariOlustur(void);
First_Level_Box* yenibox(void);
void ilk_seviyeyi_oynat(void);

// son vagon olayını sadece file op sayfasında kullandım



#include <stdio.h>

#endif /* ilk_seviye_h */
