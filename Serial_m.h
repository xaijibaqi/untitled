//
// Created by 31726 on 2023/11/18.
//

#ifndef SERIAL_PORT_SERIAL_M_H
#define SERIAL_PORT_SERIAL_M_H

#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>


class Serial_m {
public:
    serial::Serial sp;
    uint8_t read_data[24];
    uint8_t send_data[19];

    void serial_open();

    void serial_read();

    void serial_send();
};


#endif //SERIAL_PORT_SERIAL_M_H
