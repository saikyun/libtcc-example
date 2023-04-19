#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tinycc/libtcc.h"

#define print(format, ...) printf(format "\n" __VA_OPT__(, ) __VA_ARGS__)

int main()
{
    TCCState *s = tcc_new();
    assert(s);
    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    tcc_add_include_path(s, "lib/");
    tcc_add_file(s, "src/main.c");
    
    // you can do it :)
    // tcc_add_file(s, "src/other_main.c");

    const char *program = "";
    
    assert(tcc_compile_string(s, program) != -1);

    tcc_run(s, 0, NULL);

    return 0;
}