/**
 * Copyright (C) 2023 Yanderemine54
 * 
 * This file is part of vanadium.
 * 
 * vanadium is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * vanadium is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with vanadium.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "lexer.h"
#include "macros.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

lexer_t* init_lexer(char* src) {
    lexer_t* lexer = calloc(1, sizeof(lexer_t));
    lexer->src = src;
    lexer->src_size = strlen(src);
    lexer->index = 0;
    lexer->current_character = lexer->src[lexer->index];
    return lexer;
}

char lexer_peek(lexer_t* lexer, int offset) {
    return MIN(lexer->src[lexer->index + offset], lexer->src_size);
}

void lexer_advance(lexer_t* lexer) {
    if (lexer->index < lexer->src_size && lexer->current_character != '\0') {
        lexer->index += 1;
        lexer->current_character = lexer->src[lexer->index];
    }
}

token_t* lexer_advance_with(lexer_t* lexer, token_t* token) {
    lexer_advance(lexer);
    return token;
}

void lexer_skip_whitespace(lexer_t* lexer) {
    while (lexer->current_character == '\r' || lexer->current_character == '\n'
        || lexer->current_character == ' '  || lexer->current_character == '\t') {
        lexer_advance(lexer);
    }
}

token_t* lexer_parse_id(lexer_t* lexer) {
    char* value = calloc(1, sizeof(char));

    while (isalnum(lexer->current_character)) {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strlcat(value, (char[]){lexer->current_character, 0}, strlen(value) + 2);
        lexer_advance(lexer);
    }

    return init_token(value, TOKEN_IDENTIFIER);
}

token_t* lexer_next_token(lexer_t* lexer)
{
    while (lexer->current_character != '\0') {
        lexer_skip_whitespace(lexer);

        if (isalnum(lexer->current_character))
            return lexer_advance_with(lexer, lexer_parse_id(lexer));
        
        switch (lexer->current_character) {
        case '=':
            if (lexer_peek(lexer, 1) == '>') {
                return lexer_advance_with(lexer, init_token("=>", TOKEN_ARROW));
            } else {
                return lexer_advance_with(lexer, init_token("=", TOKEN_EQUALS_SIGN));
            }
        case '(': return lexer_advance_with(lexer, init_token("(", TOKEN_LEFT_PARENTHESIS));
        case ')': return lexer_advance_with(lexer, init_token(")", TOKEN_RIGHT_PARENTHESIS));
        case '{': return lexer_advance_with(lexer, init_token("{", TOKEN_LEFT_CURLY_BRACE));
        case '}': return lexer_advance_with(lexer, init_token("}", TOKEN_RIGHT_CURLY_BRACE));
        case '<': return lexer_advance_with(lexer, init_token("<", TOKEN_LEFT_ANGLE_BRACKET));
        case '>': return lexer_advance_with(lexer, init_token(">", TOKEN_RIGHT_ANGLE_BRACKET));
        case ':': return lexer_advance_with(lexer, init_token(":", TOKEN_COLON));
        case ',': return lexer_advance_with(lexer, init_token(",", TOKEN_COMMA));
        case ';': return lexer_advance_with(lexer, init_token(";", TOKEN_SEMICOLON));
        case '#': return lexer_advance_with(lexer, init_token("#", TOKEN_COMMENT));
        case '"': return lexer_advance_with(lexer, init_token("\"", TOKEN_DOUBLE_QUOTE));
        case '\0': break;
        default:
            printf("[Lexer] FATAL: Unexpected token: %c. \n", lexer->current_character);
            exit(1);
            break;
        }
    }

    return init_token(0, TOKEN_EOF);
}