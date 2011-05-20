                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Björn Eriksson
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
 * @author Kristofer Hansson Aspman \n
 *         Björn Eriksson \n
 *         Magnus Bergqvist        
 * @file moto_driver_functions.c
 * @version v0.03
 * @date 2011-05-09
 * @brief Contains the functions that sets the pulse width of the \n
          different motors.
 * @history 2011-05-17: Implemented moto_map() function \n
                        (Magnus) \n
            2011-05-09: Added map function and moved printout macros \n
                        to moto_printer_functions, changed the printouts \n
                        to fully comply with the new macro style \n
                        (Magnus) \n
            2011-04-03: Created the file. \n 
                        (Kristofer)
 */
#include <stdint.h>  

/* from the header file, a struct which can be sent to the movement */

struct pulses{
    uint16_t right;
    uint16_t left;
    uint16_t front;
    uint16_t rear;
};

/* 
 * creates the struct, sends it to the movement with the current pulse,
 * will be discarded after sending.
 */

void sendMsg(void){
    struct pulses currentPulsess = {rightPulse, leftPulse, 
                                    frontPulse, rearPulse};
    proto_write_move(currentPulses);
}


