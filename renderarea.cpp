#include "renderarea.h"
#include <QPaintEvent>
#include <iostream>
#include <QPainter>
RenderArea::RenderArea(QWidget *parent) :  QWidget(parent),mBackgroundColor(0,0,255),mPen(Qt::white),mShape(Astroid){
mPen.setWidth(2);
on_shape_change();

    }
QSize RenderArea::minimumSizeHint() const {return QSize(400,400);}
QSize RenderArea::sizeHint() const {return QSize(400,400);}
void RenderArea::on_shape_change(){
    switch(mShape){
    case Astroid:
        mScale=90;
        mIntervalLength=2*M_PI;
        mStepCount=256;
        break;
    case Cycloid:
        mScale=10;
        mIntervalLength=4*M_PI;
        mStepCount=128;
        break;
    case HygensCicloid:
        mScale=10;
        mIntervalLength=4*M_PI;
        mStepCount=256;
        break;
    case HypoCicloid:
        mScale=40;
        mIntervalLength=2*M_PI;
        mStepCount=256;
        break;
    case Line:
        mScale=50;//line length
        mIntervalLength=2;
        mStepCount=100;
        break;
    case Circle:
        mScale=100;//line length
        mIntervalLength=2*M_PI;
        mStepCount=128;
        break;
       case Ellipse:
        mScale=75;//line length
        mIntervalLength=2*M_PI;
        mStepCount=256;
        break;
    case Fancy:
     mScale=10;//line length
     mIntervalLength=12*M_PI;
     mStepCount=512;
     break;
    case StarFish:
        mScale=25;//line length
        mIntervalLength=6*M_PI;
        mStepCount=256;
    default:
        break;
    }




}
QPointF RenderArea::compute_cycloid(float t){


    return QPointF(1.5*(1-cos(t))//x
                   ,1.5*(t-sin(t))//y
                   );
}
QPointF RenderArea::compute_line(float t){
 return QPointF(1-t,1-t);
}

QPointF RenderArea::compute_huygens(float t){
 return QPointF(4*(3*cos(t)-cos(3*t)),4*(3*sin(t)-sin(3*t)));
}
QPointF RenderArea::compute_hypocicloid(float t){
    return QPointF(
                1.5*(2*cos(t)+cos(2*t)),//X
                1.5*(2*sin(t)-sin(2*t))//Y
                );

}
QPointF RenderArea::compute_astroid(float t){
    float cos_t=cos(t);
    float sin_t=sin(t);
    float x=2*cos_t*cos_t*cos_t;//pow(co_t,3);
    float y=2*sin_t*sin_t*sin_t;
    return QPointF(x,y);
}
QPointF RenderArea::compute_circle(float t){
    float x=cos(t);
    float y=sin(t);
    return QPointF(x,y);
}

QPointF RenderArea::compute_ellipse(float t){
    float a=2;
    float b=1.1;
    return QPointF(a*cos(t),b*sin(t));
}


QPointF RenderArea::compute_fancy(float t){
    return QPointF(11.0f*cos(t)-6*cos((11.0f/6)*t),11.0f*sin(t)-6*sin((11.0f/6)*t));
}


QPointF RenderArea::compute_starfish(float t){
    int R=5;
    int r=3;
    int d=5;
    return QPointF((R-r)*cos(t)+d*cos(t*(R-r)/r),(R-r)*sin(t)-d*sin(t*(R-r)/r));
}

QPointF RenderArea::compute(float t)
{
    switch(mShape){
    case Astroid:
        return compute_astroid(t);
        break;
     case Cycloid:
        return compute_cycloid(t);
        break;
    case HygensCicloid:
        return compute_huygens(t);
        break;
    case HypoCicloid:
        return compute_hypocicloid(t);
        break;
    case Line:
        return compute_line(t);
        break;
    case Circle:
        return compute_circle(t);
        break;
    case Ellipse:
        return compute_ellipse(t);
        break;
    case Fancy:
        return compute_fancy(t);
        break;
    case StarFish:
        return compute_starfish(t);
    default:
        break;

    }
return QPointF(0,0);

}
void RenderArea::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
   QPainter painter(this);

   painter.setRenderHint(QPainter::Antialiasing,true);

//   switch(mShape){
//   case Astroid:
//       mBackgroundColor=Qt::green;
//       break;
//   case Cycloid:
//       mBackgroundColor=Qt::blue;
//       break;
//   case HygensCicloid:
//       mBackgroundColor=Qt::black;
//       break;
//   case HypoCicloid:
//       mBackgroundColor=Qt::red;
//       break;
//   default:
//       break;
//   }
   painter.setBrush(mBackgroundColor);
   painter.setPen(mPen);

   //drawing area
   painter.drawRect(this->rect());

   QPoint center=this->rect().center();
   QPointF prevPoint=compute(0);
   QPoint prevPixel;
   prevPixel.setX(prevPoint.x()*mScale+center.x());
   prevPixel.setY(prevPoint.y()*mScale+center.y());
   float step=mIntervalLength/mStepCount;
   for(float t=0;t<mIntervalLength;t+=step){
       QPointF point=compute(t);
       QPoint pixel;
       pixel.setX(point.x()*mScale+center.x());
       pixel.setY(point.y()*mScale+center.y());
       painter.drawLine(pixel,prevPixel);
       prevPixel=pixel;
   }
   QPointF point=compute(mIntervalLength);
   QPoint pixel;
   pixel.setX(point.x()*mScale+center.x());
   pixel.setY(point.y()*mScale+center.y());
   painter.drawLine(pixel,prevPixel);
}
