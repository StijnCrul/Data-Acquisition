# Generic IoT DAQ

This project describes a generic DAQ system aimed at IoT applications. The DAQ is based on a PSoC 6 device, more specifically the [PSoC 6 WiFi-BT Pioneer Kit](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wifi-bt-pioneer-kit-cy8ckit-062-wifi-bt) by Cypress. A highlight is pincomptability with Arduino shields. This page will explain how to install and configure the DAQ.

# Features
The DAQ is highly flexible and reconfigurable. By default, it functions as a serial logger and sends frames of desired length through UART. Currently, tt features:
* 4 analog inputs with reconfigurable sample rate and buffer sizes.
* A library for the [Si7021](https://www.silabs.com/documents/public/data-sheets/Si7021-A20.pdf) temperature/humidity sensor by Silicon Labs
* A library for the [LSM303DLHC](https://www.st.com/resource/en/datasheet/lsm303dlhc.pdf) eCompass.

# Getting started
## Prerequisites
To reconfigure the DAQ, you require [PSoC Creator](https://www.cypress.com/products/psoc-creator-integrated-design-environment-ide)
## Importing and uploading the project using PSoC creator
* Download and unzip the workspace from this repo.
* Open PSoC Creator and open the workspace by clicking File -> Open -> Project/Workspace. 
* Build the project by clicking the generate application button.

![Generate application](/Images/generate_application.png)

* Upload the project. Choose the M4 to upload to.

## Configuring the DAQ 
* You can choose which channels and sensors you want to use by commenting or uncommenting the tasks in the main_cm4.c file.
* By default, only sample task 0 is enabled.
* Sample frequencies can be changed by opening TopDesign.cysch and changing the "Compare or Capture" value of the relevant timer.

# Documentation
Schematic
pins
DMA configuration
