#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPen>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);


    QSize minimumSizeHint() const   Q_DECL_OVERRIDE;
    QSize sizeHint() const   Q_DECL_OVERRIDE;
    enum ShapeType{Astroid,Cycloid,HygensCicloid,HypoCicloid,Line,Circle,Ellipse,Fancy,StarFish,Cloud,Sun};

    void setBackgroundColor(QColor color){mBackgroundColor=color;}
    QColor backgroundColor() const{return mBackgroundColor;}

    void setShapeColor(QColor linecolor){mPen.setColor(linecolor);repaint();}
    QColor shapeColor() const{return mPen.color();}

    void setScale(float scale){mScale=scale;repaint();}
    float scale() const{return mScale;}

    void setInterval(float interval){mIntervalLength=interval;repaint();}
    float intervalLength() const{return mIntervalLength;}

    void setStepCount(int count){mStepCount=count;repaint();}
    int stepCount() const{return mStepCount;}

    void setShape(ShapeType shape)
    {
        mShape=shape;
        on_shape_change();
    }
    ShapeType shape() const{return mShape;}
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

public slots:

private:
    QColor mBackgroundColor;
    QPen mPen;
    ShapeType mShape;
    float mIntervalLength;
    float mScale;
    int mStepCount;
    void on_shape_change();
    QPointF compute(float t);//dispatch function based on mShape's type
    QPointF compute_astroid(float t);
    QPointF compute_hypocicloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_line(float t);
    QPointF compute_circle(float t);
    QPointF compute_ellipse(float t);
    QPointF compute_fancy(float t);
    QPointF compute_starfish(float t);
    QPointF compute_cloud(float t);
    QPointF compute_sun(float t);
    QPointF compute_skythings(float t,float sign);
};

#endif // RENDERAREA_H
