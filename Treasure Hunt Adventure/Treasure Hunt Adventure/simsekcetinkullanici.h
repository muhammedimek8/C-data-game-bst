//
//  kullanici.h
//  Treasure Hunt Adventure
//
//  Created by Muhammed Şimşek on 2.05.2025.
//

#ifndef kullanici_h
#define kullanici_h

#include <stdio.h>







typedef struct Node {
    int point;                  // Anahtar
    char username[50];          // Kullanıcı adı
    char level[20];             // Seviye
    struct Node* left;
    struct Node* right;
} Node;

void freeTree(Node* root);
void printScoresInOrder(Node* root, int* isFirst);
void printMinMaxScore(Node* root);
Node* insertNode(Node* root, const char* username, const char* level, int point) ;
Node* buildUserScoreTree(const char* filename, const char* username);

#endif /* kullanici_h */
