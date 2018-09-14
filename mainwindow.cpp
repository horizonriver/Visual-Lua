#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsView"
#include "QGraphicsScene"
#include "QDebug"
#include "QClipboard"
#include "QList"
#include "QVector"
#include "QString"
#include "QFont"
#include "QGraphicsTextItem"
#include"QGraphicsItem"
#include<QTextEdit>
#include<QtMath>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    w=new CustomScene();
    ui->graphicsView->setScene(w);
    ui->graphicsView->viewport()->update();
}
void MainWindow::on_pushButton_clicked(){

}
void MainWindow::on_pushButton_4_clicked(){
    outs = "";
    outs +="function on.paint(gc)<br>&nbsp;&nbsp;&nbsp;&nbsp;gc:drawString(\"Hello world\",0,0,\"top\")<br>";
    foreach(Vrect e,w->rectcap){
        outs +="&nbsp;&nbsp;&nbsp;&nbsp;gc:drawRect(";
        outs +=QString::number(e.x1);
        outs +=",";
        outs +=QString::number(e.y1);
        outs +=",";
        outs +=QString::number(e.w);
        outs +=",";
        outs +=QString::number(e.h);
        outs +=")<br>";
    }
    foreach(Vline e,w->linecap){
        outs +="&nbsp;&nbsp;&nbsp;&nbsp;gc:drawLine(";
        outs +=QString::number(e.x1);
        outs +=",";
        outs +=QString::number(e.y1);
        outs +=",";
        outs +=QString::number(e.x2);
        outs +=",";
        outs +=QString::number(e.y2);
        outs +=")<br>";
    }
    outs +="end";
    ui->textEdit->setHtml(outs);
    clipboard->setText(ui->textEdit->toPlainText());
}
void MainWindow::on_pushButton_6_clicked(){
    clipboard->setText(ui->textEdit->toPlainText());
}
void MainWindow::on_pushButton_5_clicked(){
    ui->textEdit->setHtml("");
}
void MainWindow::on_pushButton_7_clicked(){
    if(!ui->pushButton_7->isChecked()){
        ui->pushButton_7->setChecked(true);
    }
}
bool MainWindow::eventFilter(QObject *e, QEvent *event){

}
MainWindow::~MainWindow(){
    delete ui;
}





