#include "baud_rate_select.h"
#include "esphome/core/version.h"

namespace esphome {
namespace ld2410 {

void BaudRateSelect::control(const std::string &value) {
#if ESPHOME_VERSION_CODE >= VERSION_CODE(2026, 6, 4)
  select::Select::control(value);
#else
  this->publish_state(value);
  this->parent_->set_baud_rate(state);
#endif
}

}  // namespace ld2410
}  // namespace esphome
