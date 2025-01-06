#include "MarketOrderFactory.h"

std::unique_ptr<Order> MarketOrderFactory::createOrder(int traderId, double price, int quantity, OrderType type) {
    return std::make_unique<MarketOrder>(traderId, price, quantity, std::time(nullptr), type);
}
