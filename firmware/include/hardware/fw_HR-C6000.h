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

#ifndef _FW_HR_C6000_H_
#define _FW_HR_C6000_H_

#include "FreeRTOS.h"
#include "task.h"

#include "fw_keyboard.h"

#include "fw_spi.h"
#include "fw_usb_com.h"

#include "fw_codec.h"

// C6000 interrupts
// IN      C7  - C6000 RF_RX_INTER
// IN      C16 - C6000 RF_TX_INTER
// IN      C17 - C6000 SYS_INTER
// IN      C18 - C6000 TIME_SLOT_INTER
#define Port_INT_C6000_RF_RX PORTC
#define GPIO_INT_C6000_RF_RX GPIOC
#define Pin_INT_C6000_RF_RX  7
#define Port_INT_C6000_RF_TX PORTC
#define GPIO_INT_C6000_RF_TX GPIOC
#define Pin_INT_C6000_RF_TX  16
#define Port_INT_C6000_SYS   PORTC
#define GPIO_INT_C6000_SYS   GPIOC
#define Pin_INT_C6000_SYS    17
#define Port_INT_C6000_TS    PORTC
#define GPIO_INT_C6000_TS    GPIOC
#define Pin_INT_C6000_TS     18

// Connections with C6000
// OUT/ON  E0 - C6000 RESETn
// OUT/ON  E1 - C6000 PWD
#define Port_INT_C6000_RESET PORTE
#define GPIO_INT_C6000_RESET GPIOE
#define Pin_INT_C6000_RESET  0
#define Port_INT_C6000_PWD   PORTE
#define GPIO_INT_C6000_PWD   GPIOE
#define Pin_INT_C6000_PWD    1

#define DRM_FRAME_BUFFER_SIZE 64

extern const uint8_t TG_CALL_FLAG;
extern const uint8_t PC_CALL_FLAG;
extern volatile int slot_state;
extern volatile uint8_t DMR_frame_buffer[DRM_FRAME_BUFFER_SIZE];
extern volatile bool updateLastHeard;
extern volatile int dmrMonitorCapturedTS;

enum DMR_SLOT_STATE { DMR_STATE_IDLE, DMR_STATE_RX_1, DMR_STATE_RX_2, DMR_STATE_RX_END,
					  DMR_STATE_TX_START_1, DMR_STATE_TX_START_2, DMR_STATE_TX_START_3, DMR_STATE_TX_START_4, DMR_STATE_TX_START_5,
					  DMR_STATE_TX_1, DMR_STATE_TX_2, DMR_STATE_TX_END_1, DMR_STATE_TX_END_2, DMR_STATE_TX_END_3,
					  DMR_STATE_REPEATER_WAKE_1,DMR_STATE_REPEATER_WAKE_2,DMR_STATE_REPEATER_WAKE_3,DMR_STATE_REPEATER_WAKE_4,
					  DMR_STATE_REPEATER_WAKE_FAIL_1,DMR_STATE_REPEATER_WAKE_FAIL_2};

enum WakingMode { WAKING_MODE_NONE, WAKING_MODE_WAITING, WAKING_MODE_FAILED };

void SPI_HR_C6000_init(void);
void SPI_C6000_postinit(void);
void PORTC_IRQHandler(void);
void init_HR_C6000_interrupts(void);
void init_digital_state(void);
void init_digital_DMR_RX(void);
void init_digital(void);
void terminate_digital(void);
void init_hrc6000_task(void);
void fw_hrc6000_task(void *data);
void tick_HR_C6000(void);

void clearIsWakingState(void);
int getIsWakingState(void);
void clearActiveDMRID(void);
void setMicGainDMR(uint8_t gain);

#endif /* _FW_HR_C6000_H_ */
