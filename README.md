# Learn C

### 0. PODSTAWY
```c
#include <stdio.h>
#define PI 3.14   // stała symboliczna

int main(void) {
    printf("Hello C!\n");   // wypisanie na ekran
    return 0;               // zwracamy kod zakończenia
}
```
-> Każdy program w C zaczyna się od main(). #define tworzy makro/stałą.

--------------------------------------------------
#### 0.1 ZMIENNE
```c
#include <stdio.h>
#include <stdbool.h> // Wymagane do użyawnia bool

int main() {
    // Liczby całkowite
    int a = 10;
    short b = 5;
    long c = 100000L;
    long long d = 1000000000LL;

    // Liczby zmiennoprzecinkowe
    float e = 3.14f;
    double f = 3.141592;
    long double g = 3.141592653589793L;

    // Typ znakowy
    char h = 'A';

    // Typ logiczny true lub false
    bool boo = true;

    // Typ string (tablica znaków)
    char str[] = "Hello, world!";

    // Wyświetlenie zmiennych
    printf("int: %d\n", a);
    printf("short: %d\n", b);
    printf("long: %ld\n", c);
    printf("long long: %lld\n", d);
    printf("float: %f\n", e);
    printf("double: %lf\n", f);
    printf("long double: %Lf\n", g);
    printf("char: %c\n", h);
    printf("bool: %d\n", boo);
    printf("string: %s\n", str);

    return 0;
}
```

--------------------------------------------------
#### 0.2. INSTRUKCJE WARUNKOWE
if
```c
if (choice == 0) {
	printf("Opcja 0\n");
}
else if (x == 1) {
	printf("Opcja 1\n");
}
else printf("nie istnieje taka opcja\n");
```
switch
```c
switch(choice) {
	case 0:
		printf("Opcja 0\n");
		break;
	case 1:
		printf("Opcja 1\n");
		break;
	default:
		printf("nie istnieje taka opcja\n");
		break;
}
```

--------------------------------------------------
#### 0.3 PĘTLE
for 
```c
for(int i = 0; i < 5; i++) {
	printf("i = %d\n", i);
}
```

while
```c

while(i < 5) { // może też być tu jakiś bool www argumencie
	printf("i = %d\n", i);
	i++;
}
```
do-while
```c
do {
	printf("i = %d\n", i);
	i++;
} while(i < 5);
```
--------------------------------------------------
### 1. WCZYTYWANIE DANYCH

#### 1.1. LICZBY
```c
int x;
scanf("%d", &x);
printf("Wpisano: %d\n", x);
```

-> %d – int
-> %f – float
-> %lf – double
-> UWAGA: scanf zostawia w buforze znak końca linii, co czasem psuje kolejne wczytywanie stringów.

--------------------------------------------------

#### 1.2. STRINGI – lepiej i bezpieczniej
```c
char s[100];
fgets(s, sizeof(s), stdin);
printf("Tekst: %s\n", s);
```

-> fgets czyta całą linię (łącznie ze spacjami).
-> Automatycznie dodaje '\0'.
-> Często trzeba usunąć '\n' na końcu:
```c
   s[strcspn(s, "\n")] = '\0';
```
--------------------------------------------------

#### 1.3. KOMBINACJA – fgets + sscanf
```c
char s[100];
int x;
fgets(s, sizeof(s), stdin);
sscanf(s, "%d", &x);
printf("Liczba: %d\n", x);
```

-> fgets pobiera cały wiersz bezpiecznie,
-> sscanf analizuje tekst i wyciąga liczbę.

--------------------------------------------------

#### 1.4. WIELE LICZB W LINII
```c
int a,b;
scanf("%d %d", &a, &b);
printf("%d %d\n", a, b);
```

-> scanf potrafi od razu czytać kilka wartości oddzielonych spacjami.

--------------------------------------------------

#### 1.5. SZYBSZE ALE MNIEJ BEZPIECZNE vs BEZPIECZNIEJSZE
-> szybkie: 
```c
scanf("%d", &x); scanf("%s", s);
```
-> bezpieczniejsze: fgets() + sscanf()

W praktyce:
-> Do nauki i prostych programów wystarczy scanf.
-> Do większych projektów lepiej trzymać się fgets + sscanf (kontrola błędów i rozmiarów).

--------------------------------------------------

### 2. TYPY DANYCH
```c
typedef unsigned long ulong;   // alias
enum Kolory { RED, GREEN=5, BLUE };

int a = 10;
ulong b = 20;
enum Kolory k = GREEN;
```

-> typedef tworzy nowe "imię" dla typu.
-> enum nadaje czytelne nazwy liczbom całkowitym.
-> zmienne mają różne typy (signed, unsigned, enum).

--------------------------------------------------
### 3. TABLICE

