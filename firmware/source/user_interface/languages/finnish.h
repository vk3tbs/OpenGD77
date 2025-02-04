/* -*- coding: windows-1252-unix; -*- */
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
/*
 * Translators: OH1E
 *
 *
 * Rev: 5.1
 */
#ifndef USER_INTERFACE_LANGUAGES_FINNISH_H_
#define USER_INTERFACE_LANGUAGES_FINNISH_H_
/********************************************************************
 *
 * VERY IMPORTANT.
 * This file should not be saved with UTF-8 encoding
 * Use Notepad++ on Windows with ANSI encoding
 * or emacs on Linux with windows-1252-unix encoding
 *
 ********************************************************************/
const stringsTable_t finnishLanguage =
{
.LANGUAGE_NAME 			= "Suomi",
.language			= "Kieli",
.menu				= "Menu",
.credits			= "Kiitokset",
.zone				= "Zone",
.rssi				= "RSSI Signaali",
.battery			= "Akun Tila",
.contacts			= "Kontaktit",
.firmware_info			= "Laiteohjelmisto",
.last_heard			= "Viimeksi kuultu",
.options			= "Asetukset",
.display_options		= "N�yt�n Asetukset",
.channel_details		= "Kanava Asetukset",
.new_contact			= "Uusi kontakti",
.contact_list			= "Kontakti lista",
.hotspot_mode			= "Hotspotti tila",
.contact_details		= "Kontakti Asetus",
.built				= "Koontik��nn�s",
.zones				= "Zonet",
.keypad				= "N�pp�in", // MaxLen: 12 (with .ptt)
.ptt				= "PTT", // MaxLen: 12 (with .keypad)
.locked				= "Lukossa", // MaxLen: 15
.press_blue_plus_star		= "Paina sinist� ja *", // MaxLen: 19
.to_unlock			= "avataksesi n�plukko", // MaxLen: 19
.unlocked			= "N�plukko avattu", // MaxLen: 15
.power_off			= "Virta pois...",
.error				= "VIRHE", //MaxLen: 8
.rx_only			= "Vain Rx",
.out_of_band			= "B�ndial ulkopu", // MaxLen: 14
.timeout			= "AIKAKATK", //MaxLen: 8
.tg_entry			= "Aseta TG", // MaxLen: 15
.pc_entry			= "Aseta PC", // MaxLen: 15
.user_dmr_id			= "K�ytt�j�n DMR ID",
.contact 			= "Kontakti", // MaxLen: 15
.accept_call			= "Vastaa puheluun?",
.private_call			= "Priv. puhelu",
.squelch			= "K.Salpa", // MaxLen: 7
.quick_menu 			= "Pika Menu",
.filter				= "Suodata", // MaxLen: 7 (with ':' + settings: "None", "CC", "CC,TS", "CC,TS,TG")
.all_channels			= "Kaikki Kanavat",
.gotoChannel			= "Muistipaikk", // MaxLen: 11 (" 1024")
.scan				= "Skannaus",
.channelToVfo			= "Kanava --> VFO",
.vfoToChannel			= "VFO --> Kanava",
.group				= "Ryhm�", // MaxLen: 16 (with .type)
.private			= "Privaatti", // MaxLen: 16 (with .type)
.all				= "Kaikki", // MaxLen: 16 (with .type)
.type				= "Tyyppi", // MaxLen: 16 (with .type)
.timeSlot			= "Aikav�li", // MaxLen: 16 (plus ':' and  .none, '1' or '2')
.none				= "Tyhj�", // MaxLen: 16 (with .timeSlot, "Rx CTCSS:" and ""Tx CTCSS:")
.contact_saved			= "Kontakti tallen.",
.duplicate			= "kaksoiskappale",
.tg				= "TG", // MaxLen: 8
.pc				= "PC", // MaxLen: 8
.ts				= "TS", // MaxLen: 8
.mode				= "Mode", // MaxLen: 12
.colour_code			= "V�ri Koodi", // MaxLen: 16 (with ':' * .n_a)
.n_a				= "Pois", // MaxLen: 16 (with ':' * .colour_code)
.bandwidth			= "Kaistanl", // MaxLen: 16 (with ':' + .n_a, "25kHz" or "12.5kHz")
.stepFreq			= "Steppi", // MaxLen: 7 (with ':' + xx.xxkHz fitted)
.tot				= "TOT", // MaxLen: 16 (with ':' + .off or 15..3825)
.off				= "Ei", // MaxLen: 16 (with ':' + .timeout_beep, .calibration or .band_limits)
.zone_skip			= "Skippaa zone", // MaxLen: 16 (with ':' + .yes or .no) 
.all_skip			= "Skippaa kaik", // MaxLen: 16 (with ':' + .yes or .no)
.yes				= "Joo", // MaxLen: 16 (with ':' + .zone_skip, .all_skip or .factory_reset)
.no				= "Ei", // MaxLen: 16 (with ':' + .zone_skip, .all_skip or .factory_reset)
.rx_group			= "Rx Ryhm�", // MaxLen: 16 (with ':' and codeplug group name)
.on				= "On", // MaxLen: 16 (with ':' + .calibration or .band_limits)
.timeout_beep			= "Aikakatk beep", // MaxLen: 16 (with ':' + .off or 5..20)
.factory_reset			= "TehdasAsetus", // MaxLen: 16 (with ':' + .yes or .no)
.calibration			= "Kalibriointi", // MaxLen: 16 (with ':' + .on or .off)
.band_limits			= "B�ndi Rajoitu", // MaxLen: 16 (with ':' + .on or .off)
.beep_volume			= "N�p��niVoim", // MaxLen: 16 (with ':' + -24..6 + 'dB')
.dmr_mic_gain			= "DMRMicGain", // MaxLen: 16 (with ':' + -33..12 + 'dB')
.key_long			= "N�p pitk�", // MaxLen: 11 (with ':' + x.xs fitted)
.key_repeat			= "N�p toisto", // MaxLen: 11 (with ':' + x.xs fitted)
.dmr_filter_timeout		= "Suodin aika", // MaxLen: 16 (with ':' + 1..90 + 's')
.brightness			= "Kirkkaus", // MaxLen: 16 (with ':' + 0..100 + '%')
.contrast			= "Kontrasti", // MaxLen: 16 (with ':' + 12..30)
.colour_invert			= "V�ri: K��nteinen",
.colour_normal			= "V�ri: Normaali",
.backlight_timeout		= "TaustValoAika", // MaxLen: 16 (with ':' + 0..30)
.scan_delay			= "Skann. viive", // MaxLen: 16 (with ':' + 1..30 + 's')
.YES				= "KYLL�", // MaxLen: 8 (choice above green/red buttons)
.NO				= "EI", // MaxLen: 8 (choice above green/red buttons)
.DISMISS			= "POISTU", // MaxLen: 8 (choice above green/red buttons)
.scan_mode			= "Skannaus", // MaxLen: 16 (with ':' + .hold or .pause)
.hold				= "Pys�yty", // MaxLen: 16 (with ':' + .scan_mode)
.pause				= "Pause", // MaxLen: 16 (with ':' + .scan_mode)
.empty_list			= "Tyhj� lista", // MaxLen: 16
.delete_contact_qm		= "Poista kontakti?", // MaxLen: 16
.contact_deleted		= "Kontakti Poistet", // MaxLen: 16
.contact_used			= "Kontakti k�yt�ss", // MaxLen: 16
.in_rx_group			= "on RX ryhm�ss�", // MaxLen: 16
.select_tx			= "Valitse TX", // MaxLen: 16
.edit_contact			= "Muokkaa Kontakti", // MaxLen: 16
.delete_contact			= "Poista Kontakti", // MaxLen: 16
.group_call			= "Ryhm� Puhelu", // MaxLen: 16
.all_call			= "Puhelu kaikille", // MaxLen: 16
.tone_scan				= "Tone scan",//// MaxLen: 16
.cc_scan				= "CC scan",//// MaxLen: 16
};
/********************************************************************
 *
 * VERY IMPORTANT.
 * This file should not be saved with UTF-8 encoding
 * Use Notepad++ on Windows with ANSI encoding
 * or emacs on Linux with windows-1252-unix encoding
 *
 ********************************************************************/
#endif /* USER_INTERFACE_LANGUAGES_FINNISH_H_ */
