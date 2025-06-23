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
  virtual void deliver() const = 0;
  virtual ~Transport() = default;
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
  virtual Transport* createTransport() const = 0;
  virtual ~Logistics() = default;
};

// Concrete Creator: RoadLogistics
class RoadLogistics : public Logistics {
 public:
  Transport* createTransport() const override { return new Truck(); }
};

// Concrete Creator: SeaLogistics
class SeaLogistics : public Logistics {
 public:
  Transport* createTransport() const override { return new Ship(); }
};

// Logistic Service
class LogisticService {
 public:
  LogisticService(Logistics* logistics) : logistics_(logistics) {}

  void planDelivery() const {
    Transport* transport = logistics_->createTransport();
    transport->deliver();
    delete transport;
  }

 private:
  Logistics* logistics_;
};

#endif