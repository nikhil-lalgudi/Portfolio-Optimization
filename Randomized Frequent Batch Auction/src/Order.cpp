#include "Order.h"

Order::Order()
    : trader_id(0), price(0.0), quantity(0), timestamp(std::time(nullptr)), orderType(OrderType::BUY) {}

Order::Order(int traderId, double p, int qty, std::time_t ts, OrderType type)
    : trader_id(traderId), price(p), quantity(qty), timestamp(ts), orderType(type) {}

int Order::getTraderId() const {
    return trader_id;
}

double Order::getPrice() const {
    return price;
}

int Order::getQuantity() const {
    return quantity;
}

std::time_t Order::getTimestamp() const {
    return timestamp;
}

OrderType Order::getOrderType() const {
    return orderType;
}

void Order::reduceQuantity(int qty) {
    if (qty >= quantity) {
        quantity = 0;
    } else {
        quantity -= qty;
    }
}

void Order::setOrderType(OrderType type) {
    orderType = type;
}
