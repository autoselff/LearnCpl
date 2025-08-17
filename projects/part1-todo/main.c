#include <stdio.h>
#include <string.h>

#define MAX_ACTIONS 128
#define MAX_LENGTH 128

int main() {
    char actions[MAX_ACTIONS][MAX_LENGTH] = { "Prototype Action" };
    int actions_len = MAX_ACTIONS;

    FILE *fp;
    char buf[MAX_LENGTH];

    fp = fopen("data.txt", "r");
    if (fp != NULL) {
        int i = 0;
        while (i < actions_len && fgets(buf, sizeof(buf), fp) != NULL) {
            buf[strcspn(buf, "\n")] = '\0';
            strcpy(actions[i], buf);
            i++;
        }
        fclose(fp);
    }

    int choice = 0;

    while (choice != 4) {
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("[1] Dodaj aktywnosc do listy [2] Usun aktywnosc z listy [3] Wyswietl liste [4] zakoncz dzialanie programu\n");
        printf("Aktualnie najwieksza liczba mozliwych przypisanych aktywnosci wynosi %d\n", MAX_ACTIONS);
        printf("Podaj akcje: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Niepoprawne dane. Sprobuj ponownie.\n");
            continue;
        }
        getchar();

        switch (choice) {
            case 1: {
                char a[MAX_LENGTH];
                int index;

                printf("Podaj akcje do wpisania: ");
                fgets(a, sizeof(a), stdin);
                a[strcspn(a, "\n")] = '\0';

                printf("Podaj index nowej akcji (0-%d): ", MAX_ACTIONS - 1);
                if (scanf("%d", &index) != 1) {
                    while (getchar() != '\n');
                    printf("Niepoprawny indeks.\n");
                    break;
                }
                getchar();

                if (index >= 0 && index < MAX_ACTIONS) {
                    strcpy(actions[index], a);
                    printf("Poprawnie zapisano akcje...\n");
                } else {
                    printf("Niepoprawny indeks. Akcja nie zostala dodana.\n");
                }
                break;
            }

            case 2: {
                int index_to_remove;
                printf("Podaj index aktywnosci do usuniecia (0-%d): ", MAX_ACTIONS - 1);
                if (scanf("%d", &index_to_remove) != 1) {
                    while (getchar() != '\n');
                    printf("Niepoprawny indeks.\n");
                    break;
                }
                getchar();

                if (index_to_remove >= 0 && index_to_remove < MAX_ACTIONS) {
                    actions[index_to_remove][0] = '\0';
                    printf("Poprawnie usunieto akcje\n");
                } else {
                    printf("Niepoprawny indeks.\n");
                }
                break;
            }

            case 3:
                printf("Aktualna lista aktywnosci:\n");
                for (int i = 0; i < actions_len; ++i) {
                    if (actions[i][0] != '\0') {
                        printf("%d - %s\n", i, actions[i]);
                    }
                }
                break;

            case 4:
                printf("Koniec programu.\n");

                fp = fopen("data.txt", "w");
                if (fp == NULL) {
                    perror("Nie mozna otworzyc pliku do zapisu");
                    return 1;
                }

                for (int i = 0; i < actions_len; ++i) {
                    fprintf(fp, "%s\n", actions[i]);
                }
                fclose(fp);
                break;

            default:
                printf("Niepoprawna akcja.\n");
                break;
        }
    }

    return 0;
}
