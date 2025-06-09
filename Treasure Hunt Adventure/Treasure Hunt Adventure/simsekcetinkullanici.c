//
//  kullanici.c
//  Treasure Hunt Adventure
//
//  Created by Muhammed Şimşek on 2.05.2025.
//

#include "simsekcetinkullanici.h"
// score_tree.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SCORE_FILE "/Users/muhammedsimsek/Desktop/score.txt"


Node* insertNode(Node* root, const char* username, const char* level, int point) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->point = point;
        strcpy(newNode->username, username);
        strcpy(newNode->level, level);
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (point < root->point) {
        root->left = insertNode(root->left, username, level, point);
    } else {
        root->right = insertNode(root->right, username, level, point);
    }

    return root;
}

Node* buildUserScoreTree(const char* filename, const char* username) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Dosya açılamadı!\n");
        return NULL;
    }

    Node* root = NULL;
    char fileUsername[50];
    char level[20];
    int point;

    while (fscanf(file, "%s %s %d", fileUsername, level, &point) == 3) {
        if (strcmp(fileUsername, username) == 0) {
            root = insertNode(root, fileUsername, level, point);
        }
    }

    fclose(file);
    return root;
}


void printScoresInOrder(Node* root, int* isFirst) {
    if (root == NULL) return;

    printScoresInOrder(root->left, isFirst);

    if (!*isFirst) {
        printf(", ");
    }
    printf("%d (%s)", root->point, root->level);
    *isFirst = 0;

    printScoresInOrder(root->right, isFirst);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}




void printMinMaxScore(Node* root) {
    if (root == NULL) {
        printf("Ağaç boş.\n");
        return;
    }

    Node* minNode = root;
    Node* maxNode = root;

    // En küçük skoru bulmak için en sola git
    while (minNode->left != NULL) {
        minNode = minNode->left;
    }

    // En büyük skoru bulmak için en sağa git
    while (maxNode->right != NULL) {
        maxNode = maxNode->right;
    }

    printf("Lowest score : %d (%s)\n", minNode->point, minNode->level);
    printf("Highest score : %d (%s)\n", maxNode->point, maxNode->level);
}
