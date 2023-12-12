#pragma once

class Body {
private:
  Body(const Body &other);

  Body &operator=(const Body &other);

  int _reference_count;

public:
  Body();

  virtual ~Body();

  void attach();

  void detach();

  int reference_count() const;
};