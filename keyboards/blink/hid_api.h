#pragma once
#define API_VERSION 0x02

enum api_command_id {
  id_get_protocol_version = 0x01,
  id_get_layer_state,
  id_get_matrix_state,
  id_get_mapping,
  id_evt_press,
  id_evt_release
};

void rawhid_sendlayer(void);
void rawhid_sendpress(uint8_t *row, uint8_t *col);
void rawhid_sendrelease(uint8_t *row, uint8_t *col);
void rawhid_sendrelease(uint8_t *row, uint8_t *col);
