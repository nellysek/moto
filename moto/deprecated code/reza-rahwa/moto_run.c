
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
#include <stdio.h>
#include "moto_msg_handler.h"

void snd(msg_pointer);

struct bits_type msg;

/*
* main function, NOT part of the code
* testing purpose ONLY
*/
int main(int argc, char** argv){
    char input[8];
    printf("Enter numbers for ID,Increase,Panic,Left,Right,Front,Rear or x to exit: ");
    scanf("%s",input);
    while(input[0]!='x'){
        printf("Enter numbers for ID,Increase,Panic,Left,Right,Front,Rear or x to exit: ");
        scanf("%s",input);
        msg.ID=input[0]-'0';
        msg.INCREASE=input[1]-'0';
        msg.PANIC=input[2]-'0';
        msg.LEFT=input[3]-'0';
        msg.RIGHT=input[4]-'0';
        msg.FRONT=input[5]-'0';
        msg.REAR=input[6]-'0';
        snd(&msg);
    }
    return 0;
}

void snd(msg_pointer mp){
    examineID(mp);
}