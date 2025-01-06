#ifndef LIMIT_ORDER_FACTORY_H
#define LIMIT_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "LimitOrder.h"
#include <memory>

class LimitOrderFactory : public OrderFactory {
public:
    std::unique_ptr<Order> createOrder(int traderId, double price, int quantity, OrderType type) override;
};

#endif
