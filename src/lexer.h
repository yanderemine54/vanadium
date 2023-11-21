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

#ifndef VANADIUM_LEXER_H
#define VANADIUM_LEXER_H
#include "token.h"
typedef struct {
    char* src;
    unsigned int src_size;
    char current_character;
    unsigned int index;
} lexer_t;

lexer_t* init_lexer(char* src);
char lexer_peek(lexer_t* lexer, int offset);
void lexer_advance(lexer_t* lexer);
token_t* lexer_advance_with(lexer_t* lexer, token_t* token);
void lexer_skip_whitespace(lexer_t* lexer);
token_t* lexer_parse_id(lexer_t* lexer);
token_t* lexer_next_token(lexer_t* lexer);
#endif