#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pico/cyw43_arch.h"


void init_led() {
  if (cyw43_arch_init()) {
    printf("Wi-Fi init failed");
  }
}

void blink() {
  cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
  sleep_ms(250);
  cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
}

int main() {
  stdio_init_all();
  init_led();
  const uint PIN = 14;
  gpio_set_function(PIN, GPIO_FUNC_PWM);

  uint slice_num = pwm_gpio_to_slice_num(PIN);
  uint chan_num = pwm_gpio_to_channel(PIN);
  
  int wrap = 99;
  pwm_set_wrap(slice_num, wrap);

  pwm_set_chan_level(slice_num, PWM_CHAN_A, 0);
  pwm_set_enabled(slice_num, true);
  
  int i = 0;
  while (true) {
    printf("hey\n");
    pwm_set_chan_level(slice_num, PWM_CHAN_A, i);
    sleep_ms(30);
    i++;
    if (i == wrap+1) {
      i=0;
    }
  }
}
