                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Magnus Bergqvist
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
 * @file moto_stubs.c
 * @brief Stub functions for use during testing.
 * @date 2011-04-18
 * @author Magnus Bergqvist
 * @version 1
 * @history 2011-04-18 - created
 * @details The functions in cunit_stubs.c is used during testing to \n
            replace any arduino library function that is called within \n
            the software.
 */
#include <stdint.h>
#include "moto_stubs.h"
#include "moto_driver_functions.h"
#include "moto_printer_functions.h"

/* analogWrite from arduino standard libraries, used for ordinary pwm out */
void analogWrite(int motor, uint16_t pulse){
    
    if(motor == LEFT_MOTOR){
        PRINT_NEW_LINE;
        PRINT_STRING ("LEFT_MOTOR received:  ");
        PRINT_DEC(pulse);
        PRINT_NEW_LINE;
    }
    if(motor == RIGHT_MOTOR){
        PRINT_NEW_LINE;
        PRINT_STRING ("RIGHT_MOTOR received  ");
        PRINT_DEC(pulse);
        PRINT_NEW_LINE;
    }
    if(motor == FRONT_MOTOR){
        PRINT_NEW_LINE;
        PRINT_STRING ("FRONT_MOTOR received  ");
        PRINT_DEC(pulse);
        PRINT_NEW_LINE;
    }
    if(motor == REAR_MOTOR){
        PRINT_NEW_LINE;
        PRINT_STRING ("REAR_MOTOR received  ");
        PRINT_DEC(pulse);
        PRINT_NEW_LINE;
    }
}


