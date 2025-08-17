# Learn
Private repo to store projectss and sources to learn programming.

## ROADMAP

 1. todo manager with saving to .txt

 2. own interpreter - out, variables, operations on variables (maybe loops)
 WHY? Make a great programming language to let people start writting a code.
 Programming language to let new programmersss know what programming is about
 Just simple instructions
 ADVANCED LIB -> which will allow programmes to write in really loww level

 3. Own program to make bit music with graphicsl interface

 4. ...


 X. Gameboy emulator

## NVIM HELP

 
nvim ~/.config/nvim/init.lua
:PackerSync

git clone --depth 1 https://github.com/wbthomason/packer.nvim \
  ~/.local/share/nvim/site/pack/packer/start/packer.nvim

  -- =============================
-- ŁADOWANIE PACKER
-- =============================
vim.cmd [[packadd packer.nvim]]

-- =============================
-- PODSTAWOWA KONFIGURACJA
-- =============================
vim.wo.number = true
vim.o.expandtab = true
vim.o.shiftwidth = 4
vim.o.tabstop = 4
vim.wo.cursorline = true
vim.o.ignorecase = true
vim.o.smartcase = true
vim.cmd("syntax on")

-- =============================
-- PLUGINY Z PACKER
-- =============================
require('packer').startup(function()
    use 'wbthomason/packer.nvim'

    use {
        "voldikss/vim-floaterm",
        config = function()
            vim.g.floaterm_width = 0.9
            vim.g.floaterm_height = 0.6
            vim.g.floaterm_keymap_toggle = '<F12>'
        end
    }

    use {
        "nvim-tree/nvim-tree.lua",
        requires = "nvim-tree/nvim-web-devicons",
        config = function()
            require("nvim-tree").setup({
                view = {
                    width = 30,
                    side = 'left',
                },
                filters = {
                    dotfiles = false,
                },
            })
        end
    }
end)

