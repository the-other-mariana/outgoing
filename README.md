# Outgoing

ESP32 wifi module that takes data from a sensor and sends it to a server in Golang for multithread API handling.

## Set Up

1. Look at the ESP32 module to see which chip it has. For example, mine has written "SILABS CP2102":

![img](res/module.jpg)

This means we need to use the Silicon Labs CP2102 USB-to-UART Bridge Controller driver ("cp2102 driver in google") provide USB connectivity while communicating via a simple serial protocol, which basically allows the PC to recognize the module and communicate with it through a USB cable.

- To install it, go to https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers and click on `CP210x Universal Windows Driver` option to download a zip file.

- Unzip the file to a temporary folder, right click on the file `silabser.inf` and choose Install. This is all you need to do.

2. Connect the module through a micro-USB cable.

3. Open the Arduino IDE.

4. Go to `Tools > Board` and look at the following:

![img](res/1.png)

- We choose `ESP32 Dev Module` option because the ESP32 module we have, on the back, it reads "ESP32 DEVKITV1".