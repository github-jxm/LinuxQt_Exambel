#!/usr/bin/env python
#coding=utf-8

from PyQt4.QtCore import QTimer, SIGNAL
from PyQt4.QtGui import QDialog, QLabel, QLineEdit, QPushButton, QVBoxLayout
from PyQt4.QtNetwork import QUdpSocket, QHostAddress


class UdpServer(QDialog):
    def __init__(self,parent=None):

        super(UdpServer, self).__init__(parent)

        self.setWindowTitle(self.tr("UDP Server"))

        self.vbMain = QVBoxLayout(self)

        self.LabelTimer = QLabel( self )
        self.LabelTimer.setText(self.tr("Timer:"))
        self.vbMain.addWidget( self.LabelTimer )

        self.LineEditText = QLineEdit(self)
        self.vbMain.addWidget( self.LineEditText )

        self.PushButtonStart = QPushButton( self)
        self.PushButtonStart.setText( self.tr("Start"))
        self.vbMain.addWidget( self.PushButtonStart)

        self.connect(self.PushButtonStart,SIGNAL("clicked()"),
                     self.PushButtonStart_clicked)

        self.port = 5555
        self.isStarted=False
        self.udpSocket = QUdpSocket(self)

        self.timer =  QTimer(self)
        self.connect(self.timer,SIGNAL("timeout()"),self.timeout)

    def PushButtonStart_clicked(self):
        if(not self.isStarted):
            self.timer . start(1000)
            self.isStarted = True
            self.PushButtonStart.setText(self.tr("Stop"))
        else:
            self.timer . stop()
            self.isStarted = False
            self.PushButtonStart.setText(self.tr("Start"))

    def timeout(self):
        msg = self.LineEditText.text()

        length = 0
        if(msg == ""):
            return

        length = self.udpSocket.writeDatagram(msg.toLatin1(), QHostAddress.Broadcast, self.port)
        if  length != msg.length():
            return

