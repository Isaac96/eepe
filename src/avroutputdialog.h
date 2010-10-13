#ifndef AVROUTPUTDIALOG_H
#define AVROUTPUTDIALOG_H

#include <QDialog>
#include <QtGui>

namespace Ui {
    class avrOutputDialog;
}

class avrOutputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit avrOutputDialog(QWidget *parent, QString prog, QStringList arg, bool closeOnFinish=true);
    ~avrOutputDialog();

    void addText(const QString &text);

protected slots:
    void doAddTextStdOut();
    void doAddTextStdErr();
    void doProcessStarted();
    void doFinished(int code);

private:
    Ui::avrOutputDialog *ui;

    QProcess *process;
    QString cmdLine;
    bool doCloseOnFinish;
};

#endif // AVROUTPUTDIALOG_H
