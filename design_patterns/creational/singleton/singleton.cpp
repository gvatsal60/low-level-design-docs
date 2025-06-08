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
LazySingleton *LazySingleton::instance = nullptr;
ThreadSafeSingleton *ThreadSafeSingleton::instance = nullptr;

/***************************************************************************************
 * Main Function
 **************************************************************************************/

int main() {
  // Accessing the singleton instances
  EagerSingleton &eagerInstance = EagerSingleton::getInstance();
  LazySingleton &lazyInstance = LazySingleton::getInstance();
  ThreadSafeSingleton &threadSafeInstance = ThreadSafeSingleton::getInstance();

  // Example usage of the singleton instances
  printf("Eager Singleton instance address: %p\n", &eagerInstance);
  printf("Lazy Singleton instance address: %p\n", &lazyInstance);
  printf("Thread Safe Singleton instance address: %p\n", &threadSafeInstance);

  return 0;
}
