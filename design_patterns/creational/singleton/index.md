# 🔑 **Singleton Design Pattern** 🎯

The **Singleton** pattern ensures that a class has **only one instance**
throughout the entire application, providing a global access point for it.
🛠️ This is especially useful when we need a **single object** to handle tasks across various parts of the system. 🌍

## **Types of Singleton Implementations** 🤖

### 1️⃣ **Eager Initialization** ⚡

- 🏁 **Instant Creation**: The instance is created **as soon as the program starts**.
- ✅ **Thread-Safe**: Automatically safe from thread issues because it's initialized during static setup.
- ❌ **Resource Waste**: If the instance isn't used, it still consumes resources.

---

### 2️⃣ **Lazy Initialization** 🕒

- 🚪 **Lazy Loading**: The instance is only created when **first accessed**.
- ⚠️ **Not Thread-Safe**: May cause multiple instances in a multi-threaded environment.
- 🧠 **Efficient**: Works best for single-threaded apps or when instance creation is not always needed.

---

### 3️⃣ **Thread-Safe Singleton** 🔒

- 🔑 **Thread-Safe**: Guarantees only one instance even in multi-threaded environments.
- 💡 Uses `std::call_once` and `std::once_flag` to prevent race conditions.

---

### **Conclusion** 🎬

The Singleton pattern is a powerful tool to ensure controlled access to a class’s instance,
but remember, it comes with its own trade-offs.
Whether you use eager, lazy, or thread-safe methods depends on your use case! 🌱
