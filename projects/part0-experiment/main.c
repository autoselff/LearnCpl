#include <stdio.h> // TWORCA: AUTOSELFF

const int SIZE = 32;

typedef struct {
    int x;
    int y;
} Vec2;

Vec2 CreateVec2(int x, int y) {
    Vec2 vec2;
    vec2.x = x;
    vec2.y = y;

    return vec2;
}

void draw_map(Vec2 point_map[], int point_map_size) {
    for(int y = -SIZE / 2 + 1; y < SIZE / 2; ++y) {
        for(int x = -SIZE / 2 + 1; x < SIZE / 2; ++x) {
            if (x == 0 && y == 0) {
                printf(" 0");
            }
            else if (x == 0) {
                printf(" |");
            }
            else if (y == 0) {
                printf(" -");
            }
            else {
                int is_here = 0;
                for (int i = 0; i < point_map_size; ++i) {
                    if (point_map[i].x == x && point_map[i].y == y) {
                        printf(" P");
                        is_here = 1;
                    }
                }
                if (is_here == 0) {
                    printf(" *");
                }
            }
        }
        printf("\n");
    }
}

Vec2 make_linear_eq(int i, int a, int b) {
    Vec2 vec2;
    vec2.x = i;
    vec2.y = -a * vec2.x + b;

    return vec2;
}

Vec2 make_quadratic_eq(int i, int a, int b, int c) {
    Vec2 vec2;

    vec2.x = i;
    vec2.y = (-a * (vec2.x * vec2.x)) + (-a * vec2.x) + b;

    return vec2;
}

int main() {

    int a = 1;
    int b = 0;
    Vec2 vec2_array[SIZE];

    for (int i = -SIZE/2; i < SIZE/2; ++i) {
        vec2_array[i] = make_linear_eq(i, a, b);
    }

    draw_map(vec2_array, SIZE);
    return 0;
}

