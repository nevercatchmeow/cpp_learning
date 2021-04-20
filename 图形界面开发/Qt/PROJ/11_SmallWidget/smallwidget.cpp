#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    // 关联Spin Box 与 Horizontal Slider

    void(QSpinBox:: *spainBoxP)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spainBoxP, [=](int val){
        ui->horizontalSlider->setValue(val);
    });

    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](int val){
       ui->spinBox->setValue(val);
    });

}

SmallWidget::~SmallWidget()
{
    delete ui;
}

void SmallWidget::setData(int value)
{
    ui->spinBox->setValue(value);
}

int SmallWidget::getData()
{
    return ui->spinBox->value();
}
