#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);


    QSize minimumSizeHint() const   Q_DECL_OVERRIDE;
    QSize sizeHint() const   Q_DECL_OVERRIDE;
    enum Shapes{Astroid,Cicloid,HygensCicloid,HypoCicloid};
    void setBackgroundColor(QColor color){mBackgroundColor=color;}
    QColor backgroundColor() const{return mBackgroundColor;}
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

public slots:

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
};

#endif // RENDERAREA_H
