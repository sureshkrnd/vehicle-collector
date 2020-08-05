#include "vehicle_collector.h"

#include <gtest/gtest.h>
#include <iostream>

TEST(COLLECT, any_telematics_enum_is_converted_into_one_inventory_entry) {
    enum TelematicsSample {
        Measure1,
        Measure2
    };
    const int vehicleID = 100;
    const float measuredValue = 0.45;
    InventoryItem inv = 
        telematics_to_inventory(vehicleID, Measure2, measuredValue);
    ASSERT_NEAR(inv.keyvalueMap[Measure2], measuredValue, 0.001);
    ASSERT_EQ(inv.itemID, vehicleID);
}

TEST(COLLECT, one_new_item_entry_is_added_to_inventory) {
    const int newVehicleID = 101;
    const float measuredValue = 22.3;
    const float measure = 2;
    InventoryItem newInvItem = telematics_to_inventory
            (newVehicleID, measure, measuredValue);
    
    Inventory inventory;
    inventory.addItem(newInvItem);
    ASSERT_EQ(inventory.getItem(newVehicleID).itemID, newInvItem.itemID);
}

TEST(COLLECT, motor_temp_telematics_is_converted_into_one_inventory) {
    Telematics t = {10, MOTOR_TEMP, 30.5};
    bool stored = store_to_inventory(t);
    ASSERT_TRUE(stored);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
