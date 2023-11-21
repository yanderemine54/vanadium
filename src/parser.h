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

#ifndef VANADIUM_PARSER_H
#define VANADIUM_PARSER_H
#include "lexer.h"
#include "AST.h"

typedef struct {
    lexer_t* lexer;
    token_t* token;
} parser_t;

parser_t* init_parser(lexer_t* lexer);
token_t* parser_eat(parser_t* parser, int type);
AST_t* parse(parser_t* parser);
AST_t* parse_compound(parser_t* parser);
#endif