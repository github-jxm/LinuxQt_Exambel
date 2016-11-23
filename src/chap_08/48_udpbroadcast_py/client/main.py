#!/usr/bin/env python
#coding=utf-8

from PyQt4.QtCore import QTranslator

from PyQt4.QtGui import QFont
from PyQt4.QtGui import QApplication
import sys

from udpclient import UdpClient

if __name__ == "__main__":

    font = QFont("ZYSong18030",12)
    QApplication.setFont(font)
    app = QApplication(sys.argv)

    translator = QTranslator(None)
    translator.load("udpclient_zh",".")
    app.installTranslator(translator)
    udpclient = UdpClient()
    udpclient.show()
    app.exec_()
