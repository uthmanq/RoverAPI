# RoverAPI
A lightweight API to control your robot over local wifi.
## Description
The Rover API is a lightweight program that allows you to control your robot with simple HTTP commands such as "192.168.240.1/arduino/forward/120" which would send the rover forward at 120 speed. This program is uploaded directly to your microcontroller. It connects to local wifi and you're good to go.
## What You Need
This API was set up with the Arduino Yun's Bridge library and Lynxmotion's 4WD rover kit.
It uses the built-in Arduino Yun Bridge Library and the Sabertooth Motor Controller Arduino library available at https://www.dimensionengineering.com/info/arduino)
## Setup
Setup your Sabertooth and rover system according to your project's requirements and configure the DIP switches to serial mode. This is a helpful wizard: https://www.dimensionengineering.com/datasheets/SabertoothDIPWizard/start.htm

Connect your Arduino Yun to your wifi. This is a helpful guide for people new to the Yun: https://www.twilio.com/blog/2015/02/arduino-wifi-getting-started-arduino-yun.html

Connect your Arduino pins in the following way to the Sabertooth's signal pins:

-Arduino VIN to Sabertooth 5V

-Arduino GND to Sabertooth 0V

-Arduino D11 to Sabertooth S1

-The program reserves pin D12 for RX but it is not required to be connected to anything as the Sabertooth has no TX.

Once you've connected everything, you're good to go! Your API should be responsive. 

## Using the API

-Commands run indefinitely on the API. If you send a forward command, it will continue forward indefinitely. You only have to worry about speed now. Max speed is 127. Speed of 0 stops rover. 

-A successful call to the Yun has 2 parts (if you are controlling a rover). You must first send a command and its speed. Then you need to send a stop command (speed 0) 

-Successful REST calls do not have any durations. They are executed instantaneously and run until a new command is sent. This frees up the server to listen for new commands.

## Format
*roverIPaddress/arduino/command/speed*

Example:

192.168.240.1/arduino/forward/120

Commands:

-forward

-backwards

-left

-right

Speed Range: 0-127

127 is maximum, 0 is stop

## What's coming
The API library (Bridge) is a generally unsupported library. We will very very shortly move to the aREST library that is generally better. 

This initial program is designed for the Arduino Yun but it will be usable for most Arduino controllers with WIFI in the next update.

Check out Launchpadlabs.org for more information about the Launchify team.
