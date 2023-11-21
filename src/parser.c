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

#include "parser.h"
#include <stdlib.h>
#include <stdio.h>

parser_t* init_parser(lexer_t* lexer) {
    parser_t* parser = calloc(1, sizeof(parser_t));
    parser->lexer = lexer;
    parser->token = lexer_next_token(lexer);
    return parser;
}

token_t* parser_eat(parser_t* parser, int type) {
    if (parser->token->type != type) {
        printf("[Parser] FATAL: Unexpected token: `%s`, was expecting `%s`\n", token_to_string(parser->token), token_type_to_string(type));
        exit(1);
    }

    parser->token = lexer_next_token(parser->lexer);
    return parser->token;
}

AST_t* parse(parser_t* parser) {
    // TODO: Parse expressions and return AST
}

AST_t* parse_compound(parser_t* parser) {
    // TODO: Parse compound expressions
}