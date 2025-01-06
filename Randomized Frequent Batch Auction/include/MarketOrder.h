#ifndef MARKET_ORDER_H
#define MARKET_ORDER_H

#include "Order.h"

class MarketOrder : public Order {
public:
    MarketOrder() = default;
    MarketOrder(int traderId, double p, int qty, std::time_t ts, OrderType type);
    virtual std::string getOrderTypeString() const override;
};

#endif 
