import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

CODEOWNERS = ["@me"]
DEPENDENCIES = []
AUTO_LOAD = []
MULTI_CONF = True

blinker_ns = cg.esphome_ns.namespace("blinker")
Blinker = blinker_ns.class_("Blinker", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(Blinker),
}).extend(cv.COMPONENT_SCHEMA)

PLATFORM_SCHEMA = CONFIG_SCHEMA  # ✅ THIS is what makes the `platform:` key valid

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
