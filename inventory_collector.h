#include <map>

struct InventoryItem {
  int itemID;
  std::map<int, float> keyvalueMap;
};

class Inventory {
  public:
    void addItem(const InventoryItem& invItem) {
      invContent[invItem.itemID] = invItem;
    }
    InventoryItem getItem(int itemID) {
      return invContent[itemID];
    }
  private:
    std::map<int, InventoryItem> invContent;
};

InventoryItem telematics_to_inventory
    (int vehicleID, int measureType, float value) {
  InventoryItem invItem;
  invItem.itemID = vehicleID;
  invItem.keyvalueMap[measureType] = value;
  return invItem;
}
