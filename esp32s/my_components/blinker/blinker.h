#pragma once

#include "esphome/core/component.h"
#include "esphome/core/gpio.h"
#include "esphome/components/switch/switch.h"

namespace esphome {
namespace blinker {

class Blinker : public switch_::Switch, public Component {
 public:
  void setup() override;
  void dump_config() override;
  void loop() override;

  void set_pin(GPIOPin *pin) { pin_ = pin; }

 protected:
  void write_state(bool state) override;

  GPIOPin *pin_{nullptr};
  bool enabled_{false};
  bool led_state_{false};
  uint32_t last_toggle_{0};
};

}  // namespace blinker
}  // namespace esphome