#include "blinker.h"
#include "esphome/core/log.h"
#include "esphome/core/helpers.h"
#include "esphome/core/hal.h"


namespace esphome {
namespace blinker {

static const char *const TAG = "blinker";

void Blinker::setup() {
  if (this->pin_ != nullptr) {
    this->pin_->setup();
    this->pin_->digital_write(false);
    ESP_LOGCONFIG(TAG, "Blinker initialized");
  }
}

void Blinker::write_state(bool state) {
  this->enabled_ = state;
  if (!state && this->pin_ != nullptr) {
    this->pin_->digital_write(false);
  }
  this->publish_state(state);
}

void Blinker::loop() {
  if (!enabled_ || this->pin_ == nullptr) return;

  uint32_t now = millis();
  if (now - last_toggle_ > 500) {
    led_state_ = !led_state_;
    this->pin_->digital_write(led_state_);
    last_toggle_ = now;
  }
}

void Blinker::dump_config() {
  ESP_LOGCONFIG(TAG, "Blinker Switch active");
  LOG_PIN("  Pin: ", this->pin_);
}

}  // namespace blinker
}  // namespace esphome