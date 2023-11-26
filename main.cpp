#include <iostream>
#include "Serial_m.h"

Serial_m serial1;

void open_serial() {
    serial1.serial_open();
    while (!serial1.isOpen()){
        serial1.serial_open();
        if(sp.isOpen())
        {
            ROS_INFO_STREAM("serial is opened.");
        }
    }
}

void read_serial(){
    while(ros::ser()){
        serial1.serial_read();
    }
}

void read_serial(){
    while(ros::ser()){
        serial1.serial_send();
    }
}