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

#ifndef VANADIUM_AST_H
#define VANADIUM_AST_H
typedef struct {
    enum {
        AST_COMPOUND,
        AST_FUNCTION_DECLARATION,
        AST_DECLARATION_TYPE,
        AST_VARIABLE,
        AST_STATEMENT,
        AST_NOOP,
    } type;
} AST_t;

AST_t* init_ast(int type);
#endif