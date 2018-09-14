#include "customscene.h"
#include<QGraphicsSceneMouseEvent>
#include<QVector>
int flag = 0;  //  flag=0 释放 flag=1点中态 flag=2拖动态
int VRECT::contains(int x,int y){
    int x2=x1+w;
    int y2=y1+h;
    if((qFabs(y-y1)<5&&x>x1-5&&x<x2+5)||
        (y>y1-5&&y<y2+5&&qFabs(x-x1)<5)||
        (qFabs(y-y2)<5&&x>x1-5&&x<x2+5)||
        (y>y1-5&&y<y2+5&&qFabs(x-x2)<5)){
        return 1;
    }
    return 0;
}
int VLINE::contains(int x, int y){
    double A=y2-y1;
    double B=x1-x2;
    double C=y1*(x2-x1)-(y2-y1)*x1;
    double A1=x1-x2;
    double B1=y2-y1;
    double C1=(((x1+x2)*(x2-x1))+((y1+y2)*(y2-y1)))/2;
    double distance=qFabs((A*x+B*y+C)/qSqrt(qPow(A,2)+qPow(B,2)));
    double distance1=qFabs((A1*x+B1*y+C1)/qSqrt(qPow(A1,2)+qPow(B1,2)));
    double s=qSqrt(qPow((x2-x1),2)+qPow((y2-y1),2));
    if(distance<5&&distance1<(5+s/2)){
        return 1;
    }
    return 0;
}
int VELLIPSE::contains(int x,int y){
    double x2=(x1+w+x1)/2;
    double y2=(y1+h+y1)/2;
    double a=w/2;
    double b=h/2;
    double compare1=pow(x-x2,2)/pow(a-5,2)+pow(y-y2,2)/pow(b-5,2);
    double compare2=pow(x-x2,2)/pow(a+5,2)+pow(y-y2,2)/pow(b+5,2);
    if(compare1>1&&compare2<1)
        return 1;
    return 0;
}
int VSTRING::contains(int x0,int y0){
    QRectF Rectp;
    QGraphicsScene* temp1=new QGraphicsScene();
    QFont tempfont;
    tempfont.setPixelSize(size);
    QGraphicsTextItem* temp = temp1->addText(text,tempfont);
    Rectp=temp->boundingRect();
    int x2=x+Rectp.width();
    int y2=y+Rectp.height();
    if(x0>x-5&&x0<x2+5&&y0>y-5&&y0<y2+5){
        return 1;
    }
    return 0;
}
CustomScene::CustomScene(QGraphicsScene *parent)
    :QGraphicsScene(parent){
    setSceneRect(0,0,320,211);
    item1=addRect(5,5,5,5);
    item1->setVisible(false);
    item2=addRect(5,5,5,5);
    item2->setVisible(false);
    item3=addRect(5,5,5,5);   //慎用w的add和remove函数
    item3->setVisible(false);
    item4=addRect(5,5,5,5);
    item4->setVisible(false);
    item5=addRect(5,5,5,5);
    item5->setVisible(false);
    item6=addRect(5,5,5,5);
    item6->setVisible(false);
    item7=addRect(5,5,5,5);
    item7->setVisible(false);
    item8=addRect(5,5,5,5);
    item8->setVisible(false);
    if(linecap.length()>0){
        for(int i=0;i<linecap.length();i++){
            addLine(linecap[i].x1,linecap[i].y1,linecap[i].x2,linecap[i].y2);
        }
    }
    if(stringcap.length()>0){
        for(int i=0;i<stringcap.length();i++){
            QFont tempfont;
            tempfont.setPixelSize(stringcap[i].size);
            QGraphicsTextItem* temp = addText(stringcap[i].text,tempfont);
            temp->setPos(stringcap[i].x,stringcap[i].y);
        }
    }
    if(ellipsecap.length()>0){
        foreach(Vellipse e , ellipsecap){
            addEllipse(e.x1,e.y1,e.w,e.h);
        }
    }
    rectcap.append(Vrect(1,220,100,70,100));
    rectcap.append(Vrect(2,140,130,50,50));
    if(rectcap.length()>0){
        for(int i=0;i<rectcap.length();i++){
            rectcap[i].address = addRect(rectcap[i].x1,rectcap[i].y1,rectcap[i].w,rectcap[i].h);
        }
    }
    temprect = addRect(10,10,10,10);  //如果可以在item中完成的就不要牵连上scene
    temprect->setVisible(false);
}
void CustomScene::setLittleRect(bool i,QGraphicsRectItem *item){
    int tx=item->rect().x();
    int ty=item->rect().y();
    int tw=item->rect().width();
    int th=item->rect().height();
    item1->setRect(tx-2.5,ty-2.5,5,5);
    item1->setBrush(QBrush(QColor(0,0,0)));
    item1->setVisible(i);
    item2->setRect(tx+tw/2-2.5,ty-2.5,5,5);
    item2->setBrush(QBrush(QColor(0,0,0)));
    item2->setVisible(i);
    item3->setRect(tx+tw-2.5,ty-2.5,5,5);
    item3->setBrush(QBrush(QColor(0,0,0)));
    item3->setVisible(i);
    item4->setRect(tx-2.5,ty+th/2-2.5,5,5);
    item4->setBrush(QBrush(QColor(0,0,0)));
    item4->setVisible(i);
    item5->setRect(tx+tw-2.5,ty+th/2-2.5,5,5);
    item5->setBrush(QBrush(QColor(0,0,0)));
    item5->setVisible(i);
    item6->setRect(tx-2.5,ty+th-2.5,5,5);
    item6->setBrush(QBrush(QColor(0,0,0)));
    item6->setVisible(i);
    item7->setRect(tx+tw/2-2.5,ty+th-2.5,5,5);
    item7->setBrush(QBrush(QColor(0,0,0)));
    item7->setVisible(i);
    item8->setRect(tx+tw-2.5,ty+th-2.5,5,5);
    item8->setBrush(QBrush(QColor(0,0,0)));
    item8->setVisible(i);
}
QVector<int> CustomScene::returnitem(int x, int y){
    for(int i=0;i<rectcap.length();i++){
        if(rectcap[i].contains(x,y)==1){
            return {1,rectcap[i].id};
        }
    }
    return {0,0};
}
QVector<int> temp;
int tempx,tempy,temprx,tempry;
void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *e){
    if(e->button()==Qt::LeftButton){
        int x=e->buttonDownScenePos(e->button()).x();
        int y=e->buttonDownScenePos(e->button()).y();
        temp=returnitem(x,y);
        if(flag==0){
            if(temp[0]==1){
                temprect->setVisible(true);
                setLittleRect(true,temprect);
                temprect->setRect(rectcap[temp[1]-1].x1,rectcap[temp[1]-1].y1,rectcap[temp[1]-1].w,rectcap[temp[1]-1].h);
                QPen pen;
                pen.setColor(QColor(255,0,0));
                temprect->setPen(pen);
                tempx=x;
                tempy=y;
                temprx = temprect->rect().x();
                tempry = temprect->rect().y();
                flag=2;
            }
        }
        else if(flag==1){
            if(temp[0]==1){
                rectcap[temp[1]-1].address->setVisible(false);
                temprect->setVisible(true);
                setLittleRect(true,temprect);
                temprect->setRect(rectcap[temp[1]-1].x1,rectcap[temp[1]-1].y1,rectcap[temp[1]-1].w,rectcap[temp[1]-1].h);
                QPen pen;
                pen.setColor(QColor(255,0,0));
                temprect->setPen(pen);
                tempx=x;
                tempy=y;
                temprx = temprect->rect().x();
                tempry = temprect->rect().y();
                flag=2;
            }
            else if(temp[0]==0)
            {
                temprect->setVisible(false);
                setLittleRect(false,temprect);
                flag=0;
            }
        }
        else if(flag==2){
        }
        update();
    }
}
void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e){
    int x=e->scenePos().x();
    int y=e->scenePos().y();
    if(flag==0){
        temp=returnitem(x,y);
        if(temp[0]==1){
            rectcap[temp[1]-1].address->setVisible(false);
            temprect->setVisible(true);
            temprect->setRect(rectcap[temp[1]-1].x1,rectcap[temp[1]-1].y1,rectcap[temp[1]-1].w,rectcap[temp[1]-1].h);
            QPen pen;
            pen.setColor(QColor(255,0,0));
            temprect->setPen(pen);
        }
        else if(temp[0]==0){
            for(int i=0;i<rectcap.length();i++){
                rectcap[i].address->setVisible(true);
            }
            temprect->setVisible(false);
        }
    }
    else if(flag==1){
        if(temp[0]==1){
        }
        else if(temp[0]==0){
            temprect->setVisible(false);
            setLittleRect(false,temprect);
        }
    }
    else if(flag==2){
        if(temp[0]==1){
            temprect->setRect(temprx+x-tempx,tempry+y-tempy,rectcap[temp[1]-1].w,rectcap[temp[1]-1].h);
            setLittleRect(false,temprect);
        }
    }
    update();
}
void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if(flag==2){
        temprect->setVisible(true);
        setLittleRect(true,temprect);
        rectcap[temp[1]-1].address->setRect(temprect->rect());
        rectcap[temp[1]-1].x1=temprect->rect().x();
        rectcap[temp[1]-1].y1=temprect->rect().y();
        rectcap[temp[1]-1].address->setVisible(true);
        flag = 1;
    }
    update();
}
void CustomScene::keyPressEvent(QKeyEvent *keyEvent){

}
void CustomScene::keyReleaseEvent(QKeyEvent *keyEvent){

}
