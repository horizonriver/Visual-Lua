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
#include<iostream>

using namespace std;
typedef struct VSTRING{
    QString text;
    int x,y,size;
    VSTRING(QString text="text",int x=0,int y=0,int size=12):text(text),x(x),y(y),size(size){}
}Vstring;
typedef struct VLINE{
    int x1,y1,x2,y2;
    VLINE(int x1=0,int y1=0,int x2=10,int y2=10):x1(x1),y1(y1),x2(x2),y2(y2){}
}Vline;
typedef struct VELLIPSE{
    int x1,y1,x2,y2;
    VELLIPSE(int x1=10,int y1=10,int x2=5,int y2=7):x1(x1),y1(y1),x2(x2),y2(y2){}
}Vellipse;
typedef struct VRECT{
    int x1,y1,w,h;
    VRECT(int x1=30,int y1=30,int w=12,int h=8):x1(x1),y1(y1),w(w),h(h){}
}Vrect;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    w=new QGraphicsScene();
    ui->graphicsView->setSceneRect(0,0,320,211);
    ui->graphicsView->setScene(w);
    QList<QPushButton*> t = {ui->pushButton_7,ui->pushButton,ui->pushButton_2,ui->pushButton_3};
    for(int i=0;i<t.length();i++){
        t.at(i)->setCheckable(true);
    }
    ui->pushButton_7->setChecked(true);
    ui->lineEdit->setEnabled(false);


    QVector<Vline> linecap;
    linecap.append(Vline(0,0,50,50));
    linecap.append(Vline(70,80,200,80));
    for(int i=0;i<linecap.length();i++){
        w->addLine(linecap[i].x1,linecap[i].y1,linecap[i].x2,linecap[i].y2);
    }
    QVector<Vstring> stringcap;
    stringcap.append(Vstring("test1",0,0,12));
    stringcap.append(Vstring("test2",160,180,20));
    for(int i=0;i<stringcap.length();i++){
        QFont tempfont;
        tempfont.setPixelSize(stringcap[i].size);
        QGraphicsTextItem* temp = w->addText(stringcap[i].text,tempfont);
        temp->setPos(stringcap[i].x,stringcap[i].y);
    }
    //矩形、圆形、椭圆
    //圆的实现
    QVector<Vellipse>circlecap;
    circlecap.append(Vellipse(50,50,20,20));
    circlecap.append(Vellipse(70,70,30,30));
    foreach(Vellipse e , circlecap){
        w->addEllipse(e.x1,e.y1,e.x2,e.y2);
    }
    //椭圆的实现
    QVector<Vellipse>ellipsecap;
    ellipsecap.append(Vellipse(100,100,38,47));
    ellipsecap.append(Vellipse(70,50,60,82));
    foreach(Vellipse e , ellipsecap){
        w->addEllipse(e.x1,e.y1,e.x2,e.y2);
    }
    //矩形的实现
    QVector<Vrect>rectcap;
    rectcap.append(Vrect(150,150,50,30));
    rectcap.append(Vrect(220,100,70,100));
    foreach(Vrect e,rectcap){
        w->addRect(e.x1,e.y1,e.w,e.h);
    }
}


MainWindow::~MainWindow(){
    delete ui;
}
void MainWindow::on_pushButton_clicked(){

}
void MainWindow::on_pushButton_4_clicked(){
    outs = "function on.paint(gc)<br>&nbsp;&nbsp;&nbsp;&nbsp;gc:drawString(\"Hello world\",0,0,\"top\")<br>end";
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
bool MainWindow::eventFilter(QObject *e, QEvent *event)
{
    if(event->type()==QEvent::GraphicsSceneMousePress){
        QGraphicsSceneMouseEvent * e= dynamic_cast<QGraphicsSceneMouseEvent *>(event);
        for(int i=0;i<w->selectedItems().length();i++)
        {
            if(e->buttonDownScenePos(e->button()).x()==w->selectedItems()[i]->x()
                    &&e->buttonDownScenePos(e->button()).y()==w->selectedItems()[i]->y())
            {
                if(e->button()==Qt::LeftButton)
                {
                    w->selectedItems()[i]->setEnabled(true);
                }
            }
        }
    }
    if(event->type()==QEvent::GraphicsSceneMouseMove){

    }
    if(event->type()==QEvent::GraphicsSceneMouseRelease){

    }
    return false;
}











