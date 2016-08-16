#!/usr/bin/env python
#coding = utf-8

# http://blog.csdn.net/ying_593254979/article/details/10189687

from PyQt4.QtCore import QTranslator
from PyQt4.QtGui import QApplication, QFont
import sys

from standarddialogs import StandardDialogs

if __name__ == "__main__":
    font = QFont("ZYSong18030", 18)
    # font = QFont("ubuntu", 18)
    QApplication.setFont(font)

    a = QApplication(sys.argv)

    translator = QTranslator(None)
    translator.load("standarddialogs_zh", "./")

    a.installTranslator(translator)

    standarddialogs = StandardDialogs()

    standarddialogs.show()
    a.exec_()
