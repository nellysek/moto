
/***************************************************************************
 * Copyright (C) 2011  Rahwa Bahta
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
#include "moto_msg_parsing.h"

int main(int args, char **argv){
    uint8_t msg = 0x40;
    msg_parsing(msg);

    msg=0xF0;
    msg_parsing (msg);    

    msg= 0xDC;
    msg_parsing (msg);
    msg_parsing (msg);
    msg= 0xE3;
    msg_parsing (msg);
    msg_parsing (msg);
    msg_parsing (msg);

    msg = 0x84;
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);
    msg_parsing(msg);

    return 0;
}