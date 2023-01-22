#pragma once

using namespace std;

class Entity
{
private:
	string name;
public:
	Entity();
	~Entity();
	void say_hello();
	string get_name();
	void set_name(string name);
};

class smart_pointers_playground
{
public:
    void play();
};