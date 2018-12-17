#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>
RenderArea::RenderArea(QWidget *parent) :  QWidget(parent),mBackgroundColor(0,0,255),mShapeColor(255,255,255),mShape(Astroid){


    }
QSize RenderArea::minimumSizeHint() const {return QSize(100,100);}
QSize RenderArea::sizeHint() const {return QSize(400,200);}

QPointF RenderArea::compute_astroid(float t){
    float cos_t=cos(t);
    float sin_t=sin(t);
    float x=2*cos_t*cos_t*cos_t;//pow(co_t,3);
    float y=2*sin_t*sin_t*sin_t;
    return QPointF(x,y);
}

void RenderArea::paintEvent(QPaintEvent *event){
   QPainter painter(this);

   painter.setRenderHint(QPainter::Antialiasing,true);

   switch(mShape){
   case Astroid:
       mBackgroundColor=Qt::green;
       break;
   case Cycloid:
       mBackgroundColor=Qt::blue;
       break;
   case HygensCicloid:
       mBackgroundColor=Qt::yellow;
       break;
   case HypoCicloid:
       mBackgroundColor=Qt::red;
       break;
   default:
       break;
   }
   painter.setBrush(mBackgroundColor);
   painter.setPen(mShapeColor);

   //drawing area
   painter.drawRect(this->rect());
   QPoint center=this->rect().center();
   int stepCount=256;
   float scale=40;
   float intervalLength=2*M_PI;
   float step=intervalLength/stepCount;
   for(float t=0;t<intervalLength;t+=step){
       QPointF point=compute_astroid(t);
       QPoint pixel;
       pixel.setX(point.x()*scale+center.x());
       pixel.setY(point.y()*scale+center.y());
       painter.drawPoint(pixel);
   }
}
