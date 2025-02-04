/*
 * Copyright (C)2019 Roger Clark. VK3KYY / G4KYF
 * 				and	 Colin Durbridge, G4EML
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
#include <user_interface/menuUtilityQSOData.h>
#include <user_interface/uiLocalisation.h>
#include "fw_trx.h"
#include "fw_codeplug.h"
#include "fw_settings.h"

static void updateScreen(void);
static void handleEvent(ui_event_t *ev);

static struct_codeplugContact_t tmpContact;
static const char *callTypeString[3];// = { "Group", "Private", "All" };
static int contactDetailsIndex;
static char digits[9];

enum CONTACT_DETAILS_DISPLAY_LIST { /*CONTACT_DETAILS_NAME=0,*/ CONTACT_DETAILS_TG=0, CONTACT_DETAILS_CALLTYPE, CONTACT_DETAILS_TS,
	NUM_CONTACT_DETAILS_ITEMS};// The last item in the list is used so that we automatically get a total number of items in the list

static int menuContactDetailsState;
static int menuContactDetailsTimeout;
enum MENU_CONTACT_DETAILS_STATE {MENU_CONTACT_DETAILS_DISPLAY=0, MENU_CONTACT_DETAILS_SAVED, MENU_CONTACT_DETAILS_EXISTS};

int menuContactDetails(ui_event_t *ev, bool isFirstRun)
{
	if (isFirstRun)
	{
		callTypeString[0]= currentLanguage->group;
		callTypeString[1]= currentLanguage->private;
		callTypeString[2]= currentLanguage->all;

		if (contactListContactIndex == 0) {
			contactDetailsIndex = codeplugContactGetFreeIndex();
			tmpContact.name[0] = 0x00;
			tmpContact.callType = CONTACT_CALLTYPE_TG;
			tmpContact.reserve1 = 0xff;
			tmpContact.tgNumber = 0;
			digits[0] = 0x00;
		} else {
			contactDetailsIndex = contactListContactIndex;
			memcpy(&tmpContact, &contactListContactData,sizeof(struct_codeplugContact_t));
			itoa(tmpContact.tgNumber, digits, 10);
		}

		menuContactDetailsState = MENU_CONTACT_DETAILS_DISPLAY;

		updateScreen();
	}
	else
	{
		if (ev->hasEvent || (menuContactDetailsTimeout > 0))
		{
			handleEvent(ev);

		}
	}
	return 0;
}

