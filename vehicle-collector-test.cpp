#include "vehicle_collector.h"
#include <gtest/gtest.h>

TEST(COLLECT, one_telematics_is_converted_into_one_inventory) {
    Telematics t = {10, MOTOR_TEMP, 30.5};
    Vehicle v = telemetrics_to_inventory(t);
    ASSERT_EQ(v.motor_temp, 30.5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
