#!/usr/bin/env python
#coding = utf-8

from PyQt4.QtCore import SIGNAL, SLOT, QString, Qt
from PyQt4.QtGui import QDialog, QGridLayout, QFileDialog, QColor, QColorDialog, QPalette, QFontDialog, QFont
from PyQt4.QtGui import QPushButton, QLineEdit, QFrame


class StandardDialogs(QDialog):
    def __init__(self,parent=None):
        super(StandardDialogs, self).__init__(parent)

        self.setWindowTitle(self.tr("Standard Dialogs"))

        self.__layout = QGridLayout(self)

        self.filePushButton = QPushButton()

        self.filePushButton.setText(self.tr("File Dialog"))

        self.colorPushButton =  QPushButton()
        self.colorPushButton.setText(self.tr("Color Dialog"))

        self.fontPushButton =  QPushButton( )
        self.fontPushButton.setText(self.tr("Font Dialog"))

        self.fileLineEdit =  QLineEdit()

        self.colorFrame =  QFrame()
        self.colorFrame.setFrameShape( QFrame.Box )
        self.colorFrame.setAutoFillBackground(True)

        self.fontLineEdit =  QLineEdit( )
        self.fontLineEdit.setText(self.tr("Hello World"))


        self.__layout.addWidget( self.filePushButton,0,0)
        self.__layout.addWidget( self.fileLineEdit,0,1)
        self.__layout.addWidget( self.colorPushButton,1,0)
        self.__layout.addWidget( self.colorFrame, 1,1)
        self.__layout.addWidget( self.fontPushButton,2,0)
        self.__layout.addWidget( self.fontLineEdit,2,1)
        self.__layout.setMargin(15)
        self.__layout.setSpacing(10)

        self.connect(self.filePushButton,SIGNAL("clicked()"),
                     self.slotOpenFileDlg)

        self.connect(self.colorPushButton,SIGNAL("clicked()"),
                     self.slotOpenColorDlg)

        self.connect(self.fontPushButton,SIGNAL("clicked()"),
                     self.slotOpenFontDlg)

    def slotOpenFileDlg(self):
        s = QFileDialog.getOpenFileName(self, "open file dialog",
           "C++ files (*.cpp)C files (*.c)Head files (*.h)")
        self.fileLineEdit.setText(str(s))


    def slotOpenColorDlg(self):

        color = QColorDialog.getColor(Qt.blue)

        if(color.isValid()):
            self.colorFrame.setPalette(QPalette(color))

    def slotOpenFontDlg(self):

        font,ok = QFontDialog.getFont()
        if( ok ):
            self.fontLineEdit.setFont( font )

