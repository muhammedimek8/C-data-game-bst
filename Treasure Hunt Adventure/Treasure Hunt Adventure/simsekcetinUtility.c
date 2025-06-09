//
//  Utility.c
//  Treasure Hunt Adventure
//
//  Created by Muhammed Şimşek on 27.04.2025.
//

#include "simsekcetinUtility.h"
#include <string.h>
#include <termios.h>
#include "simsekcetinkullanici.h"
#include <unistd.h>
#define SCORE_FILE "/Users/muhammedsimsek/Desktop/score.txt"

void print_linked_list(First_Level_Box* neredeyim){
    
    First_Level_Box* temp = head;
    
    
    while (temp) {
        // Başlangıç kutusu
        if (temp->box_number == 0) {
            printf(" ----<------<Başlangıç Kutusu   ");
            if (temp == neredeyim) {
                printf("000000000000BURDAYIZZZZZZ0000000000");
            }
            printf("\n");
            
            
        }
        
        // Move forward kutuları
        else  {
            usleep(100000);
            printf(" ----<------< Kutu Numarası %d  -- Kutu Puanı  -- (%d) ", temp->box_number, temp->point);
            if (temp == neredeyim) {
                printf("000000000000BURDAYIZZZZZZ0000000000");
            }
            printf("\n");
            
            
        }
        
        temp = temp->next;
    
        
    }
}
void print_doubley_linked_list(Second_Level_Box* headalınan, Second_Level_Box* neredeyim) {
    Second_Level_Box* temp = headalınan;

    while (temp) {
        // Başlangıç kutusu
        if (temp->prev == NULL) {
            printf(" ----<------<Başlangıç Kutusu   ");
            if (temp == neredeyim) {
                printf("000000000000BURDAYIZZZZZZ0000000000");
            }
            printf("\n");
           
            
        }
       
        // Move forward kutuları
        else if (temp->move_forward != 0) {
            usleep(100000);
            printf(" ----<------< Kutu Numarası %d  -- Kutu Puanı  -- (%d) ", temp->box_number, temp->point);
            printf("    ILERI  ( %d )   ", temp->move_forward);
            if (temp == neredeyim) {
                printf("000000000000BURDAYIZZZZZZ0000000000");
            }
            printf("\n");
           
            
        }
        // Backward kutuları
        else if (temp->back_forward != 0) {
            usleep(100000);
            printf(" ----<------< Kutu Numarası %d  -- Kutu Puanı  -- (%d) ", temp->box_number, temp->point);
            printf("    GERI   ( %d )", temp->back_forward);
            if (temp == neredeyim) {
                printf("000000000000BURDAYIZZZZZZ0000000000");
            }
            printf("\n");
           
            
        }
        
        
        
        else if (temp->move_forward == 0 && temp->back_forward == 0) {
            usleep(100000);
            printf(" ----<------< Kutu Numarası %d  -- Kutu Puanı  -- (%d) ",
                   temp->box_number, temp->point);
            
            printf("    SADECE ZAR ");
            if (temp == neredeyim) {
                printf("000000000000BURDAYIZZZZZZ0000000000");
            }
            printf("\n");
           
            
        }
        temp = temp->next;
        
    }
}



Second_Level_Box* dilerle(Second_Level_Box** temp, int ilerleme, int* point) {
    
    while (ilerleme-- >0 && (*temp)->next != NULL) {
        (*temp)=(*temp)->next;
    }
    *point+=(*temp)->point;
    
    return *temp;
    
}

    
    
    
    
Second_Level_Box* dgerile(Second_Level_Box** temp, int gerileme, int* point) {
    while (gerileme-- > 0 && (*temp)->prev != NULL) {
        *temp = (*temp)->prev;
    }
    *point += (*temp)->point;
    return *temp;
}


char get_input(void) {
    int ch = getchar();

    // Sadece ENTER'a basıldıysa
    if (ch == '\n') {
        return '\n';
    }

    // İlk karakter alınır
    char input_char = (char)ch;

    // Satırın geri kalanı temizlenir
    while ((ch = getchar()) != '\n' && ch != EOF);

    return input_char;
}



void writeToFile(const char* filename, const char* username, const char* level, int point) {
    FILE *file = fopen(filename, "a");  // Dosyayı ekleme modunda aç
    if (file == NULL) {
        printf("Dosya açılamadı!\n");
        return;
    }

    // Verileri uygun formatta dosyaya yaz
    fprintf(file, "%s %s %d\n", username, level, point);

    fclose(file);
}