-- =============================
-- SKRÓTY
-- =============================
vim.api.nvim_set_keymap('n', '<F12>', ':FloatermToggle<CR>', { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<F2>', ':NvimTreeToggle<CR>', { noremap = true, silent = true })

## C HELP

 
===================================
        PODSTAWY JĘZYKA C
===================================

1. STRUKTURA PROGRAMU
#include <stdio.h>
#define PI 3.14   // stała symboliczna

int main(void) {
    printf("Hello C!\n");   // wypisanie na ekran
    return 0;               // zwracamy kod zakończenia
}
-> Każdy program w C zaczyna się od main(). #define tworzy makro/stałą.

===================================
1.2 WCZYTYWANIE DANYCH W C
===================================

1.2.1. LICZBY – najprościej
int x;
scanf("%d", &x);
printf("Wpisano: %d\n", x);

-> %d – int
-> %f – float
-> %lf – double
-> UWAGA: scanf zostawia w buforze znak końca linii, co czasem psuje kolejne wczytywanie stringów.

--------------------------------------------------

1.2.2. STRINGI – lepiej i bezpieczniej
char s[100];
fgets(s, sizeof(s), stdin);
printf("Tekst: %s\n", s);

-> fgets czyta całą linię (łącznie ze spacjami).
-> Automatycznie dodaje '\0'.
-> Często trzeba usunąć '\n' na końcu:
   s[strcspn(s, "\n")] = '\0';

--------------------------------------------------

1.2.3. KOMBINACJA – fgets + sscanf
char s[100];
int x;
fgets(s, sizeof(s), stdin);
sscanf(s, "%d", &x);
printf("Liczba: %d\n", x);

-> fgets pobiera cały wiersz bezpiecznie,
-> sscanf analizuje tekst i wyciąga liczbę.

--------------------------------------------------

1.2.4. WIELE LICZB W LINII
int a,b;
scanf("%d %d", &a, &b);
printf("%d %d\n", a, b);

-> scanf potrafi od razu czytać kilka wartości oddzielonych spacjami.

--------------------------------------------------

1.2.5. SZYBSZE ALE MNIEJ BEZPIECZNE vs BEZPIECZNIEJSZE
- szybkie: scanf("%d", &x); scanf("%s", s);
- bezpieczniejsze: fgets() + sscanf()

W praktyce:
- Do nauki i prostych programów wystarczy scanf.
- Do większych projektów lepiej trzymać się fgets + sscanf (kontrola błędów i rozmiarów).

--------------------------------------------------

2. TYPY DANYCH
typedef unsigned long ulong;   // alias
enum Kolory { RED, GREEN=5, BLUE };

int a = 10;
ulong b = 20;
enum Kolory k = GREEN;

-> typedef tworzy nowe "imię" dla typu.
-> enum nadaje czytelne nazwy liczbom całkowitym.
-> zmienne mają różne typy (signed, unsigned, enum).

--------------------------------------------------

===================================
3. TABLICE – SZCZEGÓŁOWE WYJAŚNIENIA
===================================

3.1. TABLICE JEDNOWYMIAROWE
int tab[5] = {1,2,3,4,5};
printf("%d\n", tab[0]);   // 1
printf("%d\n", tab[4]);   // 5

-> Tablice mają stały rozmiar, elementy leżą w pamięci obok siebie.
-> Indeks zaczyna się od 0.

--------------------------------------------------

3.2. TABLICE DWUWYMIAROWE
int macierz[2][3] = {
    {1,2,3},
    {4,5,6}
};
printf("%d\n", macierz[1][2]); // 6

-> Tablica 2D to tablica tablic.
-> Dostęp: macierz[wiersz][kolumna].

--------------------------------------------------

3.3. TABLICE A WSKAŹNIKI
int tab[3] = {10,20,30};
int *p = tab; // nazwa tablicy to adres 1. elementu

printf("%d\n", *(p+1));   // 20
printf("%d\n", p[2]);     // 30

-> Tablica i wskaźnik są powiązane: tab[i] == *(tab+i).
-> ALE: wskaźnik można przesuwać, a tablica ma stały rozmiar.

--------------------------------------------------

3.4. PRZEKAZYWANIE TABLIC DO FUNKCJI
void drukuj(int arr[], int n) {
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

int t[3] = {7,8,9};
drukuj(t, 3);

-> Do funkcji przekazujemy ADRES pierwszego elementu.
-> Funkcja potrzebuje też informacji o rozmiarze (n).

--------------------------------------------------

3.5. TABLICE ZNAKÓW (STRINGI)
char s1[] = "Hello";
char s2[20];
strcpy(s2, s1);
printf("%s\n", s2);

-> "Hello" = {'H','e','l','l','o','\0'}.
-> Należy zawsze pamiętać o '\0' na końcu napisu.
-> Funkcje z <string.h> pomagają, ale mogą być niebezpieczne (bufor!).

--------------------------------------------------

3.6. TABLICE DYNAMICZNE
int n = 5;
int *dyn = malloc(n * sizeof(int));
for(int i=0;i<n;i++) dyn[i] = i*10;
free(dyn);

-> Tablice na stercie mogą mieć rozmiar ustalany w czasie działania.
-> Zawsze trzeba pamiętać o free().

===================================

--------------------------------------------------

4. WSKAŹNIKI
int x = 42;
int *p = &x;       // adres zmiennej
printf("%d\n", *p);// dereferencja – wartość pod adresem

int tab[3] = {1,2,3};
int *pt = tab;     // wskaźnik na pierwszy element
printf("%d\n", *(pt+1)); // 2

void fun(int *a) { *a = 100; }
fun(&x); // przekazujemy adres zmiennej

-> Wskaźnik przechowuje adres w pamięci.
-> *p – dostęp do wartości pod adresem.
-> Tablica "zamienia się" w wskaźnik przy przekazaniu.
-> Dzięki wskaźnikom możemy zmieniać wartości w funkcjach.

--------------------------------------------------

===================================
5. ALOKACJA PAMIĘCI – ROZWINIĘCIE
===================================

5.1. PODSTAWY
int *arr = malloc(5 * sizeof(int)); // 5 elementów typu int
if(arr == NULL) {
    printf("Brak pamięci!\n");
    exit(1);
}
arr[0] = 123;
free(arr);

-> malloc() rezerwuje *surowy* blok pamięci na stercie (heap).
-> Zwraca wskaźnik typu void*, więc trzeba rzutować w C++ (w C nie trzeba).
-> Jeśli pamięci brak → zwraca NULL.
-> free() zwalnia pamięć, inaczej powstaje wyciek.

--------------------------------------------------

5.2. calloc() – ZEROWANIE PAMIĘCI
int *arr = calloc(5, sizeof(int)); // 5 intów, wyzerowane
for(int i=0;i<5;i++) printf("%d ", arr[i]); // 0 0 0 0 0
free(arr);

-> calloc() działa jak malloc(), ale dodatkowo zeruje pamięć.
-> Bezpieczne do tworzenia tablic "czystych" od razu.

--------------------------------------------------

5.3. realloc() – ZMIANA ROZMIARU
int *arr = malloc(3 * sizeof(int));
for(int i=0;i<3;i++) arr[i] = i+1;

arr = realloc(arr, 5 * sizeof(int)); // powiększamy
arr[3] = 4; arr[4] = 5;
for(int i=0;i<5;i++) printf("%d ", arr[i]);
free(arr);

-> realloc() zmienia rozmiar istniejącego bloku:
   - jeśli się uda → zwraca nowy wskaźnik (stary nieważny!).
   - jeśli się nie uda → zwraca NULL (oryginalny blok zostaje!).
-> Bezpieczny wzorzec:
   int *tmp = realloc(arr, new_size);
   if(tmp) arr = tmp; else { free(arr); /* obsługa błędu */ }

--------------------------------------------------

5.4. STACK vs HEAP
void f(void) {
    int lokalna[10];        // na stosie (stack)
    int *dynamiczna = malloc(10 * sizeof(int)); // na stercie (heap)
}

-> Zmienna na stosie: znika po wyjściu z funkcji.
-> Pamięć na stercie: istnieje, dopóki nie wywołasz free().
-> Dlatego malloc jest potrzebny, gdy coś musi żyć "dłużej" niż funkcja.

--------------------------------------------------

5.5. memset(), memcpy() – OPERACJE NA PAMIĘCI
int *arr = malloc(5 * sizeof(int));
memset(arr, 0, 5 * sizeof(int)); // wypełnij zerami

int src[3] = {1,2,3};
int dst[3];
memcpy(dst, src, sizeof(src)); // kopiowanie bloków pamięci

-> memset() – wypełnia blok pamięci bajtem (często zerami).
-> memcpy() – kopiuje bajty między blokami pamięci.

--------------------------------------------------

5.6. TYPOWE BŁĘDY
- Użycie pamięci po free():
int *p = malloc(10*sizeof(int));
free(p);
p[0] = 1; // BŁĄD – undefined behavior!

- Podwójne free():
free(p);
free(p); // BŁĄD – undefined behavior!

- Brak free() → wyciek:
while(1) {
    int *x = malloc(1000);
    // brak free → program będzie zużywał coraz więcej pamięci
}

--------------------------------------------------

5.7. DOBRE PRAKTYKI
- Po free() ustaw wskaźnik na NULL:
  free(p); p=NULL;

- Sprawdzaj wynik malloc/calloc/realloc:
  if(!p) { /* obsługa błędu */ }

- Używaj sizeof(*ptr), aby unikać pomyłek:
  int *arr = malloc(10 * sizeof(*arr));

- Debugowanie wycieków:
  używaj narzędzi typu Valgrind (Linux).

  ===================================

--------------------------------------------------

6. STRUKTURY I UNION
struct Punkt { int x,y; };
struct Punkt p = {1,2}; // inicjalizacja

union Dane {
    int i; float f;
};
union Dane d; d.i = 10; // to samo miejsce pamięci może przechowywać różne typy

-> struct grupuje dane w jedną całość.
-> union to kilka pól dzielących tę samą pamięć.

--------------------------------------------------

7. FUNKCJE
int dodaj(int a, int b) { return a+b; }
int wynik = dodaj(2,3);

#include <stdarg.h>
int suma(int n, ...) {
    va_list args; va_start(args, n);
    int s=0;
    for(int i=0;i<n;i++) s += va_arg(args,int);
    va_end(args); return s;
}

-> Funkcje mogą zwracać wartość lub void.
-> Parametry zwykle przekazywane są przez wartość, wskaźnik daje dostęp do oryginału.
-> Funkcje wariadyczne (...) pozwalają przekazać zmienną liczbę argumentów (np. printf).

--------------------------------------------------

8. WEJŚCIE/WYJŚCIE
FILE *fp = fopen("plik.txt", "w"); // otwarcie pliku do zapisu
fprintf(fp, "Test\n");
fclose(fp);

char buf[100];
fgets(buf, sizeof buf, stdin);   // czytanie linii z klawiatury
printf("Wpisano: %s", buf);

-> fopen tworzy uchwyt do pliku.
-> fprintf działa jak printf, ale do pliku.
-> fgets pobiera cały wiersz ze stdin.

--------------------------------------------------

9. ORGANIZACJA KODU
// plik.h (nagłówek)
#ifndef MODUL_H
#define MODUL_H
void foo(void);
#endif

// plik.c (implementacja)
#include "plik.h"
void foo(void){ printf("ok\n"); }

-> Pliki .h zawierają deklaracje.
-> Pliki .c zawierają definicje.
-> #ifndef/#define/#endif chroni przed wielokrotnym dołączaniem.

--------------------------------------------------

10. OPERACJE BITOWE
unsigned char f = 0;
f |= 1<<2;   // ustaw bit 2
if(f & (1<<2)) printf("bit 2 ustawiony\n");
f &= ~(1<<2); // kasuj bit 2

-> << przesunięcie bitowe (1<<2 = 00000100).
-> | ustawia bity, & sprawdza, ~ neguje.
-> Typowe przy flagach i maskach.

--------------------------------------------------

11. DEBUGOWANIE
#include <assert.h>
int dziel(int a, int b){
    assert(b!=0);   // przerwie program, jeśli warunek fałszywy
    return a/b;
}

perror("blad"); // wypisuje ostatni błąd systemowy

-> assert to szybkie sprawdzanie warunków w kodzie.
-> perror wypisuje opis błędu np. przy nieudanym fopen.

--------------------------------------------------

===================================
12. OPTYMALIZACJA – DOBRE PRAKTYKI
===================================

12.1. PRZEKAZYWANIE PRZEZ WSKAŹNIK
void ustaw(int *x) {
    *x = 123; // zmiana oryginału
}
int a = 0;
ustaw(&a);

-> Zamiast kopiować dużą strukturę/funkcję, lepiej przekazać adres.

--------------------------------------------------

12.2. PRZEKAZYWANIE "TYLKO DO ODCZYTU"
void pokaz(const int *arr, int n) {
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

-> const mówi: „funkcja nie zmieni danych”.
-> Chroni przed błędami i pozwala kompilatorowi lepiej optymalizować.

--------------------------------------------------

12.3. UNIKANIE KOPIOWANIA DUŻYCH STRUKTUR
struct Dane {
    int duza_tab[1000];
};

// ŹLE – kopiowanie całej struktury:
void f1(struct Dane d);

// DOBRZE – przekazanie wskaźnika:
void f2(struct Dane *d);

-> Zamiast kopiować 4 KB na stos, przekazujemy tylko adres (kilka bajtów).

--------------------------------------------------

12.4. INLINE FUNKCJE
inline int kwadrat(int x) { return x*x; }
int a = kwadrat(5);

-> inline sugeruje kompilatorowi, aby "wkleił" kod funkcji bez wywołania.
-> Przydaje się w małych, często wywoływanych funkcjach.

--------------------------------------------------

12.5. LOKALIZACJA ZMIENNYCH
void foo(void) {
    static int licznik = 0;
    licznik++;
    printf("%d\n", licznik);
}

-> static w funkcji: zmienna jest inicjalizowana raz i przechowuje stan.
-> Optymalizacja: unikanie globalnych zmiennych i nadmiernych kopii.

--------------------------------------------------

12.6. OGRANICZENIE DOSTĘPU DO ZMIENNYCH
static int prywatna = 0;  // tylko w tym pliku .c

-> static na poziomie pliku ukrywa zmienną/funkcję przed innymi modułami.
-> Kompilator lepiej optymalizuje, gdy widzi cały kontekst.

--------------------------------------------------

12.7. RESTRICT (C99+)
void f(int * restrict a, int * restrict b) {
    *a = *a + *b;
}

-> restrict mówi kompilatorowi, że wskaźniki nie wskazują na te same dane.
-> Daje więcej możliwości optymalizacji (ważne przy pracy z tablicami).

--------------------------------------------------

8. KOMPILACJA Z OPTYMALIZACJĄ
gcc -O2 program.c -o program
gcc -O3 -march=native program.c -o program

-> -O2/-O3 – optymalizacje kompilatora.
-> -march=native – wykorzystanie instrukcji procesora (np. SSE/AVX).


===================================

