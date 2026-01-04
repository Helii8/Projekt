#include  "artefakty.h"

Node* dodajArtefakt(Node *head){
    Node* nowy = (Node*)malloc(sizeof(Node));
    if(nowy == NULL){
        printf("Blad alokacji pamieci!\n");
        return head;
    }

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

    printf("Podaj status: \n1. bezpieczny\n2. niestabilny\n3. zakazany\nWybor: ");
    int s;
    if(scanf("%d", &s) != 0){
        while(getchar() != '\n');
        
    }
    while(getchar() != '\n');
    switch(s){
        case 1:
            strcpy(nowy->dane.status, "bezpieczny\n");
            break;
        case 2:
            strcpy(nowy->dane.status, "niestabilny\n");
            break;
        case 3:
            strcpy(nowy->dane.status, "zakazany\n");
            break;
        default:
            strcpy(nowy->dane.status, "nieznany\n");
            break;
    }

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

void zapiszDoPliku(Node *head, const char *nazwaPliku){
    FILE *plik= fopen(nazwaPliku, "w");
    if(!plik){
        fprintf(stderr, "Blad otwarcia pliku do zapisu.\n");
    }
    Node* aktualny = head;
    while(aktualny != NULL){
        fprintf(plik, "%s", aktualny->dane.nazwa);
        fprintf(plik, "%s", aktualny->dane.pochodzenie);
        fprintf(plik, "%s", aktualny->dane.tworcy);
        fprintf(plik, "%d\n", aktualny->dane.zagrozenie);
        fprintf(plik, "%d\n", aktualny->dane.rokOdkrycia);
        fprintf(plik, "%s", aktualny->dane.status);
        aktualny = aktualny->nastepny;
    }
    fclose(plik);
}

/*
wyszukajArtefakt();
sortujArtefakty();
modyfikujArtefakt();
usunArtefakt();
odczytajZPliku();*/
