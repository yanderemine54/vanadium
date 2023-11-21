// Copyright (C) 2023 Yanderemine54
// 
// This file is part of vanadium.
// 
// vanadium is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// vanadium is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with vanadium.  If not, see <http://www.gnu.org/licenses/>.

#ifndef VANADIUM_TOKEN_H
#define VANADIUM_TOKEN_H
typedef struct {
    char* value;
    enum {
        TOKEN_IDENTIFIER,
        TOKEN_EQUALS_SIGN,
        TOKEN_LEFT_PARENTHESIS,
        TOKEN_RIGHT_PARENTHESIS,
        TOKEN_COLON,
        TOKEN_INT,
        TOKEN_COMMA,
        TOKEN_TYPE,
        TOKEN_LEFT_ANGLE_BRACKET,
        TOKEN_RIGHT_ANGLE_BRACKET,
        TOKEN_STRING,
        TOKEN_ARROW,
        TOKEN_LEFT_CURLY_BRACE,
        TOKEN_RIGHT_CURLY_BRACE,
        TOKEN_RETURN,
        TOKEN_SEMICOLON,
        TOKEN_EOF,
        TOKEN_COMMENT,
        TOKEN_DOUBLE_QUOTE,
    } type;
} token_t;

token_t* init_token(char* value, int type);
const char* token_type_to_string(int type);
char* token_to_string(token_t* token);
#endif