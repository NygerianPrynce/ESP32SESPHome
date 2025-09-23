import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins
from esphome.components import switch
from esphome.const import CONF_ID, CONF_PIN

blinker_ns = cg.esphome_ns.namespace("blinker")
Blinker = blinker_ns.class_("Blinker", switch.Switch, cg.Component)

CONFIG_SCHEMA = (
    switch.switch_schema(Blinker)
    .extend({
        cv.Required(CONF_PIN): pins.gpio_output_pin_schema,
    })
    .extend(cv.COMPONENT_SCHEMA)
)

async def to_code(config):
    var = await switch.new_switch(config)
    await cg.register_component(var, config)

    pin = await cg.gpio_pin_expression(config[CONF_PIN])
    cg.add(var.set_pin(pin))