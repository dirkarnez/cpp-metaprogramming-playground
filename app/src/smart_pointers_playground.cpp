#include <iostream>
#include <memory>
#include <vector>

#include "smart_pointers_playground.h"

using namespace std;

Entity::Entity()
{
	cout << "Created Entity!" << endl;
}

Entity::~Entity()
{
	cout << "Destroyed Entity!" << endl;
}

string Entity::get_name() 
{
	return this->name;
}

void Entity::set_name(string name)
{
	this->name = name;
}

void Entity::say_hello() 
{
	cout << "Hello" << endl;
}



// I only borrow the resource.
// should use a pointer (Widget*) or a reference (Widget&) as a parameter instead
// because there is no added value in using a std::shared_ptr.
bool hasName(const std::shared_ptr<Entity>& entity)
{ 
	return entity->get_name().length() > 0;
} 

void smart_pointers_playground::play() {
	cout << "Smart Pointers: wrapper for raw pointer, no more new and delete" << endl;

	cout << "===================================" << endl;
	{
		cout << "Unique Pointer: the memory block allocated for unique pointers does not allow another pointer referencing it" << endl;
		// NOT WORKING! 
		// unique_ptr<Entity> entity = new Entity();

		// NOT RECOMMENDED!
		// unique_ptr<Entity> entity(new Entity());

		unique_ptr<Entity> entity = make_unique<Entity>();

		// NOT WORKING! unique_ptr cannot be referenced!
		// unique_ptr<Entity> entityCopied = entity;
		// Entity* entityCopied = entity;
		// weak_ptr<Entity> weak = entity;
	}   // memory for entity is going to be deleted when exiting this scope!

	cout << "===================================" << endl;
	{
		cout << "Shared Pointer: reference-counting pointers, the memory block automatically freed if no more pointer referencing it" << endl;

		shared_ptr<Entity> entity;
		{
			shared_ptr<Entity> entityInner = make_shared<Entity>();
			entity = entityInner;
		}
	} // memory for entity is going to be deleted when exiting this scope since no more pointers are referencing it!

	cout << "===================================" << endl;
	{
		cout << "Weak Pointer: pointers that won't increase reference count of it referencing shared pointer, and actually weak_ptr is not a pointer" << endl;
		weak_ptr<Entity> weak; // no make_weak;
		{
			shared_ptr<Entity> entity = make_shared<Entity>();
			weak = entity;
		} // memory for entity is going to be deleted when exiting this scope! 
		cout << "weak " << (weak.expired() ? "is" : "is not yet") << " expired" << endl; // weak referencing entity is expired!
	}

	// [10 mistakes to avoid when using std::vector | by Amir Kirsh | Jan, 2022 | Dev Genius](https://blog.devgenius.io/10-mistakes-to-avoid-when-using-std-vector-274043ca157c)
	cout << "===================================" << endl;
	{
		// create a smart pointer 
		unique_ptr<Entity> entity_unique = make_unique<Entity>();
		entity_unique->set_name("Hi");

		// hasName(entity_unique) cannot compile

		shared_ptr<Entity> entity_shared = make_shared<Entity>();
		entity_shared->set_name("Hi my name is entity_shared");
		if (hasName(entity_shared)) { 
			cout << "entity_shared has name " << entity_shared->get_name() << "\n"; 
		} 
		else { 
			cout << "entity_shared has no name\n"; 
		} 
	}
	
	cout << "===================================" << endl;
	{
		std::vector<std::unique_ptr<Entity>> vec;
		vec.push_back(std::make_unique<Entity>());
		vec.push_back(std::make_unique<Entity>());
		// elements allocated above
		// would be automatically released by unique_ptr
	}
}
