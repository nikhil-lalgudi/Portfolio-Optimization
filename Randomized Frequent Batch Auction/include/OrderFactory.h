#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include <memory>
#include "Order.h"

class OrderFactory {
public:
    virtual ~OrderFactory() = default;
    virtual std::unique_ptr<Order> createOrder(int traderId, double price, int quantity, OrderType type) = 0;
};

#endif 
