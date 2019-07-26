#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _MA 0 //Main layer
#define _FN 1 //Fn
#define _FN1 2 //Fn1
#define _PN 3 //Pn

#define CTAB  CTL_T(KC_TAB)
#define CENT  CTL_T(KC_ENT)
#define SLASH KC_SLASH
#define SCLN KC_SCLN
#define COMMA KC_COMM
#define ARSPC LT(_FN, KC_SPC)
#define NMSPC LT(_FN1, KC_SPC)
#define LSALT LALT_T(KC_SPC)
#define RSALT RALT_T(KC_SPC)
#define LBGUI MT(MOD_LGUI, KC_LBRC)
#define RBGUI MT(MOD_RGUI, KC_RBRC)
#define WHLEFT KC_WH_L
#define WHDOWN KC_WH_D
#define WHUP   KC_WH_U
#define WHRGHT KC_WH_R
#define MSLEFT KC_MS_L
#define MSDOWN KC_MS_D
#define MSUP   KC_MS_U
#define MSRGHT KC_MS_R
#define VOLMDN KC__VOLDOWN
#define VOLMUP KC__VOLUP
#define VMMUTE KC__MUTE
#define MPPREV KC_MEDIA_PREV_TRACK
#define MPNEXT KC_MEDIA_NEXT_TRACK
#define MPLPP  KC_MEDIA_PLAY_PAUSE


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MA] = LAYOUT(
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   KC_GESC,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,  KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSPC, KC_BSPC, \
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
      CTAB  ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,  KC_H  ,  KC_J  ,  KC_K  ,  KC_L  ,  SCLN  ,      CENT     , \
  // -------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------------+
       KC_LSPO  ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  KC_N  ,  KC_M  ,  COMMA , KC_DOT ,   SLASH  , KC_RSPC ,	\
  // -----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------+---------+
    KC_LCTL , KC_APP ,  LBGUI ,  LSALT ,     ARSPC    ,          NMSPC         ,  RSALT ,  RBGUI , KC_APP ,  MO(_PN)    \
  // -------+--------+--------+--------+--------------+------------------------+--------+--------+--------+-----------+
),

[_FN] = LAYOUT(
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______, _______, _______, KC_ASTR,KC_MINUS, _______, KC_DEL , KC_DEL , \
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    _______ , KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, KC_QUOT,    KC_EQL     , \
  // -------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------------+
       _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_BSLS , _______ ,	\
  // -----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------+---------+
    _______ , _______, _______, _______,    _______   ,          MO(_PN)       , _______, _______, _______,   _______   \
  // -------+--------+--------+--------+--------------+------------------------+--------+--------+--------+-----------+
),

[_FN1] = LAYOUT(
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , _______, _______, \
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    _______ ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,  KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  ,    _______    , \
  // -------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------------+
       _______  , KC_F11 , KC_F12 , KC_F13 , KC_F15 , _______, _______, _______, _______, _______,  _______ , _______ ,	\
  // -----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------+---------+
    _______ , _______, _______, _______,    MO(_PN)   ,          _______       , _______, _______, _______,   _______   \
  // -------+--------+--------+--------+--------------+------------------------+--------+--------+--------+-----------+
),

[_PN] = LAYOUT(
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    RESET , _______, _______, _______, _______, _______, WHLEFT , WHDOWN ,   WHUP , WHRGHT , _______, _______, KC_BTN2, \
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    _______ , _______, _______, _______, _______, _______, MSLEFT , MSDOWN ,   MSUP , MSRGHT , _______,    KC_BTN1    , \
  // -------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------------+
       _______  , _______, _______, _______, _______, _______, VOLMDN , VMMUTE , VOLMUP , MPPREV ,  MPNEXT  , KC_BTN3 ,	\
  // -----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------+---------+
    _______ , _______, _______,  MPLPP ,     MPLPP    ,          MPLPP         ,  MPLPP , _______, _______,   _______   \
  // -------+--------+--------+--------+--------------+------------------------+--------+--------+--------+-----------+
)

};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Turn capslock on
 	   	PORTE &= ~(1 << 6);


    } else {
        // Turn capslock off
    	PORTE |= (1 << 6);
    }
}

/* TEMPLATE 
[???] = LAYOUT(
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  // -----+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+
    _______ , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______    , \
  // -------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------------+
       _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______ , _______ ,	\
  // -----------+--------+--------+--------+--------+--------+--------+--------+--------+--------+----------+---------+
    _______ , _______, _______, _______,    _______   ,          _______       , _______, _______, _______,   _______   \
  // -------+--------+--------+--------+--------------+------------------------+--------+--------+--------+-----------+
),
*/
