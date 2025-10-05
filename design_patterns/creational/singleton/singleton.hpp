/***************************************************************************************
 * File: singleton.hpp
 * Author: @gvatsal60
 * Date: 01-Jun-2025
 * Description: This file contains the declaration of the EagerSingleton class,
 * LazySingleton class, and ThreadSafeSingleton class, which implement the
 * Singleton design pattern. The EagerSingleton class uses eager initialization,
 * the LazySingleton class uses lazy initialization, and the ThreadSafeSingleton
 * class ensures thread safety during instance creation. The Singleton design
 * pattern ensures that a class has only one instance and provides a global
 * point of access to that instance.
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
#ifndef SINGLETON_GUARD
#define SINGLETON_GUARD

#include <cstdio>
#include <memory>
#include <mutex>

/***************************************************************************************
 * Constants
 **************************************************************************************/

/***************************************************************************************
 * Structure Declarations
 **************************************************************************************/

/***************************************************************************************
 * Class Declarations
 **************************************************************************************/

/*
 * EagerSingleton Class
 * This class implements the Singleton design pattern using eager
 * initialization. It ensures that only one instance of the class is created at
 * program startup, and provides a global point of access to that instance.
 */
class EagerSingleton final {
public:
  // Deleted copy constructor and assignment operator to prevent copying
  EagerSingleton(const EagerSingleton &) = delete;
  EagerSingleton &operator=(const EagerSingleton &) = delete;

  // Static method to access the `singleton` instance
  static const EagerSingleton &getInstance() {
    return instance; // Return the singleton instance
  }

private:
  // Constructor
  EagerSingleton() = default;

  // Destructor
  ~EagerSingleton() = default;

  static EagerSingleton instance; // Static instance of the singleton
};

/*
 * LazySingleton Class
 * This class implements the Singleton design pattern using lazy initialization.
 * It ensures that only one instance of the class is created and provides a
 * global point of access to that instance.
 */
class LazySingleton final {
public:
  // Deleted copy constructor and assignment operator to prevent copying
  LazySingleton(const LazySingleton &) = delete;
  LazySingleton &operator=(const LazySingleton &) = delete;

  // Static method to access the `singleton` instance
  static const LazySingleton &getInstance() { // Lazy initialization
    if (instance == nullptr) {
      // Constructor is private, so std::make_unique can't be used. Safe to use
      // new here. NOSONAR
      instance = std::unique_ptr<LazySingleton>(new LazySingleton());
    }

    return *instance;
  }

private:
  // Constructor
  LazySingleton() = default;

  // Pointer to the singleton instance
  static std::unique_ptr<LazySingleton> instance;
};

/*
 * ThreadSafeSingleton Class
 * This class implements the Singleton design pattern with thread safety.
 * It ensures that only one instance of the class is created, even in a
 * multithreaded environment.
 */
class ThreadSafeSingleton final {
public:
  // Deleted copy constructor and assignment operator to prevent copying
  ThreadSafeSingleton(const ThreadSafeSingleton &) = delete;
  ThreadSafeSingleton &operator=(const ThreadSafeSingleton &) = delete;

  // Static method to access the `singleton` instance
  static const ThreadSafeSingleton &getInstance() {
    // Use std::call_once to ensure that the instance is created only once
    std::call_once(initFlag, []() {
      // Constructor is private, so std::make_unique can't be used. Safe to use
      // new here. NOSONAR
      instance =
          std::unique_ptr<ThreadSafeSingleton>(new ThreadSafeSingleton());
    });

    return *instance;
  }

private:
  // Constructor
  ThreadSafeSingleton() = default;

  // Pointer to the singleton instance
  static std::unique_ptr<ThreadSafeSingleton> instance;
  static std::once_flag initFlag; // Once flag for thread-safe initialization
};

#endif