#### 3.1. TABLICE JEDNOWYMIAROWE
```c
int tab[5] = {1,2,3,4,5};
printf("%d\n", tab[0]);   // 1
printf("%d\n", tab[4]);   // 5
```
-> Tablice mają stały rozmiar, elementy leżą w pamięci obok siebie.
-> Indeks zaczyna się od 0.

--------------------------------------------------

#### 3.2. TABLICE DWUWYMIAROWE
```c
int macierz[2][3] = {
    {1,2,3},
    {4,5,6}
};
printf("%d\n", macierz[1][2]); // 6
```
-> Tablica 2D to tablica tablic.
-> Dostęp: macierz[wiersz][kolumna].

--------------------------------------------------

#### 3.3. TABLICE A WSKAŹNIKI
```c
int tab[3] = {10,20,30};
int *p = tab; // nazwa tablicy to adres 1. elementu

printf("%d\n", *(p+1));   // 20
printf("%d\n", p[2]);     // 30
```
-> Tablica i wskaźnik są powiązane: tab[i] == *(tab+i).
-> ALE: wskaźnik można przesuwać, a tablica ma stały rozmiar.

--------------------------------------------------

#### 3.4. PRZEKAZYWANIE TABLIC DO FUNKCJI
```c
void drukuj(int arr[], int n) {
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}

int t[3] = {7,8,9};
drukuj(t, 3);
```
-> Do funkcji przekazujemy ADRES pierwszego elementu.
-> Funkcja potrzebuje też informacji o rozmiarze (n).

--------------------------------------------------

#### 3.5. TABLICE ZNAKÓW (STRINGI)
```c
char s1[] = "Hello";
char s2[20];
strcpy(s2, s1);
printf("%s\n", s2);
```
-> "Hello" = {'H','e','l','l','o','\0'}.
-> Należy zawsze pamiętać o '\0' na końcu napisu.
-> Funkcje z <string.h> pomagają, ale mogą być niebezpieczne (bufor!).
-> strcpy służy do kopiowania łańcucha znaków (stringa).

--------------------------------------------------

#### 3.6. TABLICE DYNAMICZNE
```c
int n = 5;
int *dyn = malloc(n * sizeof(int));
for(int i=0;i<n;i++) dyn[i] = i*10;
free(dyn);
```
-> Tablice na stercie mogą mieć rozmiar ustalany w czasie działania.
-> Zawsze trzeba pamiętać o free().

--------------------------------------------------

### 4. WSKAŹNIKI
```c
int x = 42;
int *p = &x;       // adres zmiennej
printf("%d\n", *p);// dereferencja – wartość pod adresem

int tab[3] = {1,2,3};
int *pt = tab;     // wskaźnik na pierwszy element
printf("%d\n", *(pt+1)); // 2

void fun(int *a) { *a = 100; }
fun(&x); // przekazujemy adres zmiennej
```
-> Wskaźnik przechowuje adres w pamięci.
-> *p – dostęp do wartości pod adresem.
-> Tablica "zamienia się" w wskaźnik przy przekazaniu.
-> Dzięki wskaźnikom możemy zmieniać wartości w funkcjach.

Wzkaźniki do funkcji
```c
int dodaj(int a, int b) {
    return a + b;
}

int pomnoz(int a, int b) {
    return a * b;
}

void wykonaj_operacje(int x, int y, int (*f)(int, int)) {
    printf("Wynik: %d\n", f(x, y));
}

int main() {
    wykonaj_operacje(4, 5, dodaj);   // przekazanie wskaźnika do funkcji
    wykonaj_operacje(4, 5, pomnoz);  // inna funkcja
    return 0;
}
```

--------------------------------------------------

### 5. ALOKACJA PAMIĘCI
```c
int *arr = malloc(5 * sizeof(int)); // 5 elementów typu int
if(arr == NULL) {
    printf("Brak pamięci!\n");
    exit(1);
}
arr[0] = 123;
free(arr);
```
-> malloc() rezerwuje *surowy* blok pamięci na stercie (heap).
-> Zwraca wskaźnik typu void*, więc trzeba rzutować w C++ (w C nie trzeba).
-> Jeśli pamięci brak → zwraca NULL.
-> free() zwalnia pamięć, inaczej powstaje wyciek.

--------------------------------------------------

#### 5.1. calloc() – ZEROWANIE PAMIĘCI
```c
int *arr = calloc(5, sizeof(int)); // 5 intów, wyzerowane
for(int i=0;i<5;i++) printf("%d ", arr[i]); // 0 0 0 0 0
free(arr);
```
-> calloc() działa jak malloc(), ale dodatkowo zeruje pamięć.
-> Bezpieczne do tworzenia tablic "czystych" od razu.

--------------------------------------------------

