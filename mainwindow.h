#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGuiApplication>
#include <QString>
#include <QVector>
#include"customscene.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QClipboard *clipboard = QGuiApplication::clipboard();
    int con = 0;
    QString outs = "";

protected:
    bool eventFilter(QObject *watched, QEvent *event) ;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();
private:
    Ui::MainWindow *ui;
    CustomScene *w;

};









#endif // MAINWINDOW_H






