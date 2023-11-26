//
// Created by 31726 on 2023/11/18.
//

#include "Serial_m.h"


Serial_m::Robot Serial_m::read_serial_data() {

    Robot robot1;

    if(read_data[0]==66){
        robot1.Enemy_color="Blue";
    }

//    yaw_angle
    uint8_t Yaw_angle_uint8[7];
    Yaw_angle_uint8[0]= read_data[3];
    Yaw_angle_uint8[1]= read_data[4];
    Yaw_angle_uint8[2]= read_data[5];
    Yaw_angle_uint8[3]= read_data[6];
    Yaw_angle_uint8[4]= read_data[7];
    Yaw_angle_uint8[5]= read_data[8];

    float Yaw_angle;
    memcpy(&Yaw_angle, Yaw_angle_uint8, 6);

    if (read_data[2]==45){
        Yaw_angle*=-1;
    }
    Yaw_angle=Yaw_angle*180/3.141592;
    robot1.Yaw_angle=Yaw_angle;

//    pitch_angle
    uint8_t Pitch_angle_uint8[7];
    Yaw_angle_uint8[0]= read_data[4];
    Yaw_angle_uint8[1]= read_data[4];
    Yaw_angle_uint8[2]= read_data[5];
    Yaw_angle_uint8[3]= read_data[6];
    Yaw_angle_uint8[4]= read_data[7];
    Yaw_angle_uint8[5]= read_data[8];

    float Pitch_angle;
    memcpy(&Pitch_angle, Pitch_angle_uint8, 6);
    if (read_data[11]==45){
        Pitch_angle*=-1;
    }
    Pitch_angle=Pitch_angle*180/3.141592;
    robot1.Pitch_angle=Pitch_angle;

    return robot1;
}

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
            printf("\nread=%s",read_data);
            robot1=read_serial_data();
        }

    }
}

uint8_t float2u8Arry(float *f, int n)
{
    uint8_t farray[4];
    *(float *)farray = *f;
    }

void Serial_m::serial_send() {
    float Yaw_angle=serial_data.Yaw_angle,Pitch_angle=serial_data.Pitch_angle;
    send_data[0]=65;
    send_data[1]=89;
    if(serial_data.Yaw_angle>0)
        send_data[2]=45;
    else
        send_data[2]=45;
    uint8_t farray[6];
    *(float *)farray = Yaw_angle;


    send_data[3]=farray[0];
    send_data[4]=farray[1];
    send_data[5]=farray[2];
    send_data[6]=46;
    send_data[7]=farray[4];
    send_data[8]=farray[5];
    send_data[9]=80;
    if(serial_data.Pitch_angle>0)
        send_data[10]=45;
    else
        send_data[10]=45;
    *(float *)farray = Pitch_angle;
    send_data[11]=farray[0];
    send_data[12]=farray[1];
    send_data[13]=farray[2];
    send_data[14]=46;
    send_data[15]=farray[4];
    send_data[16]=farray[5];
    if(abs(serial_data.Yaw_angle) < 5 && abs(serial_data.Pitch_angle) < 5 && serial_data.d<3 )
        send_data[17]=70;
    else
        send_data[17]=78;
    send_data[18]=66;


    sp.write(send_data,19)
}