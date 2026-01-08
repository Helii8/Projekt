#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artefakty.h"

void menu(){
    printf("1. Dodaj artefakt\n");
    printf("2. Wyswietl artefakty\n");
    printf("3. Wyszukaj artefakt\n");
    printf("4. Sortuj artefakty\n");
    printf("5. Modyfikuj artefakt\n");
    printf("6. Usun artefakt\n");
    printf("7. Zapisz do pliku\n");
    printf("8. Wczytaj z pliku(UWAGA NADPISUJE NOWE DANE)\n");
    printf("0. Wyjscie\n");
    printf("Wybierz opcje: ");
}

int main(int argc, char *argv[]) {
    if ( argc < 2 ) { 
        fprintf(stderr, "Nie podano nazwy pliku!");
        return 1;
    }

    int wybor = -1;
    Node* lista = NULL;

    lista = odczytajZPliku(lista, argv[1]);

    while(wybor != 0){
        menu();
        
        if (scanf("%d", &wybor) != 1) {
            while(getchar() != '\n');
            printf("Wpisz liczbe!\n");
            continue;
        }
        
        while(getchar() != '\n');

        switch(wybor){
            case 1:
                lista = dodajArtefakt(lista);
                break;
            case 2:
                wyswietlArtefakty(lista);
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
                zapiszDoPliku(lista, argv[1]);
                break;
            case 8:
                lista = odczytajZPliku(lista, argv[1]);
                break;
            case 0:
                printf("Zamykanie programu...\n");
                zapiszDoPliku(lista, argv[1]);
                break;
            default:
                printf("Niepoprawna opcja.\n");
        }
    }

    return 0;
}