#include "blinker.h"
#include "esphome/core/log.h"
#include "esphome/core/hal.h"
#include "driver/gpio.h"

namespace esphome {
namespace blinker {

static const char *const TAG = "Blinker";

void Blinker::setup() {
  gpio_pad_select_gpio(GPIO_NUM_2);
  gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
  last_toggle_time_ = millis();
  ESP_LOGCONFIG(TAG, "Blinker setup complete on GPIO2");
}

void Blinker::loop() {
  // optional: toggle LED or do nothing
}

void Blinker::turn_led_on() {
  gpio_set_level(GPIO_NUM_2, 1);
}

void Blinker::turn_led_off() {
  gpio_set_level(GPIO_NUM_2, 0);
}

void Blinker::dump_config() {
  ESP_LOGCONFIG(TAG, "Blinker active.");
}

}  // namespace blinker
}  // namespace esphome
