#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsItem>
#include<QVector>
#include<qmath.h>
typedef struct VSTRING{
    QString text;
    int x,y,size,id;
    QPen pen;
    VSTRING(int id=0,QString text="text",int x=0,int y=0,int size=12):id(id),text(text),x(x),y(y),size(size){}
    int contains(int x,int y);
}Vstring;
typedef struct VLINE{
    int x1,y1,x2,y2,id;
    QPen pen;
    VLINE(int id=0,int x1=0,int y1=0,int x2=10,int y2=10):id(id),x1(x1),y1(y1),x2(x2),y2(y2){}
    int contains(int x,int y);
}Vline;
typedef struct VELLIPSE{
    int x1,y1,w,h,id;
    QPen pen;
    VELLIPSE(int id=0,int x1=10,int y1=10,int w=5,int h=7):id(id),x1(x1),y1(y1),w(w),h(h){}
    int contains(int x,int y);
}Vellipse;
typedef struct VRECT{
    int x1,y1,w,h,id;
    QGraphicsRectItem *address;
    QPen pen;
    VRECT(int id=0,int x1=30,int y1=30,int w=12,int h=8):id(id),x1(x1),y1(y1),w(w),h(h){}
    int contains(int x,int y);
}Vrect;
class CustomScene: public QGraphicsScene
{
private:
    QGraphicsRectItem *item1;
    QGraphicsRectItem *item2;
    QGraphicsRectItem *item3;
    QGraphicsRectItem *item4;
    QGraphicsRectItem *item5;
    QGraphicsRectItem *item6;
    QGraphicsRectItem *item7;
    QGraphicsRectItem *item8;
    QGraphicsRectItem *temprect;
    void setLittleRect(bool i,QGraphicsRectItem *item);
    QVector<int> returnitem(int x,int y);
public: 
    QVector<Vellipse> ellipsecap;
    QVector<Vrect> rectcap;
    QVector<Vline> linecap;
    QVector<Vstring> stringcap;
    CustomScene(QGraphicsScene *parent=0);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void keyPressEvent(QKeyEvent *keyEvent);
    void keyReleaseEvent(QKeyEvent *keyEvent);
};

#endif // CUSTOMSCENE_H
