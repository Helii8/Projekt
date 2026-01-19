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

    int wyborZagrozenia = -1;
    while(wyborZagrozenia < 0 || wyborZagrozenia > 10){
        printf("Podaj poziom zagrozenia 0-10: ");
        if(scanf("%d", &wyborZagrozenia) != 1){
            while(getchar() != '\n');
            printf("Wpisz liczbe.\n");
            wyborZagrozenia = -1;
            continue;
        }

        if(wyborZagrozenia < 0 || wyborZagrozenia > 10){
            printf("Wybierz liczbe 0-10.\n");
        }
    }
    nowy->dane.zagrozenie = wyborZagrozenia;

    printf("Podaj rok odkrycia: ");
    scanf("%d", &nowy->dane.rokOdkrycia);
    while(getchar() != '\n');

    int wyborStatusu = 0;
    while(wyborStatusu < 1 || wyborStatusu > 5){
        printf("Podaj status: \n1. bezpieczny\n2. niestabilny\n3. zakazany\n4. wymaga kwarantanny\n5. w trakcie badan\nWybor: ");
        if(scanf("%d", &wyborStatusu) != 1){
            while(getchar() != '\n');
            printf("Wpisz liczbe.\n");
            wyborStatusu = 0;
            continue;
        }

        while(getchar() != '\n');

        if(wyborStatusu < 1 || wyborStatusu > 5){
            printf("Wybierz liczbe 1-5.\n");
        }
    }
    
    switch(wyborStatusu){
        case 1:
            strcpy(nowy->dane.status, "bezpieczny\n");
            break;
        case 2:
            strcpy(nowy->dane.status, "niestabilny\n");
            break;
        case 3:
            strcpy(nowy->dane.status, "zakazany\n");
            break;
        case 4:
            strcpy(nowy->dane.status, "wymaga kwarantanny\n");
            break;
        case 5:
            strcpy(nowy->dane.status, "w trakcie badan\n");
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

Node *odczytajZPliku(Node *head, const char *nazwaPliku){
    FILE *plik = fopen(nazwaPliku, "r");
    if(!plik){
        fprintf(stderr, "Blad otwarcia pliku do odczytu.\n");
        return head;
    }

    char bufor[256];

    while(1){
        if(fgets(bufor, sizeof(bufor), plik) == NULL) break;
        Node* nowy = (Node*)malloc(sizeof(Node));
        if(nowy == NULL){
            printf("Blad alokacji pamieci!\n");
            break;
        }
        strcpy(nowy->dane.nazwa, bufor);
        fgets(nowy->dane.pochodzenie, 101, plik);
        fgets(nowy->dane.tworcy, 101, plik);
        fgets(bufor, sizeof(bufor), plik);
        nowy->dane.zagrozenie = atoi(bufor); //zamiana asci na int
        fgets(bufor, sizeof(bufor), plik);
        nowy->dane.rokOdkrycia = atoi(bufor);
        fgets(nowy->dane.status, 101, plik);
        nowy->nastepny = head;
        head = nowy;
    }

    fclose(plik);
    return head;
}

Node* usunArtefakt(Node *head, const char *nazwa){
    if(head == NULL){
        printf("Lista jest pusta. Nie mozna usunac artefaktu.\n");
        return head;
    }
    Node* aktualny = head;
    Node* poprzedni = NULL;
    while(aktualny != NULL){
        if(strcmp(aktualny->dane.nazwa, nazwa) == 0){
            if(aktualny->dane.zagrozenie >= 8){
                printf("Nie mozna usunac. Zbyt niebezpieczny artefakt.\n");
                return head;
            }
            poprzedni->nastepny = aktualny->nastepny; // pomijamy usuniety
            free(aktualny);
            printf("Artefakt usuniety.\n");
            return head;
        }
        poprzedni = aktualny;
        aktualny = aktualny->nastepny;
    }
    return head;
}

Node* modyfikujArtefakt(Node *head, const char *nazwa){
    if(head == NULL){
        printf("Lista jest pusta. Nie mozna usunac artefaktu.\n");
        return head;
    }
    Node* aktualny = head;
    int status = 0;
    while(aktualny != NULL){
        if(strcmp(aktualny->dane.nazwa, nazwa) == 0){
            printf("Podaj nowy status artefaktu.\n");
            scanf("%d", &status);
            while(status < 1 && status > 5){
                if(scanf("%d", &status) != 1){
                    printf("Blad, podaj liczbe.\n");
                    while(getchar() != '\n');
                    status = 0;
                }
            }
            while(getchar() != '\n');
            if(status >= 1 && status <= 5){
                switch(status) {
                    case 1:
                        strcpy(aktualny->dane.status, "bezpieczny\n");
                        break;
                    case 2:
                        strcpy(aktualny->dane.status, "niestabilny\n");
                        break;
                    case 3:
                        strcpy(aktualny->dane.status, "zakazany\n");
                        break;
                    case 4:
                        strcpy(aktualny->dane.status, "wymaga kwarantanny\n");
                        break;
                }
            }
            printf("Artefakt zmodyfikowany.\n");
            return head;
        }
        aktualny = aktualny->nastepny;
    }
    return head;
}

Node* wyszukajArtefakt(Node *head, const char *nazwa, const int rok, int typSzukane){
    if(head == NULL){
        printf("Lista jest pusta. Nie mozna wyszukac artefaktu.\n");
        return head;
    }

    Node* aktualny = head;
    int znaleziono = 0;

    while(aktualny != NULL){
        int pasuje = 0;

        if(typSzukane == 1){
            if(strcmp(aktualny->dane.nazwa, nazwa) == 0){
                pasuje = 1;
            }
        } else {
            if(aktualny->dane.rokOdkrycia == rok){
                pasuje = 1;
            }
        }
        if(pasuje == 1){
            printf("Nazwa: %s", aktualny->dane.nazwa);
            printf("Pochodzenie: %s", aktualny->dane.pochodzenie);
            printf("Tworcy: %s", aktualny->dane.tworcy);
            printf("Zagrozenie: %d\n", aktualny->dane.zagrozenie);
            printf("Rok odkrycia: %d\n", aktualny->dane.rokOdkrycia);
            printf("Status: %s", aktualny->dane.status);
            printf("-------------------------\n");
            znaleziono = 1;
        }

        aktualny = aktualny->nastepny;
    }

    if(znaleziono == 0){
        printf("Brak pasujacych artefaktow.\n");
    }

    return head;
}

/*
sortujArtefakty();
*/