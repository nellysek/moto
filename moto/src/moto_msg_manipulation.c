                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Kristofer Hansson Aspman, Magnus Bergqvist
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/*!
 * @author Kristofer Hansson Aspman & Magnus Bergqvist
 * @file moto_msg_manipulation.c
 * @version v0.03
 * @date 2011-05-09
 *
 * @brief Holds the implementations of the functions\n
   described in the corresponding .h file. For\n
   full description of the functions please refer\n
   to that file.\n
   Uses the types msg and msg_pointer defined in\n
   moto_msg_manipulation.h.\n
   Uses macros for printing defined in moto_printer_functions.h
 *
 * @history 2011-04-03: Created the file. (Kristofer)
            2011-04-07: Implemented ifdefs. (Kristofer)
            2011-05-08: Cleaned up a bit and added some comments. (Kristofer)
            2011-05-09: Created macros for printing. (Magnus & Kristofer)
            2011-05-09: Moved macros for printing, included .h file for it \n
                        to be used by other files as well (Magnus)          
 */

#ifdef ARDUINO
    #include "WProgram.h"
#endif

#include "moto_msg_manipulation.h"
#include "moto_printer_functions.h"

/*!
 * @author Kristofer Hansson Aspman
 * @function printMsg
 * @param msg_pointer
 * @return void
 * @brief Simply prints out necessary debug information\n
   such as the status of the motors and the bits of the message\n
   sent in as a parameter to the functions.\n
   Uses Serial.print or printf depending on what flag has been set\n
   for the compilation (MEGA plus DEBUG or PC plus DEBUG respectively).
 */
void printMsg(msg_pointer mp){
    PRINT_STRING("***********************************");
    PRINT_NEW_LINE;
    PRINT_NEW_LINE;
    PRINT_STRING("         Message Information");
    PRINT_NEW_LINE;
    PRINT_NEW_LINE;
    PRINT_STRING("Bits are:");
    PRINT_NEW_LINE;
    PRINT_STRING("ID: ");
    PRINT_DEC(mp->ID);
    PRINT_NEW_LINE;
    PRINT_STRING("Increase: ");
    PRINT_DEC(mp->increase);
    PRINT_NEW_LINE;
    PRINT_STRING("Panic: ");
    PRINT_DEC(mp->panic);
    PRINT_NEW_LINE;
    
    PRINT_STRING("Right: ");
    PRINT_DEC(mp->right);
    PRINT_NEW_LINE;
    PRINT_STRING("Left: ");
    PRINT_DEC(mp->left);
    PRINT_NEW_LINE;
    PRINT_STRING("Front: ");
    PRINT_DEC(mp->front);
    PRINT_NEW_LINE;
    PRINT_STRING("Rear: ");
    PRINT_DEC(mp->rear);
    
    PRINT_NEW_LINE;
    PRINT_STRING("Size of bitfield: ");
    PRINT_DEC(sizeof(*mp));
    PRINT_NEW_LINE;
    PRINT_STRING("Hexadecimal representation: ");
    PRINT_HEX(BITFIELD_TO_CHAR(mp));
    PRINT_NEW_LINE;
    PRINT_STRING("Decimal representation: ");
    PRINT_DEC(BITFIELD_TO_CHAR(mp));
    PRINT_NEW_LINE;
    
    PRINT_STRING("***********************************");
    PRINT_NEW_LINE;

}
