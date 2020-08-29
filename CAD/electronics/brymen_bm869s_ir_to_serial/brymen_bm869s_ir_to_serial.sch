EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:LED D1
U 1 1 5C066F2B
P 4450 1250
F 0 "D1" V 4488 1133 50  0000 R CNN
F 1 "LED" V 4397 1133 50  0000 R CNN
F 2 "LED_THT:LED_D4.0mm" H 4450 1250 50  0001 C CNN
F 3 "~" H 4450 1250 50  0001 C CNN
	1    4450 1250
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Conn_01x04_Male J1
U 1 1 5C066FF6
P 6050 2000
F 0 "J1" H 6023 1880 50  0000 R CNN
F 1 "Conn_01x04_Male" H 6023 1971 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6050 2000 50  0001 C CNN
F 3 "~" H 6050 2000 50  0001 C CNN
	1    6050 2000
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5C067085
P 4450 1600
F 0 "R1" H 4520 1646 50  0000 L CNN
F 1 "78R" H 4520 1555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4380 1600 50  0001 C CNN
F 3 "~" H 4450 1600 50  0001 C CNN
	1    4450 1600
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Photo D2
U 1 1 5C067167
P 5000 2400
F 0 "D2" V 4904 2557 50  0000 L CNN
F 1 "D_Photo" V 4995 2557 50  0000 L CNN
F 2 "LED_THT:LED_D4.0mm" H 4950 2400 50  0001 C CNN
F 3 "~" H 4950 2400 50  0001 C CNN
	1    5000 2400
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5C0671D2
P 5000 2800
F 0 "R2" H 4930 2754 50  0000 R CNN
F 1 "2k" H 4930 2845 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4930 2800 50  0001 C CNN
F 3 "~" H 5000 2800 50  0001 C CNN
	1    5000 2800
	-1   0    0    1   
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5C0673A0
P 5000 1000
F 0 "#PWR01" H 5000 850 50  0001 C CNN
F 1 "+5V" H 5015 1173 50  0000 C CNN
F 2 "" H 5000 1000 50  0001 C CNN
F 3 "" H 5000 1000 50  0001 C CNN
	1    5000 1000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5C0673FE
P 5000 3450
F 0 "#PWR02" H 5000 3200 50  0001 C CNN
F 1 "GND" H 5005 3277 50  0000 C CNN
F 2 "" H 5000 3450 50  0001 C CNN
F 3 "" H 5000 3450 50  0001 C CNN
	1    5000 3450
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5C067471
P 5350 1000
F 0 "#FLG01" H 5350 1075 50  0001 C CNN
F 1 "PWR_FLAG" H 5350 1174 50  0000 C CNN
F 2 "" H 5350 1000 50  0001 C CNN
F 3 "~" H 5350 1000 50  0001 C CNN
	1    5350 1000
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5C0674A5
P 5350 3450
F 0 "#FLG02" H 5350 3525 50  0001 C CNN
F 1 "PWR_FLAG" H 5350 3623 50  0000 C CNN
F 2 "" H 5350 3450 50  0001 C CNN
F 3 "~" H 5350 3450 50  0001 C CNN
	1    5350 3450
	-1   0    0    1   
$EndComp
Wire Wire Line
	5000 2500 5000 2600
Wire Wire Line
	5850 2100 5650 2100
Wire Wire Line
	5650 2100 5650 3200
Wire Wire Line
	5650 3200 5350 3200
Wire Wire Line
	5000 2950 5000 3200
Connection ~ 5000 3200
Wire Wire Line
	4150 2250 4150 2150
Wire Wire Line
	4150 2150 4000 2150
Wire Wire Line
	4700 2600 5000 2600
Connection ~ 5000 2600
Wire Wire Line
	5000 2600 5000 2650
Wire Wire Line
	5000 3450 5000 3200
Wire Wire Line
	5350 3450 5350 3200
Connection ~ 5350 3200
Wire Wire Line
	5350 3200 5000 3200
Text Label 4150 2200 0    50   ~ 0
M-TX
Text Label 4750 2600 0    50   ~ 0
M-RX
$Comp
L Transistor_BJT:2N3904 Q1
U 1 1 5C06A9ED
P 4350 2650
F 0 "Q1" H 4541 2696 50  0000 L CNN
F 1 "2N3904" H 4541 2605 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4550 2575 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N3904.pdf" H 4350 2650 50  0001 L CNN
	1    4350 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5C06AAA5
P 4150 2400
F 0 "R3" H 4080 2354 50  0000 R CNN
F 1 "4k7" H 4080 2445 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4080 2400 50  0001 C CNN
F 3 "~" H 4150 2400 50  0001 C CNN
	1    4150 2400
	-1   0    0    1   
$EndComp
Wire Wire Line
	4150 2550 4150 2650
Wire Wire Line
	5850 1800 5500 1800
Wire Wire Line
	5500 1800 5500 1050
Wire Wire Line
	5500 1050 5350 1050
Wire Wire Line
	5000 1000 5000 1050
Connection ~ 5000 1050
Wire Wire Line
	5000 1050 4450 1050
Wire Wire Line
	5350 1000 5350 1050
Connection ~ 5350 1050
Wire Wire Line
	5350 1050 5000 1050
Wire Wire Line
	5000 2200 5000 1050
Wire Wire Line
	4450 1100 4450 1050
Connection ~ 4450 1050
Wire Wire Line
	4450 1400 4450 1450
Wire Wire Line
	4450 1750 4450 2450
Wire Wire Line
	4450 2850 4450 3200
Connection ~ 4450 3200
Wire Wire Line
	4450 3200 5000 3200
$Comp
L MCU_Microchip_ATtiny:ATtiny84A-PU U1
U 1 1 5F481036
P 2650 2150
F 0 "U1" H 2121 2196 50  0000 R CNN
F 1 "ATtiny84A-PU" H 2121 2105 50  0000 R CNN
F 2 "Package_DIP:DIP-14_W7.62mm" H 2650 2150 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/doc8183.pdf" H 2650 2150 50  0001 C CNN
	1    2650 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1050 2650 1250
Wire Wire Line
	2650 1050 4450 1050
Wire Wire Line
	2650 3200 4450 3200
Connection ~ 2650 1250
Wire Wire Line
	2650 1250 2650 1300
Wire Wire Line
	3250 2250 3500 2250
Wire Wire Line
	3250 2150 3500 2150
Text Label 3300 2150 0    50   ~ 0
M-TX
Text Label 3300 2250 0    50   ~ 0
M-RX
Wire Wire Line
	3250 2450 3500 2450
Wire Wire Line
	3250 2550 3500 2550
Text Label 3300 2450 0    50   ~ 0
TX
Text Label 3300 2550 0    50   ~ 0
RX
Text Label 4150 1900 0    50   ~ 0
TX
Text Label 4150 2000 0    50   ~ 0
RX
Wire Wire Line
	4000 2000 5850 2000
Wire Wire Line
	4000 1900 5850 1900
NoConn ~ 3250 1550
NoConn ~ 3250 1650
NoConn ~ 3250 1750
NoConn ~ 3250 1850
NoConn ~ 3250 1950
NoConn ~ 3250 2050
NoConn ~ 3250 2650
NoConn ~ 3250 2750
Wire Wire Line
	2650 3050 2650 3200
$EndSCHEMATC
