/* Copyright 2019 Dima Chechetkin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "blink.h"
#include "raw_hid.h"
#include "hid_api.h"
#include "matrix.h"
#include "keymap.h"  // to get keymaps[][][]
#include "dynamic_keymap.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

layer_state_t state = 0;

layer_state_t layer_state_set_kb(layer_state_t newState) {
  state = newState;
  return newState;
}

extern const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS];


#ifdef RAW_ENABLE
void raw_hid_receive(uint8_t *data, uint8_t length) {
  uint8_t *command = &(data[0]);
  uint8_t *args = &(data[1]);

  switch(*command) {
    case id_get_protocol_version: {
                                    args[0] = API_VERSION >> 8;
                                    args[1] = API_VERSION & 0xFF;
                                    break;
                                  }
    case id_get_layer_state: {
                               args[0] = (state >> 24) & 0xFF;
                               args[1] = (state >> 16) & 0xFF;
                               args[2] = (state >> 8) & 0xFF;
                               args[3] = state & 0xFF;
                               break;
                             }
    case id_get_matrix_state: {
                                args[0] = matrix_rows();
                                args[1] = matrix_cols();
                                uint8_t colbytes = 1 + args[2] / 8;
                                for (uint8_t row = 0; row < args[0]; row++) {
                                  matrix_row_t cols = matrix_get_row(row);
                                  for (int16_t colbyte = colbytes; colbyte > -1; colbyte--) {
                                    args[2 + row * colbytes + colbyte] = (cols >> (colbyte * 8)) & 0xFF;
                                  }
                                }
                                break;
                              }
    case id_get_mapping: {
                          #ifdef DYNAMIC_KEYMAP_ENABLE
                           uint16_t mapping = dynamic_keymap_get_keycode(args[0], args[1], args[2]);
                          #else
                           uint16_t mapping = keymap_key_to_keycode(args[0], 
                               (keypos_t){.row = args[1], .col = args[2]});
                          #endif

                           args[0] = (mapping >> 8) & 0xFF;
                           args[1] = mapping & 0xFF;
                           break;
                         }
  }

  raw_hid_send(data, length);

}
#endif 

/*

void matrix_init_kb(void) {
  // put your keyboard start-up code here
  // runs once when the firmware starts up

  matrix_init_user();
}

void matrix_scan_kb(void) {
  // put your looping keyboard code here
  // runs every cycle (a lot)

  matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  // put your per-action keyboard code here
  // runs for every action, just before processing by the firmware

  return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
  // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

  led_set_user(usb_led);
}

*/
