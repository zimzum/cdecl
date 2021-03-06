//============================================================================
// FILE:
//      main_cdecl.c
//
// AUTHOR:
//      zimzum@github 
//
// DESCRIPTION:
//      Implementation of 'main'
//
//  License: GNU GPL v2.0 
//=============================================================================

#include "cdecl.h"

//===-----------------------------------------------------------------------===
// MAIN                                                                     
//===-----------------------------------------------------------------------===
int main(int argc, char *argv[])
{
    // There ought to be two arguments: this filename (argv[0]), and
    // the declaration to parse (pass in double quotes so that your shell
    // doesn't split it.).
    assert(argc >= 2);
    char *input = argv[1];

    input = read_to_first_identifier(input);
    deal_with_declarator(input);

    return 0;
}
