/***************************************************************************
 * Copyright (C) 2011  Rahwa Bahta, Reza Moussavi
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

#include <stdint.h>
#include <stdlib.h>
#include "moto_state_definitions.h"

typedef struct bits_type msg;

int examineID(msg *mp){	
    switch(mp->id){
	case START_ID:
		return 1;
		break;
    case STOP_ID:
		return 0;
		break;
    case CONTROL_ID:
		return 2;
		break;
    case SPECIAL_COMMAND_ID:
		return 3;
		break;
    }
}

/*
* It is not possible to create a structure including bitfield parameters
* thus erlang quick check method will ssend all generated fields to this function
* and this test function generate propper struct to be send to the examineID function.
*/
int test(int id,int increase,int panic,int left,int right,int front,int rear){
	msg* m=(msg*)malloc(sizeof(msg));
	m->id=id;
	m->increase=increase;
	m->panic=panic;
	m->left=left;
	m->right=right;
	m->front=front;
	m->rear=rear;
	return examineID(m);
}