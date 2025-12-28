#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char nazwa[101];
        char pochodzenie[101];
        char tworcy[101];
        int zagrozenie;
        int rokOdkrycia;
        char status[101];
    } Artefakt;

Artefakt baza[50];
int liczbaArtefaktow = 0;

/*
dodajArtefakt();
wyswietlArtefakty();
wyszukajArtefakt();
sortujArtefakty();
modyfikujArtefakt();
usunArtefakt();
zapiszDoPliku();
odczytajZPliku();
*/

void menu(){
    printf("1. Dodaj artefakt\n");
    printf("2. Wyswietl artefakty\n");
    printf("3. Wyszukaj artefakt\n");
    printf("4. Sortuj artefakty\n");
    printf("5. Modyfikuj artefakt\n");
    printf("6. Usun artefakt\n");
    printf("7. Zapisz do pliku\n");
    printf("8. Odczytaj z pliku\n");
    printf("0. Wyjscie\n");
    printf("Wybierz opcje: ");
}

int main(){
    int wybor;

    while(wybor != 0){
        menu();
        scanf("%d", &wybor);
        switch(wybor){
            case 1:
                //dodajArtefakt();
                break;
            case 2:
                //wyswietlArtefakty();
                break;
            case 3:
                //wyszukajArtefakt();
                break;
            case 4:
                //sortujArtefakty();
                break;
            case 5:
                //modyfikujArtefakt();
                break;
            case 6:
                //usunArtefakt();
                break;
            case 7:
                //zapiszDoPliku();
                break;
            case 8:
                //odczytajZPliku();
                break;
            case 0:
                printf("Zamykanie programu...\n");
                //zapiszDoPliku();
                break;
            default:
                printf("Niepoprawna opcja.\n");
        }
    }

    return 0;
}