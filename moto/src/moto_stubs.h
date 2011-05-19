                                                        
                                             
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
 * @file moto_stubs.h
 * @brief header file for the test stub functions in cunit_stubs.c
 * @date 2011-04-18
 * @author Magnus Bergqvist
 * @version 1
 * @history 2011-04-18 - created
 * @details cunit_stubs.h contains prototypes of the functions in \n
            cunit_stubs.c which is used during testing to replace any \n
            arduino library function that is called within the software
 */
#ifndef MOTO_STUBS_H
    #define MOTO_STUBS_H
#include <stdint.h>

void analogWrite(int motor, uint16_t pulse);
#endif
