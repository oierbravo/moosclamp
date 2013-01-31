/*
  moosclamp.ino - Moosclamp, an OSC moodlamp
  Copyright (C) 2013 Oier Bravo Urtasun.  All rights reserved.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

//Ethernet includes.
#include <SPI.h>        
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <OSCBundle.h>
//Moodlamp includes
#include <Moodlamp.h>

//UDP communication
EthernetUDP Udp;

//a bundle for all the incoming messages
OSCBundle bundleIN(Udp);

//the Arduino's IP
IPAddress ip(192, 168, 1, 177);

//port numbers
unsigned int inPort = 8888;
unsigned int outPort = 9999;
 //everything on the network needs a unique MAC address
byte mac[] = {  
  0xDE, 0xAD, 0xAE, 0xEF, 0xEE, 0xED };

OSCMessage msg;

//moodlamp vars
int redPin = 3;
int greenPin = 5;
int bluePin = 6;
//Initializing moodlamp.
Moodlamp moodlamp(redPin,greenPin,bluePin);

void setup(){

  #ifdef VERBOSE || DEBUG
    Serial.begin(115200);
  #endif
  
  //Ethernet
  Ethernet.begin(mac,ip);
  Udp.begin(inPort);
  
  #ifdef VERBOSE || DEBUG
    Serial.println("start");
    Serial.flush();
  #endif

}

void loop(){
  int packetSize = Udp.parsePacket();
  if(packetSize)
  {
    //fill the contents of msg with the received string
    if (bundleIN.receive()>0){
      char buffer[24];

      //OSC
       bundleIN.dispatch("/moosclamp/rgb", callback_rgb); 
      
      bundleIN.dispatch("/moosclamp/red", callback_red); 
      bundleIN.dispatch("/moosclamp/green", callback_green);
      bundleIN.dispatch("/moosclamp/blue", callback_blue);
      
      
      bundleIN.dispatch("/moosclamp/color/red", callback_color_red); 
      bundleIN.dispatch("/moosclamp/color/green", callback_color_green);
      bundleIN.dispatch("/moosclamp/color/blue", callback_color_blue);
      
      bundleIN.dispatch("/moosclamp/color/yellow", callback_color_yellow);
      bundleIN.dispatch("/moosclamp/color/orange", callback_color_orange);
      bundleIN.dispatch("/moosclamp/color/cyan", callback_color_cyan);
      bundleIN.dispatch("/moosclamp/color/purple", callback_color_purple);
      
      bundleIN.dispatch("/moosclamp/color/white", callback_color_white);
      bundleIN.dispatch("/moosclamp/color/black", callback_color_black);
      
      bundleIN.dispatch("/moosclamp/off", callback_off);
      
      bundleIN.dispatch("/moosclamp/speed", callback_speed);
      
      bundleIN.dispatch("/moosclamp/mode/manual", callback_mode_manual);
      bundleIN.dispatch("/moosclamp/mode/cycle", callback_mode_cycle);
    }
  }
    //Moodlamp updater
    moodlamp.update(); 
  
}


//-- OSC Callbacks
/*
/ /moosclamp/rgb  -> Sets red amount.
*/
void callback_rgb(OSCMessage m){
   int red = m.getInt();
   int green = m.getInt();
   int blue = m.getInt();
   moodlamp.setRGB(red,green,blue);
}
/*
/ /moosclamp/red  -> Sets red amount.
*/
void callback_red(OSCMessage m){
   int val = m.getInt();
   moodlamp.setRed(val);
}

/*
/ /moosclamp/green  -> Sets green amount.
*/
void callback_green(OSCMessage m){
  int val = m.getInt();
  moodlamp.setGreen(val);;
}

/*
/ /moosclamp/blue  -> Sets blue amount.
*/
void callback_blue(OSCMessage m){
   int val = m.getInt();
   moodlamp.setBlue(val);
}
/*
/ /moosclamp/color/red  -> Sets red color.
*/
void callback_color_red(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_RED);
}

/*
/ /moosclamp/color/green  -> Sets green color.
*/
void callback_color_green(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_GREEN);
}

/*
/ /moosclamp/color/blue  -> Sets blue color.
*/
void callback_color_blue(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_BLUE);
}

/*
/ /moosclamp/color/yellow  -> Sets yellow color.
*/
void callback_color_yellow(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_YELLOW);
}

/*
/ /moosclamp/color/orange  -> Sets orange color.
*/
void callback_color_orange(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_ORANGE);
}

/*
/ /moosclamp/color/cyan  -> Sets cyan color.
*/
void callback_color_cyan(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_CYAN);
}

/*
/ /moosclamp/color/purple  -> Sets blue color.
*/
void callback_color_purple(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_PURPLE);
}

/*
/ /moosclamp/color/white  -> Sets white color.
*/
void callback_color_white(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_WHITE);
}

/*
/ /moosclamp/color/black  -> Sets black color.
*/
void callback_color_black(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_BLACK);
}

/*
/ /moosclamp/off  -> Sets all color to 0.
*/
void callback_off(OSCMessage m){
  moodlamp.setColor(Moodlamp::COLOR_BLACK);
}

/*
/ /moosclamp/mode/manual  -> Sets manual mode.
*/
void callback_mode_manual(OSCMessage m){
   moodlamp.setMode(Moodlamp::MODE_MANUAL); 
}

/*
/ /moosclamp/mode/cycle  -> Sets cycle mode.
*/
void callback_mode_cycle(OSCMessage m){
   moodlamp.setMode(Moodlamp::MODE_CYCLE);  
}


/*
/ /moosclamp/speed [int]  -> Sets time between steps . Default: 10.
*/
void callback_speed(OSCMessage m){
  int val = m.getInt();
  moodlamp.setUpdateTime(val); 
}

