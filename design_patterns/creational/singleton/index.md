# Singleton Design Pattern

The Singleton pattern ensures that a class has only one instance and provides a global point of access to it.
This is useful when exactly one object is needed to coordinate actions across the system.

## Types of Singleton Implementations

### 1. Eager Initialization

- The singleton instance is created as soon as the program starts, before any function accesses it.
- This approach is inherently thread-safe because the instance is constructed during static initialization.
- It is simple to implement, but may waste resources if the instance is never actually used during the program's execution.

### 2. Lazy Initialization

- The singleton instance is created only when it is first accessed.
- This approach is not thread-safe by default and may create multiple instances in a multithreaded environment.
- It is simple and efficient for single-threaded applications.

```cpp
LazySingleton &instance = LazySingleton::getInstance();
```

### 3. Thread-Safe Singleton

- Ensures that only one instance is created, even in multithreaded environments.
- Achieves thread safety using `std::call_once` and `std::once_flag` to control initialization.

```cpp
ThreadSafeSingleton &instance = ThreadSafeSingleton::getInstance();
```

## Example Output

When running the example code, you will see the addresses of the singleton instances:

```text
Eager Singleton instance address: 0x55f8c8e2c2e0
Lazy Singleton instance address: 0x55f8c8e2c300
Thread-Safe Singleton instance address: 0x55f8c8e2c320
```

## References

- [singleton header](singleton.hpp)
- [singleton implementation](singleton.cpp)
