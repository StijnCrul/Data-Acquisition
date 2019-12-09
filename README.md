# Generic IoT DAQ

This project describes a generic DAQ system aimed at IoT applications. The DAQ is based on a PSoC 6 device, more specifically the [PSoC 6 WiFi-BT Pioneer Kit](https://www.cypress.com/documentation/development-kitsboards/psoc-6-wifi-bt-pioneer-kit-cy8ckit-062-wifi-bt) by Cypress. A highlight is pincomptability with Arduino shields. This page will explain how to install and configure the DAQ.

<!-- MarkdownTOC -->

- [Features](#features)
- [Getting started](#getting-started)
	- [Prerequisites](#prerequisites)
	- [Importing and uploading the project using PSoC creator](#importing-and-uploading-the-project-using-psoc-creator)
	- [Configuring the DAQ](#configuring-the-daq)
	- [Default settings](#default-settings)
- [Documentation](#documentation)
	- [Pinout](#pinout)
	- [Simplified Schematic](#simplified-schematic)
	- [DMA setup to the Serial channel](#dma-setup-to-the-serial-channel)
	- [PSoC Creator schematics](#psoc-creator-schematics)
- [How to cite](#how-to-cite)

<!-- /MarkdownTOC -->


<a id="features"></a>
# Features
The DAQ is highly flexible and reconfigurable. By default, it functions as a serial logger and sends frames of desired length through UART. Currently, tt features:
* 4 analog inputs with reconfigurable sample rate and buffer sizes.
* A library for the [Si7021](https://www.silabs.com/documents/public/data-sheets/Si7021-A20.pdf) temperature/humidity sensor by Silicon Labs
* A library for the [LSM303DLHC](https://www.st.com/resource/en/datasheet/lsm303dlhc.pdf) eCompass.
* By default, the configuration uses our inhome developed sensor board available in Eagle format [here](https://github.com/DRAMCO/Sensors_commissioning_mega_PCB)

![daq](/Images/daq.png)

<a id="getting-started"></a>
# Getting started
<a id="prerequisites"></a>
## Prerequisites
To reconfigure the DAQ, you require [PSoC Creator](https://www.cypress.com/products/psoc-creator-integrated-design-environment-ide)
<a id="importing-and-uploading-the-project-using-psoc-creator"></a>
## Importing and uploading the project using PSoC creator
* Download and unzip the workspace from this repo.
* Open PSoC Creator and open the workspace by clicking File -> Open -> Project/Workspace. 
* Build the project by clicking the generate application button.

![Generate application](/Images/generate_application.png)

* Upload the project. Choose the M4 to upload to.

![Program application](/Images/program.png)

<a id="configuring-the-daq"></a>
## Configuring the DAQ 
* You can choose which channels and sensors you want to use by commenting or uncommenting the tasks in the main_cm4.c file.
* By default, only one analog channel is enabled.

![default_tasks](/Images/default_tasks.png)

* Sample frequencies can be changed by opening TopDesign.cysch and changing the "Compare or Capture" value of the relevant timer.

<a id="default-settings"></a>
## Default settings
By default all analog channels are configured to send frames of 1024 samples each second. The samplefrequency is 44100 kHz. The accelerometer samples at 1 kHz and sends a frame of 1000 samples each second. The Si7021 sends one sample every minute.

<a id="documentation"></a>
# Documentation

<a id="pinout"></a>
## Pinout
The default pinout is depicted in the image below. A0 to A3 are the analog inputs and correspond to the same Arduino inputs. O_0 to O_9 are debug outputs. The I2C and UART pins are for communication. All pins can be changed depending on the needs of your application. 

![Pinout](/Images/pinout.png)

<a id="simplified-schematic"></a>
## Simplified Schematic

The schematic shows the functionality of the DAQ in its default configuration. I2C sensors are controlled by the bus. Analog sensors are controlled by digital control logic. Timers are used to determine the sample rate for each channel. Once a timer generates an interrupt, the control logic sets the analog multiplexer and trigger the start of conversion for the ADC. Once a conversion is finished. A DMA channel copies the result to a buffer.

![simplified_schematic](/Images/simplified_schematic.png)

<a id="dma-setup-to-the-serial-channel"></a>
## DMA setup to the Serial channel

Once a sensor's buffer is full, its respective DMA channel generates an interrupt that enables the serial DMA channel. The serial DMA channel contains 2 descriptors per sensor. One to send some command bytes and one to send the actual buffer. Once the descriptor for the command bytes is finished, it chains to the descriptor for the gathered sensor data. This is illustrated in the image below.

![dma_config](/Images/dma_config.png)

<a id="psoc-creator-schematics"></a>
## PSoC Creator schematics
The project is split up into 4 schematics: one for the ADC and communication blocks, one for the DMA channels, one for the timers and one for the timer logic.

![schematic_adc](/Images/schematic_adc.png)

![schematic_dma](/Images/schematic_dma.png)

![schematic_timers](/Images/schematic_timers.png)

![schematic_control](/Images/schematic_control_timers.png)

<a id="how-to-cite"></a>
# How to cite
```latex
@misc{crulDAQ,
author =   {Crul, Stijn and Raes, Willem},
title =    {{Generic IoT DAQ}},
doi = {10.5281/zenodo.3568053},
howpublished = {\url{https://github.com/StijnCrul/Data-Acquisition}},
}
```


