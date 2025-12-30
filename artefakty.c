#include  "artefakty.h"

Node* dodajArtefakt(Node *head){
    Node* nowy = (Node*)malloc(sizeof(Node));
    if(nowy == NULL){
        printf("Blad alokacji pamieci!\n");
        return head;
    }

    while(getchar() != '\n');

    printf("Podaj nazwe artefaktu: ");
    fgets(nowy->dane.nazwa, 101,stdin);

    printf("Podaj pochodzenie: ");
    fgets(nowy->dane.pochodzenie, 101,stdin);

    printf("Podaj tworcow: ");
    fgets(nowy->dane.tworcy, 101,stdin);

    printf("Podaj poziom zagrozenia: ");
    scanf("%d", &nowy->dane.zagrozenie);
    while(getchar() != '\n');

    printf("Podaj rok odkrycia: ");
    scanf("%d", &nowy->dane.rokOdkrycia);
    while(getchar() != '\n');

    nowy->nastepny = head;
    return nowy;
}

void wyswietlArtefakty(Node *head){
    if(head == NULL){
        printf("Brak artefaktow do wyswietlenia.\n");
        return;
    }
    Node* aktualny = head;
    while(aktualny != NULL){
        printf("Nazwa: %s", aktualny->dane.nazwa);
        printf("Pochodzenie: %s", aktualny->dane.pochodzenie);
        printf("Tworcy: %s", aktualny->dane.tworcy);
        printf("Zagrozenie: %d\n", aktualny->dane.zagrozenie);
        printf("Rok odkrycia: %d\n", aktualny->dane.rokOdkrycia);
        printf("Status: %s", aktualny->dane.status);
        printf("-------------------------\n");
        aktualny = aktualny->nastepny;
    }
}
/*
wyszukajArtefakt();
sortujArtefakty();
modyfikujArtefakt();
usunArtefakt();
zapiszDoPliku();
odczytajZPliku();*/
