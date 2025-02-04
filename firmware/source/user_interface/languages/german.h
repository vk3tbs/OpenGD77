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
 * Translators: DG3GSP, DL4LEX
 *
 *
 * Rev: 3
 */
#ifndef USER_INTERFACE_LANGUAGES_GERMAN_H_
#define USER_INTERFACE_LANGUAGES_GERMAN_H_
/********************************************************************
 *
 * VERY IMPORTANT.
 * This file should not be saved with UTF-8 encoding
 * Use Notepad++ on Windows with ANSI encoding
 * or emacs on Linux with windows-1252-unix encoding
 *
 ********************************************************************/
const stringsTable_t germanLanguage =
{
.LANGUAGE_NAME 			= "Deutsch", // MaxLen: 16
.language				= "Sprache", // MaxLen: 16
.menu					= "Men�", // MaxLen: 16
.credits				= "Mitwirkende", // MaxLen: 16
.zone					= "Zone", // MaxLen: 16
.rssi					= "Feldst�rke", // MaxLen: 16
.battery				= "Batterie", // MaxLen: 16
.contacts				= "Kontakte", // MaxLen: 16
.firmware_info			= "Firmware Info", // MaxLen: 16
.last_heard				= "Zuletzt geh�rt", // MaxLen: 16
.options				= "Einstellungen", // MaxLen: 16
.display_options		= "Display Optionen", // MaxLen: 16
.channel_details		= "Kanal Details", // MaxLen: 16
.new_contact			= "Neuer Kontakt", // MaxLen: 16
.contact_list			= "Kontaktliste", // MaxLen: 16
.hotspot_mode			= "Hotspot-Modus", // MaxLen: 16
.contact_details		= "Kontakt Details", // MaxLen: 16
.built					= "Erstellt", // MaxLen: 16
.zones					= "Zonen", // MaxLen: 16
.keypad					= "Tasten", // MaxLen: 12 (with .ptt)
.ptt					= "PTT", // MaxLen: 12 (with .keypad)
.locked					= "Gesperrt", // MaxLen: 15
.press_blue_plus_star	= "Blaue Taste + *", // MaxLen: 19
.to_unlock				= "zum entsperren", // MaxLen: 19
.unlocked				= "Entsperrt", // MaxLen: 15
.power_off				= "Schalte aus...", // MaxLen: 16
.error					= "FEHLER", // MaxLen: 8
.rx_only				= "Nur Rx", // MaxLen: 14
.out_of_band			= "AUSSER BAND", // MaxLen: 14
.timeout				= "Zeit abgelaufen", // MaxLen: 8
.tg_entry				= "TG Eingabe", // MaxLen: 15
.pc_entry				= "PC Eingabe", // MaxLen: 15
.user_dmr_id			= "Benutzer ID", // MaxLen: 15
.contact 				= "Kontakt", // MaxLen: 15
.accept_call			= "Ruf annehmen?", // MaxLen: 16
.private_call			= "Privater Ruf", // MaxLen: 16
.squelch				= "Squelch",  // MaxLen: 7
.quick_menu 			= "Schnellfunktion", // MaxLen: 16
.filter					= "Filter", // MaxLen: 7 (with ':' + settings: "None", "CC", "CC,TS", "CC,TS,TG")
.all_channels			= "Alle Kan�le", // MaxLen: 16
.gotoChannel			= "Gehe zu",  // MaxLen: 11 (" 1024")
.scan					= "Suchlauf", // MaxLen: 16
.channelToVfo			= "Kanal --> VFO", // MaxLen: 16
.vfoToChannel			= "VFO --> Kanal", // MaxLen: 16
.group					= "Gruppe", // MaxLen: 16 (with .type)
.private				= "Privat", // MaxLen: 16 (with .type)
.all					= "Alle", // MaxLen: 16 (with .type)
.type					= "Type", // MaxLen: 16 (with .type)
.timeSlot				= "Zeitschlitz", // MaxLen: 16 (plus ':' and  .none, '1' or '2')
.none					= "kein", // MaxLen: 16 (with .timeSlot, "Rx CTCSS:" and ""Tx CTCSS:")
.contact_saved			= "Kontakt gesp.", // MaxLen: 16
.duplicate				=  "Duplikat", // MaxLen: 16
.tg						= "TG", // MaxLen: 8
.pc						= "PC", // MaxLen: 8
.ts						= "TS", // MaxLen: 8
.mode					= "Modus",  // MaxLen: 12
.colour_code			= "Color Code", // MaxLen: 16 (with ':' * .n_a)
.n_a					= "N/A", // MaxLen: 16 (with ':' * .colour_code)
.bandwidth				= "Bandbreite", // MaxLen: 16 (with ':' + .n_a, "25kHz" or "12.5kHz")
.stepFreq				= "Schritt", // MaxLen: 7 (with ':' + xx.xxkHz fitted)
.tot					= "TOT", // MaxLen: 16 (with ':' + .off or 15..3825)
.off					= "Aus", // MaxLen: 16 (with ':' + .timeout_beep, .calibration or .band_limits)
.zone_skip				= "Skip Zone", // MaxLen: 16 (with ':' + .yes or .no) 
.all_skip				= "Skip Alle", // MaxLen: 16 (with ':' + .yes or .no)
.yes					= "Ja", // MaxLen: 16 (with ':' + .zone_skip, .all_skip or .factory_reset)
.no						= "Nein", // MaxLen: 16 (with ':' + .zone_skip, .all_skip or .factory_reset)
.rx_group				= "Rx Gruppe", // MaxLen: 16 (with ':' and codeplug group name)
.on						= "Ein", // MaxLen: 16 (with ':' + .calibration or .band_limits)
.timeout_beep			= "Timeout-Ton", // MaxLen: 16 (with ':' + .off or 5..20)
.factory_reset			= "Werks-Reset", // MaxLen: 16 (with ':' + .yes or .no)
.calibration			= "Kalibration", // MaxLen: 16 (with ':' + .on or .off)
.band_limits			= "Band Limit", // MaxLen: 16 (with ':' + .on or .off)
.beep_volume			= "Beep Lauts", // MaxLen: 16 (with ':' + -24..6 + 'dB')
.dmr_mic_gain			= "DMR Mikro", // MaxLen: 16 (with ':' + -33..12 + 'dB')
.key_long				= "Key lang", // MaxLen: 11 (with ':' + x.xs fitted)
.key_repeat				= "Key wied", // MaxLen: 11 (with ':' + x.xs fitted)
.dmr_filter_timeout		= "DMR Filter", // MaxLen: 16 (with ':' + 1..90 + 's')
.brightness				= "Helligkeit", // MaxLen: 16 (with ':' + 0..100 + '%')
.contrast				= "Kontrast", // MaxLen: 16 (with ':' + 12..30)
.colour_invert			= "Anzeige:Invers", // MaxLen: 16
.colour_normal			= "Anzeige:Normal", // MaxLen: 16
.backlight_timeout		= "Timeout", // MaxLen: 16 (with ':' + 0..30)
.scan_delay				= "Scan Verz�g", // MaxLen: 16 (with ':' + 1..30 + 's')
.YES					= "JA", // MaxLen: 8 (choice above green/red buttons)
.NO						= "NEIN", // MaxLen: 8 (choice above green/red buttons)
.DISMISS				= "ABLEHNEN", // MaxLen: 8 (choice above green/red buttons)
.scan_mode				= "Scan Modus", // MaxLen: 16 (with ':' + .hold or .pause)
.hold					= "Halt", // MaxLen: 16 (with ':' + .scan_mode)
.pause					= "Pause", // MaxLen: 16 (with ':' + .scan_mode)
.empty_list				= "Leere Liste", // MaxLen: 16
.delete_contact_qm		= "Kontakt l�schen?", // MaxLen: 16
.contact_deleted		= "Kontakt gel�scht", // MaxLen: 16
.contact_used			= "Kontakt benutzt", // MaxLen: 16
.in_rx_group			= "in RX Gruppe", // MaxLen: 16
.select_tx				= "W�hle TX", // MaxLen: 16
.edit_contact			= "Kontakt �ndern", // MaxLen: 16
.delete_contact			= "Kontakt l�schen", // MaxLen: 16
.group_call				= "Gruppenruf", // MaxLen: 16
.all_call				= "Ruf an alle", // MaxLen: 16
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
#endif /* USER_INTERFACE_LANGUAGES_GERMAN_H_ */