#### 5.2. realloc() – ZMIANA ROZMIARU
```c
int *arr = malloc(3 * sizeof(int));
for(int i=0;i<3;i++) arr[i] = i+1;

arr = realloc(arr, 5 * sizeof(int)); // powiększamy
arr[3] = 4; arr[4] = 5;
for(int i=0;i<5;i++) printf("%d ", arr[i]);
free(arr);
```
-> realloc() zmienia rozmiar istniejącego bloku:
   - jeśli się uda → zwraca nowy wskaźnik (stary nieważny!).
   - jeśli się nie uda → zwraca NULL (oryginalny blok zostaje!).
-> Bezpieczny wzorzec:
```c
   int *tmp = realloc(arr, new_size);
   if(tmp) arr = tmp; else { free(arr); /* obsługa błędu */ }
   ```

--------------------------------------------------

#### 5.3. STACK vs HEAP
```c
void f(void) {
    int lokalna[10];        // na stosie (stack)
    int *dynamiczna = malloc(10 * sizeof(int)); // na stercie (heap)
}
```
-> Zmienna na stosie: znika po wyjściu z funkcji.
-> Pamięć na stercie: istnieje, dopóki nie wywołasz free().
-> Dlatego malloc jest potrzebny, gdy coś musi żyć "dłużej" niż funkcja.

--------------------------------------------------

#### 5.4. memset(), memcpy() – OPERACJE NA PAMIĘCI
```c
int *arr = malloc(5 * sizeof(int));
memset(arr, 0, 5 * sizeof(int)); // wypełnij zerami

int src[3] = {1,2,3};
int dst[3];
memcpy(dst, src, sizeof(src)); // kopiowanie bloków pamięci
```
-> memset() – wypełnia blok pamięci bajtem (często zerami).
-> memcpy() – kopiuje bajty między blokami pamięci.

--------------------------------------------------
####  5.5. TYPOWE BŁĘDY
- Użycie pamięci po free():
```c
int *p = malloc(10*sizeof(int));
free(p);
p[0] = 1; // BŁĄD – undefined behavior!
```
- Podwójne free():
```c
free(p);
free(p); // BŁĄD – undefined behavior!
```
- Brak free() → wyciek:
```c
while(1) {
    int *x = malloc(1000);
    // brak free → program będzie zużywał coraz więcej pamięci
}
```

--------------------------------------------------

#### 5.6. DOBRE PRAKTYKI
- Po free() ustaw wskaźnik na NULL:
```c
  free(p); p=NULL;
```
- Sprawdzaj wynik malloc/calloc/realloc:
```c
  if(!p) { /* obsługa błędu */ }
```
- Używaj sizeof(*ptr), aby unikać pomyłek:
```c
  int *arr = malloc(10 * sizeof(*arr));
```
- Debugowanie wycieków:
  używaj narzędzi typu Valgrind (Linux).

  ===================================

--------------------------------------------------

### 6. STRUKTURY I UNION
```c
struct Punkt { int x,y; };
struct Punkt p = {1,2}; // inicjalizacja
```
```c
typedef struct {
    TokenType type;
    char value[128];
} Token;

Token token;
```
```c
union Dane {
    int i; float f;
};
union Dane d; d.i = 10; // to samo miejsce pamięci może przechowywać różne typy
```
-> struct grupuje dane w jedną całość.
-> union to kilka pól dzielących tę samą pamięć.

--------------------------------------------------

### 7. FUNKCJE
```c
int dodaj(int a, int b) { return a+b; }
int wynik = dodaj(2,3);

#include <stdarg.h>
int suma(int n, ...) {
    va_list args; va_start(args, n);
    int s=0;
    for(int i=0;i<n;i++) s += va_arg(args,int);
    va_end(args); return s;
}
```
-> Funkcje mogą zwracać wartość lub void.
-> Parametry zwykle przekazywane są przez wartość, wskaźnik daje dostęp do oryginału.
-> Funkcje wariadyczne (...) pozwalają przekazać zmienną liczbę argumentów (np. printf).

--------------------------------------------------

### 8. WEJŚCIE/WYJŚCIE
Zapisywanie do pliku
```c
FILE *fp = fopen("plik.txt", "w"); // otwarcie pliku do zapisu
fprintf(fp, "Test\n");
fclose(fp);
```
Czytanie z pliku
```c
fp = fopen("plik.txt", "r");
if (fp == NULL) {
    perror("Nie mozna otworzyc pliku");
    return 1;
}

while (fgets(buf, sizeof(buf), fp) != NULL) {
    printf("%s", buf);
}
fclose(fp);
```
Czytanie z klawiatury
```c
printf("Wpisz cos: ");
fgets(buf, sizeof(buf), stdin);   // czytanie linii z klawiatury
printf("Wpisano: %s", buf);
```

-> fopen tworzy uchwyt do pliku.
-> fprintf działa jak printf, ale do pliku.
-> fgets pobiera cały wiersz ze stdin.

