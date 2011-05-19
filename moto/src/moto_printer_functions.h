                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Kristofer Hansson Aspman,Magnus Bergqvist
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

 /*!@author Magnus Bergqvist,
 *          Kristofer Hansson Aspman
 *         
 * @file moto_printer_functions.h
 * @version v0.01
 * @date 2011-05-09
 *
 * @brief Contains macros for printing that is to be used for every file \n
 *        that needs a printout.
 *
 * @history 2011-05-09: Created the file. (Magnus & Kristofer)
 */

/* 
 * Printout macros inspired by Henrik Sandklef.
 * Will let the code result in different outputs (if any) depending
 * on what target it is compiled for.
 */
#ifndef MOTO_PRINTER_FUNCTIONS_H
    #define MOTO_PRINTER_FUNCTIONS_H
/*#ifdef ARDUINO_DBG
    #define ARDUINO
#endif*/

#ifdef ARDUINO
    #include "WProgram.h"
#elif defined PC
    #include <stdio.h>
#endif


#ifdef ARDUINO
    #ifndef DEBUG
        #define PRINT_STRING(a)
        #define PRINT_DEC(a)
        #define PRINT_HEX(a)
        #define PRINT_NEW_LINE 
    #endif
    #ifdef DEBUG
        #define PRINT_STRING(a) Serial.print(a)
        #define PRINT_DEC(a) Serial.print(a, DEC)
        #define PRINT_HEX(a) Serial.print(a, HEX)
        #define PRINT_NEW_LINE Serial.println()
    #endif
#endif

#ifdef PC
    #ifndef DEBUG
        #define PRINT_STRING(a)
        #define PRINT_DEC(a)
        #define PRINT_HEX(a)
        #define PRINT_NEW_LINE
    #endif
    #ifdef DEBUG
        #define PRINT_STRING(a) printf(a)
        #define PRINT_DEC(a) printf("%d ", a)
        #define PRINT_HEX(a) printf("%x ", a)
        #define PRINT_NEW_LINE printf("\n")
    #endif 
#endif
#endif
