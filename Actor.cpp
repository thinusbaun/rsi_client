#include "Actor.h"

Actor::Actor() {}

QString Actor::name() const { return mName; }

void Actor::setName(const QString &name) { mName = name; }

SexObj::Sex Actor::sex() const { return mSex; }

void Actor::setSex(const SexObj::Sex &sex) { mSex = sex; }
