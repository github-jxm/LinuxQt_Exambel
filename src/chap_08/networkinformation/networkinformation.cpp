#include "networkinformation.h"
#include <QDebug>

NetworkInformation::NetworkInformation( QWidget *parent, Qt::WindowFlags  f )
    : QDialog( parent, f )
{  
    setWindowTitle(tr("Network Information"));
       
    LabelLocalHostName = new QLabel();
    LabelLocalHostName->setText(tr("localhostname:"));
    
    LineEditLocalHostName = new QLineEdit();   

    LabelAddress = new QLabel();
    LabelAddress->setText(tr("address:"));

    LineEditAddress = new QLineEdit();

    PushButtonDetail = new QPushButton( this);
    PushButtonDetail->setText( tr( "Detail" ) );

    QHBoxLayout *hbLayout1 = new QHBoxLayout ();
    hbLayout1->addWidget(LabelLocalHostName);
    hbLayout1->addWidget(LineEditLocalHostName);

    QHBoxLayout *hbLayout2 = new QHBoxLayout ();
    hbLayout2->addWidget(LabelAddress);
    hbLayout2->addWidget(LineEditAddress);

    QVBoxLayout *vbLayout = new QVBoxLayout( this );
    vbLayout->addLayout( hbLayout1 );
    vbLayout->addLayout( hbLayout2 );
    vbLayout->addWidget( PushButtonDetail );

    connect(PushButtonDetail,SIGNAL(clicked()),this,SLOT(slotDetail()));
    
 	getHostInformation();
}

NetworkInformation::~NetworkInformation()
{

}

void NetworkInformation::getHostInformation()
{
	QString localHostName=QHostInfo::localHostName();
    LineEditLocalHostName->setText(localHostName);
	
    QHostInfo hostInfo = QHostInfo::fromName(localHostName);
    QList<QHostAddress> listAddress = hostInfo.addresses();  // 无线网卡,地址,识别不到
    //QList<QHostAddress>listAddress = QNetworkInterface::allAddresses();  //所有地址,会取到DHCP分配失败的保留地址
    if(!listAddress.isEmpty())
    {
//        qDebug () <<  " all : " << listAddress;
        LineEditAddress->setText(listAddress.first().toString());
        foreach (QHostAddress address,listAddress ) //遍历IP地址
        {
            if(address.protocol() == QAbstractSocket::IPv4Protocol){
                    qDebug() <<"IPV4"<<address.toString();
            }else if  (address.protocol() == QAbstractSocket::IPv6Protocol){
                    qDebug()  << "IPV6"<<address.toString();
            }else{
                    qDebug()  << "other: "<<address.toString();
            }
        }
    }
}

void NetworkInformation::slotDetail()
{                                 
	QString detail=""; 
	                                           
	QList<QNetworkInterface> list=QNetworkInterface::allInterfaces ();
	for(int i=0;i<list.count();i++)
	{
		QNetworkInterface interface=list.at(i);
		detail = detail+tr("Device:")+interface.name()+"\n";
		QString hardwareAddress=interface.hardwareAddress();
		detail = detail+tr("HardwareAddress:")+interface.hardwareAddress()+"\n";
		
		QList<QNetworkAddressEntry> entryList=interface.addressEntries();
		for(int j=0;j<entryList.count();j++)
		{
			QNetworkAddressEntry entry=entryList.at(j);
			detail = detail+"\t"+tr("IP Address:")+entry.ip().toString()+"\n";
			detail = detail+"\t"+tr("Netmask:")+entry.netmask().toString()+"\n";
			detail = detail+"\t"+tr("Broadcast:")+entry.broadcast().toString()+"\n";
		}
	}
	QMessageBox::information(this,tr("Detail"),detail);
		
}
