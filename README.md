# esp32-wifi-ssid-spam
Creates multiple fake networks using ESP 32 DEVKIT V1.

**CONFIG**\n

Change the Constant numIDs, depending on how many fake networks need to be created.
```
const int numIDs = 250; // set the no. of networks to be created
```
For example, for 250 unique networks, set to 250.


Add SSIDs in ssids list.
```
const char* ssids[numIDs] = {
  "HackedWiFi_1\n",
  "HackedWiFi_2\n"
};
```
- Important, Every SSID ends with '\n'
- Also numIDs should be same as no. of ssids in ssids list.


**USAGE**\n
Run, Flash the program on ESP 32 Boards.

**LED Indication**\n
On the creation, transmission of each packet, the in-built LED is turned on and off, which makes it easier to debug.

