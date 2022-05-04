#include <string>

class QuackBehavior {
 public:
  virtual std::string quack();
};

class Quack : public QuackBehavior {
    public:
     std::string quack();
};

class Mute : public QuackBehavior {
 public:
  std::string quack();
};

std::string Quack::quack() { return "quack"; }

std::string Mute::quack() { return ""; }