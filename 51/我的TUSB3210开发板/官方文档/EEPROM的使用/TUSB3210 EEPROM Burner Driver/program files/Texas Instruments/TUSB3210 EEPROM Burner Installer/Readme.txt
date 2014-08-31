TI TUSB2136 EEPROMBurner tool  is used to program a blank EEPROM and erase a invalid EEPROM (EEPROM without the signature 0x2136 in the first 2 bytes). This document details the installation instructions for this tool.

Installation instructions
--------------------------

1. Uninstall any previous device drivers used for the TUSB2136 device. For instance, if Apploader was used, perform a clean uninstall of the device. Make sure in the registry, HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Enum\USB\Vid_0451&Pid_2136 is not present. If it is in the registry delete this entry.
2. Unplug the device. Remove the power. Replace the EEPROM if any with a blank/invalid EEPROM. 
3. Plug the device and direct the Hardware Wizard to look for the drivers in the directory where the TI TUSB2136 EEPROMBurner install files are located. 
4. Run the application eepromburner.exe in the eepromburner_application directory to  program the EEPROM.

Known Issues
-------------

When the uninstall of previous drivers are not done proper, the system requests to reboot after the TI TUSB2136 EEPROM Burner is installed. The system should be rebooted for the EEPROM Burner to function properly.



