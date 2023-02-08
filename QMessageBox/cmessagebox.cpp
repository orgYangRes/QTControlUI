#include "cmessagebox.h"
#include "ui_cmessagebox.h"
#include <QPixmap>

SINGLETON_IMPL(CMessageBox)
CMessageBox::CMessageBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CMessageBox)
{
    ui->setupUi(this);
}

CMessageBox::~CMessageBox()
{
    delete ui;
}

void CMessageBox::setContent(MSGTYPE type, const QString &strContent,const QString &strConfirmCont,  bool isWhiteTheme)
{
    setInfoMsg(type,strContent,strConfirmCont);

    setBlackTheme();



    this->show();
}



void CMessageBox::setInfoMsg(MSGTYPE type,const QString& strContent,const QString& strConfirmCont)
{
    switch (type) {
    case MSG_WARN:
        ui->lab_icon->setPixmap(QPixmap(":/icon/msg_warn.png"));
        break;
    case MSG_INFO:
        ui->lab_icon->setPixmap(QPixmap(":/icon/msg_info.png"));
        break;
    case MSG_ERROR:
        ui->lab_icon->setPixmap(QPixmap(":/icon/msg_error.png"));
        break;
    case MSG_QUESTION:
        ui->lab_icon->setPixmap(QPixmap(":/icon/msg_question.png"));
        break;
    default:
        break;
    }

    if(!strContent.isEmpty())
    {
        ui->ld_out_content->setText(strContent);
    }
    if(!strConfirmCont.isEmpty())
    {
        ui->ld_confirm_content->setPlaceholderText(strConfirmCont);
    }

}

void CMessageBox::setWhiteTheme()
{

}

void CMessageBox::setBlackTheme()
{
    this->setStyleSheet("QDialog#CMessageBox{background: #17181F;}");
    ui->ld_out_content->setStyleSheet("background: #17181F;border-radius: 0px 0px 0px 0px;color:white");
    ui->ld_confirm_content->setStyleSheet("background: #17181F;border-radius: 0px 0px 0px 0px;color:white");
}


