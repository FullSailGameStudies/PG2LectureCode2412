#include "Sword.h"


Sword::Sword(const std::string& name, WeaponMaterial material) :
    //member initialization list
    name_(name),
    material_(material)
{
}

void Sword::DoIt(WeaponMaterial material)
{
    WeaponMaterial mat;
    material_ = material;//don't use this->  it is visual noise AND unnecessary
}

