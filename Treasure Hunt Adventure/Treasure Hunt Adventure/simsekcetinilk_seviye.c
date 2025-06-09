//
//  ilk_seviye.c
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
#include "simsekcetinkullanici.h"
#define SCORE_FILE "/Users/muhammedsimsek/Desktop/score.txt"

First_Level_Box* head = NULL;



First_Level_Box* yenibox(void) {
    First_Level_Box* yeni = (First_Level_Box*)malloc(sizeof(First_Level_Box));
    if (!yeni) {
        printf("Bellek ayrilamadi!\n");
        exit(1);
    }
    yeni->point= random_point();
    yeni->next = NULL;
    
    
    return yeni;
}

First_Level_Box* kutulariOlustur(void) {
    
    for (int i = 0; i < 31; i++) {
        First_Level_Box* yeni = yenibox();
        yeni->box_number = i;
        if (head == NULL) {
            head = yeni;
            yeni->point=0;
        } else {
            First_Level_Box* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = yeni;
        }
    }
    
    return head;
}

void ilk_seviyeyi_oynat(void){
    
    kutulariOlustur();
    First_Level_Box* temp = head;
    
    printf("lütfen kullanıcı adını giriniz :");
    char kullanici_adi[50];
    
    scanf("%s",kullanici_adi);
    
    getchar();
    
    int point = 0;
    while (temp->next!=NULL) {
        
        print_linked_list(temp);
        printf("Roll the dice (ENTER)");
        getchar();
        int result=dice();
        
        printf("Zar atiliyor...\n");
        sleep(1); // 2 saniye bekler
        printf("Gelen sayi: %d\n", result);
        if (result+temp->box_number<31) {
            for (int i = 0; i<result;i++) {
                temp=temp->next;
            }
            point+=temp->point;
        }
        else
        {
            printf("Oyun bitti tebrikler ");
            printf("Puanınız : %d",point);
            writeToFile(SCORE_FILE, kullanici_adi,"level1",point);
            break;
            
            
        }
        
            printf("Şu anki toplam puan: %d\n\n", point);
    }
    
    
    
}
