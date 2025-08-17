#include <stdio.h>

// ORGANIZATOR RZECZY DO ZROBIENIA
int main(){
    printf("[1] Dodaj aktywnosc do listy [2] Usun aktywnosc z listy [3] Wyswietl liste [4] zakoncz dzialanie programu\n");
    printf("Aktualnie najwieksza liczba mozliwych przypisanych aktywnosci wynosi 10\n");
    
    char actions[16][32] = {
        "Prototype Action"
    };
    
    int actions_len = sizeof(actions) / sizeof(actions[0]);

    int choice;
    
    while (choice != 4) {
    
        printf("Podaj akcje\n");
        scanf("%d", &choice); 
    
        switch(choice) {
            case 1:
                char a[32];
                printf("Podaj akcje do wpisania\n");
                scanf("%s", &a);
                a[strcspn(a, "\n")] = '\0';
    
                int index;
                printf("Podaj index nowej akcji\n");
                scanf("%d", &index);
                getchar();
    
                strcpy(actions[index], a);
                printf("Poprawnie zapisano akcje...\n");
                break;
    
            case 2:
                int index_to_remove;
                printf("Podaj index aktywnosci do usuniecia\n");
                scanf("%d", &index_to_remove);
                getchar();
    
                actions[index_to_remove][0] = '\0';
                printf("Poprawnie usunieto akcje\n");
                break;
    
            case 3:
                for(int i = 0; i < actions_len; ++i) {
                    if (actions[i][0] != '\0') printf("%d - %s\n", i, actions[i]);
                }
                break;
    
            case 4:
                printf("Koniec programu.\n");
                break;
    
            default:
                printf("Niepoprawna akcja.\n");
                break;
        }       
    }
}
