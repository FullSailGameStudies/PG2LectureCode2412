#pragma once
#include <string>

enum WeaponMaterial
{
	Wood, Stone, Iron, Obsidian
};

class Sword
{
public:
//ALL code can see it
	void DoIt2()
	{
		DoIt(WeaponMaterial::Obsidian);
	}

	//ctors are supposed to initialize the object
	// (give values to fields)
	// IF you do not create a ctor, 
	//		the compiler will create a default ctors for you
	// IFF you create a ctor, the compiler's ctor will NOT be available
	//Sword() //default ctor (no parameters) 
	//{

	//}
	Sword(const std::string& name, WeaponMaterial material);

	//getters (accessors)
	std::string GetName() const { return name_; }
	WeaponMaterial Material() const { return material_; }

	//setters (mutators)
	void SetName(const std::string& name)
	{
		//provide "protections" on your fields
		if (name.size() > 0 && name.size() < 32)
		{
			name_ = name;
		}
	}
	void Material(WeaponMaterial newMaterial)
	{
		material_ = newMaterial;
	}

protected:
//the Sword class and ALL descendent classes can see it

private: //the default
	//ONLY the Sword class can see it
	//camelCasingNamingConvention
	//data: sharpness, length, width, price, material
	std::string name_;
	WeaponMaterial material_;
	//m_sName, mName, m_Name, _Name, name_

	//METHODS: (member functions)
	//	camelCasing or PascalCasing, push_back
	void DoIt(WeaponMaterial material);


};

