#ifndef ORDER_MATCHING_STRATEGY_H
#define ORDER_MATCHING_STRATEGY_H

#include <vector>
#include <memory>
#include "Order.h"

class OrderMatchingStrategy {
public:
    virtual ~OrderMatchingStrategy() = default;
    virtual void matchOrders(std::vector<std::shared_ptr<Order>>& buys,
                             std::vector<std::shared_ptr<Order>>& sells) = 0;
};

#endif 
