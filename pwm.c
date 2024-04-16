#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main() {
  stdio_init_all();
  const uint LED_PIN = 14;
  gpio_set_function(LED_PIN, GPIO_FUNC_PWM);

  uint slice_num = pwm_gpio_to_slice_num(LED_PIN);
  uint chan_num = pwm_gpio_to_channel(LED_PIN);
  
  int wrap = 99;
  pwm_set_wrap(slice_num, wrap);

  pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
  pwm_set_enabled(slice_num, true);
  
  int i = 0;
  while (true) {
    pwm_set_chan_level(slice_num, PWM_CHAN_A, i);
    sleep_ms(30);
    i++;
    if (i == wrap+1) {
      i=0;
    }
  }
}
