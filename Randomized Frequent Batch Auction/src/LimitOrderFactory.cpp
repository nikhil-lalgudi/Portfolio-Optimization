#include "LimitOrderFactory.h"

std::unique_ptr<Order> LimitOrderFactory::createOrder(int traderId, double price, int quantity, OrderType type) {
    return std::make_unique<LimitOrder>(traderId, price, quantity, std::time(nullptr), type);
}
