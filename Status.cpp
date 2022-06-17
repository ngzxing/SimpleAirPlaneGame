#include "Status.h"

template<typename dataType>
Status<dataType>::Status(string name_, dataType initial, QGraphicsItem *parent) : flag(initial), name(name_){}

template<typename dataType>
void Status<dataType>::operator +=(dataType degree)
{
    flag+=degree;
}

template<typename dataType>
void Status<dataType>::operator -=(dataType degree)
{
    flag-=degree;
}

template<typename dataType>
void Status<dataType>::setTextFont(int x , int y, const QColor& color, int fontSize, string font)
{
    setDefaultTextColor(color);
    setPos(x, y);
    setFont(QFont(font.c_str(), fontSize));
}


template<typename dataType>
void Status<dataType>::showOnScreen()
{
    setPlainText( QString((name+": ").c_str()) + QString::number(flag) );
}

template<typename dataType>
void Status<dataType>::changeFlag(dataType flag_)
{
    flag = flag_;
}

template<typename dataType>
dataType Status<dataType>::getFlag()
{
    return flag;
}

template class Status<int>;
template class Status<double>;




