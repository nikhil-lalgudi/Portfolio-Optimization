#include "MarketOrder.h"

MarketOrder::MarketOrder(int traderId, double p, int qty, std::time_t ts, OrderType type)
    : Order(traderId, p, qty, ts, type) {}

std::string MarketOrder::getOrderTypeString() const {
    return "MarketOrder";
}
