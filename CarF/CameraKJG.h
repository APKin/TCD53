#pragma once

#include <QObject>

class CameraKJG  : public QObject
{
	Q_OBJECT

public:
	CameraKJG(QObject *parent);
	~CameraKJG();
};
