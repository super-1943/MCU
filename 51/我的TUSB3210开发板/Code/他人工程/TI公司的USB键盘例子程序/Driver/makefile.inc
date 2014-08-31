mofcomp: usbcrypt.bmf

usbcrypt.bmf: usbcrypt.mof
        mofcomp -B:usbcrypt.bmf usbcrypt.mof
        wmimofck usbcrypt.bmf





