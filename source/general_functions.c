/*
 * =====================================================================================
 *
 *       Filename:  general_functions.c
 *
 *    Description:   
 *
 *        Version:  1.0
 *        Created:  02.02.2022 20:30:54
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  Daniel Kucharski (), progdk22@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


/* #####   HEADER FILE INCLUDES   ################################################### */
#include "definitions.h"
#include "game_types.h"
/* #####   MACROS  -  LOCAL TO THIS SOURCE FILE   ################################### */

/* #####   TYPE DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ######################### */

/* #####   DATA TYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   VARIABLES  -  LOCAL TO THIS SOURCE FILE   ################################ */

/* #####   PROTOTYPES  -  LOCAL TO THIS SOURCE FILE   ############################### */

/* #####   FUNCTION DEFINITIONS  -  EXPORTED FUNCTIONS   ############################ */

MyGame_ErrorType TranslateErrorFrom(int error)
{
    MyGame_ErrorType errorMyGame = ALL_OK;

    if (error < 0)
    {
        errorMyGame = MYGAME_ERROR;

    }
    return errorMyGame;

}

/* #####   FUNCTION DEFINITIONS  -  LOCAL TO THIS SOURCE FILE   ##################### */

