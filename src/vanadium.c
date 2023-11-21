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

#include "vanadium.h"
#include "lexer.h"
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

void compile(char* src) {
    lexer_t* lexer = init_lexer(src);
    token_t* tok = NULL;

    while ((tok = lexer_next_token(lexer))->type != TOKEN_EOF) {
        printf("%s\n", token_to_string(tok));
    }
}

void compile_file(const char* filename) {
    char* src = read_file(filename);
    compile(src);
    free(src);
}