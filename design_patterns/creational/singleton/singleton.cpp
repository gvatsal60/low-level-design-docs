/***************************************************************************************
 * File: singleton.cpp
 * Author: @gvatsal60
 * Date: 01-Jun-2025
 * Description: Brief description of the file's purpose.
 **************************************************************************************/

/***************************************************************************************
 * Includes
 **************************************************************************************/

#include "singleton.hpp"

/***************************************************************************************
 * Global Functions Definitions
 **************************************************************************************/

/***************************************************************************************
 * Class Methods Definitions
 **************************************************************************************/

// Initialize the static instance pointer
EagerSingleton EagerSingleton::instance{};
std::unique_ptr<LazySingleton> LazySingleton::instance{nullptr};
std::unique_ptr<ThreadSafeSingleton> ThreadSafeSingleton::instance{nullptr};
std::once_flag ThreadSafeSingleton::initFlag;

/***************************************************************************************
 * Main Function
 **************************************************************************************/

int main() {
  // Accessing the singleton instances
  const auto &eagerInstance = EagerSingleton::getInstance();
  const auto &lazyInstance = LazySingleton::getInstance();
  const auto &threadSafeInstance = ThreadSafeSingleton::getInstance();

  // Example usage of the singleton instances
  printf("Eager Singleton instance address: %p\n", &eagerInstance);
  printf("Lazy Singleton instance address: %p\n", &lazyInstance);
  printf("Thread Safe Singleton instance address: %p\n", &threadSafeInstance);

  return 0;
}
