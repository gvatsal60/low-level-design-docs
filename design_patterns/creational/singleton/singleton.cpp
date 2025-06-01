#include <cstdio>

#include "singleton.h"
#include "singleton_impl.h"

namespace creational {
Singleton* Singleton::instance_ = nullptr;
Singleton* Singleton::GetInstance() {
  if (instance_ == nullptr) {
    instance_ = new SingletonImpl();
  }
  return instance_;
}
void Singleton::DestroyInstance() {
  if (instance_ != nullptr) {
    delete instance_;
    instance_ = nullptr;
  }
}
void Singleton::Print() {
  if (instance_ != nullptr) {
    instance_->Print();
  } else {
    printf("Singleton instance is not initialized.\n");
  }
}
}  // namespace creational