static void updateScreen(void)
{
	int mNum = 0;
	static const int bufferLen = 17;
	char buf[bufferLen];

	UC1701_clearBuf();

	if (tmpContact.name[0] == 0x00) {
		strncpy(buf, currentLanguage->new_contact, bufferLen);
		buf[bufferLen - 1] = 0;
	} else {
		codeplugUtilConvertBufToString(tmpContact.name, buf, 16);
	}
	menuDisplayTitle(buf);

	switch (menuContactDetailsState) {
	case MENU_CONTACT_DETAILS_DISPLAY:
		// Can only display 3 of the options at a time menu at -1, 0 and +1
		for(int i = -1; i <= 1; i++)
		{
			mNum = menuGetMenuOffset(NUM_CONTACT_DETAILS_ITEMS, i);
			buf[0] = 0;

			switch (mNum)
			{
	//			case CONTACT_DETAILS_Name:
	//				strcpy(buf,"Name");
	//				break;
			case CONTACT_DETAILS_TG:
				switch (tmpContact.callType)
				{
				case CONTACT_CALLTYPE_TG:
					snprintf(buf, bufferLen, "%s:%s", currentLanguage->tg, digits);
					break;
				case CONTACT_CALLTYPE_PC: // Private
					snprintf(buf, bufferLen, "%s:%s", currentLanguage->pc, digits);
					break;
				case CONTACT_CALLTYPE_ALL: // All Call
					snprintf(buf, bufferLen, "%s:16777215", currentLanguage->all);
					break;
				}
				break;
			case CONTACT_DETAILS_CALLTYPE:
				snprintf(buf, bufferLen, "%s:%s", currentLanguage->type, callTypeString[tmpContact.callType]);
				break;
			case CONTACT_DETAILS_TS:
				switch (tmpContact.reserve1 & 0x3)
				{
				case 1:
				case 3:
					snprintf(buf, bufferLen, "%s:%s", currentLanguage->timeSlot, currentLanguage->none);
					break;
				case 0:
					snprintf(buf, bufferLen, "%s:1", currentLanguage->timeSlot);
					break;
				case 2:
					snprintf(buf, bufferLen, "%s:2", currentLanguage->timeSlot);
					break;
				}
				break;
			}

			buf[bufferLen - 1] = 0;
			menuDisplayEntry(i, mNum, buf);
		}
		break;
	case MENU_CONTACT_DETAILS_SAVED:
		UC1701_printCentered(16,currentLanguage->contact_saved,UC1701_FONT_8x16);
		UC1701_drawChoice(UC1701_CHOICE_OK, false);
		break;
	case MENU_CONTACT_DETAILS_EXISTS:
		UC1701_printCentered(16, currentLanguage->duplicate,UC1701_FONT_8x16);
		UC1701_printCentered(32,  currentLanguage->contact,UC1701_FONT_8x16);
		UC1701_drawChoice(UC1701_CHOICE_OK, false);
		break;
	}
	UC1701_render();
	displayLightTrigger();
}

