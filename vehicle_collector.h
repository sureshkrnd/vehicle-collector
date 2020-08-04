#include "inventory_collector.h"

enum Measure {
  MOTOR_TEMP,
  BATTERY_SOC,
  BATTERY_TEMP
};

struct Telematics {
  int vehicleID;
  Measure measure;
  float value;
};

static Inventory vehicleInventory;

bool store_to_inventory(const Telematics& t) {
  InventoryItem invItem = telematics_to_inventory
      (t.vehicleID, t.measure, t.value);
  vehicleInventory.addItem(invItem);
  return true;
}
