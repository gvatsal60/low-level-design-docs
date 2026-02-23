/***************************************************************************************
 * File: factory_method.hpp
 * Author: @gvatsal60
 * Date: 23-Jun-2025
 * Description: Factory Method Design Pattern
 **************************************************************************************/

/***************************************************************************************
 * License
 **************************************************************************************/
/*
 * This file is licensed under the Apache 2.0 License.
 * License information should be updated as necessary.
 */

/***************************************************************************************
 * Includes
 **************************************************************************************/
#ifndef FACTORY_METHOD_GUARD
#define FACTORY_METHOD_GUARD

#include <cstdio>
#include <memory>
#include <stdexcept>

/***************************************************************************************
 * Constants
 ***************************************************************************************/

/***************************************************************************************
 * Structure Declarations
 **************************************************************************************/

/***************************************************************************************
 * Class Declarations
 **************************************************************************************/

// Product Interface: Transport
class Transport {
public:
  virtual ~Transport() = default;
  virtual void deliver() const = 0;
};

// Concrete Product: Truck
class Truck : public Transport {
public:
  void deliver() const override { std::puts("Delivering by land in a box."); }
};

// Concrete Product: Ship
class Ship : public Transport {
public:
  void deliver() const override {
    std::puts("Delivering by sea in a container.");
  }
};

// Creator (Factory) Interface
class Logistics {
public:
  virtual ~Logistics() = default;
  virtual Transport *createTransport() const = 0;
};

// Concrete Creator: RoadLogistics
class RoadLogistics : public Logistics {
public:
  Transport *createTransport() const override {
    std::shared_ptr<Transport> truckPtr = std::make_shared<Truck>();
    return truckPtr.get();
  }
};

// Concrete Creator: SeaLogistics
class SeaLogistics : public Logistics {
public:
  Transport *createTransport() const override {
    std::shared_ptr<Transport> shipPtr = std::make_shared<Ship>();
    return shipPtr.get();
  }
};

// Logistic Service
class LogisticService {
public:
  explicit LogisticService(Logistics *const logistics) {
    if (logistics == nullptr) {
      throw std::invalid_argument("Logistics pointer cannot be null");
    }
    logistics_ = logistics;
  }

  void planDelivery() const {
    const auto * const transport = logistics_->createTransport();
    transport->deliver();
  }

private:
  Logistics *logistics_{nullptr};
};

#endif
