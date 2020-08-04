
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

struct Vehicle {
  int vehicleID;
  float motor_temp;
  float battery_soc;
  float battery_temp;
};

Vehicle telemetrics_to_inventory(const Telematics& t) {
  Vehicle v;
  switch (t.measure)
  {
  case MOTOR_TEMP:
    v.motor_temp = t.value;
    break;
  case BATTERY_SOC:
    v.battery_soc = t.value;
    break;
  case BATTERY_TEMP:
    v.battery_temp = t.value;
  default:
    break;
  }
  return v;
}
