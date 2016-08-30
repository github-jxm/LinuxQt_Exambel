#!/usr/bin/env python
#coding=utf-8

from PyQt4.QtCore import SIGNAL
from PyQt4.QtGui import QDialog, QLabel, QGridLayout, QVBoxLayout, QMessageBox, QPixmap, QPushButton


class  MessageBox(QDialog):
    def __init__(self,parent=None):
        super(MessageBox, self).__init__(parent)
        self.setWindowTitle(self.tr("Message Box Example"))

        self.label = QLabel()


        btn1 = QPushButton("Question")
        btn2 = QPushButton("Information")
        btn3 = QPushButton("Warning")
        btn4 = QPushButton("Critical")
        btn5 = QPushButton("About")
        btn6 = QPushButton("About Qt")
        btn7 = QPushButton("Custom")

        grid =  QGridLayout()


        grid.addWidget(btn1,0,0)
        grid.addWidget(btn2,0,1)
        grid.addWidget(btn3,1,0)
        grid.addWidget(btn4,1,1)
        grid.addWidget(btn5,2,0)
        grid.addWidget(btn6,2,1)
        grid.addWidget(btn7,3,0)

        mainLayout = QVBoxLayout()
        mainLayout.setMargin(10)
        mainLayout.setSpacing(20)
        mainLayout.addWidget(self.label)
        mainLayout.addLayout(grid)
        self.setLayout(mainLayout)

        self.connect(btn1,SIGNAL("clicked()"),self.__slotQuestion)
        self.connect(btn2,SIGNAL("clicked()"),self.__slotInformation)
        self.connect(btn3,SIGNAL("clicked()"),self.__slotWarning)
        self.connect(btn4,SIGNAL("clicked()"),self.__slotCritical)
        self.connect(btn5,SIGNAL("clicked()"),self.__slotAbout)
        self.connect(btn6,SIGNAL("clicked()"),self.__slotAboutQt)
        self.connect(btn7,SIGNAL("clicked()"),self.__slotCustom)

    def __slotQuestion(self):

        ret = QMessageBox.question(self,"Question",self.tr("It's end of document,search from begin?") ,
                                     QMessageBox.Ok|QMessageBox.Cancel,QMessageBox.Ok )
        if ret == QMessageBox.Ok:
            self.label.setText(" Question button / Ok ")
        elif ret == QMessageBox.Cancel:
                    self.label.setText(" Question button / Cancel ")

    def  __slotInformation(self):
        QMessageBox.information(self,"Information",self.tr("anything you want tell user"))

    def __slotWarning(self):
        ret = QMessageBox.warning(self,"Warning",self.tr("Save changes to document?"),
                                  QMessageBox.Save|QMessageBox.Discard|QMessageBox.Cancel,QMessageBox.Save)
        if ret == QMessageBox.Save:
            self.label.setText(" Warning button / Save ")
        elif ret == QMessageBox.Discard:
            self.label.setText(" Warning button / Discard ")
        elif ret == QMessageBox.Cancel:
            self.label.setText(" Warning button / Cancel ")


    def __slotCritical(self):
        QMessageBox.critical(self,"Critical",self.tr("tell user a critical error"))
        self.label.setText(" Critical MessageBox ")

    def __slotAbout(self):
        QMessageBox.about(self,"About",self.tr("Message box example!"))
        self.label.setText(" About MessageBox ")

    def __slotAboutQt(self):
        QMessageBox.aboutQt(self,"About Qt")
        self.label.setText(" About Qt MessageBox ")

    def __slotCustom(self):
        customMsgBox = QMessageBox()

        customMsgBox.setWindowTitle("Custom message box")
        lockButton = customMsgBox.addButton(self.tr("Lock"),QMessageBox.ActionRole)
        unlockButton = customMsgBox.addButton(self.tr("Unlock"),QMessageBox.ActionRole)
        cancelButton = customMsgBox.addButton(QMessageBox.Cancel)

        customMsgBox.setIconPixmap(QPixmap(":/images/linuxredhat.png"))
        customMsgBox.setText(self.tr("This is a custom message box"))
        customMsgBox.exec_()

        if(customMsgBox.clickedButton() == lockButton):
                self.label.setText(" Custom MessageBox / Lock ")
        if(customMsgBox.clickedButton() == unlockButton):
                self.label.setText(" Custom MessageBox / Unlock ")
        if(customMsgBox.clickedButton() == cancelButton):
                self.label.setText(" Custom MessageBox / Cancel ")

