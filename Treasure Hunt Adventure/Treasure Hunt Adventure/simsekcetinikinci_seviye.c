//
//  ikinci_seviye.c
//  Treasure Hunt Adventure
//
//  Created by Muhammed Şimşek on 26.04.2025.
//
#include "simsekcetinilk_seviye.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "simsekcetinUtility.h"
#include "simsekcetinikinci_seviye.h"
#include <termios.h>
#include "simsekcetinkullanici.h"
#define SCORE_FILE "/Users/muhammedsimsek/Desktop/score.txt"
Second_Level_Box* dhead = NULL;

Second_Level_Box* yeni_dbox(void) {
    Second_Level_Box* yeni = (Second_Level_Box*)malloc(sizeof(Second_Level_Box));
    if (!yeni) {
        printf("Bellek ayrilamadi!\n");
        exit(1);
    }
    yeni->point = random_point();
    yeni->move_forward = 0;
    yeni->back_forward = 0;
    yeni->next = NULL;
    yeni->prev = NULL;
    return yeni;
}
Second_Level_Box* d_boxkutulariOlustur(void) {
    for (int i = 0; i < 31; i++) {
        Second_Level_Box* yeni = yeni_dbox();
        
        yeni->box_number = i;

        int random_case = rand() % 3;

        switch (random_case) {
            case 1:
                yeni->move_forward = yeni->move_forward = ((30 - i + 1) / 4 > 0) ? rand() % ((30 - i + 1) / 4) + 1 : 0;

                break;
            case 2:
                yeni->back_forward = (rand() % ((i+1))/4)+1; // geriye gidecek kutu olmalı
                break;
        }

        if (dhead == NULL) {
            dhead = yeni;
            yeni->point  = 0 ;
        } else {
            Second_Level_Box* temp = dhead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = yeni;
            yeni->prev = temp;
        }
    }

    return dhead;
}

void ikinci_seviyeyi_oynat(void) {
    
    d_boxkutulariOlustur();
    Second_Level_Box* temp = dhead;
    int point = 0;
    printf("lütfen kullanıcı adını giriniz :");
    char kullanici_adi[50];
    scanf("%s",kullanici_adi);
    
    
    while (temp->next != NULL) {
        print_doubley_linked_list(dhead, temp);

        if (temp->prev == NULL) {
            printf("Başlangıç. Zar atmak için Enter'a bas: ");
        } else if (temp->move_forward != 0) {
            printf("İlerle (1) ya da zar atmak için Enter'a bas: ");
        } else if (temp->back_forward != 0) {
            printf("Geri gitmek için (1), zar atmak için Enter'a bas: ");
        } else {
            printf("Zar atmak için Enter'a bas: ");
        }

        char secim = get_input();
        if (secim == '1') {
            if (temp->move_forward != 0) {
                dilerle(&temp, temp->move_forward, &point);
               
            } else if (temp->back_forward != 0) {
                dgerile(&temp, temp->back_forward, &point);
        
            }
        } else {
            printf("Zar atılıyor...\n");
            sleep(1);
            int z = dice();
            printf("Zar sonucu: %d\n", z);
            dilerle(&temp, z, &point);
            
        }
        printf("Şu anki toplam puan: %d\n\n", point);
    }
    printf("Oyun bitti! Toplam puan: %d\n", point);
    writeToFile(SCORE_FILE, kullanici_adi,"level2",point);
}


