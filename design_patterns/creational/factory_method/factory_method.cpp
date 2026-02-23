/***************************************************************************************
 * File: factory_method.cpp
 * Author: @gvatsal60
 * Date: 23-Jun-2025
 * Description: Factory Method Design Pattern
 **************************************************************************************/

/***************************************************************************************
 * Includes
 **************************************************************************************/

#include "factory_method.hpp"

/***************************************************************************************
 * Global Functions Definitions
 **************************************************************************************/

/***************************************************************************************
 * Class Methods Definitions
 **************************************************************************************/

int main() {
  RoadLogistics roadLogistics{};
  LogisticService road_logistic_ser(&roadLogistics);
  road_logistic_ser.planDelivery();

  SeaLogistics seaLogistics{};
  LogisticService sea_logistic_ser(&seaLogistics);
  sea_logistic_ser.planDelivery();

  return 0;
}
