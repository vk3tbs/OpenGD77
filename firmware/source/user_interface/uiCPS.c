/*
 * Copyright (C)2019 Roger Clark. VK3KYY / G4KYF
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
#include <user_interface/menuSystem.h>
#include "fw_trx.h"

static void handleTick(void);

static int mode=0;
static uint32_t nextPIT;
static int ledState=0;
static const int PIT_COUNTS_PER_UPDATE = 5000;
static int radioMode;
static int radioBandWidth;


int menuCPS(ui_event_t *ev, bool isFirstRun)
{
	if (isFirstRun)
	{
		radioMode=trxGetMode();
		radioBandWidth=trxGetBandwidthIs25kHz();
		trxSetModeAndBandwidth(RADIO_MODE_NONE, radioBandWidth);
		// Just clear the display and turn on the
//		UC1701_clearBuf();
//		UC1701_render();
		nextPIT = PITCounter + PIT_COUNTS_PER_UPDATE;
	}
	else
	{
		if (PITCounter >= nextPIT )
		{
			nextPIT = PITCounter + PIT_COUNTS_PER_UPDATE;
			handleTick();
		}
	}
	return 0;
}

void menuCPSUpdate(int command,int x, int y, UC1701_Font_t fontSize, UC1701_Text_Align_t alignment, bool isInverted,char *szMsg)
{
	switch(command)
	{
		case 0:
			UC1701_clearBuf();
			break;
		case 1:
			UC1701_printCore(x, y, szMsg, fontSize, alignment, isInverted);
			break;
		case 2:
			UC1701_render();
			displayLightTrigger();
			break;
		case 3:
			displayLightTrigger();
			break;
		case 4:
			mode = 1;// flash green LED
			break;
		case 5:
			mode = 2;// flash red LED
			break;
		case 6:
		    GPIO_PinWrite(GPIO_LEDgreen, Pin_LEDgreen, 0);
		    GPIO_PinWrite(GPIO_LEDred, Pin_LEDred, 0);
		    trx_setRX();// Rx would be turned off at start of CPS by setting radio mode to none
		    trxSetModeAndBandwidth(radioMode, radioBandWidth);
			menuSystemPopAllAndDisplayRootMenu();
			break;
		default:
			break;
	}
}

static void handleTick(void)
{
	switch(mode)
	{
		case 1:
			// flash green
			if (ledState==0)
			{
				ledState=1;
			    GPIO_PinWrite(GPIO_LEDgreen, Pin_LEDgreen, 1);
			}
			else
			{
				ledState=0;
			    GPIO_PinWrite(GPIO_LEDgreen, Pin_LEDgreen, 0);
			}

			break;
		case 2:
			// flash yellow
			if (ledState==0)
			{
				ledState=1;
			    GPIO_PinWrite(GPIO_LEDred, Pin_LEDred, 1);
			}
			else
			{
				ledState=0;
			    GPIO_PinWrite(GPIO_LEDred, Pin_LEDred, 0);
			}

			break;
	}
}
