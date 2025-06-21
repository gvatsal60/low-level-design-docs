# Singleton Design Pattern

The Singleton pattern ensures that a class has only one instance and provides a global point of access to it.
This is useful when exactly one object is needed to coordinate actions across the system.

## Types of Singleton Implementations

### 1. Eager Initialization

- The instance is created at program startup.
- Simple and thread-safe.
- May lead to resource wastage if the instance is never used.

```cpp
EagerSingleton &instance = EagerSingleton::getInstance();
```

### 2. Lazy Initialization

- The instance is created only when it is first needed.
- Not thread-safe by default.

```cpp
LazySingleton &instance = LazySingleton::getInstance();
```

### 3. Thread-Safe Singleton

- Ensures that only one instance is created even in multithreaded environments.
- Uses `std::call_once` and `std::once_flag` for thread safety.

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
