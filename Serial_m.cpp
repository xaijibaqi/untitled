//
// Created by 31726 on 2023/11/18.
//

#include "Serial_m.h"

void Serial_m::serial_open() {
    //创建timeout
    serial::Timeout to = serial::Timeout::simpleTimeout(100);
    //设置要打开的串口名称
    sp.setPort("/dev/ttyACM1");
    //设置串口通信的波特率
    sp.setBaudrate(115200);
    //串口设置timeout
    sp.setTimeout(to);

    try
    {
        //打开串口
        sp.open();
    }
    catch(serial::IOException& e)
    {
        ROS_ERROR_STREAM("Unable to open port.");
    }
}

void Serial_m::serial_read(){
    //获取缓冲区内的字节数
    size_t n = sp.available();
    if(n!=0)
    {
        uint8_t a;
        //读出数据
        n = sp.read(a, 1);
        if (read_data[0]==65){
            n=sp.read(read_data,24)
        }

    }
}

void Serial_m::serial_send() {
    sp.write(send_data,19)
}