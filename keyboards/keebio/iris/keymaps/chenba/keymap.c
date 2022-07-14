#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define LOWER LT(_LOWER, KC_GRV)
#define RAISE LT(_RAISE, KC_ESC)

#define SCLN_RCTL MT(MOD_RCTL, KC_SCLN)
#define QUOT_RGUI MT(MOD_RGUI, KC_QUOT)

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    FONT_0,
    TAB_NEW,
    TAB_NEXT,
    TAB_PREV,
    TAB_KILL,
    NAV_LEFT,
    NAV_RGHT,
    ALT_SPC,
    VI_YANK,
    VI_PUT,
    VI_UNDO,
    GUI_SFT_O,
    GUI_SFT_P,
    SFT_F12,
    WORD_LEFT,
    WORD_RGHT,
    LINE_START,
    LINE_END,
    SEL_WORD,
    MENU_Q
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

enum td_keycodes {
    TD_DOT_ARROW
};

td_state_t cur_dance(qk_tap_dance_state_t *state);
void       dot_arrow_finished(qk_tap_dance_state_t *state, void *user_data);
void       dot_arrow_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_LEAD,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L,   SCLN_RCTL,QUOT_RGUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐           ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_AUDIO_MUTE,       FONT_0,   KC_N,   KC_M,   KC_COMM,TD(TD_DOT_ARROW),KC_SLSH,KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘           └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, LOWER,   KC_ENT,                       KC_SPC,  RAISE,   KC_RALT
                                // └────────┴────────┴────────┘                    └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                               KC_LCBR, KC_RCBR, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                               VI_YANK, VI_UNDO, _______, _______, VI_PUT,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, WORD_LEFT,LINE_START,LINE_END,WORD_RGHT,_______,                           KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT, KC_PLUS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐           ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,             _______, _______, MENU_Q,  KC_LBRC, KC_RBRC, KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘           └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                      _______,  _______, _______
                                // └────────┴────────┴────────┘                    └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                 KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, SEL_WORD, KC_TAB, _______, TAB_NEW,                               _______, _______, KC_RGUI,GUI_SFT_O,GUI_SFT_P,_______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_TILD, KC_MINS, KC_UNDS,                               _______, KC_PGDN, KC_PGUP, SFT_F12, ALT_SPC, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐           ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, TAB_PREV, TAB_KILL, NAV_LEFT, NAV_RGHT, TAB_NEXT, _______,        _______, _______, _______,  _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘           └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                      _______, _______, _______
                                // └────────┴────────┴────────┘                    └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RESET,   _______, _______, _______, _______, _______,                               _______, _______, KC_PSCR, KC_PAUS, KC_INS,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐           ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘           └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                      _______, _______, _______
                                // └────────┴────────┴────────┘                    └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // QUERTY layer
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        // VIM yank / put / undo
        case VI_YANK:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("c"));
            }
            return false;

        case VI_PUT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("v"));
            }
            return false;

        case VI_UNDO:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("z"));
            }
            return false;

        // Browser private window or VS Code command palette
        case GUI_SFT_P:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("p")));
            }
            return false;

        // VS Code current file symbols
        case GUI_SFT_O:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("o")));
            }
            return false;

        // VS Code find usage
        case SFT_F12:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_F12);
                unregister_code(KC_LSFT);
            }
            return false;

        // Tabs and browser page nav
        case TAB_NEW:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("t"));
            }
            return false;
        case TAB_NEXT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("]")));
            }
            return false;
        case TAB_PREV:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_LSFT("[")));
            }
            return false;
        case TAB_KILL:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("w"));
            }
            return false;
        case NAV_LEFT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
            }
            return false;
        case NAV_RGHT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_RGHT);
                unregister_code(KC_LGUI);
            }
            return false;

        case ALT_SPC:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(" "));
            }
            return false;

        case WORD_LEFT:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_LEFT);
                unregister_code(KC_LALT);
            }
            return false;

        case WORD_RGHT:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_RGHT);
                unregister_code(KC_LALT);
            }
            return false;

        case LINE_START:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LGUI);
            }
            return false;

        case LINE_END:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_RGHT);
                unregister_code(KC_LGUI);
            }
            return false;

        case SEL_WORD:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_RGHT);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            }
            return false;

        case MENU_Q:
            if (record->event.pressed) {
              SEND_STRING(SS_LGUI(SS_LSFT("/")));
            }
            return false;


        // Right rotary encoder key
        case FONT_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("0"));
            }
            return false;
    }
    return true;
}

//*
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
//*/

// Leader key

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_Q) {
            SEND_STRING(SS_LGUI("q"));
        }

        SEQ_ONE_KEY(KC_M) {
            register_code(KC_LCTL);
            tap_code(KC_F2);
            unregister_code(KC_LCTL);
        }

        SEQ_TWO_KEYS(KC_H, KC_H) {
            register_code(KC_LCTL);
            tap_code(KC_LEFT);
            unregister_code(KC_LCTL);
        }

        SEQ_TWO_KEYS(KC_L, KC_L) {
            register_code(KC_LCTL);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCTL);
        }

        SEQ_TWO_KEYS(KC_S, KC_S) {
            SEND_STRING(SS_LGUI(SS_LSFT("5")));
        }

        SEQ_TWO_KEYS(KC_BSPC, KC_BSPC) {
            SEND_STRING(SS_LCTL(SS_LGUI("q")));
        }

        SEQ_TWO_KEYS(KC_W, KC_M) {
            SEND_STRING(SS_LCTL(SS_LALT(SS_LGUI(" "))));
        }
    }
}

// Tap dance
//*
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    }
    if (state->count == 2) {
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    }
    return TD_UNKNOWN;
}

static td_tap_t dot_arrow_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void dot_arrow_finished(qk_tap_dance_state_t *state, void *user_data) {
    dot_arrow_tap_state.state = cur_dance(state);

    switch (dot_arrow_tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(".");
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("=>");
            break;
        default:
            break;
    }
}

void dot_arrow_reset(qk_tap_dance_state_t *state, void *user_data) {
    dot_arrow_tap_state.state = TD_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_DOT_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_arrow_finished, dot_arrow_reset)
};
//*/

// Rotary encoders

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            SEND_STRING(SS_LGUI("="));
        } else {
            SEND_STRING(SS_LGUI("-"));
        }
    }
    return false;
}
