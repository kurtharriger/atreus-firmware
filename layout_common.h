

int fn_decay = 0;

void activate_fn() {
  fn_decay = 20;
};

int layer_to_jump = 0;

// jump to this layer when fn is released
void layer_jump() {
  layer_to_jump = 2;
};




void per_cycle() {
  if(fn_decay > 1) {
    current_layer = layers[1];
    fn_decay--;
  } else if(fn_decay == 1) {
    current_layer_number = layer_to_jump;
    fn_decay--;
  } else {
    layer_to_jump = 0;
    fn_decay = 0;
  }
};

void activate_swapped_hands() {
   // todo: activate mode to swap hands while pressed
}

uint8_t locked_keyboard_modifier_keys=0;


void fn_normal_mode() {
  locked_keyboard_modifier_keys = 0;
  current_layer_number = LAYER_NORMAL;
}

void fn_lockctrl() {
  locked_keyboard_modifier_keys |= KEY_CTRL;
}

void fn_lockshift() {
  locked_keyboard_modifier_keys |= KEY_SHIFT;
}

void fn_lockatl() {
  locked_keyboard_modifier_keys |= KEY_ALT;
}

void fn_lockgui() {
  locked_keyboard_modifier_keys |= KEY_GUI;
}


void (*layer_functions[])(void) = {
  reset,
  activate_fn,
  layer_jump,
  activate_swapped_hands,
  fn_normal_mode,
  fn_lockctrl,
  fn_lockshift,
  fn_lockatl,
  fn_lockgui
};
