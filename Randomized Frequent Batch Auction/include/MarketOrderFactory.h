#ifndef MARKET_ORDER_FACTORY_H
#define MARKET_ORDER_FACTORY_H
#include "OrderFactory.h"
#include "MarketOrder.h"
#include <memory>

class MarketOrderFactory : public OrderFactory {
public:
    std::unique_ptr<Order> createOrder(int traderId, double price, int quantity, OrderType type) override;
};

#endif
