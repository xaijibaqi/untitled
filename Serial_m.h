//
// Created by 31726 on 2023/11/18.
//

#ifndef SERIAL_PORT_SERIAL_M_H
#define SERIAL_PORT_SERIAL_M_H

#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>
#include "string"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "opencv2/opencv.hpp"


class Serial_m {
public:
    serial::Serial sp;
    uint8_t read_data[24];
    uint8_t send_data[19];

    //  串口通讯接受数据
    struct Robot{
        std::string Enemy_color="Red";
        float Yaw_angle=0;
        float Pitch_angle=0;
    };

//  串口通讯发送数据
    struct Send_data{
        float Yaw_angle=0;
        float Pitch_angle=0;
        float d=0;
        std::string Fire_control="N";
    };

    Send_data serial_data;

    Robot robot1;

    void serial_open();

    void serial_read();

    void serial_send();

    Robot read_serial_data();

    Serial_m();

    ~Serial_m();

};


#endif //SERIAL_PORT_SERIAL_M_H
