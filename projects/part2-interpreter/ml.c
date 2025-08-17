#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { 
    TOKEN_OUT, 
    TOKEN_STRING, 
    TOKEN_LPAREN, 
    TOKEN_RPAREN, 
    TOKEN_EOF 
} TokenType;

typedef struct {
    TokenType type;
    char value[128];
} Token;

int pos = 0;

void tokenizer(const char *code, Token tokens[], int *tokenCount) {
    *tokenCount = 0;

    while (code[pos] != '\0') {
        if (isspace(code[pos])) { pos++; continue; }

        if (strncmp(&code[pos], "out", 3) == 0) {
            tokens[*tokenCount] = (Token){ TOKEN_OUT, "out" };
            (*tokenCount)++; pos += 3; continue;
        }

        if (code[pos] == '(') {
            tokens[*tokenCount] = (Token){ TOKEN_LPAREN, "(" };
            (*tokenCount)++; pos++; continue;
        }

        if (code[pos] == ')') {
            tokens[*tokenCount] = (Token){ TOKEN_RPAREN, ")" };
            (*tokenCount)++; pos++; continue;
        }

        if (code[pos] == '"') {
            pos++;
            int start = pos;
            while (code[pos] != '"' && code[pos] != '\0') pos++;
            int len = pos - start;
            strncpy(tokens[*tokenCount].value, &code[start], len);
            tokens[*tokenCount].value[len] = '\0';
            tokens[*tokenCount].type = TOKEN_STRING;
            (*tokenCount)++;
            if (code[pos] == '"') pos++;
            continue;
        }

        pos++;
    }

    tokens[*tokenCount] = (Token){ TOKEN_EOF, "EOF" };
    (*tokenCount)++;
}

void interpret(Token tokens[], int tokenCount) {
    for (int i = 0; i < tokenCount; i++) {
        if (tokens[i].type == TOKEN_OUT) {
            if (tokens[i+1].type == TOKEN_LPAREN &&
                tokens[i+2].type == TOKEN_STRING &&
                tokens[i+3].type == TOKEN_RPAREN) {

                printf("%s\n", tokens[i+2].value);
                i += 3;
            } else {
                printf("Syntax error: expected out(\"text\")\n");
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s file.ml\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) { perror("Cannot open file"); return 1; }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *code = malloc(size + 1);
    if (!code) { perror("Out of memory"); fclose(file); return 1; }

    fread(code, 1, size, file);
    code[size] = '\0';
    fclose(file);

    Token tokens[50];
    int tokenCount = 0;

    tokenizer(code, tokens, &tokenCount);
    interpret(tokens, tokenCount);

    free(code);

    printf("File size: %ld bytes\n", size);

    return 0;
}
