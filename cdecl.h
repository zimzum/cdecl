//============================================================================
//  FILE:
//      cdecl.h 
//
//  AUTHOR:
//      zimzum@github 
//
//  DESCRIPTION:
//      Includes, macros, type definitions and declarations.
//
//  License: GNU GPL v2.0 
//=============================================================================

#include <string.h>
#include <stdio.h> 
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKENLEN (200)
#define MAXTOKENS (10)

//===-----------------------------------------------------------------------===
//  TYPE DEFINITIONS
//===-----------------------------------------------------------------------===
//-----------------------------------------------------------------------------
//  STRUCT: token_t
//
//  DESCRIPTION:
//      Holds one token from the input declaration. Contains its tag and name
//      (in the form of a C string).
//      
//-----------------------------------------------------------------------------
typedef struct token { 
    char type; 
    char string[MAXTOKENLEN]; 
} token_t;

//-----------------------------------------------------------------------------
//  ENUM: type_tag 
//
//  DESCRIPTION:
//      Enumeration for diffrent tags
//      
//-----------------------------------------------------------------------------
enum type_tag
{
    TYPE, 
    QUALIFIER, 
    IDENTIFIER,
    POINTER
};

//===-----------------------------------------------------------------------===
// FUNCTION DECLARATIONS
//===-----------------------------------------------------------------------===
//-----------------------------------------------------------------------------
//  NAME:
//      classify_string()
//  
//  DESCRIPTION:
//      Look at the current token and return a corresponding type_tag in
//      input.type
//  INPUT:
//      input - Pointer to the token that needs its type to be specified.
//  RETURN:
//      void
//------------------------------------------------------------------------------
void classify_string(token_t *input);

//-----------------------------------------------------------------------------
//  NAME:
//      gettoken()
//  
//  DESCRIPTION:
//      Read the next token into this.string.
//  INPUT:
//      Pointer to the current position within declaration that's being
//      analysed.
//  RETURN:
//      The number of characters read (including white spaces)
//-----------------------------------------------------------------------------
int gettoken(char *);

//-----------------------------------------------------------------------------
//  NAME:
//      read_to_first_identifier()
//  
//  DESCRIPTION:
//      Reads tokens and pushes them onto the stack until the first identifier
//      is read. 
//  INPUT:
//      The C declaration to be analysed.
//  RETURN:
//      Pointer to the current position within declaration that's being
//      analysed (i.e. first character after the identifier).
//-----------------------------------------------------------------------------
char * read_to_first_identifier(char *input);

//-----------------------------------------------------------------------------
//  NAME:
//      deal_with_function_args()
//  
//  DESCRIPTION:
//      Parses function arguments. Currently just reads until the closing ')'
//      is read. 
//  INPUT:
//      Pointer to the current position within declaration that's being
//      analysed. 
//  RETURN:
//      Pointer to the current position within declaration that's being
//      analysed (i.e. first character after the closing ')').
//-----------------------------------------------------------------------------
char* deal_with_function_args(char *input);

//-----------------------------------------------------------------------------
//  NAME:
//      deal_with_arrays()
//  
//  DESCRIPTION:
//      Parses arrays, i.e. reads what's between '[' (exclusive)
//      and ']' (inclusive).
//  INPUT:
//      Pointer to the current position within declaration that's being
//      analysed. 
//  RETURN:
//      Pointer to the current position within declaration that's being
//      analysed (i.e. first character after the closing ']').
//-----------------------------------------------------------------------------
char* deal_with_arrays(char *input);

//-----------------------------------------------------------------------------
//  NAME:
//      deal_with_special_tokens()
//  
//  DESCRIPTION:
//      Deals with '*', "const" and "volatile" until it pops a token that
//`     doesn't fall into this category.
//  INPUT:
//      void
//  RETURN:
//      void
//-----------------------------------------------------------------------------
void deal_with_special_tokens(void);

//-----------------------------------------------------------------------------
//  NAME:
//      deal_with_declarator()
//  
//  DESCRIPTION:
//      If this.type is '[' deal_with_arrays, if this.type is '('
//      deal_with_function_args.
//  INPUT:
//      Pointer to the current position within declaration that's being
//      analysed. 
//  RETURN:
//      void
//-----------------------------------------------------------------------------
void deal_with_declarator(char *);
