#  <#Title#>




projede tahminen üç tür data modeli kullanılacak 

The number you roll is the number of spaces you move on the map. When
you reach a numbered spot, see what's out there: 


bir kutuda bu işlemler olabailir  



bence öncelikle bir liste hazırlanmalı ve bu liste de olacak şey oyun başlamadan kurgulanmalı 

yine bence struct olabilir ilk seviye için 
içinde tutacağı şeyler 

bunların hepsi olsun bazıları null olur veya 0 deriz
mesela great treasure denilen şeyde hepsinde olsun 
bir tanesinde puan koyarız diğerleri 0 olur gibi 



zar atma olayı 
bu da en güzel şekilde ayarlanmalı 1 den altıya bir sayı gelicek sonuçta 



sonuc.c 

ilk_seviye.c

zar.c 

main.c

ikinci_seviye.c




menüde start game olacak ve score board olacak bunlardan birisi seçilecek illaki bir de çıkış koyarız





earn points, 
lose points, 
move back, 
move forward
nothing
happens. 




Wagon* wagon_head = NULL;
Wagon* last_wagon_g = NULL;

Wagon* create_wagon(Train* train) {
    Wagon* new_wagon = (Wagon*)malloc(sizeof(Wagon));
    if (!new_wagon) {
        printf("Memory allocation failed for wagon.\n");
        return NULL;
    }

    new_wagon->wagon_id = train->wagon_count + 1;
    new_wagon->current_weight = 0;
    new_wagon->next = NULL;
    new_wagon->prev = NULL;

    // wagon_head'i başlatıyoruz
    if (wagon_head == NULL) {
        wagon_head = new_wagon;
    }

    // Trenin ilk vagonu ise

 #ifndef VAGON_H
#define VAGON_H

#include "material.h"

// Train türüne ileri bildirim ekliyoruz
typedef struct Train Train;
typedef struct MaterialType MaterialType;


typedef struct Wagon {
    int wagon_id;
    int material_amount;
   float current_weight;
    struct Wagon* next;
    struct Wagon* prev;
    MaterialType* first_material;
} Wagon;

extern Wagon* wagon_head ;

// son vagon olayını sadece file op sayfasında kullandım 
extern Wagon* last_wagon_g ;

Wagon* create_wagon(Train* train);
void add_materials_to_wagons(void);
void add_material_to_specific_wagon( int wagon_id);

void unload_last_material_from_last_wagon(void) ;
void unload_specific_wagon(int wagon_id);

#endif /* VAGON_H */


#include <stdio.h>
#include "train.h"
#include "vagon.h"
#include "material.h"
#include "utility.h"
#include "file_opr.h"
#include "string.h"
#include "stdlib.h"

void display_menu(void) {
    printf("\n*** Train Loading Management System ***\n");
    printf("1. Load train status from file\n");
    printf("2. Load material, starting from first suitable wagon from head of the Train\n");//
    printf("3. Load material to specific wagon\n");//
    printf("4. Unload material, starting from first suitable wagon from tail of the Train\n");
    printf("5. Unload material from specific wagon\n");
    printf("6. Display train status\n");
    printf("7. Display material status\n");
    printf("8. Empty train\n");
    printf("9. Save train status to file\n");//
    printf("10. Exit\n");
    printf("Select an option: ");
}

int main(void) {

    create_multiple_materials(40); createTrain();
    create_wagon(current_train);
   
   
    int choice;

    while (1) {
        display_menu();
           scanf("%d", &choice);
           fflush(stdin);
        switch (choice) {
            case 1:
                load_train_status_from_file("Train_Information.txt");
                break;
            case 2:
                add_materials_to_wagons();
                break;
            case 3:
                {
                    int istenen;
                    printf("lütfen vagon belirtiniz");
                    scanf("%d",&istenen);
                    add_material_to_specific_wagon(istenen);
                }
                break;
            case 4:
                     unload_last_material_from_last_wagon();
                break;
            case 5:
            {
                int istenen_;
                printf("lütfen vagon belirtiniz :");
                scanf("%d",&istenen_);
               unload_specific_wagon(istenen_);
            }
                break;
            case 6:
                display_train_status();
                break;
            case 7:
                display_material_status();
                break;
            case 8:
                empty_train();
                break;
            case 9:
                save_train_status_to_file("Train_Information.txt", current_train);
                break;
            case 10:
                printf("Exiting program.\n");

                           // Hafıza temizliği
                           free(current_train);
                           free(material_head);
                           free(wagon_head);
                           clear_file_content("Train_Information.txt");

                           return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


    return 0;
   
   
    
}


        printf("Merhaba Oyuncu İlk Seviye Oyuna Hoş Geldin Başlayalım mı? \n");
        int answer ;
        printf("Başlamak için -1- girin\n");
        printf("Geri dönmek için -2- girin\n");

        scanf("%d", &answer);
        
        if (answer==1) {
            
            printf("Oyun Başladı Zar Atmak İçin Entera Basın ");
            
            
   
