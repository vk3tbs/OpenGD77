/*
 * Copyright (C)2019 Kai Ludwig, DG4KLU
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _FW_KEYBOARD_H_
#define _FW_KEYBOARD_H_

#include "fw_common.h"

// column lines
#define Port_Key_Col0   PORTC
#define GPIO_Key_Col0 	GPIOC
#define Pin_Key_Col0	0
#define Port_Key_Col1   PORTC
#define GPIO_Key_Col1 	GPIOC
#define Pin_Key_Col1 	1
#define Port_Key_Col2   PORTC
#define GPIO_Key_Col2 	GPIOC
#define Pin_Key_Col2 	2
#define Port_Key_Col3   PORTC
#define GPIO_Key_Col3 	GPIOC
#define Pin_Key_Col3 	3

// row lines
#define Port_Key_Row0   PORTB
#define GPIO_Key_Row0 	GPIOB
#define Pin_Key_Row0	19
#define Port_Key_Row1   PORTB
#define GPIO_Key_Row1 	GPIOB
#define Pin_Key_Row1	20
#define Port_Key_Row2   PORTB
#define GPIO_Key_Row2 	GPIOB
#define Pin_Key_Row2	21
#define Port_Key_Row3   PORTB
#define GPIO_Key_Row3 	GPIOB
#define Pin_Key_Row3	22
#define Port_Key_Row4   PORTB
#define GPIO_Key_Row4 	GPIOB
#define Pin_Key_Row4	23

#define SCAN_UP    0x00000100
#define SCAN_DOWN  0x00002000
#define SCAN_LEFT  0x00000200
#define SCAN_RIGHT 0x00000010
#define SCAN_GREEN 0x00000008
#define SCAN_RED   0x00040000
#define SCAN_0     0x00010000
#define SCAN_1     0x00000001
#define SCAN_2     0x00000002
#define SCAN_3     0x00000004
#define SCAN_4     0x00000020
#define SCAN_5     0x00000040
#define SCAN_6     0x00000080
#define SCAN_7     0x00000400
#define SCAN_8     0x00000800
#define SCAN_9     0x00001000
#define SCAN_STAR  0x00008000
#define SCAN_HASH  0x00020000

#define KEY_GREENSTAR  '+'    // GREEN + STAR

#define KEY_UP    1
#define KEY_DOWN  2
#define KEY_LEFT  3
#define KEY_RIGHT 4
#define KEY_GREEN 13
#define KEY_RED   27
#define KEY_0     '0'
#define KEY_1     '1'
#define KEY_2     '2'
#define KEY_3     '3'
#define KEY_4     '4'
#define KEY_5     '5'
#define KEY_6     '6'
#define KEY_7     '7'
#define KEY_8     '8'
#define KEY_9     '9'
#define KEY_STAR  '*'
#define KEY_HASH  '#'


#define KEY_MOD_DOWN  0x01000000
#define KEY_MOD_UP    0x02000000
#define KEY_MOD_LONG  0x04000000
#define KEY_MOD_PRESS 0x08000000

#define EVENT_KEY_NONE   0
#define EVENT_KEY_CHANGE 1

#define KEY_DEBOUNCE_COUNTER   20

#define KEYCHECK(keys,k) (((keys) & 0xffffff) == (k))
#define KEYCHECK_KEYMOD(keys, k, mask, mod) (((((keys) & 0xffffff) == (k)) && ((keys) & (mask)) == (mod)))
#define KEYCHECK_MOD(keys, mask, mod) (((keys) & (mask)) == (mod))

#define KEYCHECK_UP(keys, k)       KEYCHECK_KEYMOD(keys, k, KEY_MOD_UP, KEY_MOD_UP)
#define KEYCHECK_SHORTUP(keys, k)  KEYCHECK_KEYMOD(keys, k, KEY_MOD_UP| KEY_MOD_LONG, KEY_MOD_UP)
#define KEYCHECK_DOWN(keys, k)     KEYCHECK_KEYMOD(keys, k, KEY_MOD_DOWN, KEY_MOD_DOWN)
#define KEYCHECK_PRESS(keys, k)    KEYCHECK_KEYMOD(keys, k, KEY_MOD_PRESS, KEY_MOD_PRESS)
#define KEYCHECK_LONGDOWN(keys, k) KEYCHECK_KEYMOD(keys, k, KEY_MOD_DOWN | KEY_MOD_LONG, KEY_MOD_DOWN | KEY_MOD_LONG)

#define KEYCHAR(keys)              ((char)(keys & 0xff))

extern volatile bool keypadLocked;

typedef union keyboardKeycode {
	uint32_t keycode;
	struct {
		uint8_t mod;
		uint16_t reserve;
		char key;
	} code;
} keyboardKeycode_t;

void fw_init_keyboard(void);
void fw_reset_keyboard(void);
uint8_t fw_read_keyboard_col(void);
uint32_t fw_read_keyboard(void);
void fw_check_key_event(uint32_t *keys, int *event);
uint32_t fw_scan_key(uint32_t keys);

#endif /* _FW_KEYBOARD_H_ */
