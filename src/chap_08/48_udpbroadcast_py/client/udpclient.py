#!/usr/bin/env python
#coding=utf-8

from PyQt4.QtCore import SIGNAL

from PyQt4.QtGui import QDialog, QVBoxLayout, QTextEdit, QPushButton, QMessageBox
from PyQt4.QtNetwork import QUdpSocket


class UdpClient(QDialog):

        def __init__(self,parent=None):
            super(UdpClient, self).__init__(parent)
            self.setWindowTitle(self.tr("UDP Client"))

            self.setWindowTitle(self.tr("UDP Client"))

            self.vbMain = QVBoxLayout( self )

            self.TextEditReceive =  QTextEdit( self)
            self.vbMain.addWidget( self.TextEditReceive )

            self.PushButtonClose =  QPushButton( self)
            self.PushButtonClose.setText( self.tr( "Close" ) )
            self.vbMain.addWidget( self.PushButtonClose )

            self.connect(self.PushButtonClose,SIGNAL("clicked()"),
                         self.PushButtonClose_clicked)
            self.port = 5555

            self.udpSocket =  QUdpSocket(self)
            self.connect(self.udpSocket, SIGNAL("readyRead()"),self.dataReceived)

            result=self.udpSocket.bind(self.port)
            if(not result):
                QMessageBox.information(self,self.tr("error"),self.tr("udp socket create error!"))
                return

        def PushButtonClose_clicked(self):
            self.accept()

        def dataReceived(self):
            while (self.udpSocket.hasPendingDatagrams()):
                max_size = self.udpSocket.pendingDatagramSize()
                data =  self.udpSocket.readDatagram(max_size)
                # (str, QHostAddress host, int port)
                print data[0]
                print data[1].toString()  # 打印 ip 地址
                print data[2]             # 打印 port
                self.TextEditReceive.insertPlainText(data[0])
