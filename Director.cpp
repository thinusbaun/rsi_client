#include "Director.h"

Director::Director() {}

QString Director::name() const { return mName; }

void Director::setName(const QString &name) { mName = name; }

SexObj::Sex Director::sex() const { return mSex; }

void Director::setSex(const SexObj::Sex &sex) { mSex = sex; }
