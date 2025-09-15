#pragma once
#include "esphome/core/component.h"

namespace esphome {
namespace blinker {

class Blinker : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;

  void turn_led_on();
  void turn_led_off();
  

 protected:
  bool state_ = false;
  uint32_t last_toggle_time_ = 0;
};


}  // namespace blinker
}  // namespace esphome
