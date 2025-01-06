#ifndef PRICE_TIME_ORDER_MATCHING_STRATEGY_H
#define PRICE_TIME_ORDER_MATCHING_STRATEGY_H

#include "OrderMatchingStrategy.h"

class PriceTimeOrderMatchingStrategy : public OrderMatchingStrategy {
public:
    void matchOrders(std::vector<std::shared_ptr<Order>>& buys,
                     std::vector<std::shared_ptr<Order>>& sells) override;
};

#endif 
