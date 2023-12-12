#include "Handle.hpp"
#include "System.hpp"
#include "SystemBody.hpp"

class SystemHandle : public System, public Handle<SystemBody> {
public:
  SystemHandle();

  SystemHandle(std::string title, double value);

  SystemHandle(const System &system);

  SystemHandle &operator=(const System &system);

  ~SystemHandle();

  std::string get_title() const;

  double get_value() const;

  void set_value(double value);

  void set_title(std::string new_title);
};