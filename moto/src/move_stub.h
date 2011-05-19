                                                        
                                             
/***************************************************************************
 * Copyright (C) 2011  Kristofer Hansson Aspman
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

#ifndef MOVE_STUB_H
    #define MOVE_STUB_H
#include <stdint.h>
#include "moto_msg_manipulation.h"
#include "../../proto_mega/src/proto_lib.h"
extern unsigned int input;
int move_init();
int move_run();
msg scanHexMsgSTDIN(void);
uint8_t serReadUnsignedChar(void);
#endif
