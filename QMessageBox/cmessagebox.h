#ifndef CMESSAGEBOX_H
#define CMESSAGEBOX_H
#include <QObject>
#include <QDialog>
#include "CSingleton.h"
namespace Ui {
class CMessageBox;
}
enum MSGTYPE
{
    MSG_WARN = 0,
    MSG_INFO = 1,
    MSG_ERROR = 2,
    MSG_QUESTION =3
};
class CMessageBox : public QDialog
{
     Q_OBJECT SINGLETON_DECL(CMessageBox)

public:

    explicit CMessageBox(QWidget *parent = nullptr);
    ~CMessageBox();

    void  setContent(MSGTYPE type, const QString &strContent,const QString &strConfirmCont,  bool isWhiteTheme = true);


private:
    Ui::CMessageBox *ui;


    void  setInfoMsg(MSGTYPE type,const QString& strContent,const QString& strConfirmCont);

    //亮主题
    void setWhiteTheme();
    //暗主题
    void setBlackTheme();

};

#endif // CMESSAGEBOX_H
