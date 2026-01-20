#ifndef ARTEFAKTY_H
#define ARTEFAKTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nazwa[101];
    char pochodzenie[101];
    char tworcy[101];
    int zagrozenie; //0-10
    int rokOdkrycia;
    char status[101];
} Artefakt;

typedef struct Node {
    Artefakt dane;
    struct Node* nastepny;
} Node;

Node* dodajArtefakt(Node *head);
void wyswietlArtefakty(Node *head);
Node* wyszukajArtefakt(Node *head, const char *nazwa, const int rok, int typSzukane);
void sortujArtefakty(Node *head, int typSortowane);
Node* modyfikujArtefakt(Node *head, const char *nazwa);
Node* usunArtefakt(Node *head, const char *nazwa);
void zapiszDoPliku(Node *head, const char *nazwaPliku);
Node* odczytajZPliku(Node *head, const char *nazwaPliku);
#endif