# 🏭 **Factory Method Design Pattern**

The **Factory Method** pattern defines an **interface for creating objects**,
but lets subclasses decide **which class to instantiate**.
This pattern lets a class defer instantiation to its subclasses, promoting loose coupling and flexibility. 🎛️

## **Key Concepts** 🧩

- **Creator**: Declares the factory method, which returns an object of a product type.
- **ConcreteCreator**: Implements the factory method to return an instance of a specific product.
- **Product**: Defines the interface of objects the factory method creates.
- **ConcreteProduct**: Implements the Product interface.

---

## **When to Use?** 🤔

- When a class can't anticipate the class of objects it must create.
- To delegate the responsibility of instantiation to subclasses.
- To localize knowledge of which helper subclass is the delegate.

---

## **Benefits** 🌟

- **Single Responsibility**: Creation logic is separated from usage.
- **Open/Closed Principle**: Add new products without changing existing code.
- **Flexibility**: Choose which product to create at runtime.

## **Drawbacks** ⚠️

- **More Classes**: Can lead to a proliferation of subclasses.
- **Complexity**: Adds indirection to object creation.

## **Conclusion** 🎬

The Factory Method pattern is ideal when you need to delegate object creation to subclasses,
enabling more flexible and maintainable code!
