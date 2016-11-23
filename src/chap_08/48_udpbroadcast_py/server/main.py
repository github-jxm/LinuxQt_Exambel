#!/usr/bin/env python
#coding=utf-8

import sys
from PyQt4.QtCore import QTranslator
from PyQt4.QtGui import QApplication, QFont

from udpserver import UdpServer

if __name__ == "__main__":

    font = QFont("ZYSong18030",12)
    QApplication.setFont(font)
    app = QApplication(sys.argv)
    translator = QTranslator(None)
    translator.load("udpserver_zh",".")
    app.installTranslator(translator)

    udpserver =  UdpServer()
    udpserver.show()
    app.exec_()
