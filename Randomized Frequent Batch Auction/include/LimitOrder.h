#ifndef LIMIT_ORDER_H
#define LIMIT_ORDER_H
#include "Order.h"

class LimitOrder : public Order {
public:
    LimitOrder() = default;
    LimitOrder(int traderId, double p, int qty, std::time_t ts, OrderType type);

    virtual std::string getOrderTypeString() const override;
};

#endif // LIMIT_ORDER_H
