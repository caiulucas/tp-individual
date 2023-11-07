#include "System.hpp"

/**
 * Constructor that creates a new System.
 */
System::System(){};

/**
 * Constructor that creates a new System.
 *
 * @param id The id of the System.
 * @param title The title of the System.
 * @param value The value of the System.
 */
System::System(int id, string title, double value)
    : m_id(id), m_title(title), m_value(value) {}

/**
 * Copy constructor that creates a new System.
 *
 * @param other The System to copy.
 */
System::System(const System &other) {
  if (this != &other) {
    m_id = other.m_id;
    m_title = other.m_title;
    m_value = other.m_value;
  }
}

/**
 * Copy assignment operator that copies a System.
 *
 * @param other The System to copy.
 * @return The copied System.
 */
System &System::operator=(const System &other) {
  if (this != &other) {
    m_id = other.m_id;
    m_title = other.m_title;
    m_value = other.m_value;
  }
  return *this;
}

/**
 * Destructor that destroys a System.
 */
System::~System(){};

int System::get_id() const { return m_id; }

/**
 * Gets the id of the System.
 *
 * @return The id of the System.
 */
double System::get_value() const { return m_value; }

/**
 * Sets the value of the System.
 *
 * @param new_value The new value of the System.
 */
void System::set_value(double new_value) { m_value = new_value; }
