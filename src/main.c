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
#include "io.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if (argc < 2) {
        puts("Please specify an input file.");
        return 1;
    }

    compile_file(argv[1]);

    return 0;
}