static void handleEvent(ui_event_t *ev)
{
	dmrIdDataStruct_t foundRecord;
	static const int bufferLen = 17;
	char buf[bufferLen];
	int sLen = strlen(digits);

	switch (menuContactDetailsState) {
	case MENU_CONTACT_DETAILS_DISPLAY:
		if (ev->events & KEY_EVENT) {
			if (KEYCHECK_PRESS(ev->keys,KEY_DOWN))
			{
				MENU_INC(gMenusCurrentItemIndex, NUM_CONTACT_DETAILS_ITEMS);
			}
			else if (KEYCHECK_PRESS(ev->keys,KEY_UP))
			{
				MENU_DEC(gMenusCurrentItemIndex, NUM_CONTACT_DETAILS_ITEMS);
			}
			else if (KEYCHECK_PRESS(ev->keys,KEY_RIGHT))
			{
				switch(gMenusCurrentItemIndex)
				{
	//			case CONTACT_DETAILS_NAME:
	//				break;
				case CONTACT_DETAILS_TG:
					break;
				case CONTACT_DETAILS_CALLTYPE:
					MENU_INC(tmpContact.callType,3);
					break;
				case CONTACT_DETAILS_TS:
					switch (tmpContact.reserve1 & 0x3) {
					case 1:
					case 3:
						tmpContact.reserve1 &= 0xfc;
						break;
					case 0:
						tmpContact.reserve1 |= 0x02;
						break;
					case 2:
						tmpContact.reserve1 |= 0x03;
						break;
					}
					break;
				}
			}
			else if (KEYCHECK_PRESS(ev->keys,KEY_LEFT))
			{
				switch(gMenusCurrentItemIndex)
				{
	//			case CONTACT_DETAILS_NAME:
	//				break;
				case CONTACT_DETAILS_TG:
					if (sLen>0) {
						digits[sLen-1] = 0x00;
					}
					break;
				case CONTACT_DETAILS_CALLTYPE:
					MENU_DEC(tmpContact.callType,3);
					break;
				case CONTACT_DETAILS_TS:
					switch (tmpContact.reserve1 & 0x3) {
					case 1:
					case 3:
						tmpContact.reserve1 &= 0xfc;
						tmpContact.reserve1 |= 0x02;
						break;
					case 0:
						tmpContact.reserve1 |= 0x03;
						break;
					case 2:
						tmpContact.reserve1 &= 0xfc;
						break;
					}
					break;
				}
			}
			else if (KEYCHECK_SHORTUP(ev->keys,KEY_GREEN))
			{
				if (tmpContact.callType == CONTACT_CALLTYPE_ALL)
				{
					tmpContact.tgNumber = 16777215;
				}
				else
				{
					tmpContact.tgNumber = atoi(digits);
				}

				if (tmpContact.tgNumber > 0 && tmpContact.tgNumber <= 9999999)
				{
					struct_codeplugContact_t contact;
					int index = codeplugContactIndexByTGorPC(tmpContact.tgNumber, tmpContact.callType, &contact);
					if (index > 0 && index != tmpContact.NOT_IN_CODEPLUGDATA_indexNumber)
					{
						menuContactDetailsTimeout = 2000;
						menuContactDetailsState = MENU_CONTACT_DETAILS_EXISTS;
					}
					else
					{
						if (contactDetailsIndex > 0 && contactDetailsIndex <= 1024)
						{
							if (tmpContact.name[0] == 0x00)
							{
								if (tmpContact.callType == CONTACT_CALLTYPE_PC)
								{
									if (dmrIDLookup(tmpContact.tgNumber,&foundRecord))
									{
										codeplugUtilConvertStringToBuf(foundRecord.text, tmpContact.name, 16);
									} else {
										snprintf(buf, bufferLen, "%s %d", currentLanguage->tg, tmpContact.tgNumber);
										buf[bufferLen - 1] = 0;
										codeplugUtilConvertStringToBuf(buf, tmpContact.name, 16);
									}
								}
								else
								{
									snprintf(buf, bufferLen, "%s %d", currentLanguage->tg, tmpContact.tgNumber);
									buf[bufferLen - 1] = 0;
									codeplugUtilConvertStringToBuf(buf, tmpContact.name, 16);
								}
							}
							codeplugContactSaveDataForIndex(contactDetailsIndex, &tmpContact);
//							contactListContactIndex = 0;
							menuContactDetailsTimeout = 2000;
							menuContactDetailsState = MENU_CONTACT_DETAILS_SAVED;
						}
					}
				}
			}
			else if (KEYCHECK_SHORTUP(ev->keys,KEY_RED))
			{
//				contactListContactIndex = 0;
				menuSystemPopPreviousMenu();
				return;
			}
			else if (gMenusCurrentItemIndex == CONTACT_DETAILS_TG) {
				// Add a digit
				if (sLen < 7)
				{
					char c[2] = {0, 0};

					if (KEYCHECK_PRESS(ev->keys,KEY_0))
					{
						c[0]='0';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_1))
					{
						c[0]='1';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_2))
					{
						c[0]='2';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_3))
					{
						c[0]='3';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_4))
					{
						c[0]='4';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_5))
					{
						c[0]='5';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_6))
					{
						c[0]='6';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_7))
					{
						c[0]='7';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_8))
					{
						c[0]='8';
					}
					else if (KEYCHECK_PRESS(ev->keys,KEY_9))
					{
						c[0]='9';
					}

					if (c[0]!=0)
					{
						strcat(digits,c);
					}
				}
			}
			updateScreen();

		}
		break;
	case MENU_CONTACT_DETAILS_SAVED:
        menuContactDetailsTimeout--;
		if ((menuContactDetailsTimeout == 0) || (KEYCHECK_SHORTUP(ev->keys, KEY_GREEN)))
		{
			contactListContactIndex = 0;
			menuSystemPopPreviousMenu();
			return;
		}
		updateScreen();

		break;
	case MENU_CONTACT_DETAILS_EXISTS:
        menuContactDetailsTimeout--;
		if ((menuContactDetailsTimeout == 0) || (KEYCHECK_SHORTUP(ev->keys, KEY_GREEN)))
		{
			menuContactDetailsState = MENU_CONTACT_DETAILS_DISPLAY;
		}
		updateScreen();

		break;
	}
}