--------------------------------------------------

### 9. ORGANIZACJA KODU
``` c
// plik.h (nagłówek)
#ifndef MODUL_H
#define MODUL_H
void foo(void);
#endif

// plik.c (implementacja)
#include "plik.h"
void foo(void){ printf("ok\n"); }
```
-> Pliki .h zawierają deklaracje.
-> Pliki .c zawierają definicje.
-> #ifndef/#define/#endif chroni przed wielokrotnym dołączaniem.

--------------------------------------------------

### 10. OPERACJE BITOWE
```c
unsigned char f = 0;
f |= 1<<2;   // ustaw bit 2
if(f & (1<<2)) printf("bit 2 ustawiony\n");
f &= ~(1<<2); // kasuj bit 2
```
-> << przesunięcie bitowe (1<<2 = 00000100).
-> | ustawia bity, & sprawdza, ~ neguje.
-> Typowe przy flagach i maskach.

--------------------------------------------------

### 11. DEBUGOWANIE
```c
#include <assert.h>
int dziel(int a, int b){
    assert(b!=0);   // przerwie program, jeśli warunek fałszywy
    return a/b;
}

perror("blad"); // wypisuje ostatni błąd systemowy
```
-> assert to szybkie sprawdzanie warunków w kodzie.
-> perror wypisuje opis błędu np. przy nieudanym fopen.

--------------------------------------------------
### 12. OPTYMALIZACJA
```c
void ustaw(int *x) {
    *x = 123; // zmiana oryginału
}
int a = 0;
ustaw(&a);
```
-> Zamiast kopiować dużą strukturę/funkcję, lepiej przekazać adres.

--------------------------------------------------

#### 12.1. PRZEKAZYWANIE "TYLKO DO ODCZYTU"
```c
void pokaz(const int *arr, int n) {
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
}
```
-> const mówi: „funkcja nie zmieni danych”.
-> Chroni przed błędami i pozwala kompilatorowi lepiej optymalizować.

--------------------------------------------------

#### 12.2. UNIKANIE KOPIOWANIA DUŻYCH STRUKTUR
```c
struct Dane {
    int duza_tab[1000];
};

// ŹLE – kopiowanie całej struktury:
void f1(struct Dane d);

// DOBRZE – przekazanie wskaźnika:
void f2(struct Dane *d);
```
-> Zamiast kopiować 4 KB na stos, przekazujemy tylko adres (kilka bajtów).

--------------------------------------------------

#### 12.3. INLINE FUNKCJE
```c
inline int kwadrat(int x) { return x*x; }
int a = kwadrat(5);
```
-> inline sugeruje kompilatorowi, aby "wkleił" kod funkcji bez wywołania.
-> Przydaje się w małych, często wywoływanych funkcjach.

--------------------------------------------------

#### 12.4. LOKALIZACJA ZMIENNYCH
```c
void foo(void) {
    static int licznik = 0;
    licznik++;
    printf("%d\n", licznik);
}
```
-> static w funkcji: zmienna jest inicjalizowana raz i przechowuje stan.
-> Optymalizacja: unikanie globalnych zmiennych i nadmiernych kopii.

--------------------------------------------------

#### 12.5. OGRANICZENIE DOSTĘPU DO ZMIENNYCH
```c
static int prywatna = 0;  // tylko w tym pliku .c
```
-> static na poziomie pliku ukrywa zmienną/funkcję przed innymi modułami.
-> Kompilator lepiej optymalizuje, gdy widzi cały kontekst.

--------------------------------------------------

#### 12.6. RESTRICT (C99+)
```c
void f(int * restrict a, int * restrict b) {
    *a = *a + *b;
}
```
-> restrict mówi kompilatorowi, że wskaźniki nie wskazują na te same dane.
-> Daje więcej możliwości optymalizacji (ważne przy pracy z tablicami).

--------------------------------------------------

#### 12.7. KOMPILACJA
```c
gcc -O2 program.c -o program
gcc -O3 -march=native program.c -o program
```
-> -O2/-O3 – optymalizacje kompilatora.
-> -march=native – wykorzystanie instrukcji procesora (np. SSE/AVX).

--------------------------------------------------
--------------------------------------------------

### CMAKE template
```c
cmake_minimum_required(VERSION 3.10)

project(Proj C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} main.c)
```
```bash
mkdir build
cd build
cmake ../
make
./Proj
```

### MAKEFILE
```makefile
# Nazwa projektu / pliku wykonywalnego
TARGET = Proj

# Kompilator
CC = gcc

# Flagi kompilatora
CFLAGS = -std=c11 -Wall -Wextra

# Pliki źródłowe
SRCS = main.c

# Domyślna reguła
all: $(TARGET)

# Reguła budowania pliku wykonywalnego
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Czyszczenie plików wynikowych
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
```
