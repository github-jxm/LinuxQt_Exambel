#!/usr/bin/env python
# coding=utf-8


from PyQt4.QtCore import QTranslator

from messagebox import MessageBox

if __name__ == "__main__":
    import sys
    from PyQt4.QtGui import QApplication, QFont

    app = QApplication(sys.argv)

    f = QFont("ZYSong18030", 12)
    QApplication.setFont(f)

    translator = QTranslator()

    translator.load("messagebox_zh");
    app.installTranslator(translator)

    msg = MessageBox()
    msg.show();
    sys.exit(app.exec_())
