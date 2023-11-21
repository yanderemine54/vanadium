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

#include "token.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

token_t* init_token(char* value, int type) {
    token_t* token = calloc(1, sizeof(token_t));
    token->value = value;
    token->type = type;
    return token;
}

const char* token_type_to_string(int type) {
    switch (type) {
        case TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";
        case TOKEN_EQUALS_SIGN: return "TOKEN_EQUALS_SIGN";
        case TOKEN_LEFT_PARENTHESIS: return "TOKEN_LEFT_PARENTHESIS";
        case TOKEN_RIGHT_PARENTHESIS: return "TOKEN_RIGHT_PARENTHESIS";
        case TOKEN_COLON: return "TOKEN_COLON";
        case TOKEN_INT: return "TOKEN_INT";
        case TOKEN_COMMA: return "TOKEN_COMMA";
        case TOKEN_TYPE: return "TOKEN_TYPE";
        case TOKEN_LEFT_ANGLE_BRACKET: return "TOKEN_LEFT_ANGLE_BRACKET";
        case TOKEN_RIGHT_ANGLE_BRACKET: return "TOKEN_RIGHT_ANGLE_BRACKET";
        case TOKEN_STRING: return "TOKEN_STRING";
        case TOKEN_ARROW: return "TOKEN_ARROW";
        case TOKEN_LEFT_CURLY_BRACE: return "TOKEN_LEFT_CURLY_BRACE";
        case TOKEN_RIGHT_CURLY_BRACE: return "TOKEN_RIGHT_CURLY_BRACE";
        case TOKEN_RETURN: return "TOKEN_RETURN";
        case TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";
        case TOKEN_EOF: return "TOKEN_EOF";
        case TOKEN_COMMENT: return "TOKEN_COMMENT";
        case TOKEN_DOUBLE_QUOTE: return "TOKEN_DOUBLE_QUOTE";
    }
    return NULL;
}

char* token_to_string(token_t* token) {
    const char* type = token_type_to_string(token->type);
    const char* template = "<type=`%s`, type_id=`%d`, value=`%s`>";

    char* string = calloc(strlen(type) + strlen(template) + sizeof(int) + strlen(token->value) + 1, sizeof(char));
    sprintf(string, template, type, token->type, token->value);

    return string;
}