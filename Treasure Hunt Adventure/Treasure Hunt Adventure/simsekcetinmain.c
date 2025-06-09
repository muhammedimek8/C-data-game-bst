//
//  main.c
//  Treasure Hunt Adventure
//
//  Created by Muhammed Şimşek on 26.04.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simsekcetinilk_seviye.h"
#include "simsekcetinikinci_seviye.h"
#include "simsekcetinkullanici.h"
#include "simsekcetinUtility.h"
#define SCORE_FILE "/Users/muhammedsimsek/Desktop/score.txt"

int dice(void) {
    return (rand() % 6) + 1;
}

int random_point(void) {
    int secim = random() % 3;  // 0, 1 veya 2 olacak
    if (secim == 0)
        return 0;
    else if (secim == 1)
        return -5;
    else
        return 10;
}



void display_menu(void) {
    printf("\n*** Treasure Hunt Game ***\n");
    printf("Start Game (1) \n");
    printf("Scoreboard (2) \n");
    printf("Exit (3) \n");
    printf("Select an option: ");
}

int main(void) {
    
    
    srand((unsigned int)time(NULL));
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                //
                
                printf("Hello Gamer, Weolcome To The Game, Please Select The Diffucilities ? \n");
                int answer ;
                printf("Level (1)\n");
                printf("Level (2)\n");
                printf("Exit  (3)\n");
                scanf("%d", &answer);
                
                if (answer==1) {
                    ilk_seviyeyi_oynat();
                }
                else if (answer ==2){
                    
                    
                    ikinci_seviyeyi_oynat();
                    
                }
                else
                    printf("çıkılıyor ... \n");
                
                break;
            case 2:{
         
                char isim[50];
                printf("Lütfen isim giriniz: ");
                scanf("%s", isim);

                Node* tree = buildUserScoreTree(SCORE_FILE, isim);
                if (tree == NULL) {
                    printf("Kullanıcıya ait kayıt bulunamadı.\n");
                    break;
                }

                printf("Username : %s\n", isim);
                printf("All the scores : ");

                int isFirst = 1;
                printScoresInOrder(tree, &isFirst);
                printf("\n");

                // 💡 İşte buraya bunu ekliyoruz:
                printMinMaxScore(tree);

                freeTree(tree);
                break;
            
                
            }
            case 3:
                printf("Exiting program.\n");
                
               
                
                
        }}}
    






