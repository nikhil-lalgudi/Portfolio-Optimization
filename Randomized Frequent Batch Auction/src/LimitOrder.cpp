#include "LimitOrder.h"

LimitOrder::LimitOrder(int traderId, double p, int qty, std::time_t ts, OrderType type)
    : Order(traderId, p, qty, ts, type) {}

std::string LimitOrder::getOrderTypeString() const {
    return "LimitOrder";
